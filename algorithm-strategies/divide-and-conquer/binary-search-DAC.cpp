            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 
                    1. DIVIDE and CONQUER:
                            Divide the problem into subproblems and solve it, then combine the solutions for the main problem.

                    THE EXPLNATIONS HAS BEEN TAKEN IN iPAD NOTES.

                    General strucutre:
                        Divide and Conquer is a recursive method to solve a problem:


                        BINARY SEARCH: 
                            Binary search is a problem which is solved using divide and conquer pattern. 
                                A binary search is possible in a sorted array, which we get its low, high and middle, if the key is equal to middle, then return it(That
                                means, the problem is small enough and directly solved), if middle is not = key, then DIVIDE the list into half by using l+h/2(that means
                                the problem is big and we need to DIVIDE it) and do this procedure until we find the KEY. once the key found, return it and the called functions(
                                that means return the SOLUTIONS). 
                                HERE WE GO, while explaining binary search, we explained DIVIDE and CONQUER strategy. so Binary search can be solved using DAC and the question is
                                CAN WE IMPLEMENT IT USING RECURSION? becuase DAC is recursive only. YEAH WE CAN IMPLEMENT IT. 


                                Puesodocode:

                                algorithm BinarySr(int l, int high, int key){
                                    if(l > h){
                                         return -1;
                                    int mid =l+h/2;
                                    if(key == A[mid])
                                        return mid;
                                    else if( key < A[mid])
                                        return BinarySr(l, mid-1, key);
                                    else
                                        return BinarySr(mid+1, h, key);

                                 }



                                Note: For real implementation and analysis, check: DSA-with-cpp/03-arrays/arrayADT/recursice-binary-search.cpp
            */


    
