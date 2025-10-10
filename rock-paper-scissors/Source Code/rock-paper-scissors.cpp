#include <iostream>
#include <cstdlib>    
#include <ctime>
#include <string>
using namespace std;

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

string Tabs(short N)
{
    string t = "\t";

    for (short Counter = 1; Counter <= N; Counter++)
    {
        t += "\t";
    }
    return t;
}

struct stGameResults
{
    short GameRounds = 0;        
    short Player1WinTimes = 0;   
    short ComputerWinTimes = 0;  
    short DrawTimes = 0;         
    enWinner GameWinner;         
    string WinnerName = "";
};

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName ;
};

short ReadPositiveInRangeNumber(string Message, short From, short To)
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

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    // these are when the computer will win
    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
            return enWinner::Computer;
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
        return enWinner::Computer;
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
        return enWinner::Computer;
        break;
    }

    //if computer didnt win, it means the player won.
    return enWinner::Player1;
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes) 
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    else 
        return enWinner::Draw;
}

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoice[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoice[Choice - 1];
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player1", "Computer", "No Winner (Draw)" };
    return arrWinnerName[Winner - 1];
}

enGameChoice ReadPlayer1Choice()
{
    short Choice = 0;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;

        if (cin.fail())
        {
            // if other than numbers entered system will fail.
            cin.clear();                // to clear the failure
            cin.ignore(10000, '\n');    // to ignore what was entered before, to clean the buffer
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

    } while (Choice < 1 || Choice > 3);

    return (enGameChoice)Choice;
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
    cout << "_________________________________________\n" << endl;
}

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1)
        {
            system("color 2F");
            Player1WinTimes++;
        }
        else if (RoundInfo.Winner == enWinner::Computer)
        {
            cout << '\a';
            system("color 4F");
            ComputerWinTimes++;
        }
        else
        {
            system("color 6F");
            DrawTimes++;
        }

        PrintRoundResults(RoundInfo);
    }

    

    return { HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes, WhoWonTheGame(Player1WinTimes, ComputerWinTimes), WinnerName(WhoWonTheGame(Player1WinTimes, ComputerWinTimes)) };
}

void ShowFinalResult(stGameResults GameResults)
{
    cout << Tabs(3) << "--------------------------------------------------" << endl;
    cout << Tabs(5) << "+++ G a m e  O v e r +++" << endl;
    cout << Tabs(3) << "--------------------------------------------------" << endl;
    cout << Tabs(3) << "___________________[Game Results]_________________" << endl;
    cout << Tabs(3) << "Game Rounds         :" << GameResults.GameRounds << endl;
    cout << Tabs(3) << "Player Won Times    :" << GameResults.Player1WinTimes << endl;
    cout << Tabs(3) << "Computer Won Times  :" << GameResults.ComputerWinTimes<< endl;
    cout << Tabs(3) << "Draw Times          :" << GameResults.DrawTimes << endl;
    cout << Tabs(3) << "Final Winner        :" << WinnerName(GameResults.GameWinner) << endl;
    cout << Tabs(3) << "--------------------------------------------------" << endl;

    if (GameResults.GameWinner == enWinner::Player1)
        system("color 2F");
    else if (GameResults.GameWinner == enWinner::Computer)
    {
        cout << '\a';
        system("color 4F");
    }
    else
        system("color 6F");

}

string ReadPlayAgain(string Message)
{
    string Answer = "";
    do
    {
        cout << Message;
        cin >> Answer;
    } while ((Answer != "Y" && Answer != "y") && (Answer != "N" && Answer != "n"));

    return Answer;
}

void StartGame()
{
    string PlayAgain = "Y";

    do
    {
        system("cls");
        system("color 0F");
        
        cout << "\n================================================\n";
        cout << "\t  ROCK-PAPER-SCISSORS GAME";
        cout << "\n================================================\n";

        stGameResults GameResults = PlayGame(ReadPositiveInRangeNumber("How many rounds? 1 to 10:" , 1, 10));
        cout << "\nGame Over! Winner: " << GameResults.WinnerName << endl;

        ShowFinalResult(GameResults);

        PlayAgain = ReadPlayAgain("\t\t\t\tDo you want ro play again? Y/N?  ");

    } while (PlayAgain == "Y" || PlayAgain == "y");
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}

