#pragma once

#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionMenuScreen : protected clsScreen
{
private:

	enum enTransactionsMenueOptions {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eTransfer = 4, eShowTransferLog = 5, eShowMainMenu = 6
	};
	

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}


	static  void _GoBackToTransactionMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menu...\n";

		system("pause>0");
		ShowTransactionMenu();
	}

	

	static short _ReadTransactionMenuOption()
	{
		short Choice = 0;
		Choice = clsInputValidate::ReadNumInRange(1, 6, "\t\t\t\t\tChoose what you want to do [1 to 6]: ");
		return Choice;
	}

	static void _PerformTransactionMenuOption(short Option)
	{

		switch (Option)
		{
		case enTransactionsMenueOptions::eShowTotalBalance:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenu();
			break;

		case enTransactionsMenueOptions::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenu();
			break;

		case enTransactionsMenueOptions::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenu();
			break;

		case enTransactionsMenueOptions::eTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenu();
			break;

		case enTransactionsMenueOptions::eShowTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenu();
			break;

		case enTransactionsMenueOptions::eShowMainMenu:
			system("cls");
			//will exit the menu and go to main menu screen
			break;

		}

	}



public:

	static void ShowTransactionMenu()
	{

		if (!clsScreen::HasPermission(CurrentUser.Permission, clsUser::enPermission::pTransaction))
		{
			cout << "\n\tPress any key to go back to main menu.." << endl;
			system("pause>0");
			return;
		}


		system("cls");
		_DrawScreenHeader("Transactions Screen");

		cout << "\t\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t            Transactions Menu\n";
		cout << "\t\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t     [1] Deposit.\n";
		cout << "\t\t\t\t\t     [2] Withdraw.\n";
		cout << "\t\t\t\t\t     [3] Total Balances.\n";
		cout << "\t\t\t\t\t     [4] Transfer.\n";
		cout << "\t\t\t\t\t     [5] Transfer Log.\n";
		cout << "\t\t\t\t\t     [6] Main Menu.\n";
		cout << "\t\t\t\t\t===========================================\n";

		_PerformTransactionMenuOption(_ReadTransactionMenuOption());
	}
	

};

