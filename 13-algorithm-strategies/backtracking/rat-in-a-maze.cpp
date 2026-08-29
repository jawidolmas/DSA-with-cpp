            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 

                        OPTIMIZATION PROBLEMS:   
                                    Backtracking: 
                                        Backtracking is a systematic search technique that builds a solution step-by-step, and whenever the current partial solution cannot 
                                        lead to a valid complete solution, it undoes the last choice and tries another.
                                        Full explanation in iPad notes;



                                Rat in a Maze

                                Puesodocode:
                               
                                int N = 7, path = 0;
                                int M[N][N] = {init it.};
                                int sol[2][N*N];


                                Algorithm rim(int k=i, int j){
                                    if(i == N && j == N){
                                        print(sol);
                                        return;
                                    }else{
                                        M[i][j] = 0;
                                        sol[0][path]=i;
                                        sol[1][path] = j;
                                        path++;
                                        if(j<N && M[i][j+1] == 1)
                                            rim(i, j+1);
                                        if(i<N && M[i+1][j]==1)
                                            rim(i+1, j)
                                        if(j>1 && M[i][j-1] == 1)
                                            rim(i-1, j);
                                        if(i>1 && M[i-1][j]==1)
                                            rim(i-1, j);
                                    }
                                            M[i][j]=1; 
                                            path--;
                                }






                                THE TIME TAKEND FOR THIS ALGORITHM IS O(n2), if there was no condition then it will be O(4^ n*n);
            */


    
