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
    graph[5].push_back(Edge(5, 6, 1));

    graph[6].push_back(Edge(6, 5, 1));

}

void getAllPaths(vector<Edge> graph[], int src, int target, vector<bool> &vis, string &path){
    if(src == target){
        char ch = src + '0';
        path.push_back(ch);
        cout<<path<<endl;
        path.pop_back();
        return;
    }

    char ch = src + '0';
    path.push_back(ch);
    vis[src] = true;

    for(int i = 0; i<graph[src].size(); i++){
        int e = graph[src][i].dest;
        if(!vis[e]){
            getAllPaths(graph, e, target, vis, path);
        }
    }

    vis[src] = false;
    path.pop_back();
}

int main(){

    int V = 7;
    vector<Edge> graph[V];
    createGraph(graph);

    string path = "";
    vector<bool> vis(V, false);

    cout<<"All Path's from src to target are: "<<endl;
    getAllPaths(graph, 0, 5, vis, path);
    
    
 


 

    return 0;
}