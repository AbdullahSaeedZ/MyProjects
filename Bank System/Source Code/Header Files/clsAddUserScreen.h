#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;



class clsAddUserScreen : protected clsScreen
{

public:

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("Add New User Screen");

		clsUser UserToAdd;

		string UserName = clsInputValidate::ReadString("Enter User Name:");
		while (clsUser::IsUserExist(UserToAdd, UserName))
		{
			UserName = clsInputValidate::ReadString("User Name Already Exist, Enter Another User Name:");
		}

		UserToAdd = clsUser::GetAddNewUserObject(UserName);

		clsScreen::_ReadUserInfo(UserToAdd);
		clsUser::GivePermissions(UserToAdd);
		clsScreen::_PrintUser(UserToAdd);

		if (clsInputValidate::ReadBoolean("\nAre You Sure You Want To Add This User?"))
		{
			clsUser::enSaveResults SavingResult = UserToAdd.Save();

			switch (SavingResult)
			{
			case clsUser::enSaveResults::eSuccedded:

				cout << "\nUser Added Successfully!" << endl;
				break;

			case clsUser::enSaveResults::eFailedEmptyObject:

				cout << "\nError, User was not saved because it's Empty!" << endl;
			}

		}
		else
		{
			cout << "\nOperation was cancelled!" << endl;
		}

	}


};

