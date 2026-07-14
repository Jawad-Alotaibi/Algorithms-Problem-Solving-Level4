#include <iostream>
#include "HeaderFiles/DateLibrary.h"
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;

int main()
{
    DateLibrary::stDate date1 = MyInputLibrary::ReadFullDate();
    cout << endl
         << endl;
    DateLibrary::stDate date2 = MyInputLibrary::ReadFullDate();



    while (!DateLibrary::CheckDate1LessThanDate2(date1, date2))
    {
        cout << "Date 1 is not less than date2, Enter valid date" << endl;
         date1 = MyInputLibrary::ReadFullDate();
        cout << endl;
         date2 = MyInputLibrary::ReadFullDate();
    }
    cout << "Difference is: " << DateLibrary::CalculateDifferenceInDays(date1, date2) << " Day(s).\n";
    cout << "Difference (Includeing End Day) is: " << DateLibrary::CalculateDifferenceInDays(date1, date2, true) << " Day(s).\n";
    


    return 0;
}