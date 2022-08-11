/*
 * @Author: wukui
 * @Date: 2022-08-10 19:47:21
 * @LastEditTime: 2022-08-11 13:48:00
 * @LastEditors: wukui
 * @Description: 模版相关
 * @FilePath: /learn_cpp/src/0301_template.cc
 */
#include "0301_template.h"

/********01 函数模版*********/

// 交换整型函数
void SwapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// 交换浮点型函数
void SwapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

// 利用模板提供通用的交换函数（该函数定义在头文件中）
// template<typename T>
// void MySwap(T &a, T &b)
// {
//   a = a ^ b;
//   b = a ^ b;
//   a = a ^ b;
// }
// 通过下面的声明，也可以定义在c文件中
// template void MySwap(int &a, int &b);

int AddInt(int a, int b)
{
  return a + b;
}

void MyPrint(int a, int b)
{
  cout << "调用普通函数" << endl;
}
