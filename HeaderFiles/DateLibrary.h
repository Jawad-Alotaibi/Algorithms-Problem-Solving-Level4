#pragma once

#include <iostream>
#include <ctime>

using namespace std;

namespace DateLibrary
{

    struct stDate
    {
        int day;
        int month;
        int year;
    };

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
    // My Solution
    //  int TotalNumberOfDaysFromSpecificDate(short year, short month, short day)
    //  {
    //      short totalDays = 0;
    //      short numberOfDaysInMonth = 0;
    //      for (short i = 1; i <= month; i++)
    //      {
    //          if (i == month)
    //          {
    //              totalDays += day;
    //              break;
    //          }
    //          totalDays += NumberOfDaysInMonth(year, i);
    //      }

    //     return totalDays;
    // }

    int NumberOfDaysFromTheBeginingOfTheYear(short year, short month, short day)
    {
        short totalDays = 0;
        for (short i = 1; i < month; i++)
        {
            totalDays += NumberOfDaysInMonth(year, i);
        }

        totalDays += day;

        return totalDays;
    }

    stDate GetDateFromDayOrderInYear(int DayOrderInYear, int year)
    {
        stDate Date;
        short remainingDays = DayOrderInYear;
        short monthDays = 0;

        Date.year = year;
        Date.month = 1;
        while (true)
        {
            monthDays = NumberOfDaysInMonth(year, Date.month);

            if (remainingDays > monthDays)
            {
                remainingDays -= monthDays;
                Date.month++;
            }
            else
            {
                Date.day = remainingDays;
                break;
            }
        }
        return Date;
    }

    stDate GetDateAfterAddingDays(short daysToAdd, stDate Date)
    {
        // Add Days to certain Date
        short remainingDays = daysToAdd + NumberOfDaysFromTheBeginingOfTheYear(Date.year, Date.month, Date.day);
        short monthDays = 0;

        Date.month = 1;

        while (true)
        {
            monthDays = NumberOfDaysInMonth(Date.year, Date.month);

            if (remainingDays > monthDays)
            {
                remainingDays -= monthDays;
                Date.month++;

                if (Date.month > 12)
                {
                    Date.month = 1;
                    Date.year++;
                }
            }
            else
            {
                Date.day = remainingDays;
                break;
            }
        }
        return Date;
    }

    bool CheckDate1LessThanDate2(stDate date1, stDate date2)
    {
        return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
    }

    bool isDatesEqualEachOther(stDate date1, stDate date2)
    {
        return (date1.year == date2.year) ? (date1.month == date2.month ? date1.day == date2.day : false) : false;
    }

    bool isLastDayInMonth(stDate date)
    {
        return (NumberOfDaysInMonth(date.year, date.month) == date.day);
    }

    bool isLastMonthInYear(short month)
    {
        return (month == 12);
    }

    stDate IncreaseDateByOneDay(stDate date)
    {
        if (isLastDayInMonth(date))
        {
            if (isLastMonthInYear(date.month))
            {
                date.year++;
                date.day = 1;
                date.month = 1;
            }
            else
            {
                date.month++;
                date.day = 1;
            }
        }
        else
            date.day++;

        return date;
    }

    // Those three functions used to solve the problem of handling two dates the first greater than the second dates the difference must be in minus, i solved it using those three functions
    // Then i solved it using abo-hadhoud solutions
    //   bool isFirstDayInMonth(stDate date)
    //  {
    //      return (1 == date.day);
    //  }

    // bool isFirstMonthInYear(short month)
    // {
    //     return (month == 1);
    // }

    // stDate DecreaseDateByOneDay(stDate date)
    // {
    //     if (isFirstDayInMonth(date))
    //     {
    //         if (isFirstMonthInYear(date.month))
    //         {
    //             date.year--;
    //             date.month = 12;
    //             date.day = NumberOfDaysInMonth(date.year, date.month);
    //         }
    //         else
    //         {
    //             date.month--;
    //             date.day = NumberOfDaysInMonth(date.year, date.month);
    //         }
    //     }
    //     else
    //         date.day--;

