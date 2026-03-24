#include <iostream>
using namespace std;

int Getmonthday(int year, int month, int day)
{
    int _day = 0;
    int* p = new int[13] {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        p[2] = 29;
        for (int i = 1; i < month; i++)
        {
            _day += p[i];
        }
        _day += day;
        return _day;
    }
    else
    {
        p[2] = 28;
        for (int i = 1; i < month; i++)
        {
            _day += p[i];
        }
        _day += day;
        return _day;
    }
}

int main()
{
    int year, month, day;
    cin >> year >> month >> day;
    cout << Getmonthday(year, month, day) << endl;
}