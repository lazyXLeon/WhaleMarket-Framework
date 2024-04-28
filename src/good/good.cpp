#include "good/good.h"
#include "tools/info.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

static const char* filePath = "src/data/good.txt";
static const char* stateName[] = {"SELLING", "SOLD", "BANNED"};

static const char* header = "|     ID     |     NAME     |     PRICE     |     SELLER     |     STATE     |     DATE     |     DESCRIPTION     |";
static const char* divide = "+------------+--------------+---------------+----------------+---------------+--------------+---------------------+";

static Good goods[MAX_GOOD];
static int goods_count = 0;

void pullGoods() {
    goods_count = 0;

    FILE* fp = fopen(filePath, "r");
    if (fp) {
        while(fscanf(fp, "%s%s%1%s%u%s%s", goods[goods_count].id, goods[goods_count].name, &goods[goods_count].price, goods[goods_count].seller_id, &goods[goods_count].state, goods[goods_count].date, goods[goods_count].description) != EOF){
            goods_count++;
        }

        fclose(fp);
    }
}

void pushGoods() {
    ofstream ofs(filePath);
    if (ofs.is_open()) {
        for (int i = 0; i < goods_count; i++) {
            ofs << goods[i].id << " " << goods[i].name << " " << goods[i].price << " " << goods[i].seller_id << " " << goods[i].state << " " << goods[i].date << " " << goods[i].description << endl;
        }

        ofs.close();
    }
}

Good* getGood(int index) {
    return &goods[index];
}

int addGood(Good* good) {
    if(goods_count >= MAX_GOOD) return 0;
    genID(good->id, 'G');
    getDate(good->date);
    good->state = SELLING;
    goods[goods_count++] = *good;
    return 1;
}

int searchGoodById(const char* id) {
    for (int i = 0; i < goods_count; i++) {
        if (strcmp(goods[i].id, id) == 0) return i;
    }
    return -1;
}

int deleteGood(const char* id, const char* who){
    int index = searchGoodById(id);
    if(index == -1 || (who && strcmp(goods[index].seller_id, who))) return 0;
    goods[index].state = BANNED;
    return 1;
}

void goodInfo(int index) {
    cout << "ID:           | " << goods[index].id << endl
         << "Name:         | " << goods[index].name << endl
         << "Description:  | " << goods[index].description << endl
         << "Date:         | " << goods[index].date << endl
         << "Price:        | " <<  fixed << setprecision(1) << goods[index].price << endl
         << "Seller:       | " << goods[index].seller_id << endl
         << "State:        | " << stateName[goods[index].state] << endl;
}

void printGoods() {
    print_header
    print_divide
    for(int i = 0; i < goods_count; i++) {
        cout << "|"
             << setw(12) << goods[i].id << "|"
             << setw(14) << goods[i].name << "|"
             << setw(15) << goods[i].price << "|"
             << setw(16) << goods[i].seller_id << "|"
             << setw(15) << stateName[goods[i].state] << "|"
             << setw(14) << goods[i].date << "|"
             << setw(21) << goods[i].description << "|"
             << endl;
        print_divide
    }
}

void searchGoodByName4Buyer(const char* name) {
    print_header
    print_divide
    for(int i = 0; i < goods_count; i++) {
        if(goods[i].state == SELLING && strstr(goods[i].name, name) != NULL) {
            cout << "|"
             << setw(12) << goods[i].id << "|"
             << setw(14) << goods[i].name << "|"
             << setw(15) << goods[i].price << "|"
             << setw(16) << goods[i].seller_id << "|"
             << setw(15) << stateName[goods[i].state] << "|"
             << setw(14) << goods[i].date << "|"
             << setw(21) << goods[i].description << "|"
             << endl;

            print_divide
        }
    }
}

void searchGoodByName4Admin(const char* name) {
    print_header
    print_divide
    
    for(int i = 0; i < goods_count; i++) {
        if(strstr(goods[i].name, name) != NULL) {
            cout << "|"
             << setw(12) << goods[i].id << "|"
             << setw(14) << goods[i].name << "|"
             << setw(15) << goods[i].price << "|"
             << setw(16) << goods[i].seller_id << "|"
             << setw(15) << stateName[goods[i].state] << "|"
             << setw(14) << goods[i].date << "|"
             << setw(21) << goods[i].description << "|"
             << endl;
            
            print_divide
        }
    }
}

void printGoods4Seller(const char* id) {
    print_header
    print_divide
    for(int i = 0; i < goods_count; i++) {
        if(strcmp(goods[i].seller_id, id) == 0) {
            cout << "|"
             << setw(12) << goods[i].id << "|"
             << setw(14) << goods[i].name << "|"
             << setw(15) << goods[i].price << "|"
             << setw(16) << goods[i].seller_id << "|"
             << setw(15) << stateName[goods[i].state] << "|"
             << setw(14) << goods[i].date << "|"
             << setw(21) << goods[i].description << "|"
             << endl;

            print_divide
        }
    }
}

void printGoods4Buyer(const char* id) {
    print_header
    print_divide
    for(int i = 0; i < goods_count; i++) {
        if(goods[i].state == SELLING) {
            cout << "|"
             << setw(12) << goods[i].id << "|"
             << setw(14) << goods[i].name << "|"
             << setw(15) << goods[i].price << "|"
             << setw(16) << goods[i].seller_id << "|"
             << setw(15) << stateName[goods[i].state] << "|"
             << setw(14) << goods[i].date << "|"
             << setw(21) << goods[i].description << "|"
             << endl;

            print_divide
        }
    }
}