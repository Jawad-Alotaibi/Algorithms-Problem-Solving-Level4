#include <iostream>
#include <string>
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;

// the leap years is that the years the second month will be 29 day, the most years the second month have 28 day, that's why the leap year have 366 day
// to check if the year is not leap year you need to satisfy two conditions, accept the division by 4 and dont accept the division by 100
// to check it's leap year you need to divide by 400 if accept it that's leap year
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// int numberOfDays(int year)
// {
//     return isLeapYear(year) ? 366 : 365;
// }

int numberOfDaysInMonth(int month, int year)
{
// الفكرة الي بسويها اني اسوي اراي فيها ١٢ عنصر وكل عنصر يمثل عدد ايام الاشهر ويصير ارجع اليوم بناء على الشهر
   // return (month < 1 || month > 12 ? 0 : ) || (month == 2 ? isLeapYear(year) : 29);


    if (month < 1 || month > 12)
    {
        return 0;
    }

    if (month == 2)
    {
        return isLeapYear(year) ? 29 : 28;
    }

    int arrOfMonthsOf31Days[] = {1, 3, 5, 7, 8, 10, 12};

    for (short i = 1; i <= 7; i++)
    {
        if (arrOfMonthsOf31Days[i - 1] == month)
        {
            return 31;
        }
    }

    return 30;
}
int numberOfHoursInMonth(int year, int month)
{
    return numberOfDaysInMonth(month, year) * 24;
}

int numberOfMinutesInMonth(int year, int month)
{
    return numberOfHoursInMonth(year, month) * 60;
}

int numberOfSecondsInMonth(int year, int month)
{
    return numberOfMinutesInMonth(year, month) * 60;
}

int main()
{
    int year = MyInputLibrary::readNumber("Enter the year: ");
    int month = MyInputLibrary::readNumber("Enter the month: ");

    

    int daysInMonth = numberOfDaysInMonth(month, year);
    int hours = numberOfHoursInMonth(year, month);
    int minutes = numberOfMinutesInMonth(year, month);
    int seconds = numberOfSecondsInMonth(year, month);

    cout << "Number Of Days\t in month [" << month << "] is " << daysInMonth << endl;
    cout << "Number Of Hours\t in month [" << month << "] is " << hours << endl;
    cout << "Number Of Minutes in month [" << month << "] is " << minutes << endl;
    cout << "Number Of Seconds in month [" << month << "] is " << seconds << endl;

    return 0;
}