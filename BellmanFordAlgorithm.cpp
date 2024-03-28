#include<iostream>
using namespace std;

// O(V*E)
vector<int> bellman_ford(int V, vector<vector<int> >& edges, int S) {
    int num = pow(10, 8);
    vector<int> dist(V, num);
    dist[S] = 0;
    bool chaeckNegCycle = false;
    
    for(int k = 1; k<=V; k++){
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            if(dist[u] != num && dist[u]+wt < dist[v]){
                if(k == V){
                    chaeckNegCycle = true;
                    break;
                }
                dist[v] = dist[u]+wt;
            }
        }
    }
    
    if(chaeckNegCycle){
        vector<int> v(1, -1);
        return v;
    }
    return dist;
}

int main(){

    // BellmanFord Algorithm

    int V = 3;
    int S = 2;
    vector<vector<int> > Edge;
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(5);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(3);
    vector<int> v3;
    v3.push_back(1);
    v3.push_back(2);
    v3.push_back(-1);
    vector<int> v4;
    v4.push_back(2);
    v4.push_back(0);
    v4.push_back(1);

    Edge.push_back(v1);
    Edge.push_back(v2);
    Edge.push_back(v3);
    Edge.push_back(v4);

    vector<int> dist = bellman_ford(V, Edge, S);

    for(int i = 0; i<dist.size(); i++){
        cout<<dist[i]<<" ";
    }cout<<endl;






    return 0;
}