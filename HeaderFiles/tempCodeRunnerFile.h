 int CalculateDifferenceInDays(stDate date1, stDate date2, bool includeEndDays = false)
    {
        int days = 0;
        while (CheckDate1LessThanDate2(date1, date2))
        {
           date1 =  IncreaseDateByOneDay(date1);
            days++;
        }
        
        while (!CheckDate1LessThanDate2(date1, date2))
        {
            date1 = DecreaseDateByOneDay(date1);
            days--;
        }
        
        return includeEndDays ? days : ++days;
    }
