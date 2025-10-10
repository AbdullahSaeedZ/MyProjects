#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"



class clsCurrencies
{

private:

	enum enMode { eEmptyMode = 0, eUpdateMode = 1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static clsCurrencies _getEmptyCurrencyObject()
	{
		return clsCurrencies(enMode::eEmptyMode, "", "", "", 0);
	}

	static clsCurrencies _ConvertLineToObject(string Line, string Separator = "#//#")
	{
		vector<string> vStr = clsString::SplitStringToVector(Line, Separator);

		return clsCurrencies(enMode::eUpdateMode, vStr[0], vStr[1], vStr[2], stof(vStr[3]));
	}

	static string _ConvertObjectToLine(clsCurrencies Object, string Separator = "#//#")
	{
		string Line = "";

		Line += Object.getCountry() + Separator;
		Line += Object.getCurrencyCode() + Separator;
		Line += Object.getCurrencyName() + Separator;
		Line += to_string(Object.getCurrencyRate());

		return Line;
	}

	static void _SaveVectorToFile(const vector<clsCurrencies>& vCurrencies)
	{
		fstream File;
		File.open("Currencies.txt", ios::out);

		if (File.is_open())
		{
			string Line;

			for (const clsCurrencies& c : vCurrencies)
			{
					Line = _ConvertObjectToLine(c);
					File << Line << endl;
			}

			File.close();
		}
	}

	static vector<clsCurrencies> _LoadFileToVector()
	{
		vector<clsCurrencies> vCurrencies;

		fstream File;
		File.open("Currencies.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsCurrencies OneCurrency = _ConvertLineToObject(Line);
				vCurrencies.push_back(OneCurrency);
			}

			File.close();
		}

		return vCurrencies;
	}

	void _Update()
	{
		vector<clsCurrencies> vCurrencies = _LoadFileToVector();

		for (clsCurrencies& c : vCurrencies)
		{
			if (c.getCountry() == getCountry())
			{
				c = *this;
				break;
			}
		}

		_SaveVectorToFile(vCurrencies);
	}

public:

	clsCurrencies()
	{
		_Mode = enMode::eEmptyMode;
		_Country = "";
		_CurrencyCode = "";
		_CurrencyName = "";
		_Rate = 0;
	}

	clsCurrencies(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	// read only properties, cuz we dont add, delete or update the data members, except the rate.

	string getCountry()
	{
		return _Country;
	}

	string getCurrencyCode()
	{
		return _CurrencyCode;
	}

	string getCurrencyName()
	{
		return _CurrencyName;
	}

	float getCurrencyRate()
	{
		return _Rate;
	}

	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}


	bool IsEmpty() // to check is the object on empty mode
	{
		return (_Mode == enMode::eEmptyMode);
	}


	static clsCurrencies Find(string CurrencyCodeNameCountry) // static, to be used with no objects, to look for client then fill an empty one, if not found fill with empty object on empty mode.
	{
		CurrencyCodeNameCountry = clsString::UppercaseAllString(CurrencyCodeNameCountry);

		fstream File;

		File.open("Currencies.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsCurrencies Currency = _ConvertLineToObject(Line);

				if (Currency._CurrencyCode == CurrencyCodeNameCountry || clsString::UppercaseAllString(Currency._CurrencyName) == CurrencyCodeNameCountry || clsString::UppercaseAllString(Currency._Country) == CurrencyCodeNameCountry)
				{
					File.close();
					return Currency;
				}
			}

		}
		File.close();
		return _getEmptyCurrencyObject();
	}

	
	static bool IsCurrencyExist(string CurrencyCodeNameCountry)
	{
		clsCurrencies Currency = clsCurrencies::Find(CurrencyCodeNameCountry);
		return (!Currency.IsEmpty());
	}

	static bool IsCurrencyExist(clsCurrencies& Currency, string CurrencyCodeNameCountry)
	{
		Currency = clsCurrencies::Find(CurrencyCodeNameCountry);
		return (!Currency.IsEmpty());
	}

	static vector<clsCurrencies> GetCurrenciesList()
	{
		return _LoadFileToVector();
	}

	//

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / getCurrencyRate());
	}

	float ConvertToOtherCurrency(float Amount, clsCurrencies Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.getCurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.getCurrencyRate());

	}

};

