            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 

                        OPTIMIZATION PROBLEMS:   
                                    Backtracking: 
                                        Backtracking is a systematic search technique that builds a solution step-by-step, and whenever the current partial solution cannot 
                                        lead to a valid complete solution, it undoes the last choice and tries another.
                                        Full explanation in iPad notes;



                                Sudoku Solver:

                                Puesodocode:

                                int S[10][10];

                                algorithm isValid(int r, int c, int val){
                                    for(int i = 1; i<=9; i++){
                                    if(S[r][i]==val) return false;
                                    }
                                    for(int i = 1; i<=9; i++){
                                    if(S[r][c]==val) return false;
                                    }
                                    int blockRow = r - (r-1)%3;
                                    int blockCol = c - (c-1)%3;

                                    for(int i = 0; i<3; i++){
                                        for(int j = 0; j<3; j++){
                                            if(S[blckRow+i][blockCol+j]==val) return false;
                                        }
                                    }
                                        return true;
                                }


                                Algorithm sudoku(int r, int c){
                                    if(r==10 && c == 1){
                                        print 2D array S;
                                    }else{
                                        if(S[r][c] != 0){
                                        sudoku(c==9?r+1:r, c==9?1:c+1);
                                        }else{
                                            for(int i = 1; i<=9; i++){
                                                if(isValid(r, c, i)){
                                                    S[r][c] = i;
                                                    sudoku(c==9?r+1:r, c==9?1:c+1);
                                                    S[r][c] = 0;
                                                }
                                            }
                                        }
                                    }
                                }






                                THE TIME TAKEND FOR THIS ALGORITHM IS O(n^n*n) so this is a known problem and it consumes a lot of time. as it is a 9x9 matrix
                                then this will do a work of 9^9*9 = 9^81 which is extremely time consuming program. Actaully the 9^81 is the maximum trying the backtracking 
                                will do, that means the maximum bruteforce tryings. 
            */


    
