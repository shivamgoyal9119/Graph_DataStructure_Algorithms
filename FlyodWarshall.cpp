#include<iostream>
using namespace std;

void shortest_distance(vector<vector<int> >&matrix){
    int size = matrix.size();
    
    for(int h = 0; h<size; h++){
        for(int i = 0; i<size; i++){
            for(int j = 0; j<size; j++){
                if(matrix[i][h] != -1 && matrix[h][j] != -1 ){
                    if(matrix[i][j] != -1){
                        matrix[i][j] = min(matrix[i][j], matrix[i][h]+matrix[h][j]);
                    }
                    else{
                        matrix[i][j] = matrix[i][h]+matrix[h][j];
                    }
                }
            }
        }
    }
}

int main(){

    // Flyod Warshall Algorithm

    int V = 3;
    vector<vector<int> > matrix;
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(43);
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(-1);
    vector<int> v3;
    v3.push_back(-1);
    v3.push_back(-1);
    v3.push_back(0);
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);

    cout<<"Before Flyod Warshall"<<endl;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }

    shortest_distance(matrix);

    cout<<"After Flyod Warshall"<<endl;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            cout<<matrix[i][j]<<" ";
        }cout<<endl;
    }




    return 0;
}