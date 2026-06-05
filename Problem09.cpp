#include <iostream>
#include "HeaderFiles/MyInputLibrary.h"
#include "HeaderFiles/DateLibrary.h"

using namespace std;


int main()
{
    DateLibrary::PrintCalender(MyInputLibrary::ReadPositiveNumber("Enter Year? "));
    cout << endl;   
    return 0;
}