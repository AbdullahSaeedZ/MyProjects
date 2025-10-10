#pragma once

#include <iostream>
#include <vector>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsEmployeeScreen.h"
#include "clsClientsScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
private:

    enum eMainOptions { eEmployeePanel = 1, eClientPanel = 2, eExit = 3 };

    static bool _PerformMainMenuOption(short Option)
    {

        switch (Option)
        {
        case eEmployeePanel : 
        {
            system("cls");
            clsEmployeeScreen::ShowEmployeeScreen();
            ShowMainMenuScreen();
            break;
        }
        case eClientPanel :
        {
            system("cls");
            clsClientsScreen::ShowClientsScreen();
            ShowMainMenuScreen();
            break;
        }
        case eExit:
        {
            return false;
        }
        default: return false;
        }


    }

public:

	static bool ShowMainMenuScreen()
	{
        system("cls");
        clsScreen::_DrawScreenHeader("Main Menu Screen", "", "");

        cout << "\n=============================\n";
        cout << "      Queue Line System\n";
        cout << "=============================\n";
        cout << "[1] Employee Panel\n";
        cout << "[2] Client Panel\n";
        cout << "[3] Exit\n";
        cout << "=============================\n";

        return _PerformMainMenuOption(clsInputValidate::ReadNumInRange<short>(1, 3, "Choose an option:"));
	}

};