    //     return date;
    // }

    void SwapDates(stDate &date1, stDate &date2)
    {
        stDate tempDate;

        tempDate.day = date1.day;
        tempDate.month = date1.month;
        tempDate.year = date1.year;

        date1.day = date2.day;
        date1.month = date2.month;
        date1.year = date2.year;

        date2.day = tempDate.day;
        date2.month = tempDate.month;
        date2.year = tempDate.year;
    }
    int CalculateDifferenceInDays(stDate date1, stDate date2, bool includeEndDays = false)
    {
        int days = 0;
        short swapFlag = 1;

        // Handle the case if the first Date after the second date
        if (!CheckDate1LessThanDate2(date1, date2))
        {
            SwapDates(date1, date2);
            swapFlag = -1;
        }

        while (CheckDate1LessThanDate2(date1, date2))
        {
            date1 = IncreaseDateByOneDay(date1);
            days++;
        }

        return includeEndDays ? ++days * swapFlag : days * swapFlag;
    }

    stDate GetSystemDate()
    {
        stDate date;
        time_t t = time(0); // get time now

        tm *now = localtime(&t);

        date.day = now->tm_mday;
        date.month = now->tm_mon + 1;
        date.year = now->tm_year + 1900; // add 1900 because the number of the year start counting after 1900 like 231 years after 1900 to get the correct year we need them add them up

        return date;
    }
    int CalculateAgeInDays(stDate myBirthday)
    {
        stDate currentDate = GetSystemDate();

        return CalculateDifferenceInDays(myBirthday, currentDate);
    }

    stDate IncreaseDateByXDays(stDate date, short days)
    {
        for (short i = 1; i <= days; i++)
        {
            date = IncreaseDateByOneDay(date);
        }

        return date;
    }

    stDate IncreaseDateByOneWeek(stDate date)
    {
        for (short i = 1; i <= 7; i++)
        {
            date = IncreaseDateByOneDay(date);
        }

        return date;
    }

    stDate IncreaseDateByXWeeks(stDate date, short weeks)
    {
        for (short i = 1; i <= weeks; i++)
        {
            date = IncreaseDateByOneWeek(date);
        }

        return date;
    }

    stDate IncreaseDateByOneMonth(stDate date)
    {
        if (date.month == 12) // check if the current month is the last month in the year
        {
            date.year++;
            date.month = 1;
        }
        else
        {
            date.month++;
        }

        // the last case to handle if i am 31/1/2022 should not be 31/2/2022 because the last day in the second month is 28 not 31 !
        int numeberOfDaysInCurrentMonth = NumberOfDaysInMonth(date.year, date.month);
        if (date.day > numeberOfDaysInCurrentMonth)
        {
            date.day = numeberOfDaysInCurrentMonth;
        }

        return date;
    }

    stDate IncreaseDateByXMonths(stDate date, short months)
    {
        for (short i = 1; i <= months; i++)
        {
            date = IncreaseDateByOneMonth(date);
        }

        return date;
    }

    stDate IncreaseDateByOneYear(stDate date)
    {
        date.year++;
        return date;
    }

    stDate IncreaseDateByXYears(stDate date, short years)
    {
        for (short i = 1; i <= years; i++)
        {
            date = IncreaseDateByOneYear(date);
        }

        return date;
    }

    stDate IncreaseDateByXYearsFaster(stDate date, short years)
    {
        date.year += years;
        return date;
    }

    stDate IncreaseDateByOneDecade(stDate date)
    {
        date.year += 10;
        return date;
    }

    stDate IncreaseDateByXDecades(stDate date, short numberOfDecades)
    {
        for (short i = 1; i <= numberOfDecades; i++)
        {
            date = IncreaseDateByOneDecade(date);
        }

        return date;
    }

