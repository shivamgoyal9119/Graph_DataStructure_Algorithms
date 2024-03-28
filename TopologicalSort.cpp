#include<iostream>
#include<stack>
using namespace std;

void getTopoSort(int V, vector<int> adj[], stack<int> &st, int src, vector<bool> &vis){
    vis[src] = true;
    
    for(int i = 0; i<adj[src].size(); i++){
        int val = adj[src][i];
        if(!vis[val]){
            getTopoSort(V, adj, st, val, vis);
        }
    }
    
    st.push(src);
}

vector<int> getTopoSort(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    stack<int> st;
    
    for(int i = 0; i<V; i++){
        if(!vis[i]){
           getTopoSort(V, adj, st, i, vis); 
        }
    }
    
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}

int main(){

    // Topological Sort
    vector<int> adj[6];
    int V = 6;

    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[5].push_back(0);
    adj[5].push_back(2);

    vector<int> topoSort = getTopoSort(V, adj);

    cout<<"Topological Sort is:"<<endl;
    for(int i = 0; i<topoSort.size(); i++){
        cout<<topoSort[i]<<" ";
    }cout<<endl;

    // GFG ** Problem --> Eventual Safe States == done

    return 0;
}