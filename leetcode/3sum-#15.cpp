#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

// Leetcode: 15. 3Sum


class solution{
    public:

        // O(n^3) in time and O(logn) in space
        std::vector<std::vector<int>> threesum(std::vector<int>& nums){   
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> pairs;
            for(int i = 0; i<nums.size(); i++){
                    if(i > 0 && nums[i] == nums[i-1]){
                        continue;
                    }
                for(int j = i+1; j<nums.size(); j++){
                    if(j > i+1 && nums[j] == nums[j-1]){
                        continue;
                    }
                    for(int k = j+1; k<nums.size(); k++){
                    if(k > j+1 && nums[k] == nums[k-1]){
                        continue;
                    }
                        if(nums[i]+nums[j]+nums[k] == 0){
                            pairs.push_back({nums[i], nums[j], nums[k]});
                            
                        }
                    }
                }
            }
            return pairs;
        }

        // O(n^2) in time and O(logn) in space
        std::vector<std::vector<int>> threesumOptimized(std::vector<int>& nums){
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> pairs;
            for(int i = 0; i<nums.size(); i++){
                int L = i+1;
                int R = nums.size() - 1;
                if(i > 0 && nums[i] == nums[i-1]){
                    continue;
                }
                while(L < R){
                    if(nums[L] + nums[R] == -nums[i]){
                        pairs.push_back({nums[i], nums[L], nums[R]});
                        L = L + 1;
                        R = R - 1;
                        while(L < R && nums[R] == nums[R+1]){
                            R = R-1;
                        }
                        while(L < R && nums[L] == nums[L-1]){
                        L = L + 1;
                        }
                    }else if(nums[L] + nums[R] > -nums[i]){
                            R = R-1;
                    }else {
                        L = L + 1;
                    }
                }
            }
            return pairs;
        }
       
};

int main()
{
    std::vector<int> A = {-2, 0, 0, 2, 2};
    std::vector<int> B = {0, 0, 0,};
    solution s1;
    
    auto result = s1.threesumOptimized(A);

    // Print each triplet
    for (const auto& triplet : result) {
        std::cout << "[ ";
        for (int val : triplet) {
            std::cout << val << " ";
        }
        std::cout << "]\n";
    }
   


    return 0;
}