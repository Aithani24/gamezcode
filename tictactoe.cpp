#include <iostream>
using namespace std;

char array[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'X';
bool tie = false;
string name1 = "";
string name2 = "";
void gameone()
{

    cout << "     |        | \n";
    cout << "  " << array[0][0] << "  | " << "    " << array[0][1] << "  |  " << array[0][2] << " \n";
    cout << "_____|________|_____ \n";
    cout << "     |        | \n";
    cout << "  " << array[1][0] << "  | " << "    " << array[1][1] << "  |  " << array[1][2] << " \n";
    cout << "_____|________|_____ \n";
    cout << "     |        | \n";
    cout << "  " << array[2][0] << "  | " << "    " << array[2][1] << "  |  " << array[2][2] << " \n";
    cout << "     |        | \n";
}

void gametwo()
{
    int digit;
    if (token == 'X')
    {
        cout << name1 << " Please Enter the number " << endl;
        cin >> digit;
    }
    if (token == 'O')
    {
        cout << name2 << " Plesae Enter the number " << endl;
        cin >> digit;
    }
    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else if (digit < 1 || digit > 9)
    {
        cout << "Invalid !!!" << endl;
    }

    if (token == 'X' && array[row][column] != 'X' && array[row][column] != 'O')
    {
        array[row][column] = 'X';
        token = 'O';
    }
    else if (token == 'O' && array[row][column] != 'X' && array[row][column] != 'O')
    {
        array[row][column] = 'O';
        token = 'X';
    }
    else
    {
        cout << "END OF THE GAME !!!" << endl;
        gametwo();
    }
    gameone();
}

bool gamethree()
{
    for (int i = 0; i < 3; i++)
    {
        if (array[i][0] == array[i][1] && array[i][0] == array[i][2] || array[i][0] == array[1][i] && array[i][0] == array[2][i])
        {
            return true;
        }
        if (array[0][0] == array[1][1] && array[1][1] == array[2][2] || array[0][2] == array[1][1] && array[1][1] == array[2][0])
        {
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (array[i][j] != 'X' && array[i][j] != 'O')
            {
                return false;
            }
        }
    }
    tie = true;
    return false;
}
int main()
{
    cout << "Enter the Name of the 1st player" << endl;
    cin >> name1;
    cout << "Enter the Name of the 2nd player" << endl;
    cin >> name2;
    cout << "Player one is " << name1 << endl;
    cout << "Player two is " << name2 << endl;
    while (!gamethree())
    {
        gameone();
        gametwo();
        gamethree();
    }
    if (token == 'X' && tie == false)
    {
        cout << name2 << " Wins !!!" << endl;
    }
    else if (token == 'O' && tie == false)
    {
        cout << name1 << " Wins !!!" << endl;
    }
    else
    {
        cout << "It's a Draw !!!" << endl;
    }
    return 0;
}
