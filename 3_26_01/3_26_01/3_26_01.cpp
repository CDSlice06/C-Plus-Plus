#include <iostream>
#include<assert.h>
#include<iomanip>
using namespace std;
//static int monthDayArray[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
//int Getmonthday(int month)
//{
//    assert(month > 0 && month < 13);
//    return monthDayArray[month];
//}
//int rmonth(int day)
//{
//    int n = 1;
//    for (int i = 1; i <= 12; i++)
//    {
//        if (day >= Getmonthday(i))
//        {
//            n++;
//            day -= Getmonthday(i);
//        }
//    }
//    return n;
//    if (n == 12)
//        return 1;
//
//
//}
//int rday(int day)
//{
//    int n = 0;
//    for (int i = 1; i <= 12; i++)
//    {
//        if (day >= Getmonthday(i))
//        {
//            n++;
//            day -= Getmonthday(i);
//
//        }
//        return day;
//    }
//    return day;
//}
//void print(int year, int day)
//{
//    int month;
//    if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
//    {
//        monthDayArray[2] = 29;
//        month = rmonth(day);
//        day = rday(day);
//    }
//    else
//    {
//        monthDayArray[2] = 28;
//        month = rmonth(day);
//        day = rday(day);
//    }
//    cout << year << '-' << setfill('0') << setw(2) << month << '-' << setfill('0') << setw(2) << day;
//    //printf("%04d-%02d-%02d\n",year,month,day);
//}
//
//void test()
//{
//    int y, n;
//    while (cin >> y >> n)
//        print(y, n);
//}
//int main()
//{
//    test();
//}
int main()//·½·¨¶ş

{

    int year;

    int day;



    int mon[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31 };

    while (cin >> year >> day)

    {

        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))

            mon[1] = 29;

        else

            mon[1] = 28;



        for (int i = 0; i < 12; i++)

        {

            if (day <= mon[i])

            {

                printf("%04d-%02d-%02d\n", year, i + 1, day);

                break;

            }

            else

            {

                day = day - mon[i];

            }

        }

    }

    return 0;

}