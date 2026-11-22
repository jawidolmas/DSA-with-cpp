#include<iostream>
#include<vector>
#include <unordered_map>
// LeetCode #169. Majority Element
// Find the majority element in a given array with size n. 
// Majority element is the element that is more than n/2
// Approach:
// Firstly, the direct solution is bruteforce. taking a condidate and going through all array, and doing this for each value in array. 
// this will take O(n^2) time;

// O(n^2) in time, O(1) in space
int majorityElement_Bruteforce(std::vector<int>& nums){
    int count = 0;
    for(int i = 0; i<nums.size(); i++){
        for(int j = 0; j<nums.size(); j++){
            if(nums[j] == nums[i]){
                count++;
            }
        }
        if(count > nums.size()/2){
            return nums[i]; 
        }
    }
    return -1;
}

// Can we improve this solution? yeah, its fairly possible that we can have better solutions. Another one is hash table, it reduces time to n
// but increases the space into n too. so if space is not important for us, this is a great solution for us. 

// O(n) in time and O(n) in space
int majorityElement_hashtable(std::vector<int> &nums){
    std::unordered_map<int, int> hash;
    for(int i = 0; i<nums.size(); i++){
        hash[nums[i]]++;
    }
    for(int j = 0; j<hash.size(); j++){
        if(hash[j] > nums.size()/2){
            return j;
        }
    }
    return -1;
}

// It is still not optimal solution, we are seeking for linear time and constant space. If we have a little bit knowledge about Boyer-Moore algorithm, 
// The problem will be so much simple. In here, we get a condidate and check if the next one is the same thing, if so, we increment count, 
// and go ahead to the end of array like this, and if any future indices are not equal to candidate, we decrement the count. whenever the count
// and condidate are equal, there is no majority element, when they are not, there is one majority element. 

//O(n) time and O(1) space
int majorityElement(std::vector<int> &nums){
    int candidate = nums[0], count = 0;
    for(int num : nums){
        if(count == 0){
            candidate = num;
            count = 1;
        }else if(num == candidate){
            count++;
        }else{
            count--;
        }
    }
    return candidate;
}


int main()
{
    std::vector<int> A = {3,2,3};
    std::cout << "Bruteforce: " << majorityElement_Bruteforce(A) << std::endl; 
    std::cout << "Hash Table: " << majorityElement_hashtable(A) << std::endl; 
    std::cout << "Optimal Solution: " << majorityElement(A) << std::endl; 

    return 0;
}

/*

Bruteforce: 3
Hash Table: 3
Optimal Solution: 3

*/