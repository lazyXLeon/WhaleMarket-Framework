#include "user/user.h"
#include "tools/info.h"

static User users[MAX_USER]; // 存储所有的用户

static int user_count = 0; // 当前用户数量

static const string USER_FILE = "src/data/users.txt"; // 用户文件路径

static const string header = "|   用户ID   |   用户名   |   联系方式   |   用户地址   |   用户余额   |";
static const string divide = "+-----------+-----------+-------------+-------------+------------+";

void pullUsers() {
    user_count = 0;

    ifstream ifs(USER_FILE);

    if (ifs.is_open()) {
        while (ifs >> users[user_count].id >> users[user_count].name >> users[user_count].password >> users[user_count].contact >> users[user_count].address >> users[user_count].balance){
            user_count++;
        }
        ifs.close();
    }
}

void pushUsers() {
    ofstream ofs(USER_FILE);
    
    if (ofs.is_open()) {
        for (int i = 0; i < user_count; i++) {
            ofs << users[i].id << " " << users[i].name << " " << users[i].password << " " << users[i].contact << " " << users[i].address << " " << users[i].balance << endl;
        }

        ofs.close();
    }
}

User* getUser(int index) {
    return &users[index];
}

void userInfo(int index) {
    cout << "用户ID:      \t" << users[index].id << endl;
    cout << "用户名：      \t" << users[index].name << endl;
    cout << "用户联系方式： \t" << users[index].contact << endl;
    cout << "用户地址：    \t" << users[index].address << endl;
    cout << "用户余额：    \t" << fixed << setprecision(1) << users[index].balance << endl;
}

/**
 * @brief 根据用户名查找用户
 *
 * @param name 待查找的用户名
 * @return int 用户索引，-1表示未找到
 */
static int searchUserByName(const char* name) {
    for (int i = 0; i < user_count; i++) {
        if (users[i].name == name) {
            return i;
        }
    }
    return -1;
}

int addUser(User& user) {
    if (user_count >= MAX_USER) {
        return 0;
    }
    if (searchUserByName(user.name) != -1) return 0;
    genID(user.id, 'U');
    users[user_count++] = user;
    pushUsers();
    return 1;
}

/**
 * @brief 根据给定的ID查找用户
 *
 * @param id 用户ID
 * @return int 用户索引，-1表示未找到
 */
static int searchUserByID(const char* id) {
    for (int i = 0; i < user_count; i++) {
        if (users[i].id == id) {
            return i;
        }
    }
    return -1;
}

int deleteUser(const char* id, const char* who) {
    if(who) return 0; // 只有管理员可以删除用户，管理员对应的id为空
    int index = searchUserByID(id);
    if (index == -1) {
        return 0;
    }
    for (int i = index; i < user_count - 1; i++) {
        users[i] = users[i + 1];
    }
    user_count--;
    pushUsers();

    return 1;
}

/**
 * @brief 打印单个用户，即表格的一行
 *
 * @param index 用户索引
 */
static void printUser(int index) {
    cout << "|"
         << setw(14) << left << users[index].id << " |"
         << setw(14) << left << users[index].name << " |"
         << setw(14) << left << users[index].contact << " |"
         << setw(14) << left << users[index].address << " |"
         << setw(14) << left << fixed << setprecision(1) << users[index].balance << " |"
         << endl;
}

void printUsers() {
    print_header
    for (int i = 0; i < user_count; i++) {
        printUser(i);
        print_divide
    }
}

int checkPwd(const char* name, const char* password, int* index) {
    *index = searchUserByName(name);
    if (*index == -1) {
        return 0;
    }

    if (users[*index].password == password) {
        return 1;
    }

    return 0;
}

int userTopUp(const char* id, double amount) {
    int index = searchUserByID(id);
    if (index == -1) {
        return 0;
    }

    users[index].balance += amount;
    pushUsers();

    return 1;
}