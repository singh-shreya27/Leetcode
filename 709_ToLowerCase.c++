             //to lower case:

//leetcode solution:
class Solution {
public:
    string toLowerCase(string s) {
        string str="";
        char c;
        for(int i=0;i<s.length();i++){
            c=s[i];
            if(s[i]>='A' && s[i]<='Z'){
                c=(c-'A')+'a';
                str+=c;
            }
            else
            str+=c;
        }
        return str;
    }
};