    stDate IncreaseDateByXDecadesFaster(stDate date, short numberOfDecades)
    {
        date.year = date.year + (numberOfDecades * 10);
        return date;
    }

    stDate IncreaseDateByOneCentury(stDate date)
    {
        date.year += 100;
        return date;
    }

    stDate IncreaseDateByOneMillennium(stDate date)
    {
        date.year += 1000;
        return date;
    }

    bool IsFirstMonthInYear(stDate date)
    {
        return (date.month == 1);
    }

    bool IsFirstDayInMonth(stDate date)
    {
        return (date.day == 1);
    }
    stDate DecreaseDateByOneDay(stDate date)
    {
        if (IsFirstDayInMonth(date))
        {
            if (IsFirstMonthInYear(date))
            {
                date.year--;
                date.month = 12;
                date.day = NumberOfDaysInMonth(date.year, date.month);
            }
            else
            {
                date.month--;
                date.day = NumberOfDaysInMonth(date.year, date.month);
            }
        }
        else
            date.day--;

        return date;
    }

    stDate DecreasingDateByXDays(stDate date, short numberOfDays)
    {
        for (short i = 1; i <= numberOfDays; i++)
        {
            date = DecreaseDateByOneDay(date);
        }
        return date;
    }

    stDate DecreasingDateByOneWeek(stDate date)
    {
        for (short i = 1; i <= 7; i++)
        {
            date = DecreaseDateByOneDay(date);
        }

        return date;
    }

    stDate DecreasingDateByXWeeks(stDate date, short numberOfWeeks)
    {
        for (short i = 1; i <= numberOfWeeks; i++)
        {
            date = DecreasingDateByOneWeek(date);
        }

        return date;
    }

    stDate DecreaseDateByOneMonth(stDate date)
    {
        // i need to handle the case if i decrease one month to make the date corerect with the number of days of the previous month if i am 30/3 and decrease month it check if it is leap year it will be 29/2 if not 28/2
        if (date.month == 1)
        {
            date.year--;
            date.month = 12;
        }
        else
            date.month--;

        // Handle the case of the number of days of the previous month
        int numberOfDaysOfTheCurrentMonth = NumberOfDaysInMonth(date.year, date.month);

        if (date.day > numberOfDaysOfTheCurrentMonth)
        {
            date.day = numberOfDaysOfTheCurrentMonth;
        }

        return date;
    }

    stDate DecreaseDateByXMonth(stDate date, int numberOfMonths)
    {
        for (short i = 1; i <= numberOfMonths; i++)
        {
            date = DecreaseDateByOneMonth(date);
        }

        return date;
    }

    stDate DecreaseDateByOneYear(stDate date)
    {
        date.year--;
        return date;
    }
    stDate DecreaseDateByXYears(stDate date, short numberOfYears)
    {
        for (short i = 1; i <= numberOfYears; i++)
        {
            date = DecreaseDateByOneYear(date);
        }

        return date;
    }
    stDate DecreaseDateByXYearsFaster(stDate date, short numberOfYears)
    {
        date.year -= numberOfYears;
        return date;
    }

    stDate DecreaseDateByOneDecade(stDate date)
    {
        date.year -= 10;
        return date;
    }

    stDate DecreaseDateByXDecades(stDate date, short numberOfDecades)
    {
        for (short i = 0; i < numberOfDecades; i++)
        {
            date = DecreaseDateByOneDecade(date);
        }

        return date;
    }

    stDate DecreaseDateByXDecadesFaster(stDate date, short numberOfDecades)
    {
        date.year = date.year - (numberOfDecades * 10);
        return date;
    }

    stDate DecreaseDateByOneCentury(stDate date)
    {
        date.year -= 100;
        return date;
    }

    stDate DecreaseDateByOneMillennium(stDate date)
    {
        date.year -= 1000;
        return date;
    }}