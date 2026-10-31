#include<iostream>
#include<vector>

// 33. Search in Rotated Sorted Array


int search(std::vector<int>& nums, int target) {
    int mid, low = 0, high = nums.size() - 1;
    while(low <= high){
        mid = low + (high - low)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[low] <= nums[mid]){
            if(nums[low] <= target && nums[mid] >= target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }else{
            if(nums[mid] <= target && nums[high] >= target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
