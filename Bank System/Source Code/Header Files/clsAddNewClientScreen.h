#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "Global.h"
using namespace std;


//this is considered UI Code, all back-end is from clsBankClient, thus we need to move the print function from the object to the class that handles UI code here.


class clsAddNewClientScreen : protected clsScreen
{ 

public:

    static void AddNewClientScreen()
    {
        if (!clsScreen::HasPermission(CurrentUser.Permission, clsUser::enPermission::pAddClient))
        {
            return;
        }

        clsScreen::_DrawScreenHeader("Add New Client Screen");

        string AcctNumber = clsInputValidate::ReadString("Enter Account Number: ");
        while (clsBankClient::IsClientExist(AcctNumber))
        {
            AcctNumber = clsInputValidate::ReadString("Account Already Exists, Enter Another Account Number: ");
        }

        clsBankClient ClientToAdd = clsBankClient::GetAddNewClientObject(AcctNumber);
        clsScreen::_ReadClientInfo(ClientToAdd);

        clsBankClient::enSaveResults SaveResult = ClientToAdd.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResults::eFailedEmptyObject:
        {
            cout << "Error, Object is Empty! " << endl;
        }
        case clsBankClient::enSaveResults::eFiledAcctNumerExist:
        {
            cout << "Error, Account Number Already Exist!" << endl;
        }
        case clsBankClient::enSaveResults::eSuccedded:
        {
            cout << "Client Added Successfully!" << endl;
            clsScreen::_PrintClientInfo(ClientToAdd);
        }
        }

    }



};

