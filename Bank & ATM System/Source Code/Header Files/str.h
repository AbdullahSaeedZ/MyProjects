#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace str
{
    void Print1stLettersOfWords(string str)
    {
        bool IsFirstLetter = true;

        for (int i = 0; i < str.size(); i++)
        {

            if (str[i] != ' ' && IsFirstLetter) // will run only if the it is first letter and it is a letter.
                cout << str[i] << endl;

            IsFirstLetter = (str[i] != ' ') ? false : true; // it will be false for all indexes till a new space comes then it will be true.

        }

    }

    void UppercaseFirstLetters(string& str)
    {
        bool IsFirstLetter = true;

        for (int i = 0; i < str.size(); i++)
        {

            if (str[i] != ' ' && IsFirstLetter)
                str[i] = toupper(str[i]);

            IsFirstLetter = (str[i] != ' ') ? false : true;

        }

    }

    void LowercaseFirstLetters(string& str)
    {
        bool IsFirstLetter = true;

        for (int i = 0; i < str.size(); i++)
        {

            if (str[i] != ' ' && IsFirstLetter)
                str[i] = tolower(str[i]);

            IsFirstLetter = (str[i] != ' ') ? false : true;

        }

    }

    string UppercaseAllString(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = toupper(str[i]);
        }

        return str;
    }

    string LowercaseAllString(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }

        return str;
    }

    char InvertLetterCase(char c)
    {
        return (isupper(c)) ? tolower(c) : toupper(c);
    }

    string InvertAllLettersCase(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = InvertLetterCase(str[i]);
        }

        return str;
    }

    short CountCapitalLetters(string str)
    {
        short Count = 0;

        for (short i = 0; i < str.length(); i++)
        {
            if (isupper(str[i]))
                Count++;
        }

        return Count;
    }

    short CountSmallLetters(string str)
    {
        short Count = 0;

        for (short i = 0; i < str.length(); i++)
        {
            if (islower(str[i]))
                Count++;
        }

        return Count;
    }


    short CountLetterInString(string str, char Letter, bool MatchCase = true)
    {
        short Count = 0;

        for (short i = 0; i < str.length(); i++)
        {
            if (MatchCase)
            {
                if (str[i] == Letter)
                    Count++;

            }
            else
            {
                if (tolower(str[i]) == tolower(Letter))
                    Count++;
            }
        }

        return Count;
    }

    bool IsVowel(char letter)
    {
        char v = tolower(letter);
        return ((v == 'a') || (v == 'e') || (v == 'i') || (v == 'o') || (v == 'u'));
    }

    short CountVowelInString(string str)
    {
        short count = 0;

        for (short i = 0; i < str.length(); i++)
        {
            if (IsVowel(str[i]))
                count++;
        }

        return count;
    }

    void PrintVowelsInString(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (IsVowel(str[i]))
                cout << str[i] << "   ";
        }
    }

    vector<string> SplitStringToVector(string str, string delim = " ")
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

        return vWords;
    }

    string JoinToString(const vector<string>& vWords, string delim)
    {
        string str = "";

        for (const string& word : vWords)
        {
            str = str + word + delim;
        }

        return str.substr(0, str.length() - delim.length());
    }

    string JoinToString(string array[], short length, string delim)
    {
        string str = "";

        for (short i = 0; i < length; i++)
        {
            str = str + array[i] + delim;
        }

        return str.substr(0, str.length() - delim.length());
    }

    string ReverseString(string str)
    {
        vector<string> Vector = SplitStringToVector(str, " ");
        string Reversed = "";

        vector<string>::iterator itr = Vector.end();

        while (itr != Vector.begin())
        {
            itr--;

            Reversed += *itr + " ";
        }



        return Reversed.substr(0, Reversed.length() - 1);

    }

    string ReplaceExactWord(string str, string OldWord, string NewWord)
    {
        short pos = 0;
        while ((pos = str.find(OldWord)) != string::npos)
        {

            str = str.replace(pos, OldWord.length(), NewWord);

        }

        return str;
    }

    string ReplaceWord(string str, string OldWord, string NewWord, bool MatchCase = false)
    {
        vector<string> vWords = SplitStringToVector(str, " ");

        for (string& word : vWords)
        {
            if (MatchCase)
            {
                if (word == OldWord)
                    word = NewWord;
            }
            else
            {
                if (LowercaseAllString(word) == LowercaseAllString(OldWord))
                    word = NewWord;
            }
        }

        str = JoinToString(vWords, " ");

        return str;
    }

    string RemoveAllPunctInString(string str)
    {
        string New = "";

        for (short i = 0; i < str.length(); i++)
        {
            if (!ispunct(str[i]))
                New += str[i];

        }

        return New;
    }







}
