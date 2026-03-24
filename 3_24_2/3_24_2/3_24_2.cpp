#include <iostream>
#include<assert.h>
using namespace std;
class Date
{
public:
    friend bool CheckDate(const Date& s);
    friend istream& operator>>(istream& in, Date& d);
    friend Date& operator+=(Date& s, int day);
    friend Date& operator++(Date& s);
    friend bool operator!=(const Date& s1, const Date& s2);
    friend bool operator>(const Date& s1, const Date& s2);
    friend  int operator-(const Date& s1, const Date& s2);
private:
    int day;
    int month;
    int year;
};
int Getmonthday(int year, int month)
{
    assert(month > 0 && month < 13);
    static int monthDayArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
        return 29;

    return monthDayArray[month];
}
bool CheckDate(const Date& s)
{
    if (s.month < 1 || s.month>12 || s.day<1 || s.day > Getmonthday(s.year, s.month))
    {
        return false;
    }
    else
    {
        return true;
    }
}
istream& operator>>(istream& in, Date& d)
{
    in >> d.year >> d.month >> d.day;
    if (!CheckDate(d))
    {
        exit(1);
    }
    return in;
}
Date& operator+=(Date& s, int day)
{
    s.day += day;
    while (s.day > Getmonthday(s.year, s.month))
    {
        s.day -= Getmonthday(s.year, s.month);
        ++s.month;
        if (s.month == 13)
        {
            s.month = 1;
            s.year++;
        }
    }
    return s;
}
Date& operator++(Date& s)
{
    s += 1;
    return s;
}
bool operator!=(const Date& s1, const Date& s2)
{
    return s1.year != s2.year || s1.month != s2.month || s1.day != s2.day;
}
bool operator>(const Date& s1, const Date& s2)
{
    if (s1.year > s2.year)
    {
        return true;
    }
    else if (s1.year == s2.year)
    {
        if (s1.month > s2.month)
        {
            return true;
        }
        else if (s1.month == s2.month)
        {
            if (s1.day > s2.day)
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}
int operator-(const Date& s1, const Date& s2)
{
    Date max = s1;
    Date min = s2;
    if (s2 > s1)
    {
        max = s2;
        min = s1;
    }
    int n = 0;
    while (max != min)
    {
        ++min;
        n++;
    }
    return n;
}
int main()
{
    Date s1, s2;
    cin >> s1 >> s2;
    cout << (s1 - s2) << endl;

}