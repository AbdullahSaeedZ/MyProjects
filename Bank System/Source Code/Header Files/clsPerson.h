#pragma once

#include <iostream>
#include <string>
using namespace std;


class clsPerson
{
private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _PhoneNumber;

public:

	clsPerson(string FirstName, string LastName, string Email, string PhoneNumber)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}

	string getFullName()
	{
		return _FirstName + " " + _LastName;
	}

	void setFirstName(string Name)
	{
		_FirstName = Name;
	}

	string getFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	void setLastName(string Name)
	{
		_LastName = Name;
	}

	string getLastName()
	{
		return _LastName;
	}

	__declspec(property(get = getLastName, put = setLastName)) string LastName;

	void setEmail(string Email)
	{
		_Email = Email;
	}

	string getEmail()
	{
		return _Email;
	}

	__declspec(property(get = getEmail, put = setEmail)) string Email;

	void setPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}

	string getPhoneNumber()
	{
		return _PhoneNumber;
	}

	__declspec(property(get = getPhoneNumber, put = setPhoneNumber)) string PhoneNumber;

};
