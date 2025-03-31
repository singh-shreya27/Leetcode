                      //Find the index of first occurrence in a string

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();
       //edge case: if needle is empty
       if(n==0) return 0;
       //iterate through haystack
       for(int i=0;i<=m-n;i++){
        //check if needle matches substring starting at index i of haystack
        int j;
        for(j=0;j<n;j++){
            if(haystack[i+j]!=needle[j]){
              break; //mismatch found
              
            }
        }
      if(j==n){
        return i; //found needle at index i
       }
    }
    return -1; //needle not found
       }      
};


//T.C:
//O((m-n+1)*n) = O(m*n) in the worst case.
