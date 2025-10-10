#include <iostream>
#include "MyLib.h"
#include <vector>
#include <string>
#include <iomanip>
#include <ctime> 
#include <cstdlib> 
using namespace MyLib;
using namespace std;

enum enOptions {AddBook = 1, DisplayBooks = 2, BorrowBook = 3, ReturnBook = 4, RemoveBook = 5, Exit = 6};
enum enBookCategory {Fiction = 1, Science = 2, History = 3, Technology = 4, Art = 5};

struct stBookInfo
{
    short int BookID = 0;
    string BookTitle = "";
    string BookAuthor = "";
    enBookCategory Category;
    bool IsBorrowed = false;

};

string ReadNameString(string Message)
{
    string Str = "";
    cout << Message << endl;
    
    getline(cin, Str);
    

    return Str;
}

void ShowMenu()
{
    cout << "\n";
    cout << setw(80) << "Welcome to 'Library Management System' App" << endl;
    cout << "============================" << endl;
    cout << "[1] Add a Book" << endl;
    cout << "[2] Display Books" << endl;
    cout << "[3] Borrow a Book" << endl;
    cout << "[4] Return a Book" << endl;
    cout << "[5] Remove a Book" << endl;
    cout << "[6] Exit" << endl;
    cout << "============================" << endl;
}

void ShowCategory()
{
    cout << "\nCategories:" << endl;
    cout << "[1] Fiction - [2] Science - [3] History - [4] Technology - [5] Art" << endl;
}

enOptions ChooseFromMenu()
{
    ShowMenu();

    short Choice = ReadPositiveNumInRange("Enter Your Choice:", 1, 6);
    return (enOptions)Choice;
}

enBookCategory ChooseFromCategory()
{
    ShowCategory();
    short Choice = ReadPositiveNumInRange("choose a Category:", 1, 5);

    return (enBookCategory)Choice;
}

void AddBookToLibrary(vector <stBookInfo>& Books)
{
    stBookInfo AddBook;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // to clean the buffer one time before reading, cuz i will read the for multiple things repeatedlly

    AddBook.BookID = RandomNumber(1, 9999);
    AddBook.BookTitle = ReadNameString("Enter the Title of The Book:");
    AddBook.BookAuthor = ReadNameString("Enter the Author Name:");
    AddBook.Category = ChooseFromCategory();
    AddBook.IsBorrowed = false;
    Books.push_back(AddBook);

    cout << "Book was Added Successfully !!" << endl;
}

bool IsBorrowed(vector <stBookInfo>& Books, short BookId)
{
    for (stBookInfo& element : Books)
    {
        if (element.BookID == BookId)
            return element.IsBorrowed;
        
    }

    return false;
}

string BoolToStr(bool IsBorrowed)
{
    if (IsBorrowed)
        return "Yes";

    return "No";
}

string EnumToStr(enBookCategory Num)
{
    switch (Num)
    {
    case enBookCategory::Fiction: return "Fiction"; break;
    case enBookCategory::Science: return "Science"; break;
    case enBookCategory::History: return "History"; break;
    case enBookCategory::Technology: return "Technology"; break;
    case enBookCategory::Art: return "Art"; break;
    default: return "No Category Found"; break;
    }
}

bool DisplayBooksInLibrary(vector <stBookInfo>& Books)
{
    cout << "\nTotal Books: ";
    if (Books.empty())
    {
        cout << "No Books in Library" << "\n" << endl;
        return false;
    }
    else
    {
        cout << Books.size() << endl;
    }

    short Borrowed = 0;
    for (stBookInfo& element : Books)
    {
        if (element.IsBorrowed)
            Borrowed++;
    }

    cout << "Borrowed Books: " << Borrowed << "\n" << endl;

    for (stBookInfo& element : Books)
    {
        printf("ID: %04d ", element.BookID);
        cout << " | Book Title: " << element.BookTitle;
        cout << " | Author Name: " << element.BookAuthor;
        cout << " | Category: " << EnumToStr(element.Category);
        cout << " | Borrowed: " << BoolToStr(element.IsBorrowed) << "\n\n" << endl;
    }

    return true;
}

