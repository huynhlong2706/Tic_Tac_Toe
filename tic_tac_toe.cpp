#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Create a table
    char table[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};

    // Player input
    const char playerX = 'X';
    const char playerO = 'O';
    char currPlayer = playerX;
    int r, c;
    char winner = ' ';

    for (int i = 0; i < 9; i++)
    {
        cout << "   |   |   " << endl;
        cout << " " << table[0][0] << " | " << table[0][1] << " | " << table[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << table[1][0] << " | " << table[1][1] << " | " << table[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << table[2][0] << " | " << table[2][1] << " | " << table[2][2] << endl;
        cout << "   |   |   " << endl;

        if(winner != ' '){
            break;
        }
        
        cout << "Current Player is: " << currPlayer << endl;
        while (true)
        {
            cout << "Your choice: ";
            cin >> r >> c;
            if (r < 0 || r > 2 || c < 0 || c > 2)
            {
                cout << "Invalid index" << endl;
                // break;
            }

            else if (table[r][c] == 'X' || table[r][c] == 'O')
            {
                cout << "Position has been filled" << endl;
                // break;
            }

            // reset value
            else if (cin.fail())
            {
                cout << "Data type does not match" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }

            else
                break;
        }

        table[r][c] = currPlayer;
        currPlayer = (currPlayer == playerX) ? playerO : playerX;

        // Winning condition
        for (int r = 0; r < 3; r++)
        {
            if (table[r][0] != ' ' && table[r][0] == table[r][1] && table[r][1] == table[r][2])
            {
                winner = table[r][0];
                break;
            }
        }

        for (int c = 0; c < 3; c++)
        {
            if (table[0][c] != ' ' && table[0][c] == table[1][c] && table[1][c] == table[2][c])
            {
                winner = table[0][c];
                break;
            }
        }

        if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[1][1] == table[2][2])
        {
            winner = table[0][0];
        }

        else if (table[0][2] != ' ' && table[0][2] == table[1][1] && table[1][1] == table[2][0])
        {
            winner = table[0][2];
        }
    }
    if (winner != ' ')
    {
        cout << "Game Over! Winner is: " << winner << endl;
        // break;
    }
    else
    {
        cout << "Game Over! Tie!" << endl;
        // break;
    }
}