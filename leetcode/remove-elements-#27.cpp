#include<iostream>
#include<vector>

// Leetcode 27. Remove Element
/*
    Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
    The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
*/

int removeElement(std::vector<int>& nums, int val){
        int i, j;
        for(j = 0, i = 0; j<nums.size(); ++j){
            if(nums[j] == val){
            }else{
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
}



int main(){
    std::vector<int> A = {1, 2, 2, 3, 5};
    std::cout<< removeElement(A, 2);
    return 0;
}


