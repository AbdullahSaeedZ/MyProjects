#pragma once
#include "clsDate.h"

class clsPeriod
{
    clsDate _StartDate;
    clsDate _EndDate;

public:

    clsPeriod(clsDate StartDate, clsDate EndDate)
    {
        this->_StartDate = StartDate;
        this->_EndDate = EndDate;

    }

    void setStartDate(short Day, short Month, short Year)
    {
        this->_StartDate.Day = Day;
        this->_StartDate.Month = Month;
        this->_StartDate.Year = Year;
    }

    void getStartDate()
    {
        this->_StartDate.Print();
    }


    void setEndDate(short Day, short Month, short Year)
    {
        this->_EndDate.Day = Day;
        this->_EndDate.Month = Month;
        this->_EndDate.Year = Year;
    }

    void getEndDate()
    {
        this->_EndDate.Print();
    }




    static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
    {

        if (
            clsDate::CompareTwoDates(Period2._EndDate, Period1._StartDate) == clsDate::enDateComparison::Before
            ||
            clsDate::CompareTwoDates(Period2._StartDate, Period1._EndDate) == clsDate::enDateComparison::After
            )
            return false;
        else
            return true;

    }

    bool IsOverLapWith(clsPeriod Period2)
    {
        return IsOverlapPeriods(*this, Period2);
    }


    static short GetOverlapDays(clsPeriod Period1, clsPeriod Period2)
    {
        if (!IsOverlapPeriods(Period1, Period2))
            return 0;
        // take the farest start date of the two periods
        clsDate Start = (clsDate::CompareTwoDates(Period1._StartDate, Period2._StartDate) == clsDate::enDateComparison::Before) ? Period2._StartDate : Period1._StartDate;

        // take the closest end date of the two periods
        clsDate End = (clsDate::CompareTwoDates(Period1._EndDate, Period2._EndDate) == clsDate::enDateComparison::Before) ? Period1._EndDate : Period2._EndDate;

        return LengthInDays({ Start, End });
    }

    short GetOverlapDaysWith(clsPeriod Period2)
    {
        return GetOverlapDays(*this, Period2);
    }


    static bool IsDateWithinPeriod(clsPeriod Period, clsDate Date)
    {
        return  !(clsDate::CompareTwoDates(Date, Period._StartDate) == clsDate::enDateComparison::Before || clsDate::CompareTwoDates(Date, Period._EndDate) == clsDate::enDateComparison::After);
    }

    bool IsDateWithinPeriod(clsDate Date)
    {
        return IsDateWithinPeriod(*this, Date);
    }


    static short LengthInDays(clsPeriod Period, bool IncludeEndDate = true)
    {
        return clsDate::DaysDiffOfTwoDates(Period._StartDate, Period._EndDate, IncludeEndDate);
    }

    short LengthInDays()
    {
        return LengthInDays(*this);
    }


    void Print()
    {
        cout << "Start of Period: ";
        _StartDate.Print();


        cout << "\nEnd of Period: ";
        _EndDate.Print();


    }

};

