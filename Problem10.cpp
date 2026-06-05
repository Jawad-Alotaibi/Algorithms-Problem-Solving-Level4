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
    
    cout << "Number Of Days From the beginning of the year is " << totalDays << endl;       
    return 0;
}


