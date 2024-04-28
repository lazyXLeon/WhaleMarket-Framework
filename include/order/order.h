#pragma once

#include "config.h"

typedef struct {
    char id[MAX_LEN];
    char good_id[MAX_LEN];
    double price;
    char date[MAX_LEN];
    char seller_id[MAX_LEN];
    char buyer_id[MAX_LEN];
} Order;

/**
 * @brief 从外部文件导入订单信息
 *
 */
void pullOrders();

/**
 * @brief 向外部文件导出订单信息
 *
 */
void pushOrders();

/**
 * @brief 添加订单信息
 *
 * @param order 需要添加的订单
 * @return int 如果成功返回1,如果失败返回0
 */
int addOrder(Order* order);

/**
 * @brief 打印所有的订单信息
 *
 */
void printOrders();

/**
 * @brief 打印商家的订单信息
 *
 * @param id 需要打印的商家的id
 */
void printOrdersById4Seller(char* id);

/**
 * @brief 打印买家的订单信息
 *
 * @param id 需要打印的买家的id
 */
void printOrdersById4Buyer(char* id);
