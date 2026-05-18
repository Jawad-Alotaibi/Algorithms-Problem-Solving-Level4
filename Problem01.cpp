#include <iostream>
#include <string>
#include "HeaderFiles/MyInputLibrary.h"

using namespace std;

string numberToText(int number)
{
    if (number == 0)
    {
        return "";
    }

    if(number >= 1 && number <= 19)
    {
        string arr[] = {"", "one", "two", "three", "four", "five", "six" , "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", 
            "sixteen", "seventeen", "eighteen", "ninteen"};

        return arr[number] + " ";
    }

    if (number >= 20 && number <= 99)
    {
        string arr[] = {"", "", "twenty", "thirty", "fourty", "fifty","sixty",
            "seventy", "eighty", "ninty"};

            return arr[number / 10]  + " " + numberToText(number % 10);
    }

    if (number >= 100 && number <= 199)
    {
        return " one Hundred " + numberToText(number % 100);
    }
    if (number >= 200 && number <= 999)
    {
        return numberToText(number / 100) + "Hundreds " + numberToText(number % 100);
    }

    if (number >= 1000 && number <= 1999)
    {
        return "one Thousand " + numberToText(number % 1000);
    }

    if (number >= 2000 && number <= 999999)
    {
        return numberToText(number / 1000) + "Thousands " + numberToText(number % 1000);
    }

    if (number >= 1000000 && number <= 1999999)
    {
        return " one Million " + numberToText(number % 1000000);
    }

    if (number >= 2000000 && number <= 999999999)
    {
        return numberToText(number / 1000000) + " Millions " + numberToText(number % 1000000);
    }

    if (number >= 1000000000 && number <= 1999999999)
    {
        return "one Billion " + numberToText(number % 1000000000);
    }
 
    else
    {
    return  numberToText(number / 1000000000) + "Billions " +
    numberToText(number % 1000000000);
    }
}
int main()
{
    int number = MyInputLibrary::readNumber("Please Enter the number");
    //int number = 1000;
    cout << numberToText(number) << endl;


    
    return 0;
}