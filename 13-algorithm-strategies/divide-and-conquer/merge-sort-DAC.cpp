            
            
            
            
            
            /*
                ALGORITHM STRATEGIES: 
                    1. DIVIDE and CONQUER:
                            Divide the problem into subproblems and solve it, then combine the solutions for the main problem.

                    THE EXPLNATIONS HAS BEEN TAKEN IN iPAD NOTES.

                    General strucutre:
                        Divide and Conquer is a recursive method to solve a problem:


                        MERGE SORT:
                            We now know that how a merge works and we can implement it in iterative method. But, can we implement it in recursive method? YEAH, we already
                            implemented it in 11-sorting-techniques lecture. But what about the pattern? when we see a merge sort problem, and we asked to implement using 
                            recursion, what we can know from there? any pattern? YEAH, divide and conquer. 

                                Prodecure:
                                    DAC: divide until smallest portion, then solve it, then combine all solutions and CONQUER the problem. 
                                    If a list is given to us and asked to sort, what we are going to do? split it in portions of problems, so we will continue to split until
                                    we get the smallest portion, so when a merge sort is small enough that does not need to be sorted? yeah, it is 1. if a list has only one 
                                    element, then it is already sorted. In that case, for example, if there is a list with 8 keys, we split it to two, it gets two lists of 4 
                                    keys in each, then again we split those two to another two, so we will have 4 lists which got 2 keys each, then again we split all those 4 
                                    and we will get 8 lists of 1 key in each. Do we need to split it more? no, coz only one key in a list is already sorted. so after that we 
                                    will merge each of those 8 elements. that means, we will merge list 1 with 2, list 3 with 4, list 5 with 6 and list 7 with 8. then we have
                                    4 elements of sorted list each got 2 elements, then again we do the same until we reach in root. thats it. 
                                    
                                    SEE THE PATTERN? it is recursion. first we called, then we returned, and while returning we also merged them. SIMPLE, ISNT IT? 



                                Puesodocode:

                                merge(int A[],  int l, int mid, int h) -> Already implemented / check sorting-techniques

                                Algorithm MergeRecusrsive(int A[], int l, int h){
                                    if(l<h)
                                        int mid = l+h/2;
                                        MergeRecursive(A, l, mid);
                                        MergeRecursive(A, mid+1, h);
                                        merge(A, l, mid, h);
                                }


                                Note: For real implementation and analysis, check: DSA-with-cpp/11-sorting-techniques/recursice-merge-sort.cpp
            */


    
