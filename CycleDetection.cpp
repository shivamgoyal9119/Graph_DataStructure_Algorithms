#include<iostream>
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

void createUnDirectedGraph(vector<Edge> graph[]){

    graph[0].push_back(Edge(0, 1, 1));

    graph[1].push_back(Edge(1, 0, 1));
    // graph[1].push_back(Edge(1, 2, 1));
    graph[1].push_back(Edge(1, 3, 1));

    // graph[2].push_back(Edge(2, 1, 1));
    graph[2].push_back(Edge(2, 3, 1));

    graph[3].push_back(Edge(3, 1, 1));
    graph[3].push_back(Edge(3, 2, 1));

}

void createDirectedGraph(vector<Edge> graph[]){

    graph[0].push_back(Edge(0, 1, 1));
    graph[1].push_back(Edge(1, 2, 1));
    graph[2].push_back(Edge(2, 3, 1));
    graph[3].push_back(Edge(3, 4, 1));
    // graph[4].push_back(Edge(4, 2, 1));

}

bool checkCycleInDirectedGraphByDFS(vector<Edge> graph[], vector<bool> &vis, vector<bool> &recSt, int src){
    vis[src] = true;
    recSt[src] = true;

    for(int i = 0; i<graph[src].size(); i++){
        int val = graph[src][i].dest;

        if(!vis[val]){
            if(checkCycleInDirectedGraphByDFS(graph, vis, recSt, val)){
                return true;
            }
        }
        else{
            if(recSt[val]){
                return true;
            }
        }
    }

    recSt[src] = false;
    return false;
}

bool checkCycleInUnDirectedGraphByDFS(vector<Edge> graph[], vector<bool> &vis, vector<int> &parent, int src){
    vis[src] = true;

    for(int i = 0; i<graph[src].size(); i++){
        int val = graph[src][i].dest;

        if(!vis[val]){
            parent[val] = src;
            if(checkCycleInUnDirectedGraphByDFS(graph, vis, parent, val)){
                return true;
            }
        }
        else{
            if(parent[src] != val){
                return true;
            }
        }
    }

    return false;
}


int main(){

    // -> undirected graph (DFS)
    // int V = 4;
    // vector<bool> vis(V, false);
    // vector<int> parent(V, -1);

    // vector<Edge> graph1[V];
    // createUnDirectedGraph(graph1);

    // int count = 0;
    // for(int i = 0; i<V; i++){
    //     if(!vis[i]){
    //         if(checkCycleInUnDirectedGraphByDFS(graph1, vis, parent, i)){
    //             count++;
    //             cout<<"Cycle is Present"<<endl;
    //         }
    //     }
    // }
    // if(count == 0){
    //     cout<<"Cycle Is Not Present"<<endl;
    // }

    // -> directed graph (DFS)

    int V = 5;
    vector<Edge> graph2[V];
    createDirectedGraph(graph2);

    vector<bool> vis(V, false);
    vector<bool> recSt(V, false);
    int count = 0;
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            if(checkCycleInDirectedGraphByDFS(graph2, vis, recSt, i)){
                count++;
                cout<<"Cycle is Present"<<endl;
            }
        }
    }
    if(count == 0){
        cout<<"Cycle Is Not Present"<<endl;
    }

    
    

    return 0;
}