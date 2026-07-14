#include <iostream>
#include "HeaderFiles/DateLibrary.h"
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;

int main() 
{
    DateLibrary::stDate date1 = MyInputLibrary::ReadFullDate();
    cout << "\n\n";
    DateLibrary::stDate date2 = MyInputLibrary::ReadFullDate();

    if(DateLibrary::isDatesEqualEachOther(date1, date2))
    {
        cout << "Yes, Date1 is Equal To Date2.\n";
    }
    else
        cout << "No Date1 is Not Equal Date2\n";


    
}