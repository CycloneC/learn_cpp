/*
 * @Author: wukui
 * @Date: 2022-08-10 19:47:55
 * @LastEditTime: 2022-08-11 14:16:33
 * @LastEditors: wukui
 * @Description: 模版相关定义
 * @FilePath: /learn_cpp/src/0301_template.h
 */

#ifndef _0301_TEMPLATE_H_
#define _0301_TEMPLATE_H_

#include<iostream>

using namespace std;

/********01 函数模版*********/

// 交换整型函数
void SwapInt(int& a, int& b);

// 交换浮点型函数
void SwapDouble(double& a, double& b);

// 利用模板提供通用的交换函数
template<typename T>
void MySwap(T &a, T &b) {
  T temp = a;
	a = b;
	b = temp;
}

// 无参模板函数
template<typename T>
void func() {
  cout << "测试" << endl;
}

int AddInt(int a, int b);

template<typename T>
T MyAdd(T a, T b) {
  return a + b;
}

void MyPrint(int a, int b);

template<typename T>
void MyPrint(T a, T b) {
  cout << "调用模版函数" << endl;
}

template<typename T>
void MyPrint(T a, T b, T c) {
  cout << "调用重载函数" << endl;
}

template<class T>
bool MyCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Person {
public:
	Person(string name, int age) {
		this->name_ = name;
		this->age_ = age;
	}
	string name_;
	int age_;
};

//具体化模版，显示具体化的原型和定意， 以template<>开头，并通过名称来指出类型
template<> bool MyCompare(Person &p1, Person &p2) {
	if (p1.name_ == p2.name_ && p1.age_ == p2.age_) {
		return true;
	} else {
		return false;
	}
}

#endif //_0301_TEMPLATE_H_