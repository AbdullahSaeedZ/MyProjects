#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencies.h"
using namespace std;

class clsUpdateCurrencyRate : protected clsScreen
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

	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("Update Currency Screen");


		string CurrencyName = clsInputValidate::ReadString("\nEnter Currency Country:"); // ask to enter country, cuz some have similar code and name

		clsCurrencies C1;

		while (!clsCurrencies::IsCurrencyExist(C1, CurrencyName))
		{
			cout << "\nCurrency Not Found!" << endl;
			CurrencyName = clsInputValidate::ReadString("\nEnter Currency Country:");
		}

		_PrintCurrency(C1);

		if (clsInputValidate::ReadBoolean("\nAre You Sure You Want To Update This Currency Rate?"))
		{
			cout << "\nUpdate Currency Rate:" << endl;
			cout << "__________________________" << endl;
			float NewRate = clsInputValidate::ReadNumber<float>("\nEnter New Rate:");


			C1.UpdateRate(NewRate);
			cout << "\nRate Updated Successfully!" << endl;
			_PrintCurrency(C1);
		}
		else
		{
			cout << "\nOperation Was Canceled!" << endl;
		}
	}

};

