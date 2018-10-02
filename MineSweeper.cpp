/*
 ============================================================================
 Name        : homework5.cpp
 Author      : Benjamin Jimenez
 Version     :
 Copyright   : 2015
 Description : This program will allow you to play minesweeper!
 ============================================================================
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 5;     // number of rows and columns for square board
int num_of_turns;
int arr[2] = {0,0};

enum Status {INIT = '*', MINE = '@', X = 'X',NUM = 0, NUM1 = 1, NUM2 = 2, NUM3 = 3, NUM4 = 4, NUM5=5, NUM6 = 6, NUM7 = 7, NUM8 = 8};   // enum for game board type with supported values

struct coordinates {int ROW, COL;}; //structure

// functions
bool check_stat(Status **board, coordinates(x));
void printStudentInfo();
void printIntro(int num_of_mines);
void initBoard(Status **board);
bool assignMine(Status **board);
void dispBoard(Status **board, int reveal);
void position();
int getMines();

int main()
{
    coordinates x; //x.ROW and x.COL
    int    reveal = 0;
    int    num_of_mines;            // number of mines entered by user
    int    repeat;
    srand(time(0));         // seed random number generator
    num_of_turns = 1;
    
    //Status **board;       // game board implemented as enum type
    Status **board;         //game board/dynamic array implemented as enum type
    board = new Status *[SIZE];
    for (int i=0; i<SIZE; i++)
    {
        board[i] = new Status[SIZE]; //status **board
    }

    printStudentInfo();     // call function to display student info
    num_of_mines = getMines();
    printIntro(num_of_mines);       // call function to print game information
    initBoard(board);       // call function to initialize board

    // loop to assign correct number of mines
    for (int i = 0; i < num_of_mines; i++)
    {
        // loop until assign mine
        while (!assignMine(board))
        {

        }
    }

    dispBoard(board, reveal); // displays initial game board so user can pick first coordinates
    
    do
    {
        position();
        x.ROW = arr[0];
        x.COL = arr[1];

        if (num_of_turns != 1)
        {
            repeat = 0;
            while (repeat == 0)
            {
                if (board[x.ROW][x.COL] == MINE)
                {
                    repeat = 1;
                }
                else if ((board[x.ROW][x.COL] != MINE) && (board[x.ROW][x.COL] != INIT))
                {
                    repeat = 0;
                    cout << "Sorry, you entered a previously entered coordinate. Try again.\n";
                    position();
                    x.ROW = arr[0];
                    x.COL = arr[1];
                }
                else
                {
                    repeat = 1;
                }
            }
        }
        

        check_stat(board, coordinates(x));
        num_of_turns++;
        dispBoard(board, reveal); // displays game board
    }
    while ((num_of_turns<=10) && (board[x.ROW][x.COL] != X));

    if (board[x.ROW][x.COL] == X)
    {
        cout<< "\nSorry, but you hit a mine. Tough break...\n" << endl;
    }
    else
    {
        cout << "\nCongratulations! No mine hit in 10 tries!\n" << endl;
    }
    reveal = 1;
    dispBoard(board, reveal); // display final game board


    for (int i = 0; i<SIZE; i++)
    {
        delete[] board[i];
    }
    delete[]board;

    return 0;
}

/*
 ============================================================================
 Function    : printStudentInfo
 Parameters  : nothing
 Return      : nothing
 Description : This function prints out student information
 ============================================================================
 */
void printStudentInfo()
{
    // display student information
    cout << "     +----------------------------------------------+" << endl;
    cout << "     |       Computer Science and Engineering       |" << endl;
    cout << "     |        CSCE 1030 - Computer Science I        |" << endl;
    cout << "     |Benjamin Jimenez  bjj0051  bjj0051@my.unt.edu |" << endl;
    cout << "     +----------------------------------------------+" << endl;
    cout << endl;
    cout << "           Welcome to Minesweeper!             " << endl << endl;

    return;
}

/*
 ============================================================================
 Function    : printIntro
 Parameters  : integer for number of mines
 Return      : nothing
 Description : This function prints out game information, including number of
 mines, size of board, and objective of the game
 ============================================================================
 */
void printIntro(int num_of_mines)
{
    cout << "----------------------------------------------------------" << endl;
    cout << "This computer program will randomly assign ";
    cout.width(2);
    cout << num_of_mines << " mines to the " << endl;
    cout << SIZE << " by " << SIZE << " board. Your objective will be to select ten squares" << endl;
    cout << "on the board that do not contain mines using the given in-" << endl;
    cout << "formation from the adjacent squares. The game is over when" << endl;
    cout << "you either select 10 squares without hitting a mine or you" << endl;
    cout << "select a square containing a mine.                        " << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << endl;
    cout << "Initializing board...";
    cout << "assigning mines...";
    cout << "now let's begin..." << endl << endl;


    return;
}

/*
 ============================================================================
 Function    : initBoard
 Parameters  : enum type for 2D game board array
 Return      : nothing
 Description : This function initializes the game board to its initial values
 ============================================================================
 */
