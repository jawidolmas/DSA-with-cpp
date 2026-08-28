            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 

                        OPTIMIZATION PROBLEMS:   
                                GREEDY METHOD:
                                    Greedy method is used to find the Optimal Solution(the best possible solution) for an optimization problem.
                                
                                Prim's Algorithm: is an algorithm for MST to find the minimum spanning tree. This works in way that select the minimum edge first and 
                                then continue selecting the minimum edge in a way that keeps the tree connected.
                                More explanation on iPad notes;


                                Puesodocode:
                                                                                          
                                Algorithm prims(int cost[][], int n){
                                    int minCost = 0;
                                    int near[] = new int[n+1];
                                    boolean selected[] = new boolean[n+1];

                                    int u=1, v;
                                    int min = MAX_INT;
                                    for(int i = 1; i<=n; i++){
                                        if(cost[1][i] < min){
                                        min = cost[1][i];
                                        v = i;
                                        }
                                    }
                                    selected[u] = selected[v] = true; 
                                    minCost += cost[u][v];
                                    for(int i = 1; i<=n; i++){
                                        if(cost[u][i] < cost[v][i]){
                                            near[i] = u;
                                        }else{
                                        near[i] = v;
                                        }
                                    }
                                    
                                    for(int i = 1; i<=n-2; i++){
                                        min=MAX_INT;
                                        for(int j = 1; j<=n j++){
                                            if(selected[j]==false && cost[j][near[j]]<min){
                                                min = cost[j][near[j]];
                                                v = j;
                                            }
                                        }
                                        u = near[v];
                                        minCost += cost[u][v]; 
                                        selected[v] = true;
                                        for(int k = 1; k<=n; k++){
                                            if(selected[k]=false && cost[k][v] < cost[k][near[k]]){
                                                near[k] = v;
                                            }
                                        
                                        }
                                    }
                                    return minCost; 
                                }



                                THE TIME TAKEND FOR THIS ALGORITHM IS O(n2) coz we use adjacency matix; 
                                
            */


    
