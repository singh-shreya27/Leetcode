              //Valid Palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        //remove non-alphanumeric characters and convert to lowercase.
        string processed;
        for(char c:s){
            if(isalnum(c)){
                processed+=tolower(c);
            }
        } 
       //check if processed string is a palindrome.
       int left=0, right=processed.size()-1;
       while(left<right){
        if(processed[left]!= processed[right]){
            return false;
        }
        left++;
        right--;
       }
     return true;

    }
};
