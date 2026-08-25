#include <iostream>
using namespace std;


/*
        GRAPHS:
            All notes has been taken in iPad
            
            Depth First Search(DFS)

*/




void DFS(int G[][7], int start, int n){
    static int visisted[7] = {0};
    int i = start;
    if(visisted[i] == 0){
        cout << i << " ";
        visisted[i] = 1;
        for(int j=1; j<n; j++){
            if(G[i][j] == 1 && visisted[j] == 0){
                DFS(G, j, n);
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
    DFS(G, 4, 7);
    return 0;
}