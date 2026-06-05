#include <iostream>
#include "HeaderFiles/MyInputLibrary.h"
#include "HeaderFiles/DateLibrary.h"

using namespace std;


int main()
{
    int year = MyInputLibrary::ReadPositiveNumber("Enter Year? ");
    int month = MyInputLibrary::ReadPositiveNumber("Enter month? "); 

    //print the calender
    DateLibrary::PrintMonthCalender(month, year);
    cout << endl;   


}