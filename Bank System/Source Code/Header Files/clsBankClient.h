#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsDate.h"
#include "clsString.h"
#include "clsUtil.h"
using namespace std;


class clsBankClient : public clsPerson
{

private:

	struct stTransferLog;

	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2, eDeleteMode = 3 };
	enMode _Mode;

	string _AcctNumber;
	string _PinCode;
	float _AcctBalance;


	// static, to be able to be used by a static member (the find function), but in private to limit access to inside class only
	static clsBankClient _getEmptyClientObject()
	{
		return clsBankClient(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertLineToObject(string Line, string Separator = "#//#")
	{
		vector<string> vStr = clsString::SplitStringToVector(Line, Separator);

		return clsBankClient(enMode::eUpdateMode, vStr[0], clsUtil::DecryptText(vStr[1]), vStr[2], vStr[3], vStr[4], vStr[5], stoi(vStr[6]));
	}

	static string _ConvertObjectToLine(clsBankClient Object, string Separator = "#//#")
	{
		string Line = "";

		Line += Object.getAcctNumber() + Separator;
		Line += clsUtil::EncryptText(Object.getPinCode()) + Separator;
		Line += Object.getFirstName() + Separator;
		Line += Object.getLastName() + Separator;
		Line += Object.getEmail() + Separator;
		Line += Object.getPhoneNumber() + Separator;
		Line += to_string(Object.getAcctBalance());

		return Line;
	}

	static vector<clsBankClient> _LoadFileToVector()
	{
		vector<clsBankClient> vClients;

		fstream File;
		File.open("Clients.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsBankClient OneClient = _ConvertLineToObject(Line);
				vClients.push_back(OneClient);
			}

			File.close();
		}

		return vClients;
	}

	static void _SaveVectorToFile(const vector<clsBankClient>& vClients)
	{
		fstream File;
		File.open("Clients.txt", ios::out);

		if (File.is_open())
		{
			string Line;

			for (const clsBankClient& c : vClients)
			{
				if (c._Mode != enMode::eDeleteMode)
				{
					Line = _ConvertObjectToLine(c);
					File << Line << endl;
				}
			}

			File.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient> vClients = _LoadFileToVector();

		for (clsBankClient& c : vClients)
		{
			if (c.getAcctNumber() == getAcctNumber())
			{
				c = *this;
				break;
			}
		}

		_SaveVectorToFile(vClients);
	}

	//

	void _AddDataLineToFile(string DataLine)
	{
		fstream File;

		File.open("Clients.txt", ios::out | ios::app);
		if (File.is_open())
		{

			File << DataLine << endl;

			File.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertObjectToLine(*this));
	}

	//

	string _GetTransferInfoLine(float Amount, clsBankClient& Receiver, string ActiveUserName, string Separator = "#//#")
	{
		return (clsDate::GetSystemDateTimeString() + Separator + this->getAcctNumber() + Separator + Receiver.getAcctNumber()
			+ Separator + to_string(Amount) + Separator + to_string(this->AcctBalance) + Separator + to_string(Receiver.AcctBalance) + Separator + ActiveUserName);
	}


	void _RegisterTransferLog(float Amount, clsBankClient& Receiver, string ActiveUserName)
	{
		string DataLine = _GetTransferInfoLine(Amount, Receiver, ActiveUserName);

		fstream File;
		File.open("TransferLog.txt", ios::out | ios::app);

		if (File.is_open())
		{
			File << DataLine << endl;

			File.close();
		}

	}


	static stTransferLog _convertTransferLineToStructure(string Line, string Separator = "#//#")
	{
		vector<string> vStr = clsString::SplitStringToVector(Line, Separator);
		stTransferLog Record;
		Record.DateTime = vStr[0];
		Record.SenderAcct = vStr[1];
		Record.ReceiverAcct = vStr[2];
		Record.TransferAmount = vStr[3];
		Record.SenderNewBalance = vStr[4];
		Record.ReceiverNewBalance = vStr[5];
		Record.ActiveUser = vStr[6];

		return Record;
	}


public:

	clsBankClient() : clsPerson("", "", "", "")
	{
		_Mode = enMode::eEmptyMode;
		_AcctNumber = "";
		_PinCode = "";
		_AcctBalance = 0.0f;
	}

	clsBankClient(enMode Mode , string AcctNumber, string PinCode, string FirstName, string LastName, string Email, string PhoneNumber, float AcctBalance)
		: clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_AcctNumber = AcctNumber;
		_PinCode = PinCode;
		_AcctBalance = AcctBalance;
	}

	// setters & getters
	
	string getAcctNumber()// Read-only
	{
		return _AcctNumber;
	}


	void setPinCode(string Pin)
	{
		_PinCode = Pin;
	}

	string getPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setAcctBalance(float Num)
	{
		_AcctBalance = Num;
	}

	float getAcctBalance()
	{
		return _AcctBalance;
	}

	__declspec(property(get = getAcctBalance, put = setAcctBalance)) float AcctBalance;

	//

	bool IsEmpty() // to check is the object on empty mode
	{
		return (_Mode == enMode::eEmptyMode);
	}

	/*
	// No UI Related code inside the object.
	void Print()
	{
		cout << "\nClient Card:" << endl;
		cout << "____________________________________" << endl;
		cout << "Acct. Number: " << _AcctNumber << endl;
		cout << "First Name  : " << FirstName << endl; // using property declaration
		cout << "Last Name   : " << LastName << endl;
		cout << "Full Name   : " << getFullName() << endl;
		cout << "Email       : " << Email << endl;
		cout << "Phone       : " << PhoneNumber << endl;
		cout << "Balance     : " << _AcctBalance << " SAR" << endl;
		cout << "Password    : " << _PinCode << endl;
		cout << "____________________________________\n" << endl;
	}
	*/

	// 

	static clsBankClient Find(string AcctNumber) // static, to be used with no objects, to look for client then fill an empty one, if not found fill with empty object on empty mode.
	{
		fstream File;
		
		File.open("Clients.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineToObject(Line);

				if (Client._AcctNumber == AcctNumber)
				{
					File.close();
					return Client;
				}
			}

		}
			File.close();
			return _getEmptyClientObject();
	}

	static clsBankClient Find(string AcctNumber, string PinCode) // using both parameters for Login later.
	{
		fstream File;

		File.open("Clients.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineToObject(Line);

				if (Client.getAcctNumber() == AcctNumber && Client.PinCode == PinCode)
				{
					File.close();
					return Client;
				}
			}

		}
			File.close();
			return _getEmptyClientObject();
	}

	static bool IsClientExist(string AcctNum)
	{
		clsBankClient Client = clsBankClient::Find(AcctNum);
		return (!Client.IsEmpty());
	}

	static bool IsClientExist(clsBankClient& Client, string AcctNum)
	{
		Client = clsBankClient::Find(AcctNum);
		return (!Client.IsEmpty());
	}

	//

	enum enSaveResults { eFailedEmptyObject = 0, eSuccedded = 1, eFiledAcctNumerExist = 2, eFailedInsufficientAmount };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::eEmptyMode:
		{
			return enSaveResults::eFailedEmptyObject;
		}
		case enMode::eUpdateMode:
		{
			_Update();
			return enSaveResults::eSuccedded;
		}
		case enMode::eAddNewMode:
		{
			if (clsBankClient::IsClientExist(_AcctNumber)) //the number is saved in the current object but not yet in the file.
			{
				return enSaveResults::eFiledAcctNumerExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::eUpdateMode; //change the mode after saving new client.
				return enSaveResults::eSuccedded;
			}


		}
		}
	}

	//

	static clsBankClient GetAddNewClientObject(string AcctNumber)
	{
		return clsBankClient(enMode::eAddNewMode, AcctNumber, "", "", "", "", "", 0);
	}

	//

	void Delete()
	{
		vector<clsBankClient> vClients = _LoadFileToVector();
		for (clsBankClient& c : vClients)
		{
			if (c._AcctNumber == this->_AcctNumber)
			{
				c._Mode = enMode::eDeleteMode;
				break;
			}
		}
		_SaveVectorToFile(vClients);
		*this = _getEmptyClientObject();
	}

	//

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadFileToVector();
	}

	//

	static float GetTotalBalances()
	{
		vector<clsBankClient> vClients = _LoadFileToVector();
		float TotalBalances = 0;

		for (clsBankClient& c : vClients)
		{
			TotalBalances += c.AcctBalance;
		}

		return TotalBalances;
	}

	//

	enSaveResults Deposit(float Amount)
	{
		_AcctBalance += Amount;
		return enSaveResults::eSuccedded;
	}

	enSaveResults Withdraw(float Amount)
	{
		if (Amount > _AcctBalance || Amount <= 0)
		{
			return enSaveResults::eFailedInsufficientAmount;
		}
		else
		{
			_AcctBalance -= Amount;
			return enSaveResults::eSuccedded;
		}
	}

	enSaveResults Transfer(float Amount, clsBankClient& Receiver, string ActiveUserName)
	{
		if (this->Withdraw(Amount) == eFailedInsufficientAmount)
			return eFailedInsufficientAmount;
		else
		{
			Receiver.Deposit(Amount);
			_RegisterTransferLog(Amount, Receiver, ActiveUserName);
			return eSuccedded;
		}

	}

	//


	static struct stTransferLog { string DateTime, SenderAcct, ReceiverAcct, TransferAmount, SenderNewBalance, ReceiverNewBalance, ActiveUser; };

	static vector<stTransferLog> GetTransferRecords()
	{
		vector<stTransferLog> vRecords;

		fstream File;
		File.open("TransferLog.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";

			while (getline(File, Line))
			{
				stTransferLog OneRecord = _convertTransferLineToStructure(Line);
				vRecords.push_back(OneRecord);
			}

			File.close();
		}

		return vRecords;
	}

	


};

