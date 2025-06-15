            //Largest odd number in a string.

class Solution {
public:
    string largestOddNumber(string num) {
        //find the rightmost odd integer and then store the substring till that index.
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
              return num.substr(0,i+1);
            }
        }
        return "";
    }
};
