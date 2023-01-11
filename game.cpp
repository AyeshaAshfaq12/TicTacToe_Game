//--------------Header Files---------//
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;
//--------------Functions  ProtoType------------//
void header();
int menu();
void display();
void player_turn();
bool isValid();
bool game_over();
//----------------Variable Declaration--------------//
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
string p1, p2;     // p1 == player1 , p2 == player2
char turn;
char choice;
int row, column;
bool draw;
//------------------Color Change----------//
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//------------------Main Body----------------------//
main()
{
    system("cls");
    header();
    int option = menu();
    while (option < 3)
    {
        if (option == 1)
        {
            turn = 'X';
            draw = false;
            int a = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    board[i][j] = arr[a];
                    a++;
                }
            }
            system("cls");
            header();
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, 14);
            cout << "\t  Players Name: ";
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, 11);
            cout << "\t Player 1 [X]  Enter your Name: ";
            cin >> p1;
            cout << endl;
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t Player 2  [O] Enter your Name: ";
            cin >> p2;
            system("cls");
            SetConsoleTextAttribute(hConsole, 15);
            while (game_over())
            {
                game_over();
                system("cls");
                header();
                display();
                player_turn();
                system("cls");
                header();
                display();
            }
            if (turn == 'X' && draw == false)
            {
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hConsole, 10);
                cout << "\t\t\t\t\t\t\t" << p2 << " [O] Wins. Congratulations !!";
                cout << endl;
                cout << endl;
            }
            else if (turn == 'O' && draw == false)
            {
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hConsole, 10);
                cout << "\t\t\t\t\t\t\t" << p1 << " [X] Wins. Congratulations !!";
                cout << endl;
                cout << endl;
            }
            else if (draw == true)
            {
                cout << endl;
                cout << endl;
                SetConsoleTextAttribute(hConsole, 6);
                cout << "\t\t\t\t\t\t\t\t   Game Draw.";
                cout << endl;
                cout << endl;
            }
            draw = true;
        }
        if (option == 2)
        {
            system("cls");
            header();
            cout << endl;
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t\t\t\t\t       ----------------------------" << endl;
            cout << "\t\t\t\t\t       |     Game Description     |" << endl;
            cout << "\t\t\t\t\t       ----------------------------" << endl;
            cout << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\t\t How to Play :  ";
            SetConsoleTextAttribute(hConsole, 14);
            cout << "Tic Tac Toe is a noughts and cross game for 2 players " << endl;
            cout << "\t\t\t        who takes turns marking the spaces in a 3-by-3 grid with " << endl;
            cout << "\t\t\t        X or O . The player who succeeds in placing three of their " << endl;
            cout << "\t\t\t        marks in a horizontal, vertical or diagonal pattern is WINNER ." << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\t\tPlayers Required : ";
            SetConsoleTextAttribute(hConsole, 14);
            cout << " 2 " << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\t\tSkills Required :";
            SetConsoleTextAttribute(hConsole, 14);
            cout << "  Strategy, Tactics, Observation ." << endl;
            cout << endl;
            SetConsoleTextAttribute(hConsole, 6);
            cout << "\t\tOther Names :";
            SetConsoleTextAttribute(hConsole, 14);
            cout << " Noughts and Crosses, X's  and  O's " << endl;
            cout << endl;
        }
        cout << endl;
        SetConsoleTextAttribute(hConsole, 6);
        cout << "\t\tPress any key to continue_";
        getch();
        system("cls");
        header();
        option = menu();
    }
    SetConsoleTextAttribute(hConsole, 15); // set back to black background and white text  coz 15 = white
}

//-------------  --Functions Definition---- -------------//
void header()
{
    cout << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\t\t***********  **********     ******           ***********     ***          ******          ***********   *********    **********    " << endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\t\t***********  **********   *********          ***********   **   **      *********         ***********  ***********   **********    " << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "\t\t    ***          **      **                      ***      **     **    **                     ***      **       **   **            " << endl;
    SetConsoleTextAttribute(hConsole, 5);
    cout << "\t\t    ***          **      **                      ***     ***********   **                     ***      **       **   **********    " << endl;
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\t\t    ***          **      **                      ***    *************  **                     ***      **       **   **********    " << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t    ***          **      **                      ***    **         **  **                     ***      **       **   **            " << endl;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "\t\t    ***      **********   *********              ***    **         **   *********             ***      ***********   **********    " << endl;
    SetConsoleTextAttribute(hConsole, 13);
    cout << "\t\t    ***      **********    *******               ***    **         **    *******              ***       *********    **********    " << endl;
    cout << endl;
}
int menu()
{
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "\t\t\t\t\t\t---------------------" << endl;
    cout << "\t\t\t\t\t\t|     Main Menu     |" << endl;
    cout << "\t\t\t\t\t\t---------------------" << endl;
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 3);
    cout << " -------------------------------" << endl;
    cout << " | Select one option from menu |" << endl;
    cout << " -------------------------------" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\t1. Play" << endl;
    cout << "\t2. Game Description" << endl;
    cout << "\t3. Exit" << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << " Your option_";
    int option;
    cin >> option;
    return option;
}
void display()
{
    cout << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\t\t " << p1 << " = [ X ]    " << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12);
    cout << "\t\t " << p2 << " = [ O ]    " << endl;
    SetConsoleTextAttribute(hConsole, 151);
    cout << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << "\t\t\t\t\t\t\t     " << board[0][0] << "     |     " << board[0][1] << "     |     " << board[0][2] << "     " << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << "\t\t\t\t\t\t\t___________|___________|___________" << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << "\t\t\t\t\t\t\t     " << board[1][0] << "     |     " << board[1][1] << "     |     " << board[1][2] << "     " << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << "\t\t\t\t\t\t\t___________|___________|___________" << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << "\t\t\t\t\t\t\t     " << board[2][0] << "     |     " << board[2][1] << "     |     " << board[2][2] << "     " << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << "\t\t\t\t\t\t\t           |           |           " << endl;
    cout << endl;
    SetConsoleTextAttribute(hConsole, 15);
}
void player_turn()
{
    if (turn == 'X')
    {
        SetConsoleTextAttribute(hConsole, 11);
        cout << "\t\t" << p1 << " Turn [X] : ";
        cin >> choice;
    }
    else if (turn == 'O')
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\t\t" << p2 << " Turn [O] : ";
        cin >> choice;
    }
    if (isValid())
    {
        if (turn == 'X')
        {
            board[row][column] = 'X';
            turn = 'O'; //   after every turn, we have to change player's turn, otherwise it will keep taking input for same player
        }
        else if (turn == 'O')
        {
            board[row][column] = 'O';
            turn = 'X';
        }
    }
    else
    {
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(hConsole, 4);
        cout << "\t\tInvalid Choice. " << endl;
        cout << endl;
        cout << endl;
        SetConsoleTextAttribute(hConsole, 13);
        cout << "\tPress any key to continue_";
        getch();
    }
}
bool isValid()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == choice)
            {
                row = i;
                column = j;
                return true;
            }
        }
    }
    return false;
}
bool game_over()
{
    //--------------------------Check Win------------------------------//
    //  Check Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return false;
        }
    }
    //  Check Columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j])
        {
            return false;
        }
    }
    // Check Diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return false;
        cout << 1;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }
    //------------------If any box empty-----------------------//
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[x][y] != 'X' && board[x][y] != 'O')
            {
                return true;
            }
        }
    }
    //--------------------Game Draw----------------------------//
    draw = true;
    return false;
}