#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsDepositScreen : protected clsScreen
{



public:

	static void ShowDepositScreen()
	{
		clsScreen::_DrawScreenHeader("Deposit Screen");

		string AcctNumber = clsInputValidate::ReadString("\nEnter Account Number:");
		clsBankClient Client;

		while (!clsBankClient::IsClientExist(Client, AcctNumber))
		{
			cout << "\nAccount Number [" << AcctNumber << "] Doesnt Exist, ";
			AcctNumber = clsInputValidate::ReadString("Enter Account Number:");
		}

		clsScreen::_PrintClientInfo(Client);

		float Amount = clsInputValidate::ReadNumber<float>("\nEnter Amount to Deposit: ");

		if (clsInputValidate::ReadBoolean("\nAre You Sure You Want To Perform The Transaction? Y/N:"))
		{

			clsBankClient::enSaveResults SaveResults = Client.Deposit(Amount);

			switch (SaveResults)
			{
			case clsBankClient::enSaveResults::eSuccedded:
				
				Client.Save();
				cout << "\nTransaction Done Successfully!" << endl;
				cout << "\nNew Balance: " << Client.AcctBalance << " SAR" << endl;
				break;
			}

		}
		else
		{
			cout << "Operation was cancelled!" << endl;
		}

	}

};

