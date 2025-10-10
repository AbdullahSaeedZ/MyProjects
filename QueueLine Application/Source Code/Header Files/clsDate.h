#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsDate
{
private:

	short _Day;
	short _Month;
	short _Year;

	static string ReplaceExactWord(string str, string OldWord, string NewWord)
	{
		short pos = 0;
		while ((pos = str.find(OldWord)) != string::npos)
		{

			str = str.replace(pos, OldWord.length(), NewWord);

		}

		return str;
	}
	short ReadPositiveNumber(string Message)
	{
		int Number = 0;
		do
		{
			cout << Message << endl;
			cin >> Number;

			if (cin.fail())
			{
				// if other than numbers entered system will fail.
				cin.clear();                // to clear the failure
				cin.ignore(10000, '\n');    // to ignore what was entered before, to clean the buffer
				cout << "Invalid input! Please enter a number." << endl;
				continue;
			}

		} while (Number <= 0);

		return Number;
	}


public:

	clsDate()
	{
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);

		this->_Day = now.tm_mday;
		this->_Month = now.tm_mon + 1;
		this->_Year = now.tm_year + 1900;
	}

	clsDate(string strDate, string delim = "/")
	{
		vector<string> vWords;

		short pos = 0;
		string sWord;

		while ((pos = strDate.find(delim)) != string::npos)
		{
			sWord = strDate.substr(0, pos);

			if (sWord != "")
				vWords.push_back(sWord);

			strDate.erase(0, pos + delim.length());
		}

		if (strDate != "")
			vWords.push_back(strDate);


		this->_Day = stoi(vWords.at(0));
		this->_Month = stoi(vWords.at(1));
		this->_Year = stoi(vWords.at(2));

	}

	clsDate(short Day, short Month, short Year)
	{
		this->_Day = Day;
		this->_Month = Month;
		this->_Year = Year;
	}

	clsDate(short DaysNum, short Year)
	{
		
		short monthDays = 0;
		short RemainingDays = DaysNum;

		this->_Month = 1;
		this->_Year = Year;

		while (true)
		{
			monthDays = NumOfMonthDays(Year, this->_Month);

			if (RemainingDays > monthDays)
			{
				RemainingDays -= monthDays;
				this->_Month++;
			}

			if (RemainingDays < monthDays)
			{
				this->_Day = RemainingDays;
				break;
			}
		}

	}


	void setDay(short Day)
	{
		this->_Day = Day;
	}

	short getDay()
	{
		return this->_Day;
	}

	__declspec(property(get = getDay, put = setDay)) short Day;

	void setMonth(short Month)
	{
		this->_Month = Month;
	}

	short getMonth()
	{
		return this->_Month;
	}

	__declspec(property(get = getMonth, put = setMonth)) short Month;

	void setYear(short Year)
	{
		this->_Year = Year;
	}

	short getYear()
	{
		return this->_Year;
	}
	
	__declspec(property(get = getYear, put = setYear)) short Year;


	static string GetSystemDateTimeString()
	{
		short Year, Month, Day, Hour, Minutes, Seconds;
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);

		Day = now.tm_mday;
		Month = now.tm_mon + 1;
		Year = now.tm_year + 1900;
		Hour = now.tm_hour;
		Minutes = now.tm_min;
		Seconds = now.tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Minutes) + ":" + to_string(Seconds));
	}


	static clsDate GetSystemDate()
	{
		clsDate Date;
		time_t t = time(0);
		tm now;
		localtime_s(&now, &t);

		Date._Day = now.tm_mday;
		Date._Month = now.tm_mon + 1;
		Date._Year = now.tm_year + 1900;

		return Date;
	}


	static string  Print(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}

	void Print()
	{
		cout << Print(*this) << endl;
	}


	static bool IsLeapYear(short num)
	{
		return ((num % 4 == 0) && (num % 100 != 0)) || ((num % 400 == 0));
	}

	bool IsLeapYear()
	{
		return IsLeapYear(this->_Year);
	}



	static short NumOfYearDays(short num)
	{
		return (IsLeapYear(num)) ? 366 : 365;
	}

	short NumOfYearDays()
	{
		return NumOfYearDays(this->_Year);
	}



	static short NumOfYearHours(short num)
	{
		return NumOfYearDays(num) * 24;
	}

	short NumOfYearHours()
	{
		return NumOfYearHours(this->_Year);
	}


	static short NumOfYearMinutes(short num)
	{
		return NumOfYearHours(num) * 60;
	}

	short NumOfYearMinutes()
	{
		return NumOfYearMinutes(this->_Year);
	}


	static short NumOfYearSeconds(short num)
	{
		return NumOfYearMinutes(num) * 60;
	}

	short NumOfYearSeconds()
	{
		return NumOfYearSeconds(this->_Year);
	}
	
	
	static short NumOfMonthDays(short year, short mon)
	{
		return (mon < 1 || mon > 12) ? 0 : (mon == 2) ? ((IsLeapYear(year)) ? 29 : 28) : (mon == 2 || mon == 4 || mon == 6 || mon == 9 || mon == 11) ? 30 : 31;
	}

	short NumOfMonthDays()
	{
		return NumOfMonthDays(this->_Year, this->_Month);
	}
	
	
	static short GetWeekDayOrder(short year, short month, short day)
	{
		int a = ((14 - month) / 12);
		int y = year - a;
		int m = (month + (12 * a)) - 2;

		// Gregorian formula:
		// result starts from 0 = sunday ..etc.
		int dayIndex = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return dayIndex;
	}

	short GetWeekDayOrder()
	{
		return GetWeekDayOrder(this->_Year, this->_Month, this->_Day);
	}
	
	
	static string WeekDayName(short DayOrder)
	{
		string DayName;

		switch (DayOrder)
		{
		case 0: DayName = "Sunday"; break;
		case 1: DayName = "Monday"; break;
		case 2: DayName = "Tuesday"; break;
		case 3: DayName = "Wednesday"; break;
		case 4: DayName = "Thursday"; break;
		case 5: DayName = "Friday"; break;
		case 6: DayName = "Saturday"; break;
		default: "None"; break;
		}

		return DayName;
	}
	
	string WeekDayName()
	{
		short DayOrder = GetWeekDayOrder();
		return WeekDayName(DayOrder);
	}
	
	
	static string MonthName(short monthNum)
	{
		string MonthName;

		switch (monthNum)
		{
		case 1: MonthName = "JAN"; break;
		case 2: MonthName = "FEB"; break;
		case 3: MonthName = "MAR"; break;
		case 4: MonthName = "APR"; break;
		case 5: MonthName = "MAY"; break;
		case 6: MonthName = "JUN"; break;
		case 7: MonthName = "JUL"; break;
		case 8: MonthName = "AUG"; break;
		case 9: MonthName = "SEP"; break;
		case 10: MonthName = "OCT"; break;
		case 11: MonthName = "NOV"; break;
		case 12: MonthName = "DEC"; break;
		default: "None"; break;
		}

		return MonthName;
	}

	string MonthName()
	{
		return MonthName(this->_Month);
	}
	
	
	static void PrintMonthCalendar(short year, short month)
	{
		string Mon = MonthName(month);
		short Day1 = GetWeekDayOrder(year, month, 1);
		short NumOfDays = NumOfMonthDays(year, month);

		printf("\n  _______________%s_______________\n\n", Mon.c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		short i;
		for (i = 0; i < Day1; i++)
			printf("     ");

		for (short num = 1; num <= NumOfDays; num++)
		{
			printf("%5d", num);
			i++;

			if (i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
	}
	
	void  PrintMonthCalendar()
	{
		PrintMonthCalendar(this->_Year, this->_Month);
	}


	static void PrintYearCalendar(short year)
	{
		printf("\n  -----------------------------");
		printf("\n           Calendar - %d", year);
		printf("\n  -----------------------------\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(year, i);
			printf("\n  ---------------------------------\n");
		}
	}

	void PrintYearCalendar()
	{
		PrintYearCalendar(this->_Year);
	}

	
	static short DaysNumFromYearBeginning(short year, short month, short day)
	{
		short DaysCount = 0;

		for (short i = 1; i < month; i++)
		{
			DaysCount += NumOfMonthDays(year, i);
		}

		DaysCount += day;

		return DaysCount;
	}

	short DaysNumFromYearBeginning()
	{
		return DaysNumFromYearBeginning(this->_Year, this->_Month, this->_Day);
	}

	
	static string DateOfDayNumberInYear(short Year, short DaysNum)
	{
		clsDate Date;

		short monthDays = 0;
		short RemainingDays = DaysNum;

		Date._Month = 1;
		Date._Year = Year;

		while (true)
		{
			monthDays = NumOfMonthDays(Year, Date._Month);

			if (RemainingDays > monthDays)
			{
				RemainingDays -= monthDays;
				Date._Month++;
			}

			if (RemainingDays < monthDays)
			{
				Date._Day = RemainingDays;
				break;
			}
		}

		string strDate = DateToString(Date);
		return strDate;
	}


	static clsDate StringToDate(string str, string delim = "/")
	{
		vector<string> vWords;

		short pos = 0;
		string sWord;

		while ((pos = str.find(delim)) != string::npos)
		{
			sWord = str.substr(0, pos);

			if (sWord != "")
				vWords.push_back(sWord);

			str.erase(0, pos + delim.length());
		}

		if (str != "")
			vWords.push_back(str);

		clsDate D1;
		D1._Day = stoi(vWords.at(0));
		D1._Month = stoi(vWords.at(1));
		D1._Year = stoi(vWords.at(2));


		return D1;
	}



	static string DateToString(clsDate Date, string delim = "/")
	{
		string str = "";

		str = to_string(Date._Day) + delim + to_string(Date._Month) + delim + to_string(Date._Year);


		return str;
	}
	
	string DateToString()
	{
		return DateToString(*this);
	}


	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return  (Date1._Year < Date2._Year) ? true : ((Date1._Year == Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month == Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}

	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	
	static bool IsDate1EqualToDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}

	bool IsDateEqualToDate2(clsDate Date2)
	{
		return IsDate1EqualToDate2(*this, Date2);
	}


	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return  (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualToDate2(Date1, Date2));
	}

	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}


	enum enDateComparison { Before = -1, Equal = 0, After = 1 };

	static enDateComparison CompareTwoDates(clsDate Date1, clsDate Date2)
	{
		return (IsDate1AfterDate2(Date1, Date2)) ? enDateComparison::After : (IsDate1BeforeDate2(Date1, Date2) ? enDateComparison::Before : enDateComparison::Equal);
	}

	enDateComparison CompareToDate2(clsDate Date2)
	{
		return CompareTwoDates(*this, Date2);
	}


	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == NumOfMonthDays(Date._Year, Date._Month));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}


	static bool IsLastMonthInYear(short month)
	{
		return (month == 12);
	}

	bool IsLastMonthInYear()
	{
		IsLastMonthInYear(this->_Month);
	}


	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	}

	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	}


	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Year--;
				Date._Month = 12;
				Date._Day = 31;
			}
			else
			{
				Date._Month--;
				Date._Day = NumOfMonthDays(Date._Year, Date._Month);
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}
	

	static void  SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate._Year = Date1._Year;
		TempDate._Month = Date1._Month;
		TempDate._Day = Date1._Day;

		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;

		Date2._Year = TempDate._Year;
		Date2._Month = TempDate._Month;
		Date2._Day = TempDate._Day;

	}

	void SwapDates(clsDate &Date2)
	{
		SwapDates(*this, Date2);
	}


	static short CalculateAgeInDays(clsDate DateOfBirth)
	{
		return DaysDiffOfTwoDates(DateOfBirth, clsDate::GetSystemDate(), true);
	}

	short CalculateAgeInDays()
	{
		return CalculateAgeInDays(*this);
	}


	static short DaysDiffOfTwoDates(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates 
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return (IncludeEndDay) ? ++Days * SwapFlagValue : Days * SwapFlagValue;

	}

	short DaysDiffOfTwoDates(clsDate Date2)
	{
		return DaysDiffOfTwoDates(*this, Date2);
	}


	static clsDate IncreaseDateByXDays(clsDate Date, short x)
	{
		for (short i = 1; i <= x; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByXDays(short Num)
	{
		*this = IncreaseDateByXDays(*this, Num);
	}


	static clsDate IncreaseDateBy1Week(clsDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateBy1Week()
	{
		*this = IncreaseDateBy1Week(*this);
	}


	static clsDate IncreaseDateByXWeek(clsDate Date, short x)
	{
		for (short i = 1; i <= x; i++)
		{
			Date = IncreaseDateBy1Week(Date);
		}

		return Date;
	}

	void IncreaseDateByXWeek(short Num)
	{
		*this = IncreaseDateByXWeek(*this, Num);
	}


	static clsDate IncreaseDateBy1Month(clsDate Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			++Date._Month;
		}

		short EndDay = NumOfMonthDays(Date._Year, Date._Month);
		if (Date._Day > EndDay)
			Date._Day = EndDay;


		return Date;
	}

	void IncreaseDateBy1Month()
	{
		*this = IncreaseDateBy1Month(*this);
	}

	
	static clsDate IncreaseDateByXMonth(clsDate Date, short x)
	{
		for (short i = 1; i <= x; i++)
		{
			Date = IncreaseDateBy1Month(Date);
		}

		return Date;
	}

	void IncreaseDateByXMonth(short Num)
	{
		*this = IncreaseDateByXMonth(*this, Num);
	}
	
	
	static clsDate IncreaseDateBy1Year(clsDate Date)
	{
		++Date._Year;

		short EndDay = NumOfMonthDays(Date._Year, Date._Month);

		if (IsLeapYear(Date._Year) && Date._Day > EndDay)
			Date._Day = EndDay;

		return Date;
	}

	void IncreaseDateBy1Year()
	{
		*this = IncreaseDateBy1Year(*this);
	}

	
	static clsDate IncreaseDateByXYear(clsDate Date, short x)
	{
		for (short i = 1; i <= x; i++)
		{
			Date = IncreaseDateBy1Year(Date);
		}
		return Date;
	}

	void IncreaseDateByXYear(short Num)
	{
		*this = IncreaseDateByXYear(*this, Num);
	}
	
	
	static clsDate IncreaseDateBy1Decade(clsDate Date)
	{
		Date._Year += 10;
		return Date;
	}

	void IncreaseDateBy1Decade()
	{
		*this = IncreaseDateBy1Decade(*this);
	}
	
	
	static clsDate IncreaseDateByXDecade(clsDate Date, short x)
	{
		for (short i = 1; i <= x; i++)
		{
			Date = IncreaseDateBy1Decade(Date);
		}
		return Date;
	}

	void IncreaseDateByXDecade(short Num)
	{
		*this = IncreaseDateByXDecade(*this, Num);
	}
	
	
	static clsDate IncreaseDateBy1Century(clsDate Date)
	{
		Date._Year += 100;
		return Date;
	}

	void IncreaseDateBy1Century()
	{
		*this = IncreaseDateBy1Century(*this);
	}
	
	
	static clsDate IncreaseDateBy1Millennium(clsDate Date)
	{
		Date._Year += 1000;
		return Date;
	}

	void IncreaseDateBy1Millennium()
	{
		*this = IncreaseDateBy1Millennium(*this);
	}


	static bool IsEndOfWeek(clsDate Date)
	{
		return (GetWeekDayOrder(Date._Year, Date._Month, Date._Day) == 6);
	}

	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}


	static bool IsBusinessDay(clsDate Date)
	{
		return (GetWeekDayOrder(Date._Year, Date._Month, Date._Day) <= 4);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}


	static bool IsWeekEnd(clsDate Date)
	{
		return (GetWeekDayOrder(Date._Year, Date._Month, Date._Day) >= 5);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}


	static short DaysUntilEndOfWeek(clsDate Date)
	{
		return 6 - (GetWeekDayOrder(Date._Year, Date._Month, Date._Day));
	}

	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(*this);
	}


	static short DaysUntilEndOfMonth(clsDate Date)
	{
		return (NumOfMonthDays(Date._Year, Date._Month)) - Date._Day;
	}

	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	}


	static short DaysUntilEndOfYear(clsDate Date)
	{
		return ((IsLeapYear(Date._Year)) ? 366 : 365) - (DaysNumFromYearBeginning(Date._Year, Date._Month, Date._Day));
	}

	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}


	static short GetVacationDays(clsDate StartDate, clsDate EndDate)
	{
		short Counter = 0;

		while (!IsDate1EqualToDate2(StartDate, EndDate))
		{
			StartDate = IncreaseDateByOneDay(StartDate);

			if (!IsWeekEnd(StartDate))
				++Counter;
		}
		return Counter;
	}

	short GetVacationDays(clsDate EndDate)
	{
		return GetVacationDays(*this, EndDate);
	}


	static clsDate GetVacationReturnDate(clsDate Date1, short VacationDays)
	{
		short WeekEndCounter = 0;

		// if start day is a weekend then we get rid of it, then start the process wih a business day for the vacation
		while (IsWeekEnd(Date1))
		{
			Date1 = IncreaseDateByOneDay(Date1);
		}

		//now we increase the date to  reach the return date, once we face a weekend day, we increase weekend counter to control the loop condition
		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{
			if (IsWeekEnd(Date1))
				WeekEndCounter++;

			Date1 = IncreaseDateByOneDay(Date1);
		}

		// if return dates happens to be in weekend, we increase till we reach a business day
		while (IsWeekEnd(Date1))
		{
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return Date1;
	}

	clsDate GetVacationReturnDate(short VacationDays)
	{
		return GetVacationReturnDate(*this, VacationDays);
	}


	static bool IsValidDate(clsDate Date)
	{
		return  ((Date._Year >= 1) && (Date._Month >= 1 && Date._Month <= 12) && (Date._Day >= 1) && (Date._Day <= NumOfMonthDays(Date._Year, Date._Month)));
	}

	bool IsValidDate()
	{
		return IsValidDate(*this);
	}


	static string PrintDateFormat(clsDate Date, string Format = "dd/mm/yyyy")
	{
		string Formatted = "";
		Formatted = ReplaceExactWord(Format, "dd", to_string(Date._Day));
		Formatted = ReplaceExactWord(Formatted, "mm", to_string(Date._Month));
		Formatted = ReplaceExactWord(Formatted, "yyyy", to_string(Date._Year));

		return Formatted;
	}

	string PrintDateFormat(string Format = "dd/mm/yyyy")
	{
		return PrintDateFormat(*this, Format);
	}

};

