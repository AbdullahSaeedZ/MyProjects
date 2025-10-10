#pragma once

#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindClientScreen : protected clsScreen
{

public:


    static  void FindClientScreen()
    {
        if (!clsScreen::HasPermission(CurrentUser.Permission, clsUser::enPermission::pFindClient))
        {
            return;
        }

        clsScreen::_DrawScreenHeader("Find Client Screen");

        clsBankClient ClientToFind;
        string AcctNumber = clsInputValidate::ReadString("Enter Account Number:");

        while (!clsBankClient::IsClientExist(ClientToFind, AcctNumber))
        {
            AcctNumber = clsInputValidate::ReadString("Account Number Does not Exist, Enter Account Number:");
        }

        clsScreen::_PrintClientInfo(ClientToFind);
    }

};

