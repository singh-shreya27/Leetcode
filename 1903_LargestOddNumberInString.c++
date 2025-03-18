
//Largest odd number in a string.


class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;--i){
            if((num[i]-'0')%2!=0){
                //if odd digit is found , return string from 0 to i.
                return num.substr(0,i+1);
            }
        }
            //if no odd digit is found, return an empty string.
            return "";
    }
};



//num[i] - '0' converts the character num[i] to its corresponding integer value.
//The expression num[i] - '0' works because of how characters are represented in the ASCII (or Unicode) encoding.
//char ch = '5';
//int num = ch - '0'; // 53 (ASCII of '5') - 48 (ASCII of '0') = 5


//T.C:O(n)
//S.C:O(1)
