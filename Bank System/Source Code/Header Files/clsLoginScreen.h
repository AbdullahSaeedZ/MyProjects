#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"
using namespace std;

class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login()
	{
		string UserName, Password;
		short Trials = 3;

		while (true)
		{
			UserName = clsInputValidate::ReadString("\nEnter Username:");
			Password = clsInputValidate::ReadString("Enter Password:");

			if (!clsUser::IsUserExist(CurrentUser, UserName, Password))
			{
				--Trials;

				if (Trials != 0)
				{
					cout << "\nInvalid Username/Password !!" << endl;
					cout << "You Have " << Trials << " Trials Left !!" << endl;
				}
				else
				{
					cout << "\nYou Have Been Locked After 3 Failed Trials!\n" << endl;
					return false;
				}
			}
			else
				break;
		}

		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenuScreen();
		return true;
	}


public: 


	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}


};

