#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include <vector>
#include <string>
using namespace std;


class clsUtil
{
public:


    // Numbers

    static short GetDigitFreqInNum(int Num, short Digit)
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

    static bool IsPrimeNum(int Number)
    {
        float M = round(Number / 2);
        for (int Counter = 2; Counter <= M; Counter++)
        {
            if (Number % Counter == 0)
                return false;

        }

        return true;
    }

    static int GetReverseNum(int Num)
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

    static bool IsPerfectNum(int Num)
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

    static  void Swap(int& A, int& B)
    {
        int Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(double& A, double& B)
    {
        double Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }


    // Randomization

    static void  Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    enum enCharType {
        eSamallLetter = 1, eCapitalLetter = 2,
        eDigit = 3, eMixChars = 4, eSpecialCharacter = 5
    };

    static  int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == eMixChars)
        {
            //Capital/Small/Digits only
            CharType = (enCharType)RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::eSamallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::eCapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::eSpecialCharacter:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::eDigit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
    defualt:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        }
    }

    static  string GenerateWord(enCharType CharType, short Length)

    {
        string Word;

        for (int i = 1; i <= Length; i++)

        {

            Word = Word + GetRandomCharacter(CharType);

        }
        return Word;
    }

    static string  GenerateKey(enCharType CharType = eCapitalLetter)
    {

        string Key = "";


        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);


        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

    static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = RandomNumber(From, To);
    }

    static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateWord(CharType, Wordlength);

    }

    static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
    {
        for (int i = 0; i < arrLength; i++)
            arr[i] = GenerateKey(CharType);
    }

    // Arrays

    static void ReadArray(int Array[100], int& Length)
    {
        Length = clsInputValidate::ReadNumber<int>("Enter how many elements do you need: ");

        cout << "Enter value of elements: " << endl;

        for (int Counter = 0; Counter < Length; Counter++)
        {
            cout << "Element [" << Counter + 1 << "] : " << endl;
            cin >> Array[Counter];
        }
    }

    static void AddArrayElement(int Array[100], int& Length, int Num)
    {
        Length++;
        Array[Length - 1] = Num;
    }

    static void SemiDynamicUserInputArray(int Array[100], int& Length)
    {
        Length = 0;
        bool AddMore = true;

        do
        {
            AddArrayElement(Array, Length, clsInputValidate::ReadNumber<int>("Enter a number:"));
            cout << "Do you want to add more numbers? [0] No - [1] Yes" << endl;;
            cin >> AddMore;

        } while (AddMore);
    }

    static void PrintArray(int Array[100], int Length)
    {

        for (int Counter = 0; Counter < Length; Counter++)
        {
            cout << Array[Counter] << " ";
        }

        cout << endl;
    }

    static void FillRandomNumsInArray(int Array[100], int& Length)
    {
        cout << endl;
        Length = clsInputValidate::ReadNumber<int>("Enter how many elements do you need:");
        cout << endl;

        for (int Counter = 0; Counter < Length; Counter++)
        {
            Array[Counter] = RandomNumber(1, 100);
        }
    }

    static void FillArrayWith1toN(int Array[100], int& Length)
    {
        Length = clsInputValidate::ReadNumber<int>("Enter how many Numbers do you need: ");

        for (int Counter = 0; Counter < Length; Counter++)
        {
            Array[Counter] = Counter + 1;
        }
    }

    static void FillArrayWithKeys(string Array[100], int& Length)
    {
        Length = clsInputValidate::ReadNumber<int>("Enter how many Keys do you need: ");

        for (int Counter = 0; Counter < Length; Counter++)
        {
            Array[Counter] = GenerateKey();
        }
    }

    static int GetFreqOfNumInArray(int Array[100], int NumToCheck, int Length)
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

    static bool IsNumEven(int Num)
    {
        if (Num % 2 != 0)
            return false;

        return true;
    }

    static int GetFreqOfOddNumInArray(int Array[100], int Length)
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

    static int FindNumIndexInArray(int Array[100], int Length, int NumToFind)
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

    static bool IsNumInArray(int Array[100], int Length, int NumToFind)
    {
        return FindNumIndexInArray(Array, Length, NumToFind) != -1;
    }

    static int FindMaxArray(int Array[100], int Length)
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

    static int FindMinArray(int Array[100], int Length)
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

    static int SumAllArray(int Array[100], int Length)
    {
        int Sum = 0;

        for (int Counter = 0; Counter < Length; Counter++)
        {
            Sum += Array[Counter];
        }

        return Sum;
    }

    static float AvgAllArray(int Array[100], int Length)
    {
        return (float)SumAllArray(Array, Length) / Length;
    }

    static void CopyArray(int Original[100], int Copy[100], int OriginalLength)
    {
        for (int Counter = 0; Counter < OriginalLength; Counter++)
        {
            Copy[Counter] = Original[Counter];
        }
    }

    static void CopyArrayUsingAddArrayElement(int Array1[100], int Length1, int Array2[100], int& Length2)
    {
        for (int Counter = 0; Counter < Length1; Counter++)
        {
            AddArrayElement(Array2, Length2, Array1[Counter]);
        }
    }

    static void CopyOddNumArrayUsingAddArrayElement(int Array1[100], int Length1, int Array2[100], int& Length2)
    {
        for (int Counter = 0; Counter < Length1; Counter++)
        {
            if (Array1[Counter] % 2 != 0)
                AddArrayElement(Array2, Length2, Array1[Counter]);
        }
    }

    static void CopyPrimeNumArrayUsingAddArrayElement(int Array1[100], int Length1, int Array2[100], int& Length2)
    {
        for (int Counter = 0; Counter < Length1; Counter++)
        {
            if (IsPrimeNum(Array1[Counter]))
                AddArrayElement(Array2, Length2, Array1[Counter]);
        }
    }

    static void CopyDistinctArrayUsingAddArrayElement(int Array1[100], int Length1, int Array2[100], int& Length2)
    {
        for (int Counter = 0; Counter < Length1; Counter++)
        {
            if (!IsNumInArray(Array2, Length2, Array1[Counter]))
                AddArrayElement(Array2, Length2, Array1[Counter]);
        }
    }

    static void CopyArrayInReverseOrder(int Original[100], int Copy[100], int OriginalLength)
    {

        for (int Counter = 0; Counter < OriginalLength; Counter++)
        {
            Copy[Counter] = Original[OriginalLength - 1 - Counter];
        }
    }

    static void ShuffleArrayElements(int Array[100], int Length)
    {


        for (int Counter = 0; Counter < Length; Counter++)
        {
            Swap(Array[RandomNumber(0, Length - 1)], Array[RandomNumber(0, Length - 1)]);
        }

    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static bool IsArrayPalindrome(int Array[100], int Length)
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

    static int CountPositiveNumsInArray(int Array[100], int Length)
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

    static void AddNumElementInVector(vector <int>& vNumbers)
    {
        int Number = 0;
        
        do
        {
            Number = clsInputValidate::ReadNumber<int>("Enter a positive number: ");
            vNumbers.push_back(Number);

            

        } while (clsInputValidate::ReadBoolean("Do you want keep adding? Y/N:"));
    }

    static void PrintVectorNumElements(vector <int>& vNumbers)
    {

        cout << "\nvector Numbers are: " << endl;

        for (int& item : vNumbers)
        {

            printf("%04d  \n", item);
        }
    }

    // Matrix

    static void PrintMatrix(int matrix[3][3])
    {
        cout << "This is an ordered 3x3 matrix:" << endl;
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                cout << Tabs(3) << matrix[row][col] << "   ";
            }
            cout << endl;
        }
    }

    static void FillRandomNumsMatrix(int matrix[3][3])
    {
        for (int row = 0; row < 3; row++)
        {
            for (int colmn = 0; colmn < 3; colmn++)
            {
                matrix[row][colmn] = RandomNumber(1, 10);
            }
        }
    }

    static int CountFreqInMatrix(int matrix[3][3], int Number)
    {

        int Freq = 0;

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (matrix[row][col] == Number)
                    Freq++;
            }
        }

        return Freq;
    }

    static int SumMatrixRow(int array[3][3], int RowNumber, int SizeOfColmn)
    {
        int sum = 0;

        for (int colmn = 0; colmn < SizeOfColmn; colmn++)
        {
            sum += array[RowNumber][colmn];
        }

        return sum;
    }

    static int SumMatrixCol(int matrix[3][3], int colNumber, int SizeOfRows)
    {
        int sum = 0;

        for (int row = 0; row < SizeOfRows; row++)
        {
            sum += matrix[row][colNumber];
        }

        return sum;
    }

    static bool IsNumInMatrix(int matrix[3][3], int Number)
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (matrix[row][col] == Number)
                    return true;
            }
        }

        return false;
    }

    static bool IsMatrixPalindrome(int matrix[4][4], int Rows, int Cols)
    {
        for (int r = 0; r < Rows; r++)
        {
            for (int c = 0; c < Cols / 2; c++)
            {
                if (matrix[r][c] != matrix[r][Cols - 1 - c])
                    return false;
            }
        }

        return true;
    }


    // 

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static string  EncryptText(string Text, short EncryptionKey = 8)
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey = 8)
    {

        for (int i = 0; i < Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }


    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }


    }

};

