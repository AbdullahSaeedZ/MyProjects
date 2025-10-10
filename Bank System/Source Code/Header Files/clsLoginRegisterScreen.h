#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
using namespace std;

class clsLoginRegisterScreen : clsScreen
{
private:

    static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord Record)
    {

        cout << left << "" << "\t\t| " << setw(20) << left << Record.DateTime;
        cout << "| " << setw(14) << left << Record.FirstName;
        cout << "| " << setw(14) << left << Record.LastName;
        cout << "| " << setw(14) << left << Record.UserName;
        cout << "| " << setw(14) << left << Record.Password;
        cout << "| " << setw(14) << left << Record.Permission;
    }



public:

	static void ShowLoginRegisterScreen()
	{
        if (!clsScreen::HasPermission(CurrentUser.Permission, clsUser::enPermission::pLoginRegister))
        {
            return;
        }

		vector<clsUser::stLoginRegisterRecord> vRecords = clsUser::GetLoginRegisterRecords();

		string Title = "Login Register List Screen";
		string SubTitle = "(" + to_string(vRecords.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);

        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "\t\t| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(14) << "First Name";
        cout << "| " << left << setw(14) << "Last Name";
        cout << "| " << left << setw(14) << "User Name";
        cout << "| " << left << setw(14) << "Password";
        cout << "| " << left << setw(14) << "Permissions";
        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vRecords.size() == 0)
            cout << "\t\tNo Logins Available In the System!";
        else

            for (clsUser::stLoginRegisterRecord& Record : vRecords)
            {

                _PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }

        cout << "\n\t\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;




	}

};

