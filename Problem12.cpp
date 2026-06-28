#include <iostream>
#include "HeaderFiles/MyInputLibrary.h"
#include "HeaderFiles/DateLibrary.h"

using namespace std;

int main()
{
    DateLibrary::stDate Date =  MyInputLibrary::ReadFullDate();
    short dayWannaAdd = MyInputLibrary::ReadPositiveNumber("How Many Days to add? ");

    Date = DateLibrary::GetDateAfterAddingDays(dayWannaAdd, Date);
    cout << "Date for [" << dayWannaAdd << "] is: ";
    cout << Date.day << "/" << Date.month << "/" << Date.year << endl;
    
    return 0;
}