                //Maximum Subarray Sum:

//subarray:contiguous part of array.

//brute force approach:
int maxi=INT_MIN;
for(int i=0;i<n;i++){
  for(int j=i;j<n;j++){
    int sum=0;
    for(int k=i;k<j;k++){        //every subarray generation.
      sum+=arr[k];                    
    }
    maxi=max(sum,maxi);
  }
}
//T.C:~ O(n^3)
//S.C:O(1)

//better solution:
int maxi=INT_MIN;
for(int i=0;i<n;i++){
    int sum=0;
  for(int j=i;j<n;j++){
      sum+=arr[j];                    
    }
    maxi=max(sum,maxi);
  }
//T.C:O(n^2)
//S.C:O(1)

//Optimal solution:
             //KADANE'S ALGORITHMN


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0; int maxi=INT_MIN;int ansStart =-1; int ansEnd =-1;int start;
        for(int i=0;i<nums.size();i++){
            if(sum==0) int start=i;
            sum+=nums[i];
             if(sum> maxi){
                maxi = sum;
                ansStart = start,ansEnd=i;
             }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};

//T.C:O(n)
//S.C:O(1)
