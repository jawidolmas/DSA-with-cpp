            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 

                        OPTIMIZATION PROBLEMS:   
                                    Backtracking: 
                                        Backtracking is a systematic search technique that builds a solution step-by-step, and whenever the current partial solution cannot 
                                        lead to a valid complete solution, it undoes the last choice and tries another.
                                        Full explanation in iPad notes;



                                Permutations Bounding Function:

                                Puesodocode:
                                int res[];
                                bool sel[];
                                char str[];
                                Algorithm Perm(int k){
                                    if(k==n){
                                    print (res);
                                    return;
                                    }
                                    for(int i = 0; i<n; i++){
                                        if(k>0 && str[i]-res[k-1]==1){
                                            continue; // This will continue to loop, does not run statements below
                                            res[k] = str[i];
                                            sel[i] = true;
                                            Perm(k+1);
                                            sel[i] = false;
                                        }
                                    }
                                }






                                THE TIME TAKEND FOR THIS ALGORITHM IS O(n^n) coz we have recursive call inside a loop. Whenever we have a recuresive call inside a loop
                                it is mostly n to power of n. coz it does a lot of calls. If we check the tree of this program, it gives n! and we dont have a class like n!
                                in big O notation so we show it with O(n^n);
                                
            */


    
