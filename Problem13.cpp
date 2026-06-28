#include <iostream>
#include "HeaderFiles/MyInputLibrary.h"
#include "HeaderFiles/DateLibrary.h"


using namespace std;

int main()
{
    DateLibrary::stDate Date1 = MyInputLibrary::ReadFullDate();
    cout << "\n\n";
    DateLibrary::stDate Date2 = MyInputLibrary::ReadFullDate();
    
    if (DateLibrary::CheckDate1LessThanDate2(Date1, Date2))
    {
        cout << "Yes, Date 1 is less than date 2\n";
    }
    else 
        cout << "No, Date 1 is not less than Date 2\n";


    return 0;
}