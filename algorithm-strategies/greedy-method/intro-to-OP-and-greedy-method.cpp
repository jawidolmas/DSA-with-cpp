            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 

                        OPTIMIZATION PROBLEMS: 
                                Optimization problems are those problems which has a constraint and an objective to get the best possible result within those constraints 
                                and objectives. (More detialed explanation in iPad notes).

                                We solve optimization problems using:
                                    1. Greedy Method
                                    2. Dynamic Programming
                                    3. Branch and Bound

                                
                                GREEDY METHOD:
                                    Greedy method is used to find the Optimal Solution(the best possible solution) for an optimization problem.
                                
                                General Structure:

                                algorithm greedy(A, n){  // Any kind of input, in here an array
                                    solution = 0; // There is no solution yet. 
                                    for i to n do:
                                        x = Select(A, n) // Select is an algorithm that selects the Objection(minimum or maximum) solution. so the Objective part of OP is 
                                        done by Select function in Greedy Method
                                        if (feasible(Solution, x){
                                            Solution = (Solution U x);  // U -> Union 
                                        }
                                    return solution;
                                }
            */


    
