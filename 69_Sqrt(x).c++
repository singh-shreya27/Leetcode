
                       //Binary Search on answers 
//Find the sqrt of an integer.

//Brute force approach:
//n=28
int ans=1;
for(int i=1;i<n;i++){
  if(i*i<=n){
    ans=i;
  }
  else
    break;
}
//T.C:O(n)

//binary search on answers

int low=1, high=n;
int ans=1;
while(low<=high){
  int mid=(low+high)/2;
  if((mid*mid)<=n){
    ans=mid;
    low=mid+1;
  }
  else
    high=mid-1;
}
return high/ans;


//leetcode solution:

class Solution {
public:
    int mySqrt(int x) {
        int low=1, high=x;
        while(low<=high){
            long long mid=low+(high-low)/2;   //to avoid overflow use mid as long long .
            long long val=mid*mid;
            if(val<=x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};

//T.C:O(log x)
  