void initBoard(Status **board)
{
    // loop through rows
    for (int row = 0; row < SIZE; row++)
    {
        // loop through columns
        for (int col = 0; col < SIZE; col++)
        {
            // assign enum value for '*' to row-column position
            board[row][col] = INIT;
        }
    }
}

/*
 ============================================================================
 Function    : assignMine
 Parameters  : enum type for 2D game board array
 Return      : bool that indicates whether or not mine assignment successful
 Description : This function attempts to assign one single mine to a randomly
 generated row-column position and returns true if the mine as-
 signment was successful or false otherwise
 ============================================================================
 */
bool assignMine(Status **board)
{
    int row = (rand() % SIZE);      // generate random row in board
    int col = (rand() % SIZE);      // generate random column in board

    // check if mine already present at random row-column position
    if (board[row][col] == INIT)
    {
        // no mine present, so assign mine to location
        board[row][col] = MINE;
        return true;
    }
    else
    {
        // mine already present at location, so just return false
        return false;
    }
}

/*
 ============================================================================
 Function    : dispBoard
 Parameters  : enum type for 2D game board array
 Return      : nothing
 Description : This function displays the game board to the screen
 ============================================================================
 */
void dispBoard(Status **board, int reveal)
{
    cout << "    0 1 2 3 4  " << endl;
    cout << "  +-----------+" << endl;

    // loop through to display row information
    for (int row = 0; row < SIZE; row++)
    {
        cout << " " << row << "|";

        // loop through to display column information
        for (int col = 0; col < SIZE; col++)
        {
            if (reveal == 1)
            {
                switch (board[row][col])
                {
                    case INIT:
                    case MINE:
                    case X:
                        cout << " " << static_cast<char>(board[row][col]);
                        break;

                    default:
                        cout<< " " << board[row][col];
                        break;
                }
            }
            else
            {
                if (board[row][col]==MINE)
                {
                    cout<< " " << "*";
                }
                else
                {
                    switch (board[row][col])
                    {
                        case INIT:
                        case MINE:
                        case X:
                            cout << " " << static_cast<char>(board[row][col]);
                            break;

                        default:
                            cout<< " " << board[row][col];
                            break;
                    }
                }
            }
        }
        cout << " |" << endl;
    }

    cout << "  +-----------+" << endl;

}

/*
 ============================================================================
 Function    : check_stat
 Parameters  : enum type for 2D game board array, structure coordinates
 Return      : true or false
 Description : This function returns true or false to main depending
               on the coordinates typed
 ============================================================================
 */

bool check_stat(Status **board, coordinates(x))
{
    int surr_mines = 0;
   
    if (board[x.ROW][x.COL] == MINE)
    {
        board[x.ROW][x.COL] = X;
        return true;
    }
    
    else
    {
        for (int row = x.ROW-1; row <= x.ROW+1; row++)
        {
            for (int col = x.COL-1; col <= x.COL+1; col++)
            {
                if ((row < 0) || (row > 4))
                {

                }
                else if ((col < 0) || (col > 4))
                {

                }
                else
                {
                    if (board[row][col] == MINE)
                    {
                        surr_mines+=1; // counts surrounding mines
                    }
                    else
                    {

                    }
                }
            }
        }
        if (surr_mines == 0)
        {
            board[x.ROW][x.COL] = NUM;
        }
        else if (surr_mines == 1)
        {
            board[x.ROW][x.COL] = NUM1;
        }
        else if (surr_mines == 2)
        {
            board[x.ROW][x.COL] = NUM2;
        }
        else if (surr_mines == 3)
        {
            board[x.ROW][x.COL] = NUM3;
        }
        else if (surr_mines == 4)
        {
            board[x.ROW][x.COL] = NUM4;
        }
        else if (surr_mines == 5)
        {
            board[x.ROW][x.COL] = NUM5;
        }
        else if (surr_mines == 6)
        {
            board[x.ROW][x.COL] = NUM6;
        }
        else if (surr_mines == 7)
        {
            board[x.ROW][x.COL] = NUM7;
        }
        else
        {
            board[x.ROW][x.COL] = NUM8;
        }
        return false;
    }
}

int getMines()
{
    int num_of_mines;

    do
    {
        cout << "Enter number of mines to place on board (5 - 10): ";
        cin  >> num_of_mines;
    } while ((num_of_mines < 5) || (num_of_mines > 10));

    return num_of_mines;
}

void position()
{
    int repeat = 0;
    int x, y; // row col
    while (repeat == 0)
        {
            cout << "Enter position for move #" << num_of_turns << " (row[0-4] col[0-4]): ";
            cin >> x >> y;
                if((x >= 0) && (x <= 4))
                {
                    repeat = 1;
                }
                else if ((y >= 0) && (y <= 4))
                {
                    repeat = 1;
                }
                else
                {
                    cout << "Sorry, invalid position. Try again.\n";
                    repeat = 0;
                }
            arr[0] = x;
            arr[1] = y;
        }
}











