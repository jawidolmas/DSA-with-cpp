            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 

                        OPTIMIZATION PROBLEMS:   
                                GREEDY METHOD:
                                    Greedy method is used to find the Optimal Solution(the best possible solution) for an optimization problem.
                                
                                KNAPSACK ALGORITHM:
                                    Knapsack algorithm is actually a bag problem, there is a problem, an objective, a constraint and we are asked to solve it using a bag
                                    or similar to that. This is a real world problem and usefull in businesses like shippings, and other important problems. 
                                    FULL EXPLANATION IS IN iPad notes.

                                Here we have a problem, we have 7 objects and each object has a price and weight, the constraint is to get at most 15kg of those objects. and the
                                objective is to get the maximum profit from those objects. So this is a maximization problem. We are going to use the Knapsack problem in here. 
                                Knapsack problem says take a bag, add the values with heighest profit and lowest weight. So how we can do that, there can be an object with 100 profit
                                and 5 kg, and there can be 2 objects each costs 80 and each one is 2 kg. so which one we take? SO HERE IS THE GREEDY METHOD TURN TO TAKE THE CONTROL. 

                                Greedy method is: Someone tried different ways to solve a problem and found one of them the OPTIMAL SOLUTION. 
                                in here, the optimal solution is Pi/Wi means profit of each obj/weight of that object, and then add them in decreasing order in the bag. thats it. 



                                Puesodocode:
                                                                                            n = 7, m = 15
                                algorithm Knapsack(double obj[][], int n, int m){
                                    //first we need to sort the objects and find the Pi/Wi in decreasing order
                                    Sort(obj, n) // a function to sort and make the order of profits
                                    double profit = 0.0; 
                                    for(int i =0; i<n; i++){
                                        if(obj[0][i] <= m){
                                        profit += obj[0][i];
                                        m = m - obj[1][i];
                                        }else{
                                        profit += m * obj[0][i]/obj[1][i];
                                        break;
                                        }
                                    }
                                    return profit;
                                }
                                
            */


    
