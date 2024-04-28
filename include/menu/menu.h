#pragma once

typedef enum {MAIN, ADMIN, USER, BUYER, SELLER, LOGIN, LOGOUT, EXIT} Menu;

extern const int optionNum[];

/**
 * @brief 为用户提供目录界面
 *
 * @param type 目录类型
 * @return int 用户输入
 */
int menu(Menu type);