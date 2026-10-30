#include<iostream>
#include<unordered_map>


// LeetCode #13 - Roman to Integer


int romanToInt(std::string s){
    std::unordered_map<char, int> map = {    
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
    };
    int total = 0;
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(i+1 < n && map[s[i]] < map[s[i+1]]){
            total -= map[s[i]];
        }else{
            total += map[s[i]];
        }
    }
    return total;

}  

int main()
{
    std::cout << romanToInt("II");



    return 0;
}