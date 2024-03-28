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

void createGraph(vector<Edge> graph[]){

    graph[0].push_back(Edge(0, 1, 1));
    graph[0].push_back(Edge(0, 2, 1));

    graph[1].push_back(Edge(1, 0, 1));
    graph[1].push_back(Edge(1, 3, 1));

    graph[2].push_back(Edge(2, 0, 1));
    graph[2].push_back(Edge(2, 4, 1));

    graph[3].push_back(Edge(3, 1, 1));
    graph[3].push_back(Edge(3, 4, 1));
    graph[3].push_back(Edge(3, 5, 1));

    graph[4].push_back(Edge(4, 2, 1));
    graph[4].push_back(Edge(4, 3, 1));
    graph[4].push_back(Edge(4, 5, 1));

    graph[5].push_back(Edge(5, 3, 1));
    graph[5].push_back(Edge(5, 4, 1));
    // graph[5].push_back(Edge(5, 6, 1));

    // graph[6].push_back(Edge(6, 5, 1));
}

void getDFS(vector<Edge> graph[], int src, vector<bool> &vis){
    vis[src] = true;
    cout<<src<<" ";

    for(int i = 0; i<graph[src].size(); i++){
        if(!vis[graph[src][i].dest]){
            getDFS(graph, graph[src][i].dest, vis);
        }
    }
}

int main(){

    int V = 7;
    vector<Edge> graph[V];
    createGraph(graph);
    vector<bool> vis(V, 0);

    cout<<"DFS of Graph is:"<<endl;
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            getDFS(graph, i, vis);
        }
    }cout<<endl;




    return 0;
}