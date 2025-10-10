#pragma once

#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;


class clsUpdateClientScreen : protected clsScreen
{

public:

    static void UpdateClientScreen()
    {

        if (!clsScreen::HasPermission(CurrentUser.Permission, clsUser::enPermission::pUpdateClient))
        {
            return;
        }

        clsScreen::_DrawScreenHeader("Update Client Screen");

        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString("\nEnter Client Account Number:");

        clsBankClient ClientToUpdate;

        while (!clsBankClient::IsClientExist(ClientToUpdate, AccountNumber))
        {
            AccountNumber = clsInputValidate::ReadString("\nNo Account Found, Enter Account Number:");
        }

        clsScreen::_PrintClientInfo(ClientToUpdate);

        if (clsInputValidate::ReadBoolean("\nAre You sure You Want To Update The Client ? Y / N : "))
        {

            cout << "\n\nUpdate Client Info:" << endl;
            cout << "_________________________" << endl;
            clsScreen::_ReadClientInfo(ClientToUpdate);


            clsBankClient::enSaveResults SaveResult;

            // save functions will apply changes and return the result in enums. then we deal with the enum as we want in the UI, if succeeded or if failed due to empty object.
            // even though we made sure the object is not empty in the while loop above, but we do it as defensive programming and to separate UI from Backend.
            SaveResult = ClientToUpdate.Save();

            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::eSuccedded:
            {
                cout << "\nAccount Updated successfully!" << endl;
                clsScreen::_PrintClientInfo(ClientToUpdate);
                break;
            }
            case clsBankClient::enSaveResults::eFailedEmptyObject:
            {
                cout << "\nError, Account was not Updated because it is empty!" << endl;
                break;
            }
            }
        }
    }

};

