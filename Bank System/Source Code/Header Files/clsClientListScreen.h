#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "Global.h"
#include "clsBankClient.h"
using namespace std;

class clsClientListScreen : protected clsScreen
{
private:

    static void _PrintClientRecordLine(clsBankClient& Client)
    {

        cout << "\t\t| " << setw(15) << left << Client.getAcctNumber();
        cout << "| " << setw(20) << left << Client.getFullName();
        cout << "| " << setw(12) << left << Client.PhoneNumber;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AcctBalance;

    }


public:

    static void ShowClientsList()
    {

        if (!clsScreen::HasPermission(CurrentUser.Permission, clsUser::enPermission::pShowClients))
        {
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "Client List Screen";
        string SubTitle = "(" + to_string(vClients.size()) + ") Client(s).";
        clsScreen::_DrawScreenHeader(Title, SubTitle);

        

        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

      
        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In The System!";
        else

            for (clsBankClient& Client : vClients)
            {

                _PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }




};

