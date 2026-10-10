#include <iostream>
#include <string>
#include<vector>

// Leetcode: 11. Container With Most Water


class solution{
    public:
        int max(int a, int b){
            if(a > b) return a;
            else return b;
        }
        int min(int a, int b){
            if( a > b) return b;
            else return a;
        }

        // O(n^2) in time and O(1) in space
        int maxArea(std::vector<int>& height){
            int best = 0;
            int n = static_cast<int>(height.size());
            for(int i = 0; i<n; i++){
                for(int j = i+1; j<n; j++){
                    int width = j-i;
                    int h = min(height[i], height[j]);
                    int area = width * h;
                    best = max(best, area);
                    
                }
            }
            return best;
        }

        //O(n) in time and O(1) in space - optimized solution with two pointer
        int maxAreaOptimized(std::vector<int>& height){
            int best = 0;
            int L = 0;
            int R = height.size()-1;
            while(L < R){
                int width = R-L;
                int h = min(height[L], height[R]);
                int area = width * h;
                best = max(best, area);
                if(height[L] < height[R]){
                    L = L+1;
                }else{
                    R = R-1;
                }
            }
            return best;
        }
};

int main()
{
    std::vector<int> A = {1,8,6,2,5,4,8,3,7};
    std::vector<int> B = {1, 1};
    solution s1;
    std::cout << s1.maxAreaOptimized(A);


    return 0;
}