void BorrowBookFromLibrary(vector <stBookInfo>& Books, short ID)
{
    if (Books.empty())
    {
        cout << "No Books in Library" << "\n" << endl;
        return;
    }

    bool Found = false;

    if (IsBorrowed(Books, ID))
    {
        Found = true;
        cout << "Book is Already Borrowed !!" << endl;
    }
    else
    {
        for (stBookInfo& element : Books)
        {
            if (element.BookID == ID)
            {
                Found = true;
                element.IsBorrowed = true;
                cout << "Book Borrowed Successfully !!" << endl;
                break;
            }

        }
    }

    if (!Found)
    {
        system("color 4F"); // red screen
        cout << "Book was not found !" << endl;
    }
}

void ReturnBookToLibrary(vector <stBookInfo>& Books, short ID)
{

    if (Books.empty())
    {
        cout << "No Books in Library" << "\n" << endl;
        return;
    }

    bool Found = false;

        for (stBookInfo& element : Books)
        {
            if (element.BookID == ID)
            {
                Found = true;
                element.IsBorrowed = false;
                cout << "Book Returned Successfully !!" << endl;
                break;
            }           

        }

        if (!Found)
        {
            system("color 4F"); // red screen
            cout << "Book was not found !" << endl;
        }
        
   
}

void ResetWithColor(string Color = "Black")
{
    string Reset = "";

    if (Color == "Red")
        system("color 4F");
    else if (Color == "Green")
        system("color 2F");
    else if (Color == "Gray")
        system("color 8F");
    else if (Color == "White")
        system("color F0");
    else
        system("color 07");

    cout << "press 'Enter' to continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // to ignore anything in buffer , cuz getline takes last thing in buffer.
    getline(cin, Reset);

    system("cls");
    system("color 07");
}

void RemoveBookFromLibrary(vector <stBookInfo>& Books, short ID)
{
    if (Books.empty())
    {
        cout << "No Books in Library" << "\n" << endl;
        return;
    }

    bool Found = false;
    vector <stBookInfo>::iterator itr;

    for (itr = Books.begin(); itr != Books.end(); itr++)
    {
        if (itr->BookID == ID)
        {
            Found = true;
            Books.erase(itr);
            cout << "Book has been removed successfully !!" << endl;
            system("color 2F");
            break;
        }        
        
    }

    if (!Found)
    {
        system("color 4F"); // red screen
        cout << "Book was not found !" << endl;
    }
}

void StartApp()
{
    vector <stBookInfo> Books;
    enOptions Action;

    do
    {
        Action = ChooseFromMenu();

        if (Action == enOptions::AddBook)
        {
            system("cls");
            AddBookToLibrary(Books);
            ResetWithColor("Green");
        }
        else if (Action == enOptions::DisplayBooks)
        {
            system("cls");
            DisplayBooksInLibrary(Books);
            ResetWithColor("White");
        }
        else if (Action == enOptions::BorrowBook)
        {
            system("cls");
            if (DisplayBooksInLibrary(Books))
            {
                BorrowBookFromLibrary(Books, ReadPositiveNumber("Enter Book ID:"));
            }
            ResetWithColor("White");
        }
        else if (Action == enOptions::ReturnBook)
        {
            system("cls");
            if (DisplayBooksInLibrary(Books))
            {
                ReturnBookToLibrary(Books, ReadPositiveNumber("Enter Book ID:"));
            }
            
            ResetWithColor();
        }
        else if (Action == enOptions::RemoveBook)
        {
            system("cls");
            if (DisplayBooksInLibrary(Books))
            {
                RemoveBookFromLibrary(Books, ReadPositiveNumber("Enter Book ID:"));
            }
            
            ResetWithColor("Green");
        }


    } while (Action != enOptions::Exit);
}

int main()
{
    
    srand((unsigned)time(NULL));

    StartApp();

    return 0;
}
