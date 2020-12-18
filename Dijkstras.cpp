
/*
Definition -> Dijkstra's Algorithm is finding shortest Path between 
              the two vertices specified or finding shortest path 
              from given source vertex to all other vertices.

Algorihtm -> (Implementing Using Adjaceny Matrix)
step 1: input the graph in {vertex1,vertex2,edgeweight between vertex1 and vertex2}
srep 2: make an Adjacent matrix with pair as 
        vertex1 -> {vertex2,edgeweight} simillarly for vertex2 also. i.e.,
        vertex2 -> {vertex1,edgeweight}
step 3: Make a Distance vector for nodes and intialise with infinty.
step 3: Make source node distance = 0.
srep 4: Make a set with pairs as <distance , node>, Insert every possible distance 
        from source to other vertex into set.
step 5: loop until set becomes empty
step 6: remove the pair which is being visited in set
step 7: now traverse through all neighbours of removed pair, 
        If the distance of traversing node + weight < distance of neighbour then
        1 -> Erase the neighbour from set.
            i.e., s.erase({d[nb],nb});
        2 -> Increase the distance of neighbour with Weight and store it.
            i.e., d[nb] = d[i] + w;
        3 -> Add the neighbour again to Set. 
            i.e., s.insert({d[nb],nb});
step 8: Return the Distance vector.
*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define inf 1e18
int n;

vector<vector<pair<int,int>>> adj; // {neighbour,weight}

vector<int> dijkstras(int src)
{
    set<pair<int,int>> s;//{distance,node}
    vector<int> d(n+1,inf);
    d[src] = 0;

    for(int i=1;i<=n;++i)
    {
        s.insert({d[i],i});
    }

    while(!s.empty())
    {
        auto it = s.begin();
        int i = it->second;
        s.erase(it);

        for(pair<int,int> e : adj[i])
        {
            int nb = e.first, w = e.second;
            if(d[i]+w < d[nb])
            {
                s.erase({d[nb],nb});
                d[nb] = d[i] + w;
                s.insert({d[nb],nb});
            }
        }
    }

    return d;
}

int32_t main()
{
    int m;
    cin>>n; 
    cin>>m;
    adj.resize(n+1);

    while(m--)
    {
        int i,j,w;
        cin>>i>>j>>w;
        adj[i].push_back({j,w});
        adj[j].push_back({i,w});
    }

    vector<int> d = dijkstras(1);
    for(int i=1;i<=n;i++)
    {
        cout<< i << "\t" << d[i] << endl;
    }

    return 0;
}

// 9 12
// 1 2 7
// 1 3 15
// 1 6 16
// 2 3 5
// 2 4 18
// 3 6 2 
// 3 4 11
// 4 5 6
// 5 6 9
// 7 8 1
// 7 9 3
// 8 9 2
// 1       0
// 2       7
// 3       12
// 4       23
// 5       23
// 6       14
// 7       1000000000000000000
// 8       1000000000000000000
// 9       1000000000000000000
