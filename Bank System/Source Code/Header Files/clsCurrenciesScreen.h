#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;


class clsCurrenciesScreen : protected clsScreen
{

private:

	enum enExchangeOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCalculator = 4, eExit = 5 };


	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrenciesScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyRate::ShowUpdateRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}




	static  void _GoBackToCurrenciesMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currencies Menu...\n";

		system("pause>0");
		ShowCurrenciesMenu();
	}

	static short _ReadCurrenciesOption()
	{
		short Choice = 0;
		Choice = clsInputValidate::ReadNumInRange<short>(1, 5, "\t\t\t\t\tChoose what you want to do [1 to 5]: ");

		return Choice;
	}

	static void _PerformCurrenciesOption(short Option)
	{													

		switch (Option)
		{
		case enExchangeOptions::eListCurrencies:

			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrenciesMenu();
			break;

		case enExchangeOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrenciesScreen();
			_GoBackToCurrenciesMenu();
			break;

		case enExchangeOptions::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrenciesMenu();
			break;

		case enExchangeOptions::eCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenu();
			break;

		case enExchangeOptions::eExit:
			
			break;

		}


	}



public:

	static void ShowCurrenciesMenu()
	{
		system("cls");
		_DrawScreenHeader("Currency Exchange Screen");

		cout << "\t\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t          Currency Exchange Menu\n";
		cout << "\t\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t     [1] List Currencies.\n";
		cout << "\t\t\t\t\t     [2] Find Currency.\n";
		cout << "\t\t\t\t\t     [3] Update Rate.\n";
		cout << "\t\t\t\t\t     [4] Currency Calculator.\n";
		cout << "\t\t\t\t\t     [5] Main Menu.\n";
		cout << "\t\t\t\t\t===========================================\n";

		_PerformCurrenciesOption(_ReadCurrenciesOption());
	}

};

