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

int numberOfDays(int year)
{
    return isLeapYear(year) ? 366 : 365;
}

int numberOfHours(int year)
{
    return numberOfDays(year) * 24;
}

int numberOfMinutes(int year)
{
    return numberOfHours(year) * 60;
}

int numberOfSeconds(int year)
{
    return numberOfMinutes(year) * 60;
}
int main()
{
    int year = MyInputLibrary::readNumber("Enter the year: ");

    int days = numberOfDays(year);
    int hours = numberOfHours(year);
    int minutes = numberOfMinutes(year);
    int seconds = numberOfSeconds(year);

    cout << "Number Of Days\t in year [" << year << "] is " << days << endl;
    cout << "Number Of Hours\t in year [" << year << "] is " << hours << endl;
    cout << "Number Of Minutes in year [" << year << "] is " << minutes << endl;
    cout << "Number Of Seconds in year [" << year << "] is " << seconds << endl;

    return 0;
}