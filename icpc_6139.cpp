#include <iostream>
#include <cstring>

using namespace std;


int sign (int x) { return (x > 0) - (x < 0); }

/* *************************** Segment Tree ********************************* */
const int MAX_N = 100000;  // limit for array size
int n; // array size
int tree[2 * MAX_N];

// function to build the tree 
void build( int arr[])  
{  
    // insert leaf nodes in tree 
    for (int i=0; i<n; i++)     
        tree[n+i] = arr[i]; 
      
    // build the tree by calculating parents 
    for (int i = n - 1; i > 0; --i)      
        tree[i] = tree[i<<1] * tree[i<<1 | 1];     
} 
  
// set value at position p
void modify(int p, int value)  
{  
    // set value at position p 
    tree[p+n] = value; 
    p = p+n; 
      
    // move upward and update parents 
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] * tree[i^1]; 
} 
  
// product on interval [l, r) 
int query(int l, int r)  
{  
    int res = 1; 
      
    // loop to find the sum in the range 
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    { 
        if (l&1)  
            res *= tree[l++]; 
      
        if (r&1)  
            res *= tree[--r]; 
    } 
      
    return res; 
} 
/* ************************************************************************** */

int main ()
{
    int N, K, I, J, prod, num;
    string cmd;
    int signs[MAX_N];

    while (cin >> N >> K)
    {
        // initialize the tree with the input N numbers
        for (int i = 0; i < N; i++)
        {
            cin >> num;
            signs[i] = sign(num);
        }

        n = N;
        build(signs);   

        // read and execute commands
        while (K--)
        {
            cin >> cmd >> I >> J;
            if (cmd == "C") modify (I - 1, sign(J));
            else 
            {
                prod = query(I - 1, J); // we want product sign of [I, J]
                // query gives [x ,y) and theres an offset of 1 to left
                // with the indexing: array starts at 0, I starts at 1.
                if (prod == 0) cout << "0";
                else if (prod > 0) cout << "+";
                else cout << "-";
            }
        }
        cout << "\n";
    }
    return 0;
}