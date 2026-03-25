#include <climits>
#include <iostream>
#include<assert.h>
using namespace std;
int Getmonthday(int year, int month)
{
    assert(month > 0 && month < 13);
    static int monthDayArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
        return 29;

    return monthDayArray[month];
}
class Date
{
public:
    friend Date& operator+=(Date& s, int day);
    friend void input();
private:
    int year;
    int month;
    int day;
};
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
void input()
{
    int n = 0;
    cin >> n;
    int* p = new int[n];
    Date* q = new Date[n];
    for (int i = 0; i < n; i++)
    {
        cin >> q[i].year >> q[i].month >> q[i].day >> p[i];
        q[i] += p[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (q[i].month < 10)
            cout << q[i].year << '-' << '0' << q[i].month << '-' << q[i].day << endl;
        if (q[i].month >= 10)
            cout << q[i].year << '-' << q[i].month << '-' << q[i].day << endl;
        if (q[i].day < 10)
            cout << q[i].year << '-'<<q[i].month << '-' << '0' << q[i].day << endl;
        if (q[i].month < 10 && q[i].day < 10)
            cout << q[i].year << '-' << '0' << q[i].month << '-' << '0' << q[i].day << endl;
    }
    delete[] p;
    delete[] q;
}
int main()
{

    input();
    return 0;
}