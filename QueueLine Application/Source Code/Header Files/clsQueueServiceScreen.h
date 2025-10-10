#pragma once


#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
using namespace std;

class clsQueueServiceScreen : protected clsScreen
{
private:

    enum eServiceOptions { eIssueNewTicket = 1, eViewNextTicket = 2, eShowQueueInfo = 3, ePrintAllTickets = 4, eBack = 5 };
   

    static void _PerformServiceOption(short Option, clsQueueLine& QueueChosen)
    {

        switch (Option)
        {
        case eIssueNewTicket:
        {
            system("cls");
            QueueChosen.IssueTicket();
            cout << "\nTicket Printed, Please Wait For Your Turn.\n\n";
            clsScreen::Pause();
            ShowServiceScreen(QueueChosen);
            break;
        }
        case eViewNextTicket:
        {
            system("cls");
            cout << "Next Ticket: " << QueueChosen.WhoIsNext();
            clsScreen::Pause();
            ShowServiceScreen(QueueChosen);
            break;
        }
        case eShowQueueInfo:
        {
            system("cls");
            QueueChosen.PrintQueueInfo();
            clsScreen::Pause();
            ShowServiceScreen(QueueChosen);
            break;
        }
        case ePrintAllTickets:
        {
            system("cls");
            QueueChosen.PrintTickets();
            clsScreen::Pause();
            ShowServiceScreen(QueueChosen);
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

    static void ShowServiceScreen(clsQueueLine &QueueChosen)
    {
        system("cls");
        clsScreen::_DrawScreenHeader("Queue Service Screen", "", "Client");

        cout << "\n=============================\n";
        cout << "      Queue Services\n";
        cout << "=============================\n";
        cout << "[1] Issue New Ticket\n";
        cout << "[2] View Next Ticket\n";
        cout << "[3] Show Queue Info\n";
        cout << "[4] Print All Tickets\n";
        cout << "[5] Back\n";
        cout << "=============================\n";

        return _PerformServiceOption(clsInputValidate::ReadNumInRange<short>(1, 5, "Choose an option:"), QueueChosen);
    }

};

