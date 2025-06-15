          //Reverse words in a string.

class Solution {
public:
    string reverseWords(string s) {
        //first reverse the whole string
        //then reverse individual words 
        //then store them in space separated ans.
        //remove the first space using substr.

        reverse(s.begin(),s.end());
            string ans="";
        for(int i=0;i<s.size();i++){
            string word="";
            while(i<s.size() && s[i]!=' '){
                word+=s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(word.size()>0){
                ans+=" "+word;
            }
        }
        return ans.substr(1);
    }
};

//T.C:O(n)
