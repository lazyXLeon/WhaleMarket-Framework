#pragma once

#include "config.h"

typedef enum {SELLING, SOLD, BANNED} GoodState;

typedef struct {
    char id[MAX_LEN];
    char name[MAX_LEN];
    double price;
    char seller_id[MAX_LEN];
    GoodState state;
    char date[MAX_LEN];
    char description[MAX_LEN];
} Good;

/**
 * @brief 从外部文件导入商品信息
 *
 */
void pullGoods();

/**
 * @brief 将商品信息导出到外部文件
 *
 */
void pushGoods();

/**
 * @brief 获取商品对象
 *
 * @param index 商品在数组中的索引
 * @return Good* 商品对象
 */
Good* getGood(int index);

/**
 * @brief 添加新的商品
 *
 * @param good 待添加的商品
 * @return int 如果成功返回1，如果失败返回0
 */
int addGood(Good* good);

/**
 * @brief 根据商品的ID搜索商品
 *
 * @param id 商品的ID
 * @return int 搜索成功返回商品对应的索引，搜索失败返回-1
 */
int searchGoodById(const char* id);

/**
 * @brief 删除给定ID的商品
 *
 * @param ID 给定商品的ID
 * @param who 删除的操作人的id，管理员的id为null
 * @return int 如果删除成功返回1,如果删除失败返回0
 */
int deleteGood(const char* ID, const char* who);

/**
 * @brief 打印商品的详细信息
 *
 * @param index 需要打印的商品的索引
 */
void goodInfo(int index);

/**
 * @brief 打印所有商品的详细信息
 * 
 */
void printGoods();

/**
 * @brief 为买家提供商品搜索功能-只搜索正在出售的商品
 *
 * @param name 商品名
 */
void searchGoodByName4Buyer(const char* name);

/**
 * @brief 为管理员提供商品搜索功能-搜索所有商品
 *
 * @param name 商品名
 */
void searchGoodByName4Admin(const char* name);

/**
 * @brief 打印给定ID的卖家的商品
 *
 * @param id 卖家的ID
 */
void printGoods4Seller(const char* id);

/**
 * @brief 打印出售中的商品
 *
 * @param id 需要打印商品的买家的ID
 */
void printGoods4Buyer(const char* id);