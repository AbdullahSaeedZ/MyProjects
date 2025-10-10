#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{

public:


	static void ShowWithdrawScreen()
	{
		clsScreen::_DrawScreenHeader("Withdraw Screen");

		string AcctNumber = clsInputValidate::ReadString("\nEnter Account Number:");
		clsBankClient Client;

		while (!clsBankClient::IsClientExist(Client, AcctNumber))
		{
			cout << "\nAccount Number [" << AcctNumber << "] Doesnt Exist, ";
			AcctNumber = clsInputValidate::ReadString("Enter Account Number:");
		}

		clsScreen::_PrintClientInfo(Client);

		float Amount = clsInputValidate::ReadNumber<float>("\nEnter Amount to Withdraw: ");

		if (clsInputValidate::ReadBoolean("\nAre You Sure You Want To Perform The Transaction? Y/N:"))
		{

			clsBankClient::enSaveResults SaveResults = Client.Withdraw(Amount);

			switch (SaveResults)
			{
			case clsBankClient::enSaveResults::eSuccedded:

				Client.Save();
				cout << "\nTransaction Done Successfully!" << endl;
				cout << "\nNew Balance: " << Client.AcctBalance << " SAR" << endl;
				break;

			case clsBankClient::enSaveResults::eFailedInsufficientAmount:

				cout << "\nFailed Operation! Insuffecient Amount" << endl;
				cout << "Amount To Withdraw:  " << Amount << endl;
				cout << "Your Balance: " << Client.AcctBalance << endl;
				break;
			}
		}
		else
		{
			cout << "\nOperation was cancelled!" << endl;
		}
	}



};

