#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{

public:

	static void ShowTransferScreen()
	{
		clsScreen::_DrawScreenHeader("Transfer Screen");

		string AcctNumber1 = clsInputValidate::ReadString("\nEnter Account Number of Sender:");
		clsBankClient Sender;

		while (!clsBankClient::IsClientExist(Sender, AcctNumber1))
		{
			cout << "\nAccount Number [" << AcctNumber1 << "] Doesnt Exist, ";
			AcctNumber1 = clsInputValidate::ReadString("Enter a Valid Account Number of Sender:");
		}

		clsScreen::_PrintClientInfo(Sender, true);


		string AcctNumber2 = clsInputValidate::ReadString("\nEnter Account Number of Receiver:");
		clsBankClient Receiver;

		while (!clsBankClient::IsClientExist(Receiver, AcctNumber2) || AcctNumber2 == AcctNumber1)
		{
			cout << "\nAccount Number [" << AcctNumber2 << "] Doesnt Exist or Already Entered, ";
			AcctNumber2 = clsInputValidate::ReadString("Enter a Valid Account Number of Receiver:");
		}

		clsScreen::_PrintClientInfo(Receiver, true);





		float Amount = clsInputValidate::ReadNumber<float>("\nEnter Amount to Transfer: ");

		if (clsInputValidate::ReadBoolean("\nAre You Sure You Want To Perform The Transaction? Y/N:"))
		{
			clsBankClient::enSaveResults SaveResults = Sender.Transfer(Amount, Receiver, CurrentUser.UserName);
			
			switch (SaveResults)
			{
			case clsBankClient::enSaveResults::eSuccedded:

				Sender.Save();
				Receiver.Save();
				cout << "\nTransfer Done Successfully!" << endl;
				clsScreen::_PrintClientInfo(Sender, true);
				clsScreen::_PrintClientInfo(Receiver, true);
				break;

			case clsBankClient::enSaveResults::eFailedInsufficientAmount:

				cout << "\nFailed Operation! Insufficient Amount" << endl;
				cout << "Amount To Withdraw:  " << Amount << endl;
				cout << "Sender Balance: " << Sender.AcctBalance << endl;
				break;
			}
		}
		else
		{
			cout << "\nOperation was cancelled!" << endl;
		}
	}


};

