#include<iostream>
#include<vector>
    // 88. Merge Sorted Array


    // This merge works for two sorted array, but what leetcode wants is a little bit different in here. The problem we solved in here
    // is the classic merge sort problem, but here if the input A is 1 2 3 0 0 0, and B is 2 5 6, the output will be 1 2 2 3 0 0 0 5 6 coz it 
    // treats the zero as real smallest value in this input. 
void mergeClassic(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n){
    std::vector<int> A;
    A.reserve(m+n); 
    int i = 0, j = 0, k = 0;
    for(i=0, j=0; i<nums1.size() && j<nums2.size();){
        if(nums1[i] <= nums2[j]){
            A.push_back(nums1[i++]);
        }else{
            A.push_back(nums2[j++]);
        }
    }
    for(; i<nums1.size(); i++){
        A.push_back(nums1[i]);
    }
    for(; j<nums2.size(); j++){
        A.push_back(nums2[j]);
    }
    nums1 = std::move(A);
    for(auto& element : nums1){
        std::cout << element << " ";
    }
}

// What really leetcode wants is different; in fact, we really dont need any third array. we can do it inplace. 
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;
    while(j >= 0){
        if(i >= 0 && nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        }else{
            nums1[k--] = nums2[j--];
        }
    }
}

int main()
{   
    std::vector<int> A = {1, 2, 3, 0, 0, 0};
    std::vector<int> B = {2, 5, 6};
    merge(A, 3, B, 3);


    return 0;
}