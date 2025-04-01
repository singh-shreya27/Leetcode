      //Length of last word.


class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        int n=s.size();
        
        if (s.empty()) return 0; //Edge case:empty string.

        //Step 1:trim trailing spaces
        int end=n-1;

        while(end>=0 &&  s[end]==' '){
            end--;
        }

        if(end<0) return 0; //Edge case: String has only spaces.

        //count the length of the last word
        while(end>=0 && s[end]!=' '){
            length++;
            end--;
        }
       return length;
    }
};

//T.C:O(n)+O(n)=O(n) 
//S.C:O(1)
