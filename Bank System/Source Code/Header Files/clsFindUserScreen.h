#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindUserScreen : protected clsScreen
{

public:

    static  void ShowFindUserScreen()
    {
        clsScreen::_DrawScreenHeader("Find User Screen");

        clsUser UserToFind;
        string UserName = clsInputValidate::ReadString("Enter User Name:");

        while (!clsUser::IsUserExist(UserToFind, UserName))
        {
            UserName = clsInputValidate::ReadString("User Name Does not Exist, Enter Another User Name:");
        }

        clsScreen::_PrintUser(UserToFind);
    }

};

