#include<iostream>
#include<queue>
using namespace std;

class Edge{
    public:
    int src;
    int dest;
    int wt;

    Edge(int src, int dest, int w){
        this->src = src;
        this->dest = dest;
        this->wt = w;
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

void getBFS(vector<Edge> graph[], int src, int V, vector<bool> &vis){
    // vector<bool> vis(V, 0);
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while(!q.empty()){
        int n = q.front();
        q.pop();
        cout<<n<<" ";

        for(int i = 0; i<graph[n].size(); i++){
            if(!vis[graph[n][i].dest]){
                q.push(graph[n][i].dest);
                vis[graph[n][i].dest] = true;
            }
        }
    }
}

int main(){

    int V = 7;
    vector<Edge> graph[V];
    createGraph(graph);

    vector<bool> vis(V, 0);
    cout<<"BFS of Graph is:"<<endl;

    for(int i = 0; i<V; i++){
        if(!vis[i]){
            getBFS(graph, i, V, vis);
        }
    }cout<<endl;





    return 0;
}