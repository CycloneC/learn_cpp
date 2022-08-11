/*
 * @Author: wukui
 * @Date: 2022-08-10 19:54:23
 * @LastEditTime: 2022-08-11 14:10:08
 * @LastEditors: wukui
 * @Description: 模版相关单元测试
 * @FilePath: /learn_cpp/src/0301_template_unittest.cc
 */
#include <gtest/gtest.h>
#include "0301_template.h"

// 函数模版的简单测试
TEST(TemplateFuncTest, SimpleTest01) {
  int a = 1, b = 2;
  double c = 1.2, d = 2.3;

  // 普通函数调用
  SwapInt(a, b);
  EXPECT_EQ(a, 2);
  EXPECT_EQ(b, 1);
  SwapDouble(c, d);
  EXPECT_EQ(c, 2.3);
  EXPECT_EQ(d, 1.2);

  // 模版函数调用 1.自动类型推导
  MySwap(a, b);
  EXPECT_EQ(a, 1);
  EXPECT_EQ(b, 2);
  MySwap(c, d);
  EXPECT_EQ(c, 1.2);
  EXPECT_EQ(d, 2.3);

  // 模版函数调用 2.显示指定类型
  MySwap<int>(a, b);
  EXPECT_EQ(a, 2);
  EXPECT_EQ(b, 1);

  // 错误1：自动类型推导，必须推导出一致的数据类型T,才可以使用
  // MySwap(a, c);

  // 错误2：模板必须要确定出T的数据类型，才可以使用
  // func(); 
  func<int>();
}

// 普通函数与函数模板区别
TEST(TemplateFuncTest, SimpleTest02) {
  int a = 1;
  double c = 1.2;

  // 1. 普通函数调用时可以发生自动类型转换
  EXPECT_EQ(AddInt(a, c), 2);

  // 2. 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换 以下代码错误
  // MyAdd(a, c);

  // 3. 如果利用显示指定类型的方式，可以发生隐式类型转换
  EXPECT_EQ(MyAdd<int>(a, c), 2); 
}

// 普通函数与函数模板区别
TEST(TemplateFuncTest, SimpleTest03) {
  int a = 1, b = 2, c = 3;
  char d = '1', e = '2';

  // 1. 如果函数模板和普通函数都可以实现，优先调用普通函数
  MyPrint(a, b);

  // 2. 可以通过空模板参数列表来强制调用函数模板
  MyPrint<int>(a, b);

  // 3. 函数模板也可以发生重载
  MyPrint(a, b, c);

  // 4. 如果函数模板可以产生更好的匹配,优先调用函数模板
  MyPrint(d, e);
}

// 普通函数与函数模板区别
TEST(TemplateFuncTest, SimpleTest04) {
  // 1. 内置数据类型可以直接使用通用的函数模板
  int a = 1, b = 2;
  EXPECT_FALSE(MyCompare(a, b));

  // 2. 自定义数据类型，不会调用普通的函数模板，调用具体化的模版
  Person p1("Tom", 10);
	Person p2("Tom", 10);
  EXPECT_TRUE(MyCompare(p1, p2));
}