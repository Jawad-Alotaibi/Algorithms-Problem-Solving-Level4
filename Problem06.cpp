#include <iostream>
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;


bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int numberOfDaysInMonth(int year, int month)
{
    int numberOfDaysInEachMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (month < 1 || month > 12)
    {
        return 0;
    }

    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDaysInEachMonth[month]; // nested ternary operator
}

int main()
{
    int year = MyInputLibrary::ReadPositiveNumber("Please Enter a year to check? ");
    int month = MyInputLibrary::ReadPositiveNumber("Please Enter a month to check? ");

    int numberofDaysInCertainMonth = numberOfDaysInMonth(year, month);

    cout << "Number Of Days in month [" << month << "] is " << numberofDaysInCertainMonth << endl;



} 