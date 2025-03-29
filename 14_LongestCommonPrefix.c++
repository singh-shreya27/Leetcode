           //Longest common prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        // Take the first string as the initial prefix candidate
        string prefix=strs[0];

        for(int i=1;i<strs.size();++i){
             // Compare the current prefix with each string in the array
             while(strs[i].find(prefix)!=0){
                  // If the current prefix is not a prefix of strs[i], shorten it
                  prefix=prefix.substr(0,prefix.length()-1);
                  if(prefix.empty()){
                    return "";
                  }
             }
        }
        return prefix;
    }
};

//T.C:O(n*m)
//S.C:O(1)
//n is the number of strings in the array.
//m is the length of the longest string (or the prefix).
