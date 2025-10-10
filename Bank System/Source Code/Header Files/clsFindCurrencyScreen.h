#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencies.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrencies& Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.getCountry();
		cout << "\nCode       : " << Currency.getCurrencyCode();
		cout << "\nName       : " << Currency.getCurrencyName();
		cout << "\nRate(1$) = : " << Currency.getCurrencyRate();

		cout << "\n_____________________________\n";

	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");


		string CurrencyName = clsInputValidate::ReadString("\nEnter Currency Code or Name or Country:");

		clsCurrencies C1;

		while (!clsCurrencies::IsCurrencyExist(C1, CurrencyName))
		{
			cout << "\nCurrency Not Found!" << endl;
			CurrencyName = clsInputValidate::ReadString("\nEnter Currency Code or Name or Country:");
		}

		_PrintCurrency(C1);

	}

};

