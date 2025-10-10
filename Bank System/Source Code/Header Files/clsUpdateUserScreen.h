#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;


class clsUpdateUserScreen : protected clsScreen
{


public:

	static void ShowUpdateUserScreen()
	{

		_DrawScreenHeader("Update User Screen");

		clsUser UserToUpdate;

		string UserName = clsInputValidate::ReadString("Enter User Name:");
		while (!clsUser::IsUserExist(UserToUpdate, UserName))
		{
			UserName = clsInputValidate::ReadString("User Name Does Not Exist, Enter Another User Name:");
		}

		clsScreen::_PrintUser(UserToUpdate);

		cout << "\nUpdate User Information:\n" << endl;
		clsScreen::_ReadUserInfo(UserToUpdate);
		clsUser::GivePermissions(UserToUpdate);

		if (clsInputValidate::ReadBoolean("\nAre You Sure You Want To Update This User?"))
		{
			clsUser::enSaveResults SavingResult = UserToUpdate.Save();

			switch (SavingResult)
			{
			case clsUser::enSaveResults::eSuccedded:

				cout << "\nUser Updated Successfully!" << endl;

				if (CurrentUser.UserName == UserToUpdate.UserName)
				{
					CurrentUser = UserToUpdate;
				}

				break;

			case clsUser::enSaveResults::eFailedEmptyObject:

				cout << "\nError, User was not Updated because it's Empty!" << endl;
			}

		}
		else
		{
			cout << "\nOperation was cancelled!" << endl;
		}



	}

};

