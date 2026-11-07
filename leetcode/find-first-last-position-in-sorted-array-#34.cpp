#include<iostream>
#include<vector>

// Leetcode #34 - Find First and Last Postion of an Element in Sorted Array
    // Time : O(logn)   
    // Space: O(1);
std::vector<int> searchRange(std::vector<int>& nums, int target){
    int l = 0, h = nums.size()-1;
    int first = -1, last = -1;
    int mid = 0;
    while(l <= h){
        mid = l + (h-l)/2;
        if(nums[mid] == target){
            first = mid;
            h = mid-1;
        }else if(nums[mid] < target){
            l = mid + 1;
        }else{
            h = mid-1;
        }
    }
    l = 0, h = nums.size()-1;
    while(l <= h){
        mid = l + (h-l)/2;
        if(nums[mid] == target){
            last = mid;
            l = mid+1;
        }else if(nums[mid] > target){
            h = mid-1;
        }else{
            l = mid+1;
        }

    }
    return {first, last};
}


int main()
{

    std::vector<int> A = {5, 7, 7, 8, 8, 8};
    for(const auto& i :searchRange(A, 1)){
        std::cout << i;
    }



    return 0;
}
