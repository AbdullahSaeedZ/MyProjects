#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include "clsDate.h"
using namespace std;

class clsQueueLine
{
private:

    string _Prefix;
    int _TotalTickets;
    int _WaitingClients;
    int _ServedTickets;
    int _AvrgWaitingTime;

    
    struct stTicket
    {
        string TicketID;
        string IssueDate;
        int WaitingClients;
        int ServingTime;
    };

    queue <stTicket> Tickets;

    void _PrintOneTicket(stTicket Ticket)
    {
        cout << "\n\n___________________________" << endl;
        cout << "           " << Ticket.TicketID << endl;
        cout << Ticket.IssueDate << endl;
        cout << "Waiting Clients = " << Ticket.WaitingClients << endl;
        cout << "Serve Time In " << Ticket.ServingTime << " Minutes." << endl;
        cout << "___________________________" << endl;
    }

public:

    clsQueueLine(string Prefix, int AvrgWaitingTime)
    {
        _Prefix = Prefix;
        _AvrgWaitingTime = AvrgWaitingTime;
        _TotalTickets = 0;
        _WaitingClients = 0;
        _ServedTickets = 0;
    }

    string getPrefix()
    {
        return _Prefix;
    }

    void setTotalTickets(int total)
    {
        _TotalTickets = total;
    }

    void setWaitingClients(int waiting)
    {
        _WaitingClients = waiting;
    }

    void setServedTickets(int served)
    {
        _ServedTickets = served;
    }

    void setAvrgWaitingTime(int avgTime)
    {
        _AvrgWaitingTime = avgTime;
    }

    int getTotalTickets()
    {
        return _TotalTickets;
    }

    int getWaitingClients()
    {
        return _WaitingClients;
    }

    int getServedTickets()
    {
        return _ServedTickets;
    }

    int getAvrgWaitingTime()
    {
        return _AvrgWaitingTime;
    }

    __declspec(property(get = getTotalTickets, put = setTotalTickets)) int TotalTickets;
    __declspec(property(get = getWaitingClients, put = setWaitingClients)) int WaitingClients;
    __declspec(property(get = getServedTickets, put = setServedTickets)) int ServedTickets;
    __declspec(property(get = getAvrgWaitingTime, put = setAvrgWaitingTime)) int AvrgWaitingTime;

    //

    void IssueTicket()
    {
        WaitingClients++;
        TotalTickets++;

        stTicket OneTicket;
        OneTicket.IssueDate = clsDate::GetSystemDateTimeString();
        OneTicket.TicketID = _Prefix + to_string(TotalTickets);
        OneTicket.WaitingClients = WaitingClients -1;
        OneTicket.ServingTime = (WaitingClients -1) * AvrgWaitingTime;


        Tickets.push(OneTicket);
    }

    string WhoIsNext()
    {
        if (Tickets.empty())
            return "\nNo Clients Left.\n";
        else
            return Tickets.front().TicketID + "\n\n";
    }


    void PrintQueueInfo()
    {
        
        cout << "\n----------------------" << endl;
        cout << "\tQueue Info" << endl;
        cout << "----------------------" << endl;
        cout << "Prefix          = " << _Prefix << endl;
        cout << "Total Tickets   = " << TotalTickets << endl;
        cout << "Served Clients  = " << ServedTickets << endl;
        cout << "Waiting Clients = " << WaitingClients << endl;
        cout << "----------------------" << endl;
    }

    bool PrintTickets()
    {
        if (Tickets.empty())
            return false;
        else
        {
            queue <stTicket> tempQue = Tickets;
            while (!tempQue.empty())
            {
                _PrintOneTicket(tempQue.front());
                tempQue.pop();
            }
        }
        return true;
    }

    bool PrintTicketsLineRTL()
    {
        if (Tickets.empty())
            return false;
        else
        {
            queue <stTicket> tempQue = Tickets;
            
            cout << "\nTickets: ";
            while (!tempQue.empty())
            {
                cout << tempQue.front().TicketID << " <-- ";
                tempQue.pop();
            }
        }
        cout << "\n" << endl;
        return true;
    }

    bool PrintTicketsLineLTR()
    {
        if (Tickets.empty())
            return false;
        else
        {
            queue <stTicket> tempQue = Tickets;
            stack <stTicket> tempStack;
            
            while (!tempQue.empty())
            {
                tempStack.push(tempQue.front());
                tempQue.pop();
            }

            cout << "\nTickets: ";
            while (!tempStack.empty())
            {
                cout << tempStack.top().TicketID << " --> ";
                tempStack.pop();
            }

        }
        cout << "\n" << endl;
        return true;
    }


    bool ServeNextClient()
    {
        if (!Tickets.empty())
        {
            Tickets.pop();
            WaitingClients--;
            ServedTickets++;
            return true;
        }
        else
            return false;
    }


};

	


