
short DayOrder(short year, short month, short day)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a - 2);

    short d = ((day + y) + (y/4) - (y/100) + (y/400) + ((31 * m) / 12)) % 7 ;
    return d;
}

string DayName(short dayOrder)
{
    // return the day name based on the returend index from dayOrder function 
    string dayNames[] = {"Sunday", "Monday" , "Tuesday",
                        "Thursday", "Wenesday" , "Friday" , "Saturday"};

    return dayNames[dayOrder];
}
int main()
{
    int year = MyInputLibrary::ReadPositiveNumber("Please Enter a Year? ");
    int month = MyInputLibrary::ReadPositiveNumber("Please Enter a Month? ");
    int day = MyInputLibrary::ReadPositiveNumber("Please Enter a Day? ");

    string date = formatDate(year, month, day);
    short dayOrder = DayOrder(year, month, day);
    string dayName = DayName(DayOrder(year, month, day));

    cout << "Date\t: " << date << endl;
    cout << "Day Order\t: " << dayOrder << endl;
    cout << "Day Name\t: " << dayName << endl;
} 