         //Two sum
//Brute force approach:
for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++){
    // if(i==j) continue;
    if(arr[i]+arr[j]==target){
      return i,j;
    }
  }
}

//T.C:~O(n^2)

//better solution:
//using hashing
string read(int n, vector<int> book, int target){
         map<int,int>mpp;
         for(int i=0;i<n;i++){
                  int a=book[i];
                  int more = target -a;
                  if(mpp.find(more) != mpp.end()){
                     return "YES"; //for index {mpp[more],i};
                           
                  }
                  mpp[a] = i;
         }
         return "NO";
}

//T.C:O(n*nlogn) depends on map 
//S.C:O(n)

//optimal solution:
//without using map data structure.
//using 2 pointer approach.

//leetcode solution:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      map<int,int> mpp;
      int n=nums.size();
      for(int i=0;i<n;i++){
        int num=nums[i];
        int moreNeeded = target - num;
        if(mpp.find(moreNeeded)!=mpp.end()){
            return {mpp[moreNeeded],i};
        }
        mpp[num] =i;
      }
      return{-1,-1};
    }
};
