#include"Date.h"
bool Date::CheckDate()const
{

}

//打印年月日
void Date::Print() const
{
	cout << _year << "年" << _month << "月" << _day << "天";
}

// 全缺省的构造函数

Date::Date(int year = 1900, int month = 1, int day = 1)
{
	_year = year;
	_month = month;
	_day = day;
}





// 拷贝构造函数

// d2(d1)

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

}



// 赋值运算符重载

// d2 = d3 -> d2.operator=(&d2, d3)

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}



// 析构函数

Date::~Date()
{
}



// 日期+=天数

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
		_day += day;
		while(_day > GetMonthDay(_year,_month))
		{
			_day-= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month == 1;
				_year++;
			}
		}
	return *this;
}



// 日期+天数

Date Date::operator+(int day)const
{

}



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