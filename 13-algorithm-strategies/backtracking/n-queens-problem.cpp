            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 

                        OPTIMIZATION PROBLEMS:   
                                    Backtracking: 
                                        Backtracking is a systematic search technique that builds a solution step-by-step, and whenever the current partial solution cannot 
                                        lead to a valid complete solution, it undoes the last choice and tries another.
                                        Full explanation in iPad notes;

                                Puesodocode:
                                int n = 4; 
                                int x[5];
                                
                                boolean valid(int k, int l){
                                    for(int i = 1; i<k; i++){
                                        if(x[i]==l || abs(i-k) == abd(x[i]-l)){
                                            return false;
                                        }
                                        return true;
                                    }
                                }
                                Algorithm NQueens(int k){
                                    for(int i = 1; i<=n; i++){
                                        if(valid(k, i){
                                            x[k] = i;
                                            if(k==n){
                                            print (x);
                                            return;
                                            }
                                        }
                                        NQueens(k+1);
                                    }
                                }






                                THE TIME TAKEND FOR THIS ALGORITHM IS O(n^n) coz we have recursive call inside a loop. Whenever we have a recuresive call inside a loop
                                it is mostly n to power of n. coz it does a lot of calls. 
                                
            */


    
