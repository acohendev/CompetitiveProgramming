#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct unionfind
{
    vector<int> rank;
    vector<int> parent;
    vector<int> sizes;
    unionfind(int size)
    {
        rank=vector<int>(size,0);
        parent=vector<int>(size);
        sizes = vector<int>(size, 1);
        for(int i=0;i<size;i++)
            parent[i]=i;
    }

    int find(int x){
        int tmp=x;
        while(x!=parent[x]) x=parent[x];
        while(tmp!=x)//for log*, not needed most of the time
        {
            int remember=parent[tmp];
            parent[tmp]=x;
            tmp=remember;
        }
        return x;
    }
    int Union(int p, int q){
        p = find(p);
        q = find(q);
        if(q==p)
        {
            //alredy in the same group
            return sizes[p];
        }
        if(rank[p] < rank[q])
        {
            parent[p] = q;
            sizes[p] += sizes[q];
            sizes[q] = sizes[p];
        } 
        else 
        {
            parent[q] = p;
            sizes[q] += sizes[p];
            sizes[p] = sizes[q];
        }
        if(rank[p] == rank[q]) rank[p]++;
        return sizes[p];
    }
};

int main ()
{
    int T, F;

    cin >> T;

    while (T--)
    {
        cin >> F;

        int max_ppl = min (F * 2, 100000);

        unionfind uf(max_ppl);
        string lhs, rhs;
        unordered_map<string, int> name_id_map;
        int key = 0;

        while (F--)
        {
            bool inserted = false;
            cin >> lhs;
            cin >> rhs;

            inserted = name_id_map.insert(make_pair(lhs, key)).second;
            if (inserted) key++;
            inserted = name_id_map.insert(make_pair(rhs, key)).second;
            if (inserted) key++;

            cout << uf.Union(name_id_map[lhs], name_id_map[rhs]) << endl;
        }
    }

    return 0;
}