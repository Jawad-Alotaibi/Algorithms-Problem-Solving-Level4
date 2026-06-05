#include <iostream>
#include "HeaderFiles/MyInputLibrary.h"
#include "HeaderFiles/DateLibrary.h"

using namespace std;


int main()
{
   short day =  MyInputLibrary::ReadPositiveNumber("Enter Day? ");
   short month = MyInputLibrary::ReadPositiveNumber("Enter Month? ");
   short year =  MyInputLibrary::ReadPositiveNumber("Enter Year? ");

    short totalDays = DateLibrary::TotalNumberOfDaysFromSpecificDate(year, month, day);
    string date = DateLibrary::formatDate(year, month, day);
    // printf("Memory Address: %p\n", date.c_str());
        cout << "Number Of Days From the beginning of the year is " << totalDays << endl << endl;
    printf("Date for [%d] is %s\n", totalDays, date.c_str()); //because we use printf we need c_str to convert any c++ string to a c style string 'pointer to an array of char'
    return 0;
}


