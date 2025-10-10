#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrencies.h"
using namespace std;


class clsCurrenciesListScreen : protected clsScreen
{
private:

    static void PrintCurrencyRecordLine(clsCurrencies Currency)
    {

        cout << setw(8) << left << "" << "\t| " << setw(30) << left << Currency.getCountry();
        cout << "| " << setw(8) << left << Currency.getCurrencyCode();
        cout << "| " << setw(45) << left << Currency.getCurrencyName();
        cout << "| " << setw(10) << left << Currency.getCurrencyRate();

    }

public:

	static void ShowCurrenciesListScreen()
	{
        vector <clsCurrencies> vCurrencies = clsCurrencies::GetCurrenciesList();
        string Title = "Currencies List Screen";
        string SubTitle = "(" + to_string(vCurrencies.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "\t| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrencies& Currency : vCurrencies)
            {

                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;




	}



};

