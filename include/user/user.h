#pragma once

#include "config.h"

#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// 用户结构体的定义
typedef struct {
    char id[MAX_LEN]; // 用户ID
    char name[MAX_LEN]; // 用户名
    char password[MAX_LEN]; // 用户密码
    char contact[MAX_LEN]; // 用户联系方式
    char address[MAX_LEN]; // 用户地址
    double balance; // 用户余额
} User;

/**
 * @brief 从外部文件导入用户信息
 *
 */
void pullUsers();

/**
 * @brief 向外部文件导出用户信息
 *
 */
void pushUsers();

/**
 * @brief 获取用户对象
 *
 * @param index 用户在数组中的索引
 * @return User* 用户对象
 */
User* getUser(int index);

/**
 * @brief 打印用户的信息
 *
 * @param index 用户在数组中的索引
 */
void userInfo(int index);

/**
 * @brief 添加新用户
 *
 * @param user 待添加的用户对象
 * @return int 添加成功返回1，否则返回0
 */
int addUser(User& user);

/**
 * @brief 删除给定ID的用户
 *
 * @param id 用户ID
 * @param who 删除操作的发起者，管理员为null
 * @return int 删除成功返回1，否则返回0
 */
int deleteUser(const char* id,const char* who);

/**
 * @brief 打印所有用户的信息
 *
 */
void printUsers();

/**
 * @brief 检查用户名和密码是否匹配
 *
 * @param name 用户名
 * @param password 密码
 * @param index 如果成功，通过指针返回用户在数组中的索引
 * @return int 匹配成功返回1，否则返回0
 */
int checkPwd(const char* name, const char* password, int* index);

/**
 * @brief 用户充值
 *
 * @param id 带充值的用户ID
 * @param amount 充值金额
 * @return int 充值成功返回1，否则返回0
 */
int userTopUp(const char* id, double amount);
