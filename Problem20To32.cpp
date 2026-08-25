#include <iostream>
#include "HeaderFiles/MyInputLibrary.h"
#include "HeaderFiles/DateLibrary.h"

using namespace std;

int main()
{
    DateLibrary::stDate date = MyInputLibrary::ReadFullDate();

    cout << "\nDate After: \n\n";
    date = DateLibrary::IncreaseDateByOneDay(date);
    cout << "\n01-Adding One Day is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByXDays(date, 10);
    cout << "02-Adding 10 Day is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByOneWeek(date);
    cout << "03-Adding one week is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByXWeeks(date, 10);
    cout << "04-Adding 10 Week Day is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByOneMonth(date);
    cout << "05-Adding one month is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByXMonths(date, 5);
    cout << "06-Adding 5 months is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByOneYear(date);
    cout << "07-Adding one year is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByXYears(date, 10);
    cout << "08-Adding 10 years is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByXYearsFaster(date, 10);
    cout << "09-Adding 10 years (faster) is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByOneDecade(date);
    cout << "10-Adding one Decades is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByXDecades(date, 10);
    cout << "11-Adding 10 Decades is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByXDecadesFaster(date, 10);
    cout << "12-Adding 10 Decades Faster is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::IncreaseDateByOneCentury(date);
    cout << "13-Adding one Century is: " << date.day << "/" << date.month << "/" << date.year << endl;
    date = DateLibrary::IncreaseDateByOneMillennium(date);
    cout << "14-Adding one Millennium is: " << date.day << "/" << date.month << "/" << date.year << endl; //Millennium is 1000 years

    return 0;
}