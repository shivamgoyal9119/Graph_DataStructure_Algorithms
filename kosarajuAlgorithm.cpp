#include<iostream>
#include<stack>
using namespace std;

class Edge{
    public:

    int src, dest, wt;

    Edge(int src, int dest, int wt){
        this->src = src;
        this->dest = dest;
        this->wt = wt;
    }
};

void createGraph(vector<Edge> graph[]){

    graph[0].push_back(Edge(0, 2, 1));
    graph[0].push_back(Edge(0, 3, 1));
    graph[1].push_back(Edge(1, 0, 1));
    graph[2].push_back(Edge(2, 1, 1));
    graph[3].push_back(Edge(3, 4, 1));

}

void getTopoSort(vector<Edge> graph[], int src, vector<bool> &vis, stack<int> &st){
    vis[src] = true;

    for(int i = 0; i<graph[src].size(); i++){
        int v = graph[src][i].dest;

        if(!vis[v]){
            getTopoSort(graph, v, vis, st);
        }
    }

    st.push(src);
}

void getDFS(vector<Edge> graph[], int src, vector<bool> &vis){
    vis[src] = true;

    for(int i = 0; i<graph[src].size(); i++){
        int v = graph[src][i].dest;

        if(!vis[v]){
            getDFS(graph, v, vis);
        }
    }
}

int getStronglyConnectedComponents(vector<Edge> graph[], int V){
    stack<int> st;
    vector<bool> vis(V, false);

    for(int i = 0; i<V; i++){
        if(!vis[i]){
            getTopoSort(graph, i, vis, st);
        }
    }

    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }

    vector<Edge> tGraph[V];
    for(int i = 0; i<V; i++){
        int u = i;
        for(int j = 0; j<graph[u].size(); j++){
            int v = graph[u][j].dest;

            tGraph[v].push_back(Edge(v, u, 1));
        }
    }

    vector<bool> visited(V, false);
    int ans = 0;
    for(int i = 0; i<topo.size(); i++){
        int val = topo[i];
        if(!visited[val]){
            ans++;
            getDFS(tGraph, val, visited);
        }
    }

    return ans;
}

int main(){

    int V = 5;
    vector<Edge> graph[V];
    createGraph(graph);
    
    cout<<"Number of strongly connected components are: "<<getStronglyConnectedComponents(graph, V)<<endl;





    return 0;
}