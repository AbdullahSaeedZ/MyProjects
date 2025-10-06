#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"
using namespace std;



class clsInputValidate
{
public:

    // Reading Inputs

	static bool ReadBoolean(const string& Message = "")
	{
		string line;
		char Answer = ' ';

		do
		{
			cout << Message << endl;

			if (cin.peek() == '\n')
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			getline(cin, line);

			if (!line.empty())
				Answer = line[0];

		} while (Answer != 'Y' && Answer != 'y' && Answer != 'N' && Answer != 'n');

		return (tolower(Answer) == 'y');
	}

    static string ReadString(const string& Message = "")
    {
        string str;

        cout << Message << endl;
        getline(cin >> ws, str);

        return str;
    }

    static char ReadChar(const string& Message = "")
    {
        string line;

        cout << Message << endl;
        getline(cin >> ws, line);
        // getline is better than cin in terms of handling with buffer

        return line.empty() ? ' ' : line[0];
    }


    static unsigned int ReadPositiveInt(const string& Message = "")
    {
        unsigned int Number = 0;

        while (true)
        {
            cout << Message << endl;
            cin >> Number;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a positive number." << endl;
                continue;
            }

            // delete any leftovers in buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (Number > 0)
                return Number;
            else
                cout << "Number must be positive. Try again." << endl;
        }
    }

	template <typename T>
	static T ReadNumber(const string& Message = "")
	{
		T Number;

		cout << Message << endl;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Number, Enter again\n";
		}
		return Number;
	}

	template <typename T>
	static T ReadNumInRange(T From, T To, const string& Message = "")
	{
		T Number = ReadNumber<int>(Message);

		while (!IsNumberBetween<int>(Number, From, To))
		{
			cout << "Number is not within range, Enter again:\n";
			Number = ReadNumber<int>(Message);
		}
		return Number;
	}

	static bool IsDateBetween(const clsDate& date, clsDate date1, clsDate date2) {
		if (clsDate::IsDate1AfterDate2(date1, date2))
			clsDate::SwapDates(date1, date2);

		return !(clsDate::IsDate1AfterDate2(date, date2) || clsDate::IsDate1BeforeDate2(date, date1));
	}

	template <typename T>
	static bool IsNumberBetween(const T& Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsValidDate(const clsDate &Date)
	{
		return	clsDate::IsValidDate(Date);
	}

};

