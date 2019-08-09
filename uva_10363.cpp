#include <iostream>

using namespace std;

bool Win (char game[3][3], char player)
{
    for (int row = 0; row < 3; row++)
        if (game[row][0] == player && game[row][1] == player && game[row][2] == player)
            return true;

    for (int col = 0; col < 3; col++)
        if (game[0][col] == player && game[1][col] == player && game[2][col] == player)
            return true;
    
    if (game[0][0] == player && game[1][1] == player && game[2][2] == player)
        return true;

    if (game[2][0] == player && game[1][1] == player && game[0][2] == player)
        return true;

    return false;
}


int main ()
{
    int nr_tests = 0;
    char game[3][3];
    char sign;


    cin >> nr_tests;

    while (nr_tests--)
    {
        int nr_x = 0;
        int nr_o = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> sign;

                if (sign == 'X')
                    nr_x++;
                else if (sign == 'O')
                    nr_o++;

                game[i][j] = sign;
            }
        }

        if (nr_x == nr_o + 1 && !Win(game, 'O'))
            cout << "yes" << endl;
        else if (nr_x == nr_o && !Win(game, 'X'))
            cout << "yes" << endl;
        else
            cout << "no" << endl;        
    }

    return 0;
}