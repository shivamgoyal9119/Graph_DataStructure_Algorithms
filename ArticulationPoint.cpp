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

    graph[1].push_back(Edge(1, 0, 1));
    graph[1].push_back(Edge(1, 4, 1));

    graph[2].push_back(Edge(2, 3, 1));
    graph[2].push_back(Edge(2, 4, 1));

    graph[3].push_back(Edge(3, 2, 1));
    graph[3].push_back(Edge(3, 4, 1));

    graph[4].push_back(Edge(4, 1, 1));
    graph[4].push_back(Edge(4, 2, 1));
    graph[4].push_back(Edge(4, 3, 1));

}

void getArticulationPt(vector<Edge> graph[], int src, int &tim, int parent, 
                    vector<int> &time, vector<int> &low, vector<bool> &vis, unordered_map<int, bool> &mark){
    vis[src] = true;
    int child = 0; // ***

    for(int i = 0; i<graph[src].size(); i++){
        int u = graph[src][i].src;
        int v = graph[src][i].dest;
        int wt = graph[src][i].wt;

        if(!vis[v]){
            time[v] = ++tim;
            low[v] = time[v];

            getArticulationPt(graph, v, tim, u, time, low, vis, mark);
            low[u] = min(low[u], low[v]);
            if(low[v] >= time[u] && parent != -1){
                mark[u] = true;
            }
            child++;
        }
        else{
            if(v != parent){
                low[u] = min(low[u], time[v]);
            }
        }
        if(parent != -1 && child > 1){
            mark[src] = true;
        }
    }
}

int main(){

    // Articulation Point 
    // Time Complexity O(V+2E)

    int V = 5;
    vector<Edge> graph[V];
    createGraph(graph);

    vector<int> low(V, 0);
    vector<int> time(V, 0);
    vector<bool> vis(V, false);

    unordered_map<int, bool> mark;
    int tim = 0;
    int src = 0;

    getArticulationPt(graph, src, tim, -1, time, low, vis, mark);
    vector<int> ans;
    for(auto i : mark){
        if(i.second){
            ans.push_back(i.first);
        }
    }

    for(auto i : ans){
        cout<<i<<" ";
    }cout<<endl;





    return 0;
}