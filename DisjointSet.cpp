#include<iostream>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;

    public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    // find ult parent & Applying Path Compression
    // Time Complexity = O(4alpha) ~ O(1)
    int findUltPar(int n){
        // base case
        if(parent[n] == n){
            return n;
        }

        parent[n] = findUltPar(parent[n]);
        return parent[n];
    }

    // Time Complexity = O(4alpha) ~ O(1)
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

    // Time Complexity = O(4alpha) ~ O(1)
    void unionBySize(int u, int v){
        int ultP_u = findUltPar(u);
        int ultP_v = findUltPar(v);

        if(ultP_u == ultP_v){
            return;
        }

        int size_u = size[ultP_u];
        int size_v = size[ultP_v];

        if(size_u < size_v){
            parent[ultP_u] = ultP_v;
            size[ultP_v]+=size[ultP_u];
        }
        else{
            parent[ultP_v] = ultP_u;
            size[ultP_u]+=size[ultP_v];
        }
    }
};

int main(){

    // Disjoint Set

    DisjointSet ds(7);

// --> Union By Rank
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);

    // // Q] Does 3 and 7 belong to same component?
    // if(ds.findUltPar(3) == ds.findUltPar(7)){
    //     cout<<"Same"<<endl;
    // }
    // else{
    //     cout<<"Not Same"<<endl;
    // }

    // ds.unionByRank(3, 7);

    // if(ds.findUltPar(3) == ds.findUltPar(7)){
    //     cout<<"Same"<<endl;
    // }
    // else{
    //     cout<<"Not Same"<<endl;
    // }

// --> Union By Size
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Q] Does 3 and 7 belong to same component?
    if(ds.findUltPar(3) == ds.findUltPar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }

    ds.unionBySize(3, 7);

    if(ds.findUltPar(3) == ds.findUltPar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }




    return 0;
}