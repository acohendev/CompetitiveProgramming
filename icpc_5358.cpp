#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

bool isSolution (int queens_layout[8])
{
    for (int col1 = 0; col1 < 7; col1++)
    {
        for (int col2 = col1 + 1; col2 < 8; col2++)
        {
            if (queens_layout[col1] == queens_layout[col2] ||               /* same row */
                queens_layout[col1] - col1 == queens_layout[col2] - col2 || /* same diag left to right */
                queens_layout[col1] + col1 == queens_layout[col2] + col2)   /* same diag right to left */
                return false;
        }
    }
    return true;
}

int main ()
{
    int t, row, col, sol, layout[9] = {0};

    cin >> t;

    while (t--)
    {
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";

        cin >> row >> col;

        // adjust row and col to my indexing, fix when printing
        row--;
        col--;

        // make a sorted permutation w/o the fixed row.
        int permutation[8] = {0, 1, 2, 3, 4, 5 ,6, 7};
        for (int i = row; i < 7; i++) permutation[i] = permutation[i + 1];

        sol = 1;
        do
        {
            // construct a possible solution with the current permutation
            // and the fixed (row, col)
            for (int i_col = 0, p_idx = 0; i_col < 8; i_col++)
            {
                if (i_col != col) layout[i_col] = permutation[p_idx++];
                else layout[i_col] = row;
            }

            if (isSolution(layout))
            {
                cout << setw(2) << setfill(' ') << setiosflags(ios::right);
                cout << sol++ << "     ";
                for (int i = 0; i < 8; i++) cout << " " << layout[i] + 1;
                cout << "\n";
            }
        } while (next_permutation(permutation, permutation + 7));
        
        if (t) cout << "\n";
    }
    return 0;
}