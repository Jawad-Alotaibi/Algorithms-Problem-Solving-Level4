#include <iostream>
#include "HeaderFiles/DateLibrary.h"
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;

int main() 
{
    DateLibrary::stDate date = MyInputLibrary::ReadFullDate();
    date = DateLibrary::IncreaseDateByOneDay(date);

    cout << "Date after adding one day is: " 
        << date.day << "/" << date.month << "/" << date.year << endl;
    
    return 0;
}