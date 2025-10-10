#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace in
{
    string AskY_N(string Message)
    {
        string Answer = " ";
        do
        {
            cout << Message << endl;
            cin >> Answer;

        } while ((Answer != "Y" && Answer != "y") && (Answer != "N" && Answer != "n"));

        return Answer;
    }

    short ReadPositiveNumInRange(string Message, short From, short To)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;

            if (cin.fail())
            {
                // if other than numbers entered system will fail.
                cin.clear();                // to clear the failure
                cin.ignore(10000, '\n');    // to ignore what was entered before, to clean the buffer
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }

        } while (Number < From || Number > To);

        return Number;
    }

    int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;

            if (cin.fail())
            {
                // if other than numbers entered system will fail.
                cin.clear();                // to clear the failure
                cin.ignore(10000, '\n');    // to ignore what was entered before, to clean the buffer
                cout << "Invalid input! Please enter a number." << endl;
                continue;
            }

        } while (Number <= 0);

        return Number;
    }

    string ReadString(string Message)
    {
        string str = "";

        cout << Message << endl;
        getline(cin >> ws, str);

        return str;
    }

    char ReadChar(string Message)
    {
        char c = ' ';

        cout << Message << endl;
        cin >> c;

        return c;
    }

   













}