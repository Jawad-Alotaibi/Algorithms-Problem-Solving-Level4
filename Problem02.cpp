#include <iostream>
#include <string>
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;

// the leap years is that the years the second month will be 29 day, the most years the second month have 28 day, that's why the leap year have 366 day
// to check if the year is not leap year you need to satisfy two conditions, accept the division by 4 and dont accept the division by 100
// to check it's leap year you need to divide by 400 if accept it that's leap year
bool checkLeapYear(int year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 4 == 0)
    {
        if (year % 100 != 0)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    int year = MyInputLibrary::readNumber("Enter the year you wanna check if it's leap or not");
    if (checkLeapYear(year))
    {
        cout << "Yes, " << year << " is leap year." << endl;
    }
    else
        cout << "No, " << year << " is Not leap year." << endl;

    return 0;
}