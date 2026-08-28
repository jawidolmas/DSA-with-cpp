            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 

                        OPTIMIZATION PROBLEMS:   
                                GREEDY METHOD:
                                    Greedy method is used to find the Optimal Solution(the best possible solution) for an optimization problem.
                                
                                DIJKSTRA: Single Source Shortest Path
                                    Full explanation in iPad notes

                                Puesodocode:
                                                                                          
                                Algorithm prims(int cost[][], int n, int s){
                                    int d[] = new int[n+1];
                                    boolean selected[] = new boolean[n+1];
                                    for(int i = 0; i<n+1; i++){
                                        selected[i] = false;
                                    }
                                    for(int i = 1; i<=n; i++){
                                        d[i] = cost[s][i];
                                    }
                                    d[s]=0;
                                    selected[s]=true;
                                    int min=0, u=0;
                                    for(int k = 1; k<n; k++){
                                        min = MAX_INT;
                                        for(int i =1; i<=n; i++){
                                            if(selected[i]==false && d[i]<min){
                                                min = d[i];
                                                u =i;
                                            }
                                        }
                                        selected[u] = true;
                                        for(int v = 1; v<=n; v++){
                                            if(selected[v]=false && d[u]+cost[u][v] < d[v]){
                                                d[v] = d[u] + cost[u][v];
                                            }
                                        }
                                    }
                                    return d;
                                }






                                THE TIME TAKEND FOR THIS ALGORITHM IS O(n2) coz we scan and select for n time for n varaibles.  
                                
            */


    
