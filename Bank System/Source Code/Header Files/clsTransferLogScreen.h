#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
using namespace std;


class clsTransferLogScreen : protected clsScreen
{
private:

    static void _PrintTransferRecordLine(clsBankClient::stTransferLog Record)
    {
        cout << left << "\t\t| " << setw(20) << left << Record.DateTime;
        cout << "| " << setw(6) << left << Record.SenderAcct;
        cout << "| " << setw(6) << left << Record.ReceiverAcct;
        cout << "| " << setw(12) << left << stoi(Record.TransferAmount);
        cout << "| " << setw(15) << left << stoi(Record.SenderNewBalance);
        cout << "| " << setw(17) << left << stoi(Record.ReceiverNewBalance);
        cout << "| " << setw(14) << left << Record.ActiveUser;
    }


public :

	static void ShowTransferLogScreen()
	{
        vector<clsBankClient::stTransferLog> vRecords = clsBankClient::GetTransferRecords();

        string Title = "Transfer Log List Screen";
        string SubTitle = "(" + to_string(vRecords.size()) + ") Record(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(6) << "From";
        cout << "| " << left << setw(6) << "To";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(15) << "Sender Balance";
        cout << "| " << left << setw(17) << "Receiver Balance";
        cout << "| " << left << setw(14) << "By User";
        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vRecords.size() == 0)
            cout << "\t\tNo Transfer Info Available In the System!";
        else

            for (clsBankClient::stTransferLog& Record : vRecords)
            {
                _PrintTransferRecordLine(Record);
                cout << endl;
            }

        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;





	}

};

