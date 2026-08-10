class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(i >= strs[j].size() || strs[j][i] != strs[0][i]){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
        
    }
};

// Leetcode Array #14    : Longest Common Prefix
 
// The pattern
    /*
        think of this as a table: 
                flower
                flow
                fly
                ^ First iteration;
                flower
                flow
                fly
                 ^  Second iteration;

                on each iteration check if coloumn 0 equal to row 0 and return char if equal, if not nothing;


    */