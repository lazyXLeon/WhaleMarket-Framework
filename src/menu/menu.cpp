#include "config.h"
#include "menu/menu.h"
#include "tools/hint.h"
#include "tools/color.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

const int optionNum[MENU_NUM] = {4, 7, 4, 6, 6, 4, 4, 4};

static const char* menuPrompts[MENU_NUM] = {"\
+==============+================+===============+========+\n\
| 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit |\n\
+==============+================+===============+========+\n", \
"\
+=========+==========+==========+=========+==========+=======+========+\n\
| 1.Goods | 2.Search | 3.Orders | 4.Users | 5.Delete | 6.Ban | 7.Back |\n\
+=========+==========+==========+=========+==========+=======+========+\n", \
"\
+=========+==========+==============+========+\n\
| 1.Buyer | 2.Seller | 3.Infomation | 4.Back |\n\
+=========+==========+==============+========+\n", \
"\
+=========+=======+==========+=========+===============+========+\n\
| 1.Goods | 2.Buy | 3.Search | 4.Order | 5.Information | 6.Back |\n\
+=========+=======+==========+=========+===============+========+\n", \
"\
+========+=========+==========+=======+=========+========+\n\
| 1.Sell | 2.Goods | 3.Modify | 4.Ban | 5.Order | 6.Back |\n\
+========+=========+==========+=======+=========+========+\n", \
"\
+===============+==========+==========+========+\n\
| 1.Information | 2.Modify | 3.Top Up | 4.Back |\n\
+===============+==========+==========+========+\n", \
"\
+============+===========+===========+========+\n\
| 1.Password | 2.Contact | 3.Address | 4.Back |\n\
+============+===========+===========+========+\n", \
"\
+========+=========+===============+========+\n\
| 1.Name | 2.Price | 3.Description | 4.Back |\n\
+========+=========+===============+========+\n"};

static const char* menuNames[MENU_NUM] = {"Main", "Admin", "User", "Buyer", "Seller", "Information", "Modify", "Good"};

/**
 * @brief 打印提示信息
 *
 * @param type 菜单类型
 */
static void promptMessage(Menu type) {
    printf("\t\t\t%s%s Menu%s\n", REVERSE, menuNames[type], RESET);
    printf("%s\nPlease choose operation: ", menuPrompts[type]);
}

int menu(Menu type) {
    promptMessage(type);
    char buffer[MAX_LEN];
    int res;
    cin >> buffer;
    res = atoi(buffer);
    while(1) {
        if(res >= 1 && res <= optionNum[type]) break;
        invalidMessage();
        cout << "Please choose operation: ";
        cin >> buffer;
        res = atoi(buffer);
    }
    return res;
}