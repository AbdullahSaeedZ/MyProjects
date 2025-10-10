#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;


class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "", string User = "Employee")
    {
        cout << "\n--------------------------------------------------\n";
        cout << Title << "  (" << User << " | " << clsDate::Print(clsDate()) << ")\n";
        cout << "--------------------------------------------------\n\n";
    }

    static void Pause()
    {
        cout << "\n\nPress any key to go back" << endl;
        system("pause>0");
    }

};

