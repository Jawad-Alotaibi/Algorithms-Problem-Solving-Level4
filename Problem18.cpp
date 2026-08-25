#include <iostream>
#include "HeaderFiles/DateLibrary.h"
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;

int main()
{
    DateLibrary::stDate date1 = MyInputLibrary::ReadFullDate();
    
    DateLibrary::stDate date2 = DateLibrary::GetSystemDate();

    //To calculate my age in days o need to get my birthday date from the user and the current date then get the diffrence using the function i built
    cout << "your age  is: " << DateLibrary::CalculateDifferenceInDays(date1, date2, true) << " Day(s).\n";
    


    return 0;
}