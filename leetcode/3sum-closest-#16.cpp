#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

// Three Sum Closest
    //You are given an integer array nums of length n and an integer target.
    //Find three integers at distinct indices in nums such that the sum is closest to target.
    //Return the sum of the three integers.
    // 14ms and 14.11 MB 

    int threeSumClosest(std::vector<int> &nums, int target){
        std::sort(nums.begin(), nums.end());
        int closest;
        int i = 0;
        closest = nums[i]  + nums[1] + nums[nums.size()-1];
        size_t size = nums.size();
        for(; i<size-2; i++){
            int j = i+1, k = nums.size() - 1;   
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(closest - target)){
                    closest = sum;
                }
                if(sum == target){
                    return sum;
                }else if(sum > target){
                        k--;
                }else{
                    j++;
                }
            }
        }
        return closest; 
        
    }




int main()
{
    std::vector<int> A = {-1, 2, 1, -4};
    std::cout << threeSumClosest(A, -2);

    return 0;
}
