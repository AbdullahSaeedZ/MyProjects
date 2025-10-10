#pragma once

#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsUserListScreen : protected clsScreen
{
private:

    static void _PrintUserRecordLine(clsUser &User)
    {

        cout << setw(8) << left << "" << "\t| " << setw(12) << left << User.UserName;
        cout << "| " << setw(25) << left << User.getFullName();
        cout << "| " << setw(14) << left << User.PhoneNumber;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(12) << left << User.Permission;

    }

public:

	static void ShowUsersListScreen()
	{

        vector <clsUser> vUsers = clsUser::GetUsersList();

        string Title = "Users List Screen";
        string SubTitle = "(" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t\t___________________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "\t| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(14) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t\t___________________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser &User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t\t___________________________________________________________";
        cout << "______________________________________________\n" << endl;

	}

};

