#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionMenuScreen.h"
#include "clsManageUsersMenuScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrenciesScreen.h"
using namespace std;


//this is UI code,  main screen class calls the other screen classes which are also UI code, then those UI code classes communicate with backend code which is clsBankClient class.


class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
		eManageUsers = 7, eLoginRegister = 8, eCurrencyMenu = 9, eExit = 10
	};

	static void _ShowClientListScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::AddNewClientScreen();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::DeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::UpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::FindClientScreen();
	}

	static void _ShowTransactionMenuScreen()
	{
		clsTransactionMenuScreen::ShowTransactionMenu();
	} 

	static void _ShowManageUsersScreen()
	{
		clsManageUsersMenuScreen::ShowManageUsersScreen();
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyMenuScreen()
	{
		clsCurrenciesScreen::ShowCurrenciesMenu();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		// to empty the object at logout
		// it will go to main function.

		// why dont we just write the login function here?
		// // Circular dependency = mutual dependency
		// Happens when two classes or files depend on each other simultaneously
		// Example: clsMainScreen includes clsLoginScreen
		// And clsLoginScreen includes clsMainScreen
		// This causes an infinite loop at compile time => Compilation error
	}



	static  void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\t\t\tPress any key to go back to Main Menu...\n";

		system("pause>0");
		ShowMainMenuScreen();
	}


	static short _ReadMainMenuOption()
	{
		short Choice = 0;
		Choice = clsInputValidate::ReadNumInRange<short>(1, 10, "\t\t\t\t\tChoose what you want to do [1 to 10]: ");

		return Choice;
	}

	static void _PerformMainMenuOption(short Option)
	{														// Checking permissions in the main menu = easy but weak security
															// If someone uses a bypass code, they can call the function directly
															// Better: check inside the function itself
															// It doesn’t matter where the function is called from,
															// protection must be enforced inside the function, not elsewhere
		switch (Option)
		{
		case enMainMenueOptions::eListClients:
		
			system("cls");
			_ShowClientListScreen();
			_GoBackToMainMenu();
			break;
		
		case enMainMenueOptions::eAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eShowTransactionsMenu:
			system("cls");
			_ShowTransactionMenuScreen();
			ShowMainMenuScreen();
			break;

		case enMainMenueOptions::eManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			ShowMainMenuScreen();
			break;

		case enMainMenueOptions::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenueOptions::eCurrencyMenu:
			system("cls");
			_ShowCurrencyMenuScreen();
			ShowMainMenuScreen();
			break;

		case enMainMenueOptions::eExit:
			system("cls");
			_Logout();
			break;
		}

	
	}


public:


	static void ShowMainMenuScreen()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");

		cout << "\t\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t                Main Menu\n";
		cout << "\t\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t     [1] Show Client List.\n";
		cout << "\t\t\t\t\t     [2] Add New Client.\n";
		cout << "\t\t\t\t\t     [3] Delete Client.\n";
		cout << "\t\t\t\t\t     [4] Update Client Info.\n";
		cout << "\t\t\t\t\t     [5] Find Client.\n";
		cout << "\t\t\t\t\t     [6] Transactions.\n";
		cout << "\t\t\t\t\t     [7] Manage Users.\n";
		cout << "\t\t\t\t\t     [8] Login Register.\n";
		cout << "\t\t\t\t\t     [9] Currency Exchange.\n";
		cout << "\t\t\t\t\t     [10] Logout.\n";
		cout << "\t\t\t\t\t===========================================\n";

		_PerformMainMenuOption(_ReadMainMenuOption());
	}


};

