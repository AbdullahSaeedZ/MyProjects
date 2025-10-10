#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen
{

public:

	static void ShowDeleteUserScreen()
	{

        clsScreen::_DrawScreenHeader("Delete User Screen");

		clsUser UserToDelete;

		string UserName = clsInputValidate::ReadString("Enter User Name:");

		while (!clsUser::IsUserExist(UserToDelete, UserName) || UserName == "Admin")
		{
			UserName = clsInputValidate::ReadString("User Does Not Exist or Admin User Name Entered, Enter Another User Name:");
		}

		clsScreen::_PrintUser(UserToDelete);

		if (clsInputValidate::ReadBoolean("\nAre You Sure You Want To Delete This User?"))
		{
			UserToDelete.Delete();
			cout << "\nUser Deleted Successfully!" << endl;
			clsScreen::_PrintUser(UserToDelete);
		}
		else
		{
			cout << "\nOperation was cancelled!" << endl;
		}

	}



};

