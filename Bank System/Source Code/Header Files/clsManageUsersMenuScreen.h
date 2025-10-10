#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "Global.h"
#include "clsUserListScreen.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;

class clsManageUsersMenuScreen : protected clsScreen
{
private:


	enum enManageUsersMenuOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
	};



	static void _ShowListUsersScreen()
	{
		clsUserListScreen::ShowUsersListScreen();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menu...\n";

		system("pause>0");
		ShowManageUsersScreen();
	}

	static short _ReadManageUsersMenuOption()
	{
		short Choice = 0;
		Choice = clsInputValidate::ReadNumInRange(1, 6, "\t\t\t\t\tChoose what you want to do [1 to 6]: ");
		return Choice;
	}

	static void _PerformManageUsersMenuOption(short Option)
	{

		switch (Option)
		{
		case enManageUsersMenuOptions::eListUsers:
			
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenu();
			break;

		case enManageUsersMenuOptions::eAddNewUser:

			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenu();
			break;

		case enManageUsersMenuOptions::eDeleteUser:

			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenu();
			break;
		
		case enManageUsersMenuOptions::eUpdateUser:

			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenu();
			break;

		case enManageUsersMenuOptions::eFindUser:

			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenu();
			break;

		case enManageUsersMenuOptions::eMainMenu:

			break;

		}


	}



public:

	static void ShowManageUsersScreen()
	{
		if (!clsScreen::HasPermission(CurrentUser.Permission, clsUser::enPermission::pManageUsers))
		{
			cout << "\n\tPress any key to go back to main menu.." << endl;
			system("pause>0");
			return;
		}


		system("cls");
		_DrawScreenHeader("Manage Users Screen");

		cout << "\t\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t           Manage Users Menu\n";
		cout << "\t\t\t\t\t===========================================\n";
		cout << "\t\t\t\t\t     [1] List Users.\n";
		cout << "\t\t\t\t\t     [2] Add New User.\n";
		cout << "\t\t\t\t\t     [3] Delete User.\n";
		cout << "\t\t\t\t\t     [4] Update User.\n";
		cout << "\t\t\t\t\t     [5] Find User.\n";
		cout << "\t\t\t\t\t     [6] Main Menu.\n";
		cout << "\t\t\t\t\t===========================================\n";

		_PerformManageUsersMenuOption(_ReadManageUsersMenuOption());
	}

};

