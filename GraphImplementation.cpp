#include<iostream>
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

    graph[0].push_back(Edge(0, 2, 2));

    graph[1].push_back(Edge(1, 2, 10));
    graph[1].push_back(Edge(1, 3, 0));

    graph[2].push_back(Edge(2, 0, 2));
    graph[2].push_back(Edge(2, 1, 10));
    graph[2].push_back(Edge(2, 3, -1));

    graph[3].push_back(Edge(3, 1, 0));
    graph[3].push_back(Edge(3, 2, -1));

}

int main(){

    // Graph Implementation

    // By Adjacency List

    // graph[0].push_back(Edge(0, 2));
    // Edge e = Edge(1, 2);  ***

    int V = 4;
    vector<Edge> graph[V];
    createGraph(graph);

    // print 2's neighbours
    for(int i = 0; i<graph[2].size(); i++){
        cout<<graph[2][i].src<<" -> "<<graph[2][i].dest<<" Weight: "<<graph[2][i].wt<<endl;
    }

    


    return 0;
}