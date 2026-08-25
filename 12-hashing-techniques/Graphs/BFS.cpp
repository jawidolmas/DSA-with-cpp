#include <iostream>
using namespace std;

#include "Queue.hpp"

/*
        GRAPHS:
            All notes has been taken in iPad
            
            Breadth First Search(BFS)

*/

void BFS(int G[][7], int start, int n){
    int visited[7] = {0};
    int i = start;
    cout << i << " ";
    visited[i] = 1;
    enqueue(i);
    
    while(!isEmpty()){
        i = dequeue();
        for(int j = 1; j<n; j++){
            if(G[i][j] == 1 && visited[j] == 0){
                cout << j << " ";
                visited[j] = 1;
                enqueue(j);
            }
        }    
    }
}




int main()  
{
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0}, 
                   {0, 1, 0, 0, 1, 0, 0}, 
                   {0, 0, 1, 1, 0, 1, 1}, 
                   {0, 0, 0, 0, 1, 0, 0}, 
                   {0, 0, 0, 0, 1, 0, 0}
                };
    BFS(G, 4, 7);
    return 0;
}