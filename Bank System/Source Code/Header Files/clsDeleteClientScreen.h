#pragma once

#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;


class clsDeleteClientScreen : protected clsScreen
{

public: 

    static void DeleteClientScreen()
    {
        if (!clsScreen::HasPermission(CurrentUser.Permission, clsUser::enPermission::pDeleteClient))
        {
            return;
        }

        clsScreen::_DrawScreenHeader("Delete Client Screen");


        clsBankClient ClientToDelete;
        string AcctNumber = clsInputValidate::ReadString("Enter Account Number:");

        while (!clsBankClient::IsClientExist(ClientToDelete, AcctNumber))
        {
            AcctNumber = clsInputValidate::ReadString("Account Number Does not Exist, Enter Account Number:");
        }

        clsScreen::_PrintClientInfo(ClientToDelete);

        if (clsInputValidate::ReadBoolean("\nAre You sure You Want To Delete The Client ? Y / N : "))
        {
            ClientToDelete.Delete();

            cout << "\nClient Deleted Successfully!" << endl;
            clsScreen::_PrintClientInfo(ClientToDelete);
        }

    }



};

