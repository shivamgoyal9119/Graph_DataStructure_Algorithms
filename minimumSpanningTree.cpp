#include<iostream>
#include<queue>
using namespace std;

class compare{
    public:

    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.second > p2.second;
    }
};

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

    graph[0].push_back(Edge(0, 1, 5));
    graph[0].push_back(Edge(0, 2, 1));

    graph[1].push_back(Edge(1, 0, 5));
    graph[1].push_back(Edge(1, 2, 3));

    graph[2].push_back(Edge(2, 0, 1));
    graph[2].push_back(Edge(2, 1, 3));

}

// TC = ElogE
int getMinCost(vector<Edge> graph[], int src, int n){
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
    pq.push(make_pair(src, 0));
    vector<int> vis(n, false);
    int cost = 0;

    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();

        int u = p.first;
        int w = p.second;
        if(!vis[u]){
            cost+=w;
            vis[u] = true;
            for(int i = 0; i<graph[u].size(); i++){
                int v = graph[u][i].dest;
                int wth = graph[u][i].wt;

                if(!vis[v]){
                    pq.push(make_pair(v, wth));
                }
            }
        }
    }

    return cost;
}

int main(){
    
    //-> Minimum Spanning Tree(MST)
    // A spanning tree is defined as a tree-like subgraph of a connected,
    // undirected graph that includes all the vertices of the graph. 
    // Or, to say in Layman’s words, it is a subset of the edges of the graph
    // that forms a tree (acyclic) where every node of the graph is a part of the tree.

    // -> Prim's Algorithm

    vector<Edge> graph[3];
    createGraph(graph);

    int ans = getMinCost(graph, 0, 3);
    cout<<ans<<endl;


    return 0;
}