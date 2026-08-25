#include <iostream>
#include "HeaderFiles/MyInputLibrary.h"
#include "HeaderFiles/DateLibrary.h"

using namespace std;

int main()
{

    // call the decreasing functions
    DateLibrary::stDate date = MyInputLibrary::ReadFullDate();

    cout << "\nDate After: \n\n";
    date = DateLibrary::DecreaseDateByOneDay(date);
    cout << "\n01-Subtracting One Day is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreasingDateByXDays(date, 10);
    cout << "02-Subtracting 10 Days is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreasingDateByOneWeek(date);
    cout << "03-Subtracting one week is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreasingDateByXWeeks(date, 10);
    cout << "04-Subtracting 10 Weeks Day is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreaseDateByOneMonth(date);
    cout << "05-Subtracting one month is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreaseDateByXMonth(date, 5);
    cout << "06-Subtracting 5 months is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreaseDateByOneYear(date);
    cout << "07-Subtracting one year is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreaseDateByXYears(date, 10);
    cout << "08-Subtracting 10 years is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreaseDateByXYearsFaster(date, 10);
    cout << "09-Subtracting 10 years (faster) is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreaseDateByOneDecade(date);
    cout << "10-Subtracting one Decades is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreaseDateByXDecades(date, 10);
    cout << "11-Subtracting 10 Decades is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreaseDateByXDecadesFaster(date, 10);
    cout << "12-Subtracting 10 Decades Faster is: " << date.day << "/" << date.month << "/" << date.year << endl;

    date = DateLibrary::DecreaseDateByOneCentury(date);
    cout << "13-Subtracting one Century is: " << date.day << "/" << date.month << "/" << date.year << endl;
    date = DateLibrary::DecreaseDateByOneMillennium(date);
    cout << "14-Subtracting one Millennium is: " << date.day << "/" << date.month << "/" << date.year << endl; //Millennium is 1000 years

    return 0;
}