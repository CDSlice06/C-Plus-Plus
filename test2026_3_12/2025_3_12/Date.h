#pragma once
#include<iostream>
using namespace std;
#include<assert.h>
class Date

{

public:

	
	//日期检查
	//声明一个不会修改对象任何成员变量的成员函数，既保护了对象，又能被 const 对象调用
	//在函数后面加const,承诺不修改当前对象
	bool CheckDate()const;

	// 获取某年某月的天数

	int GetMonthDay(int year, int month)const
	{
		assert(month > 0 && month < 13);
		static int monthDayArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,12 };
		if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
		{
			return 29;
		}
		return monthDayArray[month];
	}
	//打印年月日
	void Print() const;
	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1);



	// 拷贝构造函数

  // d2(d1)

	Date(const Date& d);



	// 赋值运算符重载

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d);



	// 析构函数

	~Date();



	// 日期+=天数

	Date& operator+=(int day);



	// 日期+天数

	Date operator+(int day)const;



	// 日期-天数

	Date operator-(int day)const;



	// 日期-=天数

	Date& operator-=(int day);



	// 前置++

	Date& operator++();



	// 后置++

	Date operator++(int);



	// 后置--

	Date operator--(int);



	// 前置--

	Date& operator--();



	// >运算符重载

	bool operator>(const Date& d)const;



	// ==运算符重载

	bool operator==(const Date& d)const;



	// >=运算符重载

	bool operator >= (const Date& d)const;



	// <运算符重载

	bool operator < (const Date& d)const;



	// <=运算符重载

	bool operator <= (const Date& d)const;



	// !=运算符重载

	bool operator != (const Date& d)const;



	// 日期-日期 返回天数

	int operator-(const Date& d)const;

private:

	int _year;

	int _month;

	int _day;

};
ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);