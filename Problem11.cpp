#include <iostream>
#include "HeaderFiles/MyInputLibrary.h"
#include "HeaderFiles/DateLibrary.h"


using namespace std;


int main()
{
   short day =  MyInputLibrary::ReadPositiveNumber("Enter Day? ");
   short month = MyInputLibrary::ReadPositiveNumber("Enter Month? ");
   short year =  MyInputLibrary::ReadPositiveNumber("Enter Year? ");

    short dayOrderInYear = DateLibrary::NumberOfDaysFromTheBeginingOfTheYear(year, month, day);
    cout << "Number Of Days From the beginning of the year is " << dayOrderInYear << endl << endl;
    
    DateLibrary::stDate Date;
    Date = DateLibrary::GetDateFromDayOrderInYear(dayOrderInYear, year);
    cout << "Date for [" << dayOrderInYear << "] is: ";
    cout << Date.day << "/" << Date.month << "/" << Date.year << endl;
    
    
    return 0;
}


