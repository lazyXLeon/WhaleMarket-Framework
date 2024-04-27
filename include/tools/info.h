#pragma once

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
#include <iomanip>

using namespace std;

/**
 * @brief 获取当前日期
 *
 * @param dest 储存日期的字符串
 */
 void getDate(string& dest);

/**
 * @brief 生成一个对应类型的ID
 *
 * @param dest 储存ID的目标字符串
 * @param type ID类型，U-用户，G-Good，O-订单
 */
 void genID(string& dest, char type);