#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "in.h"
#include "str.h"
using namespace std;

const string ClientBase = "Clients.txt";
const string UserBase = "Users.txt";
const string TransBase = "Trans.txt";

//in bits for bitwise
enum enPermission { pShowClients = 1, pAddClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransaction = 32, pManageUsers = 64 };
enum enChoice { eShowList = 1, eAddClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5, eTransaction = 6, eManageUsers = 7, eLogout = 8 };
enum enTransChoice { Deposit = 1, Withdraw = 2, TotalBalances = 3, BackToMenu = 4 };
enum enManageOption { eListUser = 1, eAddUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu = 6 };

struct stDate
{
    short month = 0, day = 0, year = 0;
};

struct stHistory
{
    string ID = "";
    stDate DateOfTrans;
    double AmountOfTrans = 0;
    string SenderID = "";
    string RecipientID = "";
    bool IsOutsideTransaction = 0;
};

struct stClientData
{
    string ID, PINCode, Name, Phone;
    double AcctBalance;
    bool MarkForDelete = false;
    stHistory TransHistory;
    
};


struct stUser
{
    string UserName = "";
    string Password = "";
    short Permission = 0;
    bool MarkForDelete = false;
};

double ReadAmount(string Message)
{
    double Number = 0;
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

void ShowMenu(string Screen, string UserName)
{
    system("cls");

    if (Screen == "Bank")
    {
        cout << "Current User: " << UserName << endl;
        cout << "===========================================" << endl;
        cout << "            Bank Main Menu Screen" << endl;
        cout << "===========================================" << endl;
        cout << "[1] Show Clients List." << endl;
        cout << "[2] Add New Client." << endl;
        cout << "[3] Delete Client." << endl;
        cout << "[4] Update Client Info." << endl;
        cout << "[5] Find Client." << endl;
        cout << "[6] Transaction." << endl;
        cout << "[7] Manage Users." << endl;
        cout << "[8] Logout." << endl;
        cout << "===========================================" << endl;
    }
    else if (Screen == "ATM")
    {
        cout << "Current User: " << UserName << endl;
        cout << "===========================================" << endl;
        cout << "            ATM Main Menu Screen" << endl;
        cout << "===========================================" << endl;
        cout << "[1] Quick Withdraw." << endl;
        cout << "[2] Normal Withdraw." << endl;
        cout << "[3] Deposit." << endl;
        cout << "[4] Check Balance." << endl;
        cout << "[5] Transfer Money." << endl;
        cout << "[6] View Transaction History." << endl;
        cout << "[7] View Account Info." << endl;
        cout << "[8] Logout." << endl;
        cout << "===========================================" << endl;
    }
    
}


void ClientListHeader(vector<stClientData>& vAllClients)
{

    cout << "-----------------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "                                        Clients List (" << vAllClients.size() << ") Clients(s)." << endl;
    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(18) << "Account Number"
        << "| " << setw(18) << "Pin Code"
        << "| " << setw(48) << "Client Name"
        << "| " << setw(18) << "Phone"
        << "| " << setw(18) << "Balance" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------\n" << endl;
}

void ShowClientsList(vector<stClientData>& vAllClients)
{
    ClientListHeader(vAllClients);

    for (stClientData& ClientInfo : vAllClients)
    {
        cout << "| " << setw(18) << ClientInfo.ID
            << "| " << setw(18) << ClientInfo.PINCode
            << "| " << setw(48) << ClientInfo.Name
            << "| " << setw(18) << ClientInfo.Phone
            << "| " << setw(15) << ClientInfo.AcctBalance << " SAR" << endl;
    }
    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------\n" << endl;


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

string ConvertRecordToLine(stClientData Client1, string delim = "#//#")
{
    string str = "";

    str += Client1.ID + delim;
    str += Client1.PINCode + delim;
    str += Client1.Name + delim;
    str += Client1.Phone + delim;
    str += to_string(Client1.AcctBalance);

    return str;
}

bool IsIDFound(vector<stClientData>& vAllClients, string ClientID)
{
    for (stClientData& record : vAllClients)
    {
        if (record.ID == ClientID)
        {
            return true;
        }
    }
    return false;
}

bool IsClientFound(vector<stClientData>& vAllClients, stClientData& Client, string ClientID)
{
    for (stClientData& record : vAllClients)
    {
        if (record.ID == ClientID)
        {
            Client = record;
            return true;
        }
    }
    return false;
}


vector<stClientData> LoadDataFromFile(string FilePath)
{
    vector<stClientData> vAllClients;
    fstream File;

    File.open(FilePath, ios::in);

    if (File.is_open())
    {
        string Line = "";
        stClientData Record;

        while (getline(File, Line))
        {
            Record = ConvertDataLineToRecord(Line);
            vAllClients.push_back(Record);
        }

        File.close();
    }

    return vAllClients;
}

stClientData ReadClientData(vector<stClientData>& vAllClients)
{
    stClientData Client;


    cout << "Enter Account Number? "; // Usage of std::ws will extract all the whitespace character  
    getline(cin >> ws, Client.ID);

    while (IsIDFound(vAllClients, Client.ID))
    {
        cout << "Client with [" << Client.ID << "] already exists, enter another Account number: ";
        getline(cin, Client.ID);
    }

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


void AddClientHeader()
{
    cout << "\n--------------------------------" << endl;
    cout <<"      Add New Clients Screen" << endl;
    cout << "--------------------------------\n";
    cout << "Adding New Client:\n" << endl;
}

void AddNewClient(vector<stClientData>& vAllClients)
{
    string Again = "";
    fstream File;
    File.open(ClientBase, ios::out | ios::app);

    do
    {
        system("cls");
        AddClientHeader();

        if (File.is_open())
        {
            stClientData NewClient = ReadClientData(vAllClients);
            string Line = ConvertRecordToLine(NewClient);
            File << Line << endl;

        }

        cout << "\nClient Added Successfully !" << endl;

        vAllClients = LoadDataFromFile(ClientBase);

        Again = in::AskY_N("\nDo you want to add more clients? y/n?");

    } while (Again == "y" || Again == "Y");

    File.close();
}


void PrintDataRecord(stClientData Client)
{
    cout << "\n--------------------------------" << endl;
    cout << "Account ID: " << Client.ID << endl;
    cout << "Pin Code  : " << Client.PINCode << endl;
    cout << "Name      : " << Client.Name << endl;
    cout << "Phone     : " << Client.Phone << endl;
    cout << "Balance   : " << Client.AcctBalance << " SAR" << endl;
    cout << "--------------------------------\n" << endl;
}

void DeleteHeader()
{
    cout << "\n--------------------------------" << endl;
    cout << "     Delete Client Screen" << endl;
    cout << "--------------------------------\n" << endl;
}

void MarkForDelete(vector<stClientData>& vAllClients, string ClientID)
{
    for (stClientData& record : vAllClients)
    {
        if (record.ID == ClientID)
        {
            record.MarkForDelete = true;
            break;
        }
    }
}

void UpdateClientsAfterDelete(vector<stClientData>& vAllClients, string ClientID)
{
    string Line = "";
    fstream File;
    File.open(ClientBase, ios::out);

    if (File.is_open())
    {
        for (stClientData& record : vAllClients)
        {
            if (record.MarkForDelete == false)
            {
                Line = ConvertRecordToLine(record);
                File << Line << endl;
            }
        }

        File.close();
    }
}

void DeleteOneClient(vector<stClientData>& vAllClients, string ClientID)
{
    MarkForDelete(vAllClients, ClientID);
    UpdateClientsAfterDelete(vAllClients, ClientID);
}

void DeleteClientProcess(vector<stClientData>& vAllClients)
{
    stClientData Client;
    string Again = "";
    string sure = "";
    string ClientID = "";

    do
    {
        system("cls");
        DeleteHeader();

        ClientID = in::ReadString("\nPlease enter Account Number: ");
        if (IsClientFound(vAllClients, Client, ClientID))
        {
            PrintDataRecord(Client);

            sure = in::AskY_N("\nAre you sure you want to delete this client ? y/n ? ");
            if (sure == "y" || sure == "Y")
            {
                DeleteOneClient(vAllClients, ClientID);
                vAllClients = LoadDataFromFile(ClientBase);
                cout << "\nClient Deleted Successfully !" << endl;
            }
        }
        else
        {
            cout << "\nClient with this Account Number Doesn`t exist !" << endl;
        }


        Again = in::AskY_N("\nDo you want to delete other clients? y/n?");

    } while (Again == "y" || Again == "Y");

}


void UpdateHeader()
{
    cout << "\n--------------------------------" << endl;
    cout << "   Update Client Info Screen" << endl;
    cout << "--------------------------------\n";
}

stClientData ReadRecordUpdate(string ClientID)
{
    stClientData Client;

    Client.ID = ClientID;

    cout << "Enter PinCode? ";
    getline(cin >> ws, Client.PINCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AcctBalance;

    return Client;
}

void UpdateOneClient(vector<stClientData>& vAllClients, string ClientID)
{
    for (stClientData& record : vAllClients)
    {
        if (record.ID == ClientID)
        {
            record = ReadRecordUpdate(ClientID);
            break;
        }
    }
}

void LoadVectorToFile(vector<stClientData>& vAllClients)
{
    string Line = "";
    fstream File;
    File.open(ClientBase, ios::out);

    if (File.is_open())
    {
        for (stClientData& record : vAllClients)
        {
            Line = ConvertRecordToLine(record);
            File << Line << endl;
        }

        File.close();
    }
}

void UpdateClientInfo(vector<stClientData>& vAllClients)
{
    stClientData Client;
    string Again = "";
    string sure = "";
    string ClientID = "";

    do
    {
        system("cls");
        UpdateHeader();

        ClientID = in::ReadString("\nPlease enter Account Number: ");
        if (IsClientFound(vAllClients, Client, ClientID))
        {
            cout << "\nClient Details: " << endl;
            PrintDataRecord(Client);

            sure = in::AskY_N("\nAre you sure you want to update this client ? y/n ? ");
            if (sure == "y" || sure == "Y")
            {
                UpdateOneClient(vAllClients, ClientID);
                LoadVectorToFile(vAllClients);
                vAllClients = LoadDataFromFile(ClientBase);
                cout << "\nClient Info Updated Successfully !" << endl;
            }
        }
        else
        {
            cout << "\nClient with this Account Number Doesn`t exist !" << endl;
        }


        Again = in::AskY_N("\nDo you want to update other clients info? y/n?");

    } while (Again == "y" || Again == "Y");

}


void FindHeader()
{
    cout << "\n--------------------------------" << endl;
    cout << "       Find Client Screen" << endl;
    cout << "--------------------------------\n";
}

void ShowClientInfo(vector<stClientData>& vAllClients)
{
    stClientData Client;
    string Again = "";
    string ClientID = "";

    do
    {
        system("cls");
        FindHeader();

        ClientID = in::ReadString("\nPlease enter Account Number: ");
        if (IsClientFound(vAllClients, Client, ClientID))
        {
            cout << "\nClient Details: " << endl;
            PrintDataRecord(Client);
        }
        else
        {
            cout << "\nClient with this Account Number Doesn`t exist !" << endl;
        }


        Again = in::AskY_N("\nDo you want to find other clients info? y/n?");

    } while (Again == "y" || Again == "Y");
}



void DepositHeader()
{
    cout << "\n--------------------------------" << endl;
    cout << "        Deposit Screen" << endl;
    cout << "--------------------------------\n";
}

void DepositToClient(vector<stClientData>& vAllClients, string ClientID, double Amount)
{
    string sure = "";

    sure = in::AskY_N("\nAre you sure you want to perform this transaction ? y/n?");

    if (sure == "y" || sure == "Y")
    {
        for (stClientData& record : vAllClients)
        {
            if (record.ID == ClientID)
            {
                record.AcctBalance += Amount;
                break;
            }
        }

        cout << "\nTransaction performed successfully !!" << endl;
    }

}

void ShowNewBalance(vector<stClientData>& vAllClients, string ClientID)
{
    for (stClientData& record : vAllClients)
    {
        if (record.ID == ClientID)
        {
            cout << "\nNew Balance: " << record.AcctBalance << " SAR" << endl;
            break;
        }
    }
}

void DepositProcess(vector<stClientData>& vAllClients)
{
    string ClientID = "";
    string Again = "";
    stClientData Client;
    double DepositAmount = 0;

    do
    {
        system("cls");
        DepositHeader();
        ClientID = in::ReadString("\nPlease enter Account Number:");

        if (IsClientFound(vAllClients, Client, ClientID))
        {
            cout << "\nClient Details: " << endl;
            PrintDataRecord(Client);

            DepositAmount = ReadAmount("Please enter deposit amount:");
            DepositToClient(vAllClients, ClientID, DepositAmount);

            LoadVectorToFile(vAllClients);
            vAllClients = LoadDataFromFile(ClientBase);

            ShowNewBalance(vAllClients, ClientID);
        }
        else
        {
            cout << "\nClient with this Account Number Doesn`t exist !" << endl;
        }

        Again = in::AskY_N("\nDo you want to deposit to other clients? y/n?");

    } while (Again == "y" || Again == "Y");


}


void WithdrawHeader()
{
    cout << "\n--------------------------------" << endl;
    cout << "        Withdraw Screen" << endl;
    cout << "--------------------------------\n";
}

void WithdrawFromClient(vector<stClientData>& vAllClients, string ClientID, double Amount)
{
    string sure = "";

    sure = in::AskY_N("\nAre you sure you want to perform this transaction ? y/n?");

    if (sure == "y" || sure == "Y")
    {
        for (stClientData& record : vAllClients)
        {
            if (record.ID == ClientID)
            {
                record.AcctBalance -= Amount;
                break;
            }
        }

        cout << "\nTransaction performed successfully !!" << endl;
    }

}

void WithdrawProcess(vector<stClientData>& vAllClients)
{
    string ClientID = "";
    string Again = "";
    stClientData Client;
    double WithdrawAmount = 0;

    do
    {
        system("cls");
        WithdrawHeader();
        ClientID = in::ReadString("\nPlease enter Account Number:");

        if (IsClientFound(vAllClients, Client, ClientID))
        {
            cout << "\nClient Details: " << endl;
            PrintDataRecord(Client);

            WithdrawAmount = ReadAmount("\nPlease enter Withdraw amount:");
            while (WithdrawAmount > Client.AcctBalance)
            {
                cout << "\nAmount exceeds the balance, you can withdraw up to: " << Client.AcctBalance << endl;
                WithdrawAmount = ReadAmount("Please enter Withdraw amount:");
            }

            WithdrawFromClient(vAllClients, ClientID, WithdrawAmount);

            LoadVectorToFile(vAllClients);
            vAllClients = LoadDataFromFile(ClientBase);

            ShowNewBalance(vAllClients, ClientID);
        }
        else
        {
            cout << "\nClient with this Account Number Doesn`t exist !" << endl;
        }

        Again = in::AskY_N("\nDo you want to withdraw from other clients? y/n?");

    } while (Again == "y" || Again == "Y");

}


void TransactionScreen(string Username)
{
    cout << "Current User: " << Username << endl;
    cout << "\n--------------------------------" << endl;
    cout << "     Transaction Menu Screen" << endl;
    cout << "--------------------------------\n";
    cout << "[1] Deposit." << endl;
    cout << "[2] Withdraw." << endl;
    cout << "[3] Total Balances." << endl;
    cout << "[4] Back To Main Menu." << endl;
    cout << "--------------------------------\n";

}

void ShowTotalBalances(const vector<stClientData>& vAllClients)
{
    double TotalBalances = 0;

    cout << "--------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "                                        Balances List (" << vAllClients.size() << ") Clients(s)." << endl;
    cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(18) << "Account Number"
        << "| " << setw(70) << "Client Name"
        << "| " << setw(18) << "Balance" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------\n" << endl;

    if (vAllClients.size() == 0)
    {
        cout << "                  No Clients In The System." << endl;
    }
    else
    {
        for (const stClientData& ClientInfo : vAllClients)
        {
            cout << "| " << setw(18) << ClientInfo.ID
                << "| " << setw(70) << ClientInfo.Name
                << "| " << setw(18) << ClientInfo.AcctBalance << " SAR" << endl;

            TotalBalances += ClientInfo.AcctBalance;
        }
    }
    cout << "\n--------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "\n                                                              Total Balances = " << TotalBalances << " SAR" << endl;

}

void TransactionProcess(vector<stClientData>& vAllClients, string Username)
{
    short Choice;

    do
    {
        system("cls");
        TransactionScreen(Username);
        Choice = in::ReadPositiveNumInRange("Choose what to do from the list [1 to 4]: ", 1, 4);

        if (Choice == enTransChoice::Deposit)
        {
            system("cls");
            DepositProcess(vAllClients);
            system("pause");
        }
        else if (Choice == enTransChoice::Withdraw)
        {
            system("cls");
            WithdrawProcess(vAllClients);
            system("pause");
        }
        else if (Choice == enTransChoice::TotalBalances)
        {
            system("cls");
            ShowTotalBalances(vAllClients);
            system("pause");
        }


    } while (Choice != enTransChoice::BackToMenu);


}




void LoginHeader(string Screen)
{
    if (Screen == "Bank")
    {
        cout << "\n--------------------------------" << endl;
        cout << "          Bank Login Screen" << endl;
        cout << "--------------------------------\n";

    }
    else if (Screen == "ATM")
    {
        cout << "\n--------------------------------" << endl;
        cout << "          ATM Login Screen" << endl;
        cout << "--------------------------------\n";
    }
}

bool IsUserFound(vector<stUser>& vAllUsers, stUser& User)
{
    for (stUser& record : vAllUsers)
    {
        if (record.UserName == User.UserName && record.Password == User.Password)
        {
            User = record;
            return true;
        }
    }
    return false;
}

stUser ReadAndValidateLogin(vector<stUser> vAllUsers)
{
    LoginHeader("Bank");

    stUser User;
    cout << "Enter User Name: "; // Usage of std::ws will extract all the whitespace character  
    getline(cin >> ws, User.UserName);

    cout << "Enter Password: ";
    getline(cin, User.Password);

    while (!IsUserFound(vAllUsers, User))
    {
        system("cls");
        LoginHeader("Bank");
        cout << "Invalid UserName/Password!" << endl;
        cout << "Enter User Name: ";
        getline(cin, User.UserName);
        cout << "Enter Password: ";
        getline(cin, User.Password);
    }
    return User;
}

string ConvertUserRecordToLine(stUser User1, string delim = "#//#")
{
    string str = "";

    str += User1.UserName + delim;
    str += User1.Password + delim;
    str += to_string(User1.Permission);

    return str;
}

stUser ConvertUserLineToRecord(string Line, string Delim = "#//#")
{
    vector<string> Records = str::SplitStringToVector(Line, Delim);
    stUser User;

    User.UserName = Records[0];
    User.Password = Records[1];
    User.Permission = stoi(Records[2]);

    return User;
}

vector<stUser> LoadUsersFromFile(string FilePath)
{
    vector<stUser> vAllUsers;
    fstream File;

    File.open(FilePath, ios::in);

    if (File.is_open())
    {
        string Line = "";
        stUser Record;

        while (getline(File, Line))
        {
            Record = ConvertUserLineToRecord(Line);
            vAllUsers.push_back(Record);
        }

        File.close();
    }

    return vAllUsers;
}


void ShowManageMenu(string Username)
{
    system("cls");
    cout << "Current User: " << Username << endl;
    cout << "===========================================" << endl;
    cout << "             Manage Users Menu Screen" << endl;
    cout << "===========================================" << endl;
    cout << "[1] List Users." << endl;
    cout << "[2] Add New User." << endl;
    cout << "[3] Delete User." << endl;
    cout << "[4] Update User." << endl;
    cout << "[5] Find User." << endl;
    cout << "[6] Main Menu." << endl;
    cout << "===========================================" << endl;
}

void ShowUsersList(const vector<stUser>& vAllUsers)
{
    cout << "--------------------------------------------------------------------------------------------------------------------------\n" << endl;
    cout << "                                        Users List (" << vAllUsers.size() << ") Users(s)." << endl;
    cout << "\n--------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "| " << setw(22) << "User Name"
        << "| " << setw(18) << "Password"
        << "| " << setw(18) << "Permission" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------\n" << endl;

    for (const stUser& UserInfo : vAllUsers)
    {
        cout << "| " << setw(22) << UserInfo.UserName
            << "| " << setw(18) << UserInfo.Password
            << "| " << setw(18) << UserInfo.Permission << endl;


    }
    cout << "\n--------------------------------------------------------------------------------------------------------------------------\n" << endl;
}


bool IsUserNameFound(const vector<stUser>& vAllUsers, string UserName)
{
    for (const stUser& record : vAllUsers)
    {
        if (record.UserName == UserName)
        {
            return true;
        }
    }
    return false;
}

short GivePermission()
{
    short Permission = 0;

    string Full = in::ReadString("\nDo you want to give full access ? y / n ?");
    if (Full == "y" || Full == "Y")
    {
        return Permission = -1;
    }
    else
    {
        string ShowCient = in::ReadString("\nDo you want to give access to Show Clients ? y / n ?");
        if (ShowCient == "y" || ShowCient == "Y")
        {
            Permission = Permission | enPermission::pShowClients;
        }

        string AddClient = in::ReadString("\nDo you want to give access to Add New Clients ? y / n ?");
        if (AddClient == "y" || AddClient == "Y")
        {
            Permission = Permission | enPermission::pAddClient;
        }

        string DeleteClient = in::ReadString("\nDo you want to give access to Delete Clients ? y / n ?");
        if (DeleteClient == "y" || DeleteClient == "Y")
        {
            Permission = Permission | enPermission::pDeleteClient;
        }

        string UpdateClients = in::ReadString("\nDo you want to give access to Update Clients ? y / n ?");
        if (UpdateClients == "y" || UpdateClients == "Y")
        {
            Permission = Permission | enPermission::pUpdateClient;
        }

        string FindClient = in::ReadString("\nDo you want to give access to Find Clients ? y / n ?");
        if (FindClient == "y" || FindClient == "Y")
        {
            Permission = Permission | enPermission::pFindClient;
        }

        string Transactions = in::ReadString("\nDo you want to give access to Transactions ? y / n ?");
        if (Transactions == "y" || Transactions == "Y")
        {
            Permission = Permission | enPermission::pTransaction;
        }

        string Managing = in::ReadString("\nDo you want to give access to Manage Clients ? y / n ?");
        if (Managing == "y" || Managing == "Y")
        {
            Permission = Permission | enPermission::pManageUsers;
        }
    }

    return Permission;
}

stUser ReadNewUser(const vector<stUser>& vAllUsers)
{
    stUser User;
    cout << "Enter User Name: "; // Usage of std::ws will extract all the whitespace character  
    getline(cin >> ws, User.UserName);

    while (IsUserNameFound(vAllUsers, User.UserName))
    {
        cout << "User with [" << User.UserName << "] Already Exists!" << endl;
        cout << "Enter Another User Name: ";
        getline(cin, User.UserName);
    }

    cout << "Enter Password: ";
    getline(cin, User.Password);

    User.Permission = GivePermission();

    return User;
}

void AddUserHeader()
{
    cout << "\n--------------------------------" << endl;
    cout << "       Add New User Screen" << endl;
    cout << "--------------------------------\n";
}

void AddNewUserProcess(vector<stUser>& vAllUsers)
{
    string Again = "";
    fstream File;
    File.open(UserBase, ios::out | ios::app);

    do
    {
        system("cls");
        AddUserHeader();

        if (File.is_open())
        {
            stUser NewUser = ReadNewUser(vAllUsers);
            string Line = ConvertUserRecordToLine(NewUser);
            File << Line << endl;

        }

        cout << "\nUser Added Successfully !" << endl;

        vAllUsers = LoadUsersFromFile(UserBase);

        Again = in::AskY_N("\nDo you want to add more Users? y/n?");

    } while (Again == "y" || Again == "Y");

    File.close();
}


void PrintUserRecord(stUser User)
{
    cout << "\n--------------------------------" << endl;
    cout << "Username  : " << User.UserName << endl;
    cout << "Password  : " << User.Password << endl;
    cout << "Permission: " << User.Permission << endl;
    cout << "--------------------------------\n" << endl;
}

void DeleteUserHeader()
{
    cout << "\n--------------------------------" << endl;
    cout << setw(50) << "Delete User Screen" << endl;
    cout << "--------------------------------\n" << endl;
}

void MarkUserForDelete(vector<stUser>& vAllUsers, string UserName)
{
    for (stUser& record : vAllUsers)
    {
        if (record.UserName == UserName)
        {
            record.MarkForDelete = true;
            break;
        }
    }
}

void UpdateUsersAfterDelete(vector<stUser>& vAllUsers, string UserName)
{
    string Line = "";
    fstream File;
    File.open(UserBase, ios::out);

    if (File.is_open())
    {
        for (stUser& record : vAllUsers)
        {
            if (record.MarkForDelete == false)
            {
                Line = ConvertUserRecordToLine(record);
                File << Line << endl;
            }
        }

        File.close();
    }
}

void DeleteOneUser(vector<stUser>& vAllUsers, string UserName)
{
    MarkUserForDelete(vAllUsers, UserName);
    UpdateUsersAfterDelete(vAllUsers, UserName);
}

bool IsUserNameFound(const vector<stUser>& vAllUsers, string UserName, stUser& ToBeFilled)
{
    for (const stUser& record : vAllUsers)
    {
        if (record.UserName == UserName)
        {
            ToBeFilled = record;
            return true;
        }
    }
    return false;
}

void DeleteUserProcess(vector<stUser>& vAllUsers)
{
    stUser User;
    string Again = "";
    string sure = "";
    string UserName = "";


    do
    {
        system("cls");
        DeleteUserHeader();

        UserName = in::ReadString("\nPlease enter Username: ");

        if (UserName == "Admin")
        {
            cout << "\nAdmin Cannot be Deleted!" << endl;
            break;
        }

        if (IsUserNameFound(vAllUsers, UserName, User))
        {
            PrintUserRecord(User);

            sure = in::AskY_N("\nAre you sure you want to delete this User ? y/n ? ");
            if (sure == "y" || sure == "Y")
            {
                DeleteOneUser(vAllUsers, UserName);
                vAllUsers = LoadUsersFromFile(UserBase);
                cout << "\nUser Deleted Successfully !" << endl;
            }
        }
        else
        {
            cout << "\nUser with this Username Doesn`t exist !" << endl;
        }


        Again = in::AskY_N("\nDo you want to delete other Users? y/n?");

    } while (Again == "y" || Again == "Y");

}


void UpdateUserHeader()
{
    cout << "\n--------------------------------" << endl;
    cout << "    Update User Info Screen" << endl;
    cout << "--------------------------------\n";
}

stUser ReadUserRecordUpdate(string UserName)
{
    stUser User;

    User.UserName = UserName;

    cout << "Enter New Password? ";
    getline(cin >> ws, User.Password);

    User.Permission = GivePermission();

    return User;
}

void UpdateOneUser(vector<stUser>& vAllUsers, string UserName)
{
    for (stUser& record : vAllUsers)
    {
        if (record.UserName == UserName)
        {
            record = ReadUserRecordUpdate(UserName);
            break;
        }
    }
}

void LoadVectorToFile(vector<stUser>& vAllUsers)
{
    string Line = "";
    fstream File;
    File.open(UserBase, ios::out);

    if (File.is_open())
    {
        for (stUser& record : vAllUsers)
        {
            Line = ConvertUserRecordToLine(record);
            File << Line << endl;
        }

        File.close();
    }
}

void UpdateUserProcess(vector<stUser>& vAllUsers)
{
    stUser User;
    string Again = "";
    string sure = "";
    string UserName = "";

    do
    {
        system("cls");
        UpdateUserHeader();

        UserName = in::ReadString("\nPlease enter Username: ");
        if (IsUserNameFound(vAllUsers, UserName, User))
        {
            cout << "\nUser Details: " << endl;
            PrintUserRecord(User);

            sure = in::AskY_N("\nAre you sure you want to update this User ? y/n ? ");
            if (sure == "y" || sure == "Y")
            {
                UpdateOneUser(vAllUsers, UserName);
                LoadVectorToFile(vAllUsers);
                vAllUsers = LoadUsersFromFile(UserBase);
                cout << "\nUser Info Updated Successfully !" << endl;
            }
        }
        else
        {
            cout << "\nUser with this Username Doesn`t exist !" << endl;
        }


        Again = in::AskY_N("\nDo you want to update other Users info? y/n?");

    } while (Again == "y" || Again == "Y");

}



void FindUserHeader()
{
    cout << "\n--------------------------------" << endl;
    cout << "     Find User Screen" << endl;
    cout << "--------------------------------\n";
}

void ShowUserInfoProcess(vector<stUser>& vAllUsers)
{
    stUser User;
    string Again = "";
    string UserName = "";

    do
    {
        system("cls");
        FindUserHeader();

        UserName = in::ReadString("\nPlease enter Username: ");
        if (IsUserNameFound(vAllUsers, UserName, User))
        {
            cout << "\nUser Details: " << endl;
            PrintUserRecord(User);
        }
        else
        {
            cout << "\nUser with this Username Doesn`t exist !" << endl;
        }


        Again = in::AskY_N("\nDo you want to find other Users info? y/n?");

    } while (Again == "y" || Again == "Y");
}


void ManageUsersProcess(vector<stUser>& vAllUsers, string Username)
{
    short Choice = 0;
    do
    {
        system("cls");
        ShowManageMenu(Username);
        Choice = in::ReadPositiveNumInRange("Choose what to do from the list [1 to 6]: ", 1, 6);

        if (Choice == enManageOption::eListUser)
        {
            system("cls");
            ShowUsersList(vAllUsers);
            system("pause");
        }
        else if (Choice == enManageOption::eAddUser)
        {
            system("cls");
            AddNewUserProcess(vAllUsers);
            system("pause");
        }
        else if (Choice == enManageOption::eDeleteUser)
        {
            system("cls");
            DeleteUserProcess(vAllUsers);
            system("pause");
        }
        else if (Choice == enManageOption::eUpdateUser)
        {
            system("cls");
            UpdateUserProcess(vAllUsers);
            system("pause");
        }
        else if (Choice == enManageOption::eFindUser)
        {
            system("cls");
            ShowUserInfoProcess(vAllUsers);
            system("pause");
        }
        else
        {
            break;
        }


    } while (Choice != enManageOption::eMainMenu);
}



void PrintDeniedAccess()
{
    cout << "Access denied!" << endl;
    cout << "You have no permission to access this option." << endl;
    cout << "Contact the Admin for more info." << endl;
}

bool HasPermission(short Permission, enPermission Access)
{
    return (Permission == -1) || (Permission & Access);
}

void StartBankSystem(vector<stUser>& vAllUsers, stUser User)
{
    vector<stClientData> vAllClients = LoadDataFromFile(ClientBase);
    short Choice = 0;

    do
    {
        system("cls");
        ShowMenu("Bank", User.UserName);
        Choice = in::ReadPositiveNumInRange("Choose what to do from the list [1 to 8]: ", 1, 8);

        if (Choice == enChoice::eShowList)
        {
            if (HasPermission(User.Permission, enPermission::pShowClients))
            {
                system("cls");
                ShowClientsList(vAllClients);
                system("pause");
            }
            else
            {
                system("cls");
                PrintDeniedAccess();
                system("pause");
            }
        }
        else if (Choice == enChoice::eAddClient)
        {
            if (HasPermission(User.Permission, enPermission::pAddClient))
            {
                system("cls");
                AddNewClient(vAllClients);
                system("pause");
            }
            else
            {
                system("cls");
                PrintDeniedAccess();
                system("pause");
            }
        }
        else if (Choice == enChoice::eDeleteClient)
        {
            if (HasPermission(User.Permission, enPermission::pDeleteClient))
            {
                system("cls");
                DeleteClientProcess(vAllClients);
                system("pause");
            }
            else
            {
                system("cls");
                PrintDeniedAccess();
                system("pause");
            }
        }
        else if (Choice == enChoice::eUpdateClient)
        {
            if (HasPermission(User.Permission, enPermission::pUpdateClient))
            {
                system("cls");
                UpdateClientInfo(vAllClients);
                system("pause");
            }
            else
            {
                system("cls");
                PrintDeniedAccess();
                system("pause");
            }
        }
        else if (Choice == enChoice::eFindClient)
        {
            if (HasPermission(User.Permission, enPermission::pFindClient))
            {
                system("cls");
                ShowClientInfo(vAllClients);
                system("pause");
            }
            else
            {
                system("cls");
                PrintDeniedAccess();
                system("pause");
            }
        }
        else  if (Choice == enChoice::eTransaction)
        {
            if (HasPermission(User.Permission, enPermission::pTransaction))
            {
                system("cls");
                TransactionProcess(vAllClients, User.UserName);
            }
            else
            {
                system("cls");
                PrintDeniedAccess();
                system("pause");
            }
        }
        else if (Choice == enChoice::eManageUsers)
        {
            if (HasPermission(User.Permission, enPermission::pManageUsers))
            {
                system("cls");
                ManageUsersProcess(vAllUsers, User.UserName);
            }
            else
            {
                system("cls");
                PrintDeniedAccess();
                system("pause");
            }
        }
        else
        {
            break;
        }

    } while (Choice != enChoice::eLogout);

}

void BankSystemLogin()
{
    vector<stUser> vAllUsers = LoadUsersFromFile(UserBase);

    system("cls");
    stUser User;

    User = ReadAndValidateLogin(vAllUsers);

    StartBankSystem(vAllUsers, User);
}

// ======================================= ATM System 

enum enATMChoice { eQuickWithdraw = 1, eNormalWithdraw = 2, eDeposit = 3, eCheckBalance = 4, eTransfer = 5, eTransHistory = 6, eViewInfo = 7, eATMLogout = 8};
enum enQuickWithdrawAmount { e20 = 1, e50 = 2, e100 = 3, e200 = 4, e400 = 5, e600 = 6, e800 = 7, e1000 = 8, eExit = 9 };


stDate StringToStDate(string str, string delim = "/")
{
    vector<string> vWords;

    short pos = 0;
    string sWord;

    while ((pos = str.find(delim)) != string::npos)
    {
        sWord = str.substr(0, pos);

        if (sWord != "")
            vWords.push_back(sWord);

        str.erase(0, pos + delim.length());
    }

    if (str != "")
        vWords.push_back(str);

    stDate Date = { 0, 0, 0 };

    if (vWords.size() >= 3)
    {
        Date.day = stoi(vWords[0]);
        Date.month = stoi(vWords[1]);
        Date.year = stoi(vWords[2]);
    }

    return Date;
}

string stDateToString(stDate Date, string delim = "/")
{
    string str = "";

    str = to_string(Date.day) + delim + to_string(Date.month) + delim + to_string(Date.year);


    return str;
}

string ConvertClientHistoryRecordToLine(stHistory HistoryRecord, string delim = "#//#")
{
    string str = "";

        str += HistoryRecord.ID + delim;
        str += stDateToString(HistoryRecord.DateOfTrans) + delim;
        str += to_string(HistoryRecord.AmountOfTrans) + delim;
        str += HistoryRecord.SenderID + delim;
        str += HistoryRecord.RecipientID;
        
    return str;
}

stHistory ConvertClientHistoryLineToRecord(string Line, string Delim = "#//#")
{
    vector<string> Records = str::SplitStringToVector(Line, Delim);
    stHistory History;

    History.ID = Records[0];
    History.DateOfTrans = StringToStDate(Records[1]);
    History.AmountOfTrans = stoi(Records[2]);
    History.SenderID = Records[3];
    History.RecipientID = Records[4];
    

    return History;
}

vector<stHistory> LoadClientHistoryFromFile(string FilePath, stClientData& Client)
{
    vector<stHistory> vClientHistory;
    fstream File;

    File.open(FilePath, ios::in);

    if (File.is_open())
    {
        string Line = "";
        stHistory Record;

        while (getline(File, Line))
        {
            Record = ConvertClientHistoryLineToRecord(Line);

            if (Record.ID == Client.ID)
            {
                vClientHistory.push_back(Record);
            }
        }

        File.close();
    }

    return vClientHistory;
}

stDate GetSystemDate()
{
    stDate Date;

    time_t t = time(0);
    tm* now = localtime(&t);

    Date.day = now->tm_mday;
    Date.month = now->tm_mon + 1;
    Date.year = now->tm_year + 1900;

    return Date;
}

stHistory FillTransctionInfo(stClientData& Client, double Amount, bool IsExternal = false)
{
    stHistory NewHistory;
    NewHistory.ID = (IsExternal) ? Client.TransHistory.RecipientID : Client.TransHistory.SenderID;
    NewHistory.DateOfTrans = GetSystemDate();
    NewHistory.AmountOfTrans = Amount;
    NewHistory.SenderID = Client.TransHistory.SenderID;
    NewHistory.RecipientID = Client.TransHistory.RecipientID;

    return NewHistory;
}

void SaveTransactionHistory(stClientData& Client, double Amount, bool IsExternal = false)
{
    fstream File;
    File.open(TransBase, ios::out | ios::app);
    
    if (File.is_open())
    {
        stHistory NewHistory;
        NewHistory = FillTransctionInfo(Client, Amount);

        string Line = ConvertClientHistoryRecordToLine(NewHistory);
        File << Line << endl;

        if (IsExternal)
        {
            stHistory RecipientHistory = FillTransctionInfo(Client, Amount, IsExternal);
            string Line = ConvertClientHistoryRecordToLine(RecipientHistory);
            File << Line << endl;
        }
        File.close();
    }
}

void TransHistoryProcess(stClientData& Client)
{
    vector<stHistory> vClientHistory = LoadClientHistoryFromFile(TransBase, Client);

    cout << "Transaction History of Account Number " << Client.ID << "\n\n" << endl;

    for (stHistory& record : vClientHistory)
    {
        if (record.SenderID != record.RecipientID)
            cout << "[" << stDateToString(record.DateOfTrans) << "] External Transaction From " << record.SenderID << " To " << record.RecipientID << " : " << record.AmountOfTrans << " SAR" << endl;
        else
            cout << "[" << stDateToString(record.DateOfTrans) << "] Internal Transaction: " << record.AmountOfTrans << " SAR" << endl;

    }

    cout << "\n\n";
}



bool IsClientFound(vector<stClientData>& vAllClients, stClientData& Client, string ClientID, string ClientPIN)
{
    for (stClientData& record : vAllClients)
    {
        if (record.ID == ClientID && record.PINCode == ClientPIN)
        {
            Client = record;
            return true;
        }
    }
    return false;
}

stClientData ReadAndValidateClientLogin(vector<stClientData> vAllClients)
{
    LoginHeader("ATM");

    stClientData Client;
    cout << "Enter Account Number: "; // Usage of std::ws will extract all the whitespace character  
    getline(cin >> ws, Client.ID);

    cout << "Enter PIN Code: ";
    getline(cin, Client.PINCode);

    while (!IsClientFound(vAllClients, Client, Client.ID, Client.PINCode))
    {
        system("cls");
        LoginHeader("ATM");
        cout << "Invalid AccountNumber/PINCode!" << endl;
        cout << "Enter Account Number: ";
        getline(cin, Client.ID);
        cout << "Enter PIN Code: ";
        getline(cin, Client.PINCode);
    }
    return Client;
}


void CheckBalanceProcess(vector<stClientData>& vAllClients, stClientData Client)
{
    cout << "\n--------------------------------" << endl;
    cout << "      Check Balance Screen" << endl;
    cout << "--------------------------------\n";

    for (stClientData& record : vAllClients)
    {
        if (record.ID == Client.ID)
        {
            cout << "\nYour Balance is: " << record.AcctBalance << " SAR" << endl;
            break;
        }
    }
}


void QuickWihdrawMenu(stClientData Client)
{
    cout << "===========================================" << endl;
    cout << "              Quick Wihdraw" << endl;
    cout << "===========================================" << endl;
    cout << "[1] 20               [2] 50" << endl;
    cout << "[3] 100              [4] 200" << endl;
    cout << "[5] 400              [6] 600" << endl;
    cout << "[7] 800              [8] 1000" << endl;
    cout << "[9] Exit" << endl;
    cout << "===========================================" << endl;
    cout << "Your Balance is: " << Client.AcctBalance << endl;
}

bool HasEnoughBalance(stClientData Client, short Choice)
{
    if (Choice == enQuickWithdrawAmount::e20)
        return (Client.AcctBalance >= 20);
    else if (Choice == enQuickWithdrawAmount::e50)
        return (Client.AcctBalance >= 50);
    else if (Choice == enQuickWithdrawAmount::e100)
        return (Client.AcctBalance >= 100);
    else if (Choice == enQuickWithdrawAmount::e200)
        return (Client.AcctBalance >= 200);
    else if (Choice == enQuickWithdrawAmount::e400)
        return (Client.AcctBalance >= 400);
    else if (Choice == enQuickWithdrawAmount::e600)
        return (Client.AcctBalance >= 600);
    else if (Choice == enQuickWithdrawAmount::e800)
        return (Client.AcctBalance >= 800);
    else if (Choice == enQuickWithdrawAmount::e1000)
        return (Client.AcctBalance >= 1000);
    else
        return false;
}

double EnumToWithdrawAmount(short Choice)
{
    if (Choice == enQuickWithdrawAmount::e20)
        return  20;
    else if (Choice == enQuickWithdrawAmount::e50)
        return 50;
    else if (Choice == enQuickWithdrawAmount::e100)
        return 100;
    else if (Choice == enQuickWithdrawAmount::e200)
        return 200;
    else if (Choice == enQuickWithdrawAmount::e400)
        return 400;
    else if (Choice == enQuickWithdrawAmount::e600)
        return 600;
    else if (Choice == enQuickWithdrawAmount::e800)
        return 800;
    else if (Choice == enQuickWithdrawAmount::e1000)
        return 1000;
}

void QuickWithdrawProcess(vector<stClientData>& vAllClients, stClientData& Client)
{
    QuickWihdrawMenu(Client);

    Client.TransHistory.SenderID = Client.ID;
    Client.TransHistory.RecipientID = Client.ID;
    short Choice = 0;
    double Amount = 0;

    Choice = in::ReadPositiveNumInRange("Choose Withdraw amount from the menu [1] to [8]:", 1, 9);

    if (Choice == enQuickWithdrawAmount::eExit)
        return;

    while (!HasEnoughBalance(Client, Choice))
    {
        cout << "\nAmount exceeds the balance, you can withdraw up to: " << Client.AcctBalance << endl;
        Choice = in::ReadPositiveNumInRange("Choose Withdraw amount from the menu [1] to [8]:", 1, 9);
    }
    Amount = EnumToWithdrawAmount(Choice);
    WithdrawFromClient(vAllClients, Client.ID, Amount);

    SaveTransactionHistory(Client , Amount * -1);


    LoadVectorToFile(vAllClients);
    vAllClients = LoadDataFromFile(ClientBase);

    ShowNewBalance(vAllClients, Client.ID);

}


void NormalWithdrawHeader(stClientData& Client)
{
    cout << "===========================================" << endl;
    cout << "             Normal Wihdraw" << endl;
    cout << "===========================================" << endl;
    cout << "Your Balance is: " << Client.AcctBalance << endl;
}

void NormalWithdrawProcess(vector<stClientData>& vAllClients, stClientData& Client)
{
    NormalWithdrawHeader(Client);

    Client.TransHistory.SenderID = Client.ID;
    Client.TransHistory.RecipientID = Client.ID;
    double WithdrawAmount = 0;

    WithdrawAmount = ReadAmount("\nPlease enter an amount multiple of 5:");
    while (WithdrawAmount > Client.AcctBalance || ((int)WithdrawAmount % 5 != 0))
    {
        cout << "\nAmount is not multiple of 5 or exceeds the balance, you can withdraw up to: " << Client.AcctBalance << endl;
        WithdrawAmount = ReadAmount("Please enter an amount multiple of 5:");
    }

    WithdrawFromClient(vAllClients, Client.ID, WithdrawAmount);

    SaveTransactionHistory(Client, WithdrawAmount * -1);

    LoadVectorToFile(vAllClients);
    vAllClients = LoadDataFromFile(ClientBase);

    ShowNewBalance(vAllClients, Client.ID);

}


void ATMDepositHeader(stClientData& Client)
{
    cout << "===========================================" << endl;
    cout << "                 Deposit" << endl;
    cout << "===========================================" << endl;
    cout << "Your Balance is: " << Client.AcctBalance << endl;
}

void DepositProcess(vector<stClientData>& vAllClients, stClientData& Client)
{
    ATMDepositHeader(Client);

    Client.TransHistory.SenderID = Client.ID;
    Client.TransHistory.RecipientID = Client.ID;
    double DepositAmount = 0;

    DepositAmount = ReadAmount("Please enter deposit amount:");
    DepositToClient(vAllClients, Client.ID, DepositAmount);

    SaveTransactionHistory(Client, DepositAmount);

    LoadVectorToFile(vAllClients);
    vAllClients = LoadDataFromFile(ClientBase);

    ShowNewBalance(vAllClients, Client.ID);
}


void TransferMoneyHeader(stClientData& Client)
{
    cout << "===========================================" << endl;
    cout << "              Transfer Money" << endl;
    cout << "===========================================" << endl;
    cout << "Your Balance is: " << Client.AcctBalance << endl;
}

void TranferFromClientToClient(vector<stClientData>& vAllClients, stClientData& Sender, double TransferAmount)
{
    bool AddDone = false;
    bool SubDone = false;

    for (stClientData& record : vAllClients)
    {
        if (record.ID == Sender.ID)
        {
            record.AcctBalance -= TransferAmount;
            SubDone = true;
        }

        if (record.ID == Sender.TransHistory.RecipientID)
        {
            record.AcctBalance += TransferAmount;
            AddDone = true;
        }

        if (AddDone == true && SubDone == true)
            break;
    }
}

void TransferMoneyProcess(vector<stClientData>& vAllClients, stClientData& Client)
{
    stClientData Recipient;
    string sure = "";
    string Again = "";
    double TransferAmount = 0;

    do
    {
        system("cls");
        TransferMoneyHeader(Client);

        Client.TransHistory.SenderID = Client.ID;
        Client.TransHistory.RecipientID = in::ReadString("\nPlease enter Account Number of The Recipient: ");

        if (IsClientFound(vAllClients, Recipient, Client.TransHistory.RecipientID))
        {
            TransferAmount = ReadAmount("Please enter Transfer amount:");
            while (TransferAmount > Client.AcctBalance)
            {
                cout << "\nAmount exceeds your balance, you can transfer up to: " << Client.AcctBalance << endl;
                TransferAmount = ReadAmount("Please enter Transfer amount:");
            }

            
            sure = in::AskY_N("\nAre you sure you want to perform this transaction ? y/n?");
            if (sure == "y" || sure == "Y")
            {
                TranferFromClientToClient(vAllClients, Client, TransferAmount);
                cout << "\nMoney Transfered Successfully !" << endl;

                SaveTransactionHistory(Client, TransferAmount, true);

                LoadVectorToFile(vAllClients);
                vAllClients = LoadDataFromFile(ClientBase);

                ShowNewBalance(vAllClients, Client.ID);
            }
        }
        else
        {
            cout << "\nClient with this Account Number Doesn`t exist !" << endl;
        }

        Again = in::AskY_N("\nDo you want to make another transaction? y/n?");

    } while (Again == "y" || Again == "Y");
}


void StartATMSystem(vector<stClientData>& vAllClients, stClientData& Client)
{
    short Choice = 0;

    do
    {
        system("cls");
        ShowMenu("ATM", Client.ID);
        Choice = in::ReadPositiveNumInRange("Choose what to do from the list [1 to 8]: ", 1, 8);

        if (Choice == enATMChoice::eQuickWithdraw)
        {
                system("cls");
                QuickWithdrawProcess(vAllClients, Client);
                system("pause");
           
        }
        else if (Choice == enATMChoice::eNormalWithdraw)
        {
                system("cls");
                NormalWithdrawProcess(vAllClients, Client);
                system("pause");
           
        }
        else if (Choice == enATMChoice::eDeposit)
        {
            
                system("cls");
                DepositProcess(vAllClients, Client);
                system("pause");
           
        }
        else if (Choice == enATMChoice::eCheckBalance)
        {
            
                system("cls");
                CheckBalanceProcess(vAllClients, Client);
                system("pause");
           
        }
        else if (Choice == enATMChoice::eTransfer)
        {
            
                system("cls");
                TransferMoneyProcess(vAllClients, Client);
                system("pause");
           
        }
        else  if (Choice == enATMChoice::eTransHistory)
        {
            
                system("cls");
                TransHistoryProcess(Client);
                system("pause");
        }
        else if (Choice == enATMChoice::eViewInfo)
        {
            
                system("cls");
                PrintDataRecord(Client);
                system("pause");
        }
        else
        {
            break;
        }

    } while (Choice != enATMChoice::eATMLogout);
}

void ATMSystemLogin()
{
    vector<stClientData> vAllClients = LoadDataFromFile(ClientBase);

    system("cls");
    stClientData Client;

    Client = ReadAndValidateClientLogin(vAllClients);

    StartATMSystem(vAllClients, Client);
}


void MainLoginScreen()
{
    cout << "\n--------------------------------------" << endl;
    cout << "|        Welcome To My Project!      |" << endl;
    cout << "--------------------------------------" << endl;
    cout << "|                                    |" << endl;
    cout << "|          [1] Bank System           |" << endl;
    cout << "|                                    |" << endl;
    cout << "|          [2] ATM System            |" << endl;
    cout << "|                                    |" << endl;
    cout << "|          [3] Shutdown              |" << endl;
    cout << "|                                    |" << endl;
    cout << "--------------------------------------\n" << endl;
    
}

void EndingScreen()
{
    system("cls");
    cout << "\n--------------------------------------" << endl;
    cout << "|      See You In Another Project!   |" << endl;
    cout << "--------------------------------------" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "|          Made By Abdullah.         |" << endl;
    cout << "|                 10/8/2025          |" << endl;
    cout << "|                                    |" << endl;
    cout << "|                                    |" << endl;
    cout << "--------------------------------------\n" << endl;
    system("pause");
}

void MainLogin()
{
    short Screen = 0;

    do 
    {
        system("cls");
        MainLoginScreen();
    
        Screen = in::ReadPositiveNumInRange("Which System Do You Want To Use [1 To 3]: ", 1, 3);
        if (Screen == 1)
        {
            BankSystemLogin();
        }
        else if (Screen == 2)
        {
            ATMSystemLogin();
        }
        else
        {
            EndingScreen();
            break;
        }

    } while (Screen != 3);
}

int main()
{
    
    MainLogin();

    return 0;
}
