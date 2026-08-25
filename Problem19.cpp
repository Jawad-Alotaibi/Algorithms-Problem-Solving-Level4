#include <iostream>
#include "HeaderFiles/DateLibrary.h"
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;

int main()
{
    DateLibrary::stDate date1 = MyInputLibrary::ReadFullDate();
    cout << endl;
    DateLibrary::stDate date2 = MyInputLibrary::ReadFullDate();

     cout << "\nDifference is: " << DateLibrary::CalculateDifferenceInDays(date1, date2) << " Day(s).\n";
    cout << "Difference (Includeing End Day) is: " << DateLibrary::CalculateDifferenceInDays(date1, date2, true) << " Day(s).\n";
    

    return 0;
}