#include "order/order.h"
#include "tools/info.h"
#include "config.h"

#include <stdio.h>
#include <string>
#include <iostream>

static Order orders[MAX_ORDER];
static int order_count = 0;

static const char* filePath = "src/data/order.txt";
static const char* header = "|     ID     |     Good     |     Price     |     Date     |     Seller     |     Buyer     |";
static const char* divide = "+------------+--------------+---------------+--------------+----------------+---------------+";

void pullOrders() {
    order_count = 0;
    FILE* file = fopen(filePath, "r");
    if (file) {
        while (fscanf(file, "%s%s%1f%s%s%s", orders[order_count].id, orders[order_count].good_id, &orders[order_count].price, orders[order_count].date, orders[order_count].seller_id, orders[order_count].buyer_id) != EOF) {
            order_count++;
        }
        fclose(file);
    }
}

void pushOrders() {
    FILE* file = fopen(filePath, "w");
    if (file) {
        for(int i = 0; i < order_count; i++){
            fprintf(file, "%s%s%1f%s%s%s\n", orders[i].id, orders[i].good_id, orders[i].price, orders[i].date, orders[i].seller_id, orders[i].buyer_id);
        }
        fclose(file);
    }
}

int addOrder(Order* order) {
    if(order_count >= MAX_ORDER) return 0;
    genID(order->id, 'O');
    getDate(order->date);
    orders[order_count++] = *order;
    pushOrders();
    return 1;
}

static void printOrder(int index){
    printf("|%-10s|%-10s|%-10.1f|%-10s|%-10s|%-10s|\n", orders[index].id, orders[index].good_id, orders[index].price, orders[index].date, orders[index].seller_id, orders[index].buyer_id);
}

void printOrders() {
    print_header
    print_divide
    for(int i = 0; i < order_count; i++){
        printOrder(i);
        print_divide
    }
}

void printOrdersById4Seller(const char* id) {
    print_header
    print_divide
    for(int i = 0; i < order_count; i++){
        if(strcmp(orders[i].seller_id, id) == 0){
            printOrder(i);
            print_divide
        }
    }
}

void printOrdersById4Buyer(const char* id) {
    print_header
    print_divide
    for(int i = 0; i < order_count; i++){
        if(strcmp(orders[i].buyer_id, id) == 0){
            printOrder(i);
            print_divide
        }
    }
}