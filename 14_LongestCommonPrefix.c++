           //Longest common prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

       if(strs.empty()) return "";
       //sort the array
       sort(strs.begin(), strs.end());

       //get the first and last strings
       string first=strs[0];
       string last=strs[strs.size()-1];

       string result="";
       //compare characters till mismatch
       for(int i=0;i<first.size();i++){
        if(first[i]!=last[i]) break;
        result+=first[i];
       }
       return result;
    }
};

//T.C:O(nlogn)
//S.C:O(1)
