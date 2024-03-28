#include<iostream>
using namespace std;

class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    
    public:
    DisjointSet(int n){
        rank.resize(n, 0);
        parent.resize(n);
        
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }
    }
    
    int findUltPar(int n){
        // base case
        if(parent[n] == n){
            return n;
        }
        
        parent[n] = findUltPar(parent[n]);
        return parent[n];
    }
    
    void unionByRank(int u, int v){
        int ultP_u = findUltPar(u);
        int ultP_v = findUltPar(v);
        
        if(ultP_u == ultP_v){
            return;
        }
        
        int rank_u = rank[ultP_u];
        int rank_v = rank[ultP_v];
        
        if(rank_u > rank_v){
            parent[ultP_v] = ultP_u;
        }
        else if(rank_u < rank_v){
            parent[ultP_u] = ultP_v;
        }
        else{
            parent[ultP_v] = ultP_u;
            rank[ultP_u]++;
        }
    }
};


static bool getSort(vector<int> &v1, vector<int> &v2){
    return v1[2] < v2[2];
}

//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int> > adj[]){
    vector<vector<int> > newAdj;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<adj[i].size(); j++){
            int u = i;
            int v = adj[i][j][0];
            int wt = adj[i][j][1];
            
            vector<int> temp;
            temp.push_back(u);
            temp.push_back(v);
            temp.push_back(wt);
            newAdj.push_back(temp);
        }
    }
    sort(newAdj.begin(), newAdj.end(), getSort);
    
    int ans = 0;
    DisjointSet ds(V);
    for(int i = 0; i<newAdj.size(); i++){
        int u = newAdj[i][0];
        int v = newAdj[i][1];
        int wt = newAdj[i][2];
        if(ds.findUltPar(u) != ds.findUltPar(v)){
            ans+=wt;
            ds.unionByRank(u, v);
        }
    }
    
    return ans;
}

int main(){

    // Kruskal's Algorithm

    int V = 3;
    vector<vector<int> > adj[V];
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(5);
    adj[0].push_back(temp);
    temp.pop_back();
    temp.pop_back();
    temp.push_back(2);
    temp.push_back(3);
    adj[1].push_back(temp);
    temp.pop_back();
    temp.pop_back();
    temp.push_back(0);
    temp.push_back(1);
    adj[2].push_back(temp);

    cout<<"MST Weight Is: "<<spanningTree(V, adj)<<endl;


    return 0;
}