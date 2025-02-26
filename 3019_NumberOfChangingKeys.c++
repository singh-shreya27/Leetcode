          //Number of changing keys.

class Solution {
public:
    int countKeyChanges(string s) {
        int count=0;
        for(int i=1;i<s.size();i++){
             if(tolower(s[i])!= tolower(s[i-1])){
                count++;
             }
        }
        return count;
    }
};

//Inside the loop, tolower function is used to convert characters to lowercase before comparison. 
//This ensures that characters are considered equal regardless of case.

