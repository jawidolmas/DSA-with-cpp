#include<iostream>
#include<vector>
#include<algorithm>


    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target){
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> pairs;
        int k;
        for(int i = 0; i<nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i + 1; j <nums.size(); j++){
                if(j > i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int l = j + 1;
                long long need = (long long)target - nums[i] - nums[j];
                k = nums.size() - 1;
                while(l < k){
                    long long sum = (long long)nums[l] + nums[k];
                    if(sum == need){
                        pairs.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k--;
                        l++;
                        while(l < k && nums[l] == nums[l-1]){
                            l++;
                        }
                        while(l < k && nums[k] == nums[k+1]){
                            k--;
                        }
                    } else if(sum > need){
                        k--;
                    }else{
                        l++;
                    }
                }
            }
        }
        return pairs;
    }








int main()
{   
    
    std::vector<int> A = {1,0,-1,0,-2,2};
    return 0;
}