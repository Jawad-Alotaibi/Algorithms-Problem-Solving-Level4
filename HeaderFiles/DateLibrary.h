#pragma once

#include <iostream>
#include "MyInputLibrary.h"

using namespace std;

namespace DateLibrary
{

    string formatDate(int year, int month, int day)
    {
        string yearInString = to_string(year);
        string monthInString = to_string(month);
        string dayInString = to_string(day);

        string formatedDate = dayInString + "/" + monthInString + "/" + yearInString;
        return formatedDate;
    }

    short DayOrder(short year, short month, short day)
    {
        short a = (14 - month) / 12;
        short y = year - a;
        short m = month + (12 * a - 2);

        short d = ((day + y) + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
        return d;
    }

    string DayName(short dayOrder)
    {
        // return the day name based on the returend index from dayOrder function
        string dayNames[] = {"Sunday", "Monday", "Tuesday",
                             "Thursday", "Wenesday", "Friday", "Saturday"};

        return dayNames[dayOrder];
    }

    bool isLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int NumberOfDaysInMonth(int year, int month)
    {
        int numberOfDaysInEachMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month < 1 || month > 12)
        {
            return 0;
        }

        return (month == 2) ? (isLeapYear(year) ? 29 : 28) : numberOfDaysInEachMonth[month]; // nested ternary operator
    }

    string MonthName(int month)
    {
        string monthsNames[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        return monthsNames[month];
    }
    void PrintMonthCalender(int month, int year)
    {

        int numberOfDays = NumberOfDaysInMonth(year, month); // number of days in a month
        int dayOrder = DayOrder(year, month, 1);

        // print current month name
        printf("\n _______________%s_______________\n\n", MonthName(month).c_str());
        // print columns
        printf("  Sun  Mon  Tue  Wen  Thu  Fri  Sat\n");
        // printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        // print appropriate spaces if the first day is friday we need spaces until thursday
        int i; // where i'm i inside a week
        for (i = 0; i < dayOrder; i++)
        {
            printf("     ");
        }

        for (int j = 1; j <= numberOfDays; j++)
        {
            printf("%5d", j);

            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }

        printf("\n ________________________________\n");
    }

    void PrintCalender(short year)
    {
        printf("\n ________________________________\n\n");
        printf("\tCalender - %d", year);
        printf("\n\n ________________________________\n");

        for (short i = 1; i <= 12; i++)
        {
            PrintMonthCalender(i, year);
        }
    }
    //My Solution
    // int TotalNumberOfDaysFromSpecificDate(short year, short month, short day)
    // {
    //     short totalDays = 0;
    //     short numberOfDaysInMonth = 0;
    //     for (short i = 1; i <= month; i++)
    //     {
    //         if (i == month)
    //         {
    //             totalDays += day;
    //             break;
    //         }
    //         totalDays += NumberOfDaysInMonth(year, i);
    //     }
        
    //     return totalDays;
    // }

    int TotalNumberOfDaysFromSpecificDate(short year, short month, short day)
    {
        short totalDays = 0;
        for (short i = 1; i < month; i++)
        {
            totalDays += NumberOfDaysInMonth(year, i);
        }

        totalDays += day;

        return totalDays;
    }
}
