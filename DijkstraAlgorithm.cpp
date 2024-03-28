#include<iostream>
#include<queue>
using namespace std;

class compare{
    public:
    
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }
};

// O(E + ElogV)
vector<int> getShortestPath(int V, int src, vector<pair<int, int> > adj[]){
    vector<bool> vis(V, false);
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
    
    dist[src] = 0;
    pq.push(make_pair(src, 0));
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();

        if(!vis[p.first]){
            vis[p.first] = true;

            for(int i = 0; i<adj[p.first].size(); i++){
                int u = p.first;
                int v = adj[p.first][i].first;
                int wt = adj[p.first][i].second;

                if(dist[u]+wt < dist[v]){
                    dist[v] = dist[u]+wt;
                    pq.push(make_pair(v, dist[v]));
                }
            }
        }
    }
    return dist;
}


int main(){

    // Dijkstra Algorithm

    int V = 6;
    vector<pair<int, int> > adj[V];
    adj[0].push_back(make_pair(1, 2));
    adj[0].push_back(make_pair(2, 4));

    adj[1].push_back(make_pair(2, 1));
    adj[1].push_back(make_pair(3, 7));

    adj[2].push_back(make_pair(4, 3));

    adj[3].push_back(make_pair(5, 1));

    adj[4].push_back(make_pair(3, 2));
    adj[4].push_back(make_pair(5, 5));

    int src = 0;
    vector<int> dist = getShortestPath(V, src, adj);
    for(int i = 0; i<V; i++){
        cout<<dist[i]<<" ";
    }cout<<endl;






    return 0;
}