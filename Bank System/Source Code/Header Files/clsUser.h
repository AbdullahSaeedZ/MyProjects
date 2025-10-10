#pragma once

// users class, backend code


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;



class clsUser : public clsPerson
{
private:

	struct stLoginRegisterRecord;

	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddNewMode = 2, eDeleteMode = 3 };

	enMode _Mode;
	string _UserName;
	string _Password;
	short _Permission;

	// 

	static clsUser _getEmptyUserObject()
	{
		return clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUser _ConvertLineToObject(string Line, string Separator = "#//#")
	{
		vector<string> vStr = clsString::SplitStringToVector(Line, Separator);

		return clsUser(enMode::eUpdateMode, vStr[0], vStr[1], vStr[2], vStr[3], vStr[4], clsUtil::DecryptText(vStr[5]), stoi(vStr[6]));  // decrypt when fetching from database
	}

	static string _ConvertObjectToLine(clsUser Object, string Separator = "#//#")
	{
		string Line = "";

		Line += Object.getFirstName() + Separator;
		Line += Object.getLastName() + Separator;
		Line += Object.getEmail() + Separator;
		Line += Object.getPhoneNumber() + Separator;
		Line += Object.getUserName() + Separator;
		Line += clsUtil::EncryptText(Object.getPassword()) + Separator; // password encryption before saving to database
		Line += to_string(Object.getPermission());
		
		return Line;
	}

	static vector<clsUser> _LoadFileToVector()
	{
		vector<clsUser> vUsers;

		fstream File;
		File.open("Users.txt", ios::in);

		if (File.is_open())
		{
			string Line;

			while (getline(File, Line))
			{
				clsUser OneUser = _ConvertLineToObject(Line);
				vUsers.push_back(OneUser);
			}

			File.close();
		}

		return vUsers;
	}

	static void _SaveVectorToFile(const vector<clsUser>& vUsers)
	{
		fstream File;
		File.open("Users.txt", ios::out);

		if (File.is_open())
		{
			string Line;

			for (const clsUser& c : vUsers)
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
		vector<clsUser> vUsers = _LoadFileToVector();

		for (clsUser& c : vUsers)
		{
			if (c.getUserName() == getUserName())
			{
				c = *this;
				break;
			}
		}

		_SaveVectorToFile(vUsers);
	}

	//

	void _AddDataLineToFile(string DataLine)
	{
		fstream File;

		File.open("Users.txt", ios::out | ios::app);
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

	string _GetLoginInfoLine(string Separator = "#//#")
	{
		return (clsDate::GetSystemDateTimeString() + Separator + FirstName + Separator + LastName + Separator + UserName + Separator + clsUtil::EncryptText(Password) + Separator + to_string(Permission));
	}
	
	static stLoginRegisterRecord _convertLoginLineToStructure(string Line, string Separator = "#//#")
	{
		vector<string> vStr = clsString::SplitStringToVector(Line, Separator);
		stLoginRegisterRecord Record;
		Record.DateTime = vStr[0];
		Record.FirstName = vStr[1];
		Record.LastName = vStr[2];
		Record.UserName = vStr[3];
		Record.Password = clsUtil::DecryptText(vStr[4]);
		Record.Permission = vStr[5];

		return Record;
	}
	

public:

	enum enPermission { pShowClients = 1, pAddClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransaction = 32, pManageUsers = 64, pLoginRegister = 128, pAll = -1};

	clsUser() : clsPerson("", "", "", "")
	{
		_Mode = enMode::eEmptyMode;
		_UserName = "";
		_Password = "";
		_Permission = 0;
	}

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber, string UserName, string Password, short Permission)
		: clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permission = Permission;
	}


	void setUserName(string Name)
	{
		_UserName = Name;
	}

	string getUserName()
	{
		return _UserName;
	}

	_declspec(property(get = getUserName, put = setUserName)) string UserName;

	void setPassword(string Password)
	{
		_Password = Password;
	}

	string getPassword()
	{
		return _Password;
	}

	_declspec(property(get = getPassword, put = setPassword)) string Password;

	void setPermission(short Permission)
	{
		_Permission = Permission;
	}

	short getPermission()
	{
		return _Permission;
	}

	_declspec(property(get = getPermission, put = setPermission)) short Permission;

	//

	bool IsEmpty() // to check is the object on empty mode
	{
		return (_Mode == enMode::eEmptyMode);
	}

	static clsUser Find(string UserName) // static, to be used with no objects, to look for User then fill an empty one, if not found fill with empty object on empty mode.
	{
		fstream File;

		File.open("Users.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsUser User = _ConvertLineToObject(Line);

				if (User.UserName == UserName)
				{
					File.close();
					return User;
				}
			}
			File.close();
		}
		return _getEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password) // using both parameters for Login later.
	{
		fstream File;

		File.open("Users.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsUser User = _ConvertLineToObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					File.close();
					return User;
				}
			}
			File.close();
		}
		return _getEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	static bool IsUserExist(clsUser& User, string UserName)
	{
		User = clsUser::Find(UserName);
		return (!User.IsEmpty());
	}

	static bool IsUserExist(clsUser& User, string UserName, string Password)
	{
		User = clsUser::Find(UserName, Password);
		return (!User.IsEmpty());
	}


	//

	enum enSaveResults { eFailedEmptyObject = 0, eSuccedded = 1, eFiledUserNameExist = 2 };

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
			if (clsUser::IsUserExist(UserName)) //the UserName is saved in the current object but not yet in the file.
			{
				return enSaveResults::eFiledUserNameExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::eUpdateMode; //change the mode after saving new User.
				return enSaveResults::eSuccedded;
			}


		}
		}
	}

	//

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::eAddNewMode, "", "", "", "", UserName, "", 0);
	}

	void Delete()
	{
		vector<clsUser> vUsers = _LoadFileToVector();
		for (clsUser& c : vUsers)
		{
			if (c.UserName == this->UserName)
			{
				c._Mode = enMode::eDeleteMode;
				break;
			}
		}
		_SaveVectorToFile(vUsers);
		*this = _getEmptyUserObject();
	}

	//

	static vector<clsUser> GetUsersList()
	{
		return _LoadFileToVector();
	}


	//

	static void GivePermissions(clsUser& User)
	{
		cout << "\nEnter Permissions: " << endl;

		if (clsInputValidate::ReadBoolean("\nFull Access?"))
		{
			User.Permission = -1;
			return;
		}

		if (clsInputValidate::ReadBoolean("\nAccess To Show Clients?"))
		{
			User.Permission += enPermission::pShowClients;
		}

		if (clsInputValidate::ReadBoolean("\nAccess To Add Clients?"))
		{
			User.Permission += enPermission::pAddClient;
		}

		if (clsInputValidate::ReadBoolean("\nAccess To Delete Clients?"))
		{
			User.Permission += enPermission::pDeleteClient;
		}

		if (clsInputValidate::ReadBoolean("\nAccess To Update Clients?"))
		{
			User.Permission += enPermission::pUpdateClient;
		}

		if (clsInputValidate::ReadBoolean("\nAccess To Find Clients?"))
		{
			User.Permission += enPermission::pFindClient;
		}

		if (clsInputValidate::ReadBoolean("\nAccess To Transactions?"))
		{
			User.Permission += enPermission::pTransaction;
		}

		if (clsInputValidate::ReadBoolean("\nAccess To Manage Users?"))
		{
			User.Permission += enPermission::pManageUsers;
		}

		if (clsInputValidate::ReadBoolean("\nAccess To Login Register?"))
		{
			User.Permission += enPermission::pLoginRegister;
		}
	}

	//

	void RegisterLogin()
	{
		fstream File;
		File.open("LoginRegister.txt", ios::out | ios::app);

		if (File.is_open())
		{
			string UserLogin = _GetLoginInfoLine();
			File << UserLogin << endl;

			File.close();
		}
	}

	static struct stLoginRegisterRecord { string DateTime, FirstName, LastName, UserName, Password, Permission; };

	static vector<stLoginRegisterRecord> GetLoginRegisterRecords()
	{
		vector<stLoginRegisterRecord> vRecords;

		fstream File;
		File.open("LoginRegister.txt", ios::in);

		if (File.is_open())
		{
			string Line = "";

			while (getline(File, Line))
			{
				stLoginRegisterRecord OneRecord = _convertLoginLineToStructure(Line);
				vRecords.push_back(OneRecord);
			}

			File.close();
		}

		return vRecords;
	}



};

