#include <iostream>
#include "HeaderFiles/DateLibrary.h"
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;

int main() 
{
    DateLibrary::stDate date = MyInputLibrary::ReadFullDate();

    if(DateLibrary::isLastDayInMonth(date))
    {
        cout << "Yes, Day is Last Day In Month.\n";   
    }
    else
        cout << "No, Day is Not Last Day In Month.\n";

    if(DateLibrary::isLastMonthInYear(date.month))
    {
        cout << "Yes, Month is Last Month In Year.\n";
    }
    else
        cout << "No, Month is Not Last Month In Year.\n";

    
    return 0;
}