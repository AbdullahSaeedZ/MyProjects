#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencies.h"
using namespace std;


class clsCurrencyCalculatorScreen : protected clsScreen
{
private: 

	static  void _PrintCurrencyCard(clsCurrencies Currency, string Title = "Currency Card:")
	{

		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.getCountry();
		cout << "\nCode          : " << Currency.getCurrencyCode();
		cout << "\nName          : " << Currency.getCurrencyName();
		cout << "\nRate(1$) =    : " << Currency.getCurrencyRate();
		cout << "\n_____________________________\n\n";

	}

	static void _PrintCalculationsResults(float Amount, clsCurrencies Currency1, clsCurrencies Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.getCurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.getCurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.getCurrencyCode()
			<< " = " << AmountInCurrency2 << " " << Currency2.getCurrencyCode();

	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		do
		{
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");


			string Currency1 = clsInputValidate::ReadString("\nEnter Currency To Convert From:");
			clsCurrencies C1;
			while (!clsCurrencies::IsCurrencyExist(C1, Currency1))
			{
				cout << "\nCurrency Not Found!" << endl;
				Currency1 = clsInputValidate::ReadString("\nEnter Currency To Convert From:");
			}

			string Currency2 = clsInputValidate::ReadString("\nEnter Currency To Convert To:");
			clsCurrencies C2;
			while (!clsCurrencies::IsCurrencyExist(C2, Currency2))
			{
				cout << "\nCurrency Not Found!" << endl;
				Currency2 = clsInputValidate::ReadString("\nEnter Currency To Convert To:");
			}

			//

			float Amount = clsInputValidate::ReadNumber<float>("\nEnter Amount to Convert:");
			_PrintCalculationsResults(Amount, C1, C2);

		} while (clsInputValidate::ReadBoolean("\n\nDo You Want To Continue Using The Calculator?"));

	}
};

