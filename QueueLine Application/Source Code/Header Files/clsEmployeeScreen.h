#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
using namespace std;

class clsEmployeeScreen : protected clsScreen
{
private:
    
    enum eEmployeeOptions {  eShowQueuesInfo = 1, eServeNextClient = 2, ePrintAllTickets = 3, eShowTicketsRTL = 4, eShowTicketsLTR = 5, eBackToMainMenu = 6 };

    static void _ChooseQueueMenu(string Title)
    {
        clsScreen::_DrawScreenHeader("Employee Panel Screen");

        cout << "\n=============================\n";
        cout << "       " << Title << "\n";
        cout << "=============================\n";
        cout << "[1] Bills Client\n";
        cout << "[2] Accounts Client\n";
        cout << "[3] Back\n";
        cout << "=============================\n";

    }


    static void _ServeClient()
    {
        short Option = 0;
        do
        {
            system("cls");
            _ChooseQueueMenu("Serve Client");
            
            Option = clsInputValidate::ReadNumInRange<short>(1, 3, "Choose an option:");

            switch (Option)
            {
            case 1 :
            {
                system("cls");
                if (BillsQueue.ServeNextClient())
                    cout << "\n\nClient Served !\n";
                else
                    cout << "\n\nNo Clients Yet!\n";

                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                if (AccountsQueue.ServeNextClient())
                    cout << "\n\nClient Served !\n";
                else
                    cout << "\n\nNo Clients Yet!\n";
                system("pause");
                break;
            }
            case 3:
            {
                return;
            }
            default:
            {
                return;
            }
            }


        } while (Option != 3);
    }

    static void _ShowQueuesInfo()
    {
        short Option = 0;
        do
        {
            system("cls");
            _ChooseQueueMenu("Show Queues Info");

            Option = clsInputValidate::ReadNumInRange<short>(1, 3, "Choose an option:");

            switch (Option)
            {
            case 1:
            {
                system("cls");
                BillsQueue.PrintQueueInfo();
                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                AccountsQueue.PrintQueueInfo();
                system("pause");
                break;
            }
            case 3:
            {
                return;
            }
            default:
            {
                return;
            }
            }

        } while (Option != 3);

    }

    static void _PrintAllTickets()
    {
        short Option = 0;
        do
        {
            system("cls");
            _ChooseQueueMenu("Print All Tickets");

            Option = clsInputValidate::ReadNumInRange<short>(1, 3, "Choose an option:");

            switch (Option)
            {
            case 1:
            {
                system("cls");
                if (!BillsQueue.PrintTickets())
                    cout << "\n\nNo Tickets Issued Yet!\n";

                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                if (!AccountsQueue.PrintTickets())
                    cout << "\n\nNo Tickets Issued Yet!\n";

                system("pause");
                break;
            }
            case 3:
            {
                return;
            }
            default:
            {
                return;
            }
            }

        } while (Option != 3);
    }  
    
    static void _ShowTicketsLTR()
    {

        short Option = 0;
        do
        {
            system("cls");
            _ChooseQueueMenu("Show Ticket LTR");

            Option = clsInputValidate::ReadNumInRange<short>(1, 3, "Choose an option:");

            switch (Option)
            {
            case 1:
            {
                system("cls");
                if (!BillsQueue.PrintTicketsLineLTR())
                    cout << "\n\nNo Tickets Issued Yet!\n";

                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                if (!AccountsQueue.PrintTicketsLineLTR())
                    cout << "\n\nNo Tickets Issued Yet!\n";

                system("pause");
                break;
            }
            case 3:
            {
                return;
            }
            default:
            {
                return;
            }
            }

        } while (Option != 3);
    }

    static void  _ShowTicketsRTL()
    {

        short Option = 0;
        do
        {
            system("cls");
            _ChooseQueueMenu("Show Ticket RTL");

            Option = clsInputValidate::ReadNumInRange<short>(1, 3, "Choose an option:");

            switch (Option)
            {
            case 1:
            {
                system("cls");
                if (!BillsQueue.PrintTicketsLineRTL())
                    cout << "\n\nNo Tickets Issued Yet!\n";

                system("pause");
                break;
            }
            case 2:
            {
                system("cls");
                if (!AccountsQueue.PrintTicketsLineRTL())
                    cout << "\n\nNo Tickets Issued Yet!\n";

                system("pause");
                break;
            }
            case 3:
            {
                return;
            }
            default:
            {
                return;
            }
            }

        } while (Option != 3);
    
    }

    static void _PerformEmployeeOption(short Option)
    { 
        switch (Option)
        {
        case eServeNextClient:
        {
            system("cls");
            _ServeClient();
            ShowEmployeeScreen();
            break;
        }
        case eShowQueuesInfo:
        {
            system("cls");
            _ShowQueuesInfo();
            ShowEmployeeScreen();
            break;
        }
        case ePrintAllTickets:
        {
            system("cls");
            _PrintAllTickets();
            ShowEmployeeScreen();
            break;
        }
        case eShowTicketsRTL:
        {
            system("cls");
            _ShowTicketsRTL();
            ShowEmployeeScreen();
            break;
        }
        case eShowTicketsLTR:
        {
            system("cls");
            _ShowTicketsLTR();
            ShowEmployeeScreen();
            break;
        }
        case eBackToMainMenu:
        {
            return;
        }
        default: return;
        }
    }

public:

	static void ShowEmployeeScreen()
	{
        system("cls");
        clsScreen::_DrawScreenHeader("Employee Panel Screen");

        cout << "\n=============================\n";
        cout << "       Employee Panel\n";
        cout << "=============================\n";
        cout << "[1] Show Queues Info\n";
        cout << "[2] Serve Next Client\n";
        cout << "[3] Print All Tickets\n";
        cout << "[4] Show Tickets (RTL)\n";
        cout << "[5] Show Tickets (LTR)\n";
        cout << "[6] Back\n";
        cout << "=============================\n";


        _PerformEmployeeOption(clsInputValidate::ReadNumInRange<short>(1, 6, "Choose an option:"));

	}



};

