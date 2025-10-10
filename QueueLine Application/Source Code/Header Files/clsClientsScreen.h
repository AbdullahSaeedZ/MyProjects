#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsQueueServiceScreen.h"
#include "Global.h"
using namespace std;


class clsClientsScreen : protected clsScreen
{
private:

    enum eClientOptions {ePayBills = 1, eAccountServices = 2, eBack = 3};


    static void _PerformClientsOption(short Option)
    {
        switch (Option)
        {
        case ePayBills:
        {
            system("cls");
            clsQueueServiceScreen::ShowServiceScreen(BillsQueue);
            break;
        }
        case eAccountServices:
        {
            system("cls");
            clsQueueServiceScreen::ShowServiceScreen(AccountsQueue);
            break;
        }
        case eBack:
        {
            return;
        }
        default:
        {
            return;
        }
        }
    }

public:

    static void ShowClientsScreen()
    {
        system("cls");
        clsScreen::_DrawScreenHeader("Client Panel Screen", "", "Client");

        cout << "\n=============================\n";
        cout << "         Client Panel\n";
        cout << "=============================\n";
        cout << "[1] Pay Bills\n";
        cout << "[2] Account Services\n";
        cout << "[3] Back\n";
        cout << "=============================\n";

        _PerformClientsOption(clsInputValidate::ReadNumInRange<short>(1, 3, "Choose an option:"));

    }
};

