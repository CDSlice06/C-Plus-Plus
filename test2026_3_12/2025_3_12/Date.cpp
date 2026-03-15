#include"Date.h"
bool Date::CheckDate()const
{
	if (_month > 12 || _month < 1 || _day<1 || _day>GetMonthDay(_year, _month))
	{
		return false;
	}
	else
	{
		return true;
	}
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
	Date tmp = *this;
	tmp += day;
	return tmp;
}



// 日期-天数

Date Date::operator-(int day)const
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}



// 日期-=天数

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day<0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year,_month);
	}
	return *this;
}



// 前置++

Date& Date::operator++()
{
	*this += 1;
	return *this;
}



// 后置++

Date Date::operator++(int)
{
	Date tmp = *this;
	++*this;
	return tmp;
}



// 后置--

Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}



// 前置--

Date& Date::operator--()
{
	(*this)--;
	return *this;
}


// >运算符重载

bool Date::operator>(const Date& d)const
{
	if (_year > d . _year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}



// ==运算符重载

bool Date::operator==(const Date& d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}



// >=运算符重载

bool Date::operator >= (const Date& d)const
{
	return *this > d && *this == d;
}



// <运算符重载

bool Date::operator < (const Date& d)const
{
	return !(*this >= d);
}



// <=运算符重载

bool Date::operator <= (const Date& d)const
{
	return !(*this > d);
}



// !=运算符重载

bool Date::operator != (const Date& d)const
{
	return !(*this == d);
}




// 日期-日期 返回天数

int Date::operator-(const Date& d)const
{
	int flag = 1;
	Date max, min;
	max = *this;
	min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		min++;
		n++;
	}
	return n * flag;
}


ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "请依次输入年月日:>";
		in >> d._year >> d._month >> d._day;

		if (!d.CheckDate())
		{
			cout << "输入日期非法:";
			d.Print();
			cout << "请重新输入!!!" << endl;
		}
		else
		{
			break;
		}
	}

	return in;
}