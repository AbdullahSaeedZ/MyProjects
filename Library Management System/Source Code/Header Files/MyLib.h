#pragma once

#include <iostream>
#include <cstdlib>  
#include <ctime>  
#include <string>  
#include <vector>  
#include <fstream>  


using namespace std;


namespace MyLib
{


    string Tabs(short N)
    {
        string t = "\t";

        for (short Counter = 1; Counter <= N; Counter++)
        {
            t += "\t";
        }
        return t;
    }

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

    short GetDigitFreqInNum(int Num, int Digit)
    {
        short Freq = 0, Remainder = 0;

        while (Num > 0)
        {
            Remainder = Num % 10;

            if (Remainder == Digit)
            {
                Freq += 1;
            }

            Num = Num / 10;
        }

        return Freq;
    }

    bool IsPrimeNum(int Number)
    {
        float M = round(Number / 2);
        for (int Counter = 2; Counter <= M; Counter++)
        {
            if (Number % Counter == 0)
                return false;

        }

        return true;
    }

    int GetReverseNum(int Num)
    {
        int New = 0, Remainder = 0;

        while (Num > 0)
        {
            Remainder = Num % 10;
            Num = Num / 10;
            New = New * 10 + Remainder;

        }
        return New;
    }

    bool IsPerfectNum(int Num)
    {
        int Sum = 0;

        for (int Counter = 1; Counter < Num; Counter++)
        {
            if (Num % Counter == 0)
            {
                Sum += Counter;
            }
        }

        return Sum == Num;    // if its true it returns true, if not, it returns false
    }

    void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    // Random Generating

   // srand((unsigned)time(NULL));

    int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };
    char GetRandomCharacter(enCharType Type)
    {

        if (Type == enCharType::CapitalLetter)
            return char(RandomNumber(65, 90));

        else if (Type == enCharType::Digit)
            return char(RandomNumber(49, 57));

        else if (Type == enCharType::SmallLetter)
            return char(RandomNumber(97, 122));

        else
            return char(RandomNumber(33, 47));

    }

    string GetRandomWord(enCharType CharType, short Length)
    {
        string Word = "";

        for (int Counter = 1; Counter <= Length; Counter++)
        {
            Word.append(1, GetRandomCharacter(CharType));
        }

        return Word;
    }

    string GenerateKey()
    {
        string Key = "";

        for (int Counter = 1; Counter <= 4; Counter++)    // 4 is number of slots (how many words in this key to be generated.
        {
            if (Counter == 4) // to eliminate the "-" in the end and exit function.
            {
                return Key = Key + GetRandomWord(enCharType::CapitalLetter, 4);
            }

            Key = Key + GetRandomWord(enCharType::CapitalLetter, 4) + "-";

        }

        return Key;
    }

    void GenerateKeys(int RequiredKeys)
    {
        for (int Counter = 1; Counter <= RequiredKeys; Counter++)
        {
            cout << "Key [" << Counter << "] : " << GenerateKey() << endl;
        }

    }

    // Arrays

    void ReadArray(int Array[100], int& Length)
    {
        Length = ReadPositiveNumber("Enter how many elements do you need: ");

        cout << "Enter value of elements: " << endl;

        for (int Counter = 0; Counter < Length; Counter++)
        {
            cout << "Element [" << Counter + 1 << "] : " << endl;
            cin >> Array[Counter];
        }
    }

    void AddArrayElement(int Array[100], int& Length, int Num)
    {
        Length++;
        Array[Length - 1] = Num;
    }

    void SemiDynamicUserInputArray(int Array[100], int& Length)
    {
        Length = 0;
        bool AddMore = true;

        do
        {
            AddArrayElement(Array, Length, ReadPositiveNumber("Enter a number:"));
            cout << "Do you want to add more numbers? [0] No - [1] Yes" << endl;;
            cin >> AddMore;

        } while (AddMore);
    }

    void PrintArray(int Array[100], int Length)
    {

        for (int Counter = 0; Counter < Length; Counter++)
        {
            cout << Array[Counter] << " ";
        }

        cout << endl;
    }

    void FillRandomNumsInArray(int Array[100], int& Length)
    {
        cout << endl;
        Length = ReadPositiveNumber("Enter how many elements do you need:");
        cout << endl;

        for (int Counter = 0; Counter < Length; Counter++)
        {
            Array[Counter] = RandomNumber(1, 100);
        }
    }

    void FillArrayWith1toN(int Array[100], int& Length)
    {
        Length = ReadPositiveNumber("Enter how many Numbers do you need: ");

        for (int Counter = 0; Counter < Length; Counter++)
        {
            Array[Counter] = Counter + 1;
        }
    }

    void FillArrayWithKeys(string Array[100], int& Length)
    {
        Length = ReadPositiveNumber("Enter how many Keys do you need: ");

        for (int Counter = 0; Counter < Length; Counter++)
        {
            Array[Counter] = GenerateKey();
        }
    }

    int GetFreqOfNumInArray(int Array[100], int NumToCheck, int Length)
    {
        int Freq = 0;

        for (int Counter = 0; Counter < Length; Counter++)
        {
            if (Array[Counter] == NumToCheck)
            {
                Freq++;
            }
        }

        return Freq;
    }

    bool IsNumEven(int Num)
    {
        if (Num % 2 != 0)
            return false;

        return true;
    }

    int GetFreqOfOddNumInArray(int Array[100], int Length)
    {
        int Freq = 0;

        for (int Counter = 0; Counter < Length; Counter++)
        {
            if (!IsNumEven(Array[Counter]))
            {
                Freq++;
            }
        }

        return Freq;
    }

    int FindNumIndexInArray(int Array[100], int Length, int NumToFind)
    {

        for (int Counter = 0; Counter < Length; Counter++)
        {
            if (Array[Counter] == NumToFind)
            {
                return Counter;
            }

        }

        return -1;
    }

    bool IsNumInArray(int Array[100], int Length, int NumToFind)
    {
        return FindNumIndexInArray(Array, Length, NumToFind) != -1;
    }

    int FindMaxArray(int Array[100], int Length)
    {
        int Max = Array[0];

        for (int Counter = 0; Counter < Length; Counter++)
        {
            if (Array[Counter] > Max)
            {

                Max = Array[Counter];
            }
        }

        return Max;
    }

    int FindMinArray(int Array[100], int Length)
    {
        int Min = Array[0];

        for (int Counter = 0; Counter < Length; Counter++)
        {
            if (Array[Counter] < Min)
            {

                Min = Array[Counter];
            }
        }

        return Min;
    }

    int SumAllArray(int Array[100], int Length)
    {
        int Sum = 0;

        for (int Counter = 0; Counter < Length; Counter++)
        {
            Sum += Array[Counter];
        }

        return Sum;
    }

    float AvgAllArray(int Array[100], int Length)
    {
        return (float)SumAllArray(Array, Length) / Length;
    }

    void CopyArray(int Original[100], int Copy[100], int OriginalLength)
    {
        for (int Counter = 0; Counter < OriginalLength; Counter++)
        {
            Copy[Counter] = Original[Counter];
        }
    }

    void CopyArrayUsingAddArrayElement(int Array1[100], int Length1, int Array2[100], int& Length2)
    {
        for (int Counter = 0; Counter < Length1; Counter++)
        {
            AddArrayElement(Array2, Length2, Array1[Counter]);
        }
    }

    void CopyOddNumArrayUsingAddArrayElement(int Array1[100], int Length1, int Array2[100], int& Length2)
    {
        for (int Counter = 0; Counter < Length1; Counter++)
        {
            if (Array1[Counter] % 2 != 0)
                AddArrayElement(Array2, Length2, Array1[Counter]);
        }
    }

    void CopyPrimeNumArrayUsingAddArrayElement(int Array1[100], int Length1, int Array2[100], int& Length2)
    {
        for (int Counter = 0; Counter < Length1; Counter++)
        {
            if (IsPrimeNum(Array1[Counter]))
                AddArrayElement(Array2, Length2, Array1[Counter]);
        }
    }

    void CopyDistinctArrayUsingAddArrayElement(int Array1[100], int Length1, int Array2[100], int& Length2)
    {
        for (int Counter = 0; Counter < Length1; Counter++)
        {
            if (!IsNumInArray(Array2, Length2, Array1[Counter]))
                AddArrayElement(Array2, Length2, Array1[Counter]);
        }
    }

    void CopyArrayInReverseOrder(int Original[100], int Copy[100], int OriginalLength)
    {

        for (int Counter = 0; Counter < OriginalLength; Counter++)
        {
            Copy[Counter] = Original[OriginalLength - 1 - Counter];
        }
    }

    void ShuffleArrayElements(int Array[100], int Length)
    {


        for (int Counter = 0; Counter < Length; Counter++)
        {
            Swap(Array[RandomNumber(0, Length - 1)], Array[RandomNumber(0, Length - 1)]);
        }

    }

    bool IsArrayPalindrome(int Array[100], int Length)
    {
        for (int Counter = 0; Counter < Length / 2; Counter++)
        {
            if (Array[Counter] != Array[Length - 1 - Counter])
            {
                return false;
            }
        }
        return true;
    }

    int CountPositiveNumsInArray(int Array[100], int Length)
    {
        int Freq = 0;

        for (int Counter = 0; Counter < Length; Counter++)
        {
            if (Array[Counter] >= 0)
            {
                Freq++;
            }
        }

        return Freq;

    }


    // Vectors

    void AddElementInVector(vector <int>& vNumbers)
    {
        int Number = 0;
        string Again = " ";
        do
        {
            Number = ReadPositiveNumber("Enter a positive number: ");
            vNumbers.push_back(Number);

            Again = AskY_N("Do you want keep adding? Y/N:");

        } while (Again == "Y" || Again == "y");
    }

    void PrintVectorElements(vector <int>& vNumbers)
    {

        cout << "\nvector Numbers are: " << endl;

        for (int& item : vNumbers)
        {

            printf("%04d  \n", item);
        }
    }


    // Files

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
