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

    graph[1].push_back(Edge(1, 2, 1));
    graph[1].push_back(Edge(1, 4, 1));

    graph[2].push_back(Edge(2, 1, 1));
    graph[2].push_back(Edge(2, 3, 1));

    graph[3].push_back(Edge(3, 2, 1));
    graph[3].push_back(Edge(3, 4, 1));

    graph[4].push_back(Edge(4, 3, 1));
    graph[4].push_back(Edge(4, 5, 1));
    graph[4].push_back(Edge(4, 1, 1));

    graph[5].push_back(Edge(5, 6, 1));
    graph[5].push_back(Edge(5, 4, 1));

    graph[6].push_back(Edge(6, 7, 1));
    graph[6].push_back(Edge(6, 9, 1));
    graph[6].push_back(Edge(6, 5, 1));

    graph[7].push_back(Edge(7, 6, 1));
    graph[7].push_back(Edge(7, 8, 1));
    
    graph[8].push_back(Edge(8, 7, 1));
    graph[8].push_back(Edge(8, 9, 1));
    graph[8].push_back(Edge(8, 10, 1));

    graph[9].push_back(Edge(9, 6, 1));
    graph[9].push_back(Edge(9, 8, 1));

    graph[10].push_back(Edge(10, 8, 1));
    graph[10].push_back(Edge(10, 11, 1));
    graph[10].push_back(Edge(10, 12, 1));

    graph[11].push_back(Edge(11, 10, 1));
    graph[11].push_back(Edge(11, 12, 1));

    graph[12].push_back(Edge(12, 10, 1));
    graph[12].push_back(Edge(12, 11, 1));

}

int getCountStronglyConnectedComponents(vector<Edge> graph[], int n, int src, vector<bool> &vis,
                                             vector<int> &time, vector<int> &low, int& setTime, int par){

    vis[src] = true;

    int count = 0;
    for(int i = 0; i<graph[src].size(); i++){
        int u = graph[src][i].src;
        int v = graph[src][i].dest;
        int wt = graph[src][i].wt;

        if(!vis[v]){
            time[v] = setTime++;
            low[v] = time[v];
            count+=getCountStronglyConnectedComponents(graph, n, v, vis, time, low, setTime, u);
            if(low[v] > time[u]){
                count++;
            }
            else{
                low[u] = low[v];
            }
        }
        else{
            if(low[v] < low[u] && v != par){
                low[u] = low[v];
            }
        }
    }

    return count;                                    
}

int main(){

    // Targan's Algorthms (Strongly Connected Components Or Find Bridge In A Graph)

    int V = 13;
    vector<Edge> graph[V];
    createGraph(graph);

    int src = 1;
    int setTime = 1;
    int par = 0;
    vector<bool> vis(V, false);
    vector<int> time(V, 0);
    vector<int> low(V, 0);

    cout<<getCountStronglyConnectedComponents(graph, V, src, vis, time, low, setTime, par)<<endl;

    

    return 0;
}