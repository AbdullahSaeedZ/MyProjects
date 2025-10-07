#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "str.h"
using namespace std;


namespace fs
{

    struct stClientData
    {
        string ID, PINCode, Name, Phone;
        double AcctBalance;
    };

    string ConvertRecordToLine(stClientData Client1, string delim = "#//#")
    {
        string str = "";

        str += Client1.ID + delim;
        str += Client1.Name + delim;
        str += Client1.PINCode + delim;
        str += Client1.Phone + delim;
        str += to_string(Client1.AcctBalance);

        return str;
    }

    stClientData ConvertDataLineToRecord(string Line, string Delim = "#//#")
    {
        vector<string> Records = str::SplitStringToVector(Line, Delim);
        stClientData Client;

        Client.ID = Records[0];
        Client.PINCode = Records[1];
        Client.Name = Records[2];
        Client.Phone = Records[3];
        Client.AcctBalance = stod(Records[4]);

        return Client;
    }


    void PrintDataRecord(stClientData Client)
    {
        cout << "Account ID: " << Client.ID << endl;
        cout << "Pin Code  : " << Client.PINCode << endl;
        cout << "Name      : " << Client.Name << endl;
        cout << "Phone     : " << Client.Phone << endl;
        cout << "Balance   : " << Client.AcctBalance << endl;
    }

    stClientData ReadClientData()
    {
        stClientData Client;
        cout << "Enter Account Number? "; // Usage of std::ws will extract all the whitespace character  
        getline(cin >> ws, Client.ID);

        cout << "Enter PinCode? ";
        getline(cin, Client.PINCode);

        cout << "Enter Name? ";
        getline(cin, Client.Name);

        cout << "Enter Phone? ";
        getline(cin, Client.Phone);

        cout << "Enter AccountBalance? ";
        cin >> Client.AcctBalance;

        return Client;
    }

    void AddDataLineToFile(string FilePath, string strDataLine)
    {
        fstream DataBase;

        DataBase.open(FilePath, ios::out | ios::app);

        if (DataBase.is_open())
        {
            DataBase << strDataLine << endl;
            DataBase.close();
        }

    }

    void AddNewClient(string FilePath)
    {
        stClientData Client = ReadClientData();

        AddDataLineToFile(FilePath, ConvertRecordToLine(Client, "#//#"));
    }

    void CreateFile(string FileName)
    {
        // trying to read a file with this name, if file not created it will fail and no imapct happens.

        ifstream CheckFile(FileName);  // ifstream opens in ios::in by default

        if (CheckFile.is_open())
            return;
        else
            ofstream NewFile(FileName); // ofstream opens in ios::out by default
    }

    void PrintFile(const string FilePath)
    {
        fstream File;
        File.open(FilePath, ios::in);

        string Line;

        if (File.is_open())
        {
            while (getline(File, Line))
            {
                cout << Line << endl;
            }

            File.close();
        }
    }

    void ClearFile(const string FilePath)
    {
        fstream File;
        File.open(FilePath, ios::out);

        if (File.is_open())
        {
            File.close();
        }
    }

    void CopyFile(const string srcFilePath, const string dstFilePath, const bool OverrideDst = false)
    {
        fstream src(srcFilePath, ios::in);
        fstream dst(dstFilePath, (OverrideDst) ? ios::out : ios::app);

        if (src.is_open() && dst.is_open())
        {
            string Line;

            while (getline(src, Line))
            {
                dst << Line << endl;
            }

            src.close();
            dst.close();
        }
    }

    void LoadFileToVector(string FilePath, vector <string>& vFileContent)
    {
        fstream File;
        File.open(FilePath, ios::in);

        if (File.is_open())
        {
            string Line;

            while (getline(File, Line))
            {
                vFileContent.push_back(Line);
            }

            File.close();
        }
    }

    void LoadVectorToNewFile(string FilePath, const vector <string>& VectorContent)
    {
        fstream File;
        File.open(FilePath, ios::out); // ios::out  to create a file if not created.

        if (File.is_open())
        {
            for (const string& Line : VectorContent)
            {
                if (Line != "")   //to ignore if vector element is empty (due to capacity nature)
                {
                    File << Line << endl;
                }
            }
            File.close();
        }
    }

    void DeleteRecordInFile(string FilePath, string Record)
    {
        vector <string> Temp;
        LoadFileToVector(FilePath, Temp);

        for (string& item : Temp)
        {
            if (item == Record)
            {
                item = "";
            }
        }
        LoadVectorToNewFile(FilePath, Temp);
    }

    void DeleteLineInFile(string FilePath, unsigned short LineNumber)
    {
        vector <string> Temp;
        LoadFileToVector(FilePath, Temp);

        Temp.at(LineNumber - 1) = "";

        LoadVectorToNewFile(FilePath, Temp);
    }

    void DeleteStringInLineInFile(string FilePath, string str)
    {
        vector<string> Temp;
        LoadFileToVector(FilePath, Temp);

        // size_t is unsgined long long int , but better use size_t for perforamce as it is for all systems (64-bit and 32-bit)

        size_t Index;

        for (string& Element : Temp)
        {
            Index = Element.find(str);

            while (Index != string::npos)  // search for str in the same element (the whole line)
            {
                Element.erase(Index, str.length());

                Index = Element.find(str);    // Update Index to find the next occurrence of the string in the same element, if not found, will result in npos.
            }
        }

        LoadVectorToNewFile(FilePath, Temp);
    }

    void UpdateRecordInFile(string FilePath, string Record, string UpdateTo)
    {
        vector <string> Temp;
        LoadFileToVector(FilePath, Temp);

        for (string& item : Temp)
        {
            if (item == Record)
            {
                item = UpdateTo;
            }
        }
        LoadVectorToNewFile(FilePath, Temp);
    }

}
