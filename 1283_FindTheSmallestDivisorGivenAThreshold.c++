      //find the smallest divisor given a threshold.

//brute force approach:
for(int divisor=1;divisor<=max[arr];divisor++){
    int sum=0;
    for(int i=0;i<n;i++){
      sum+=ceil(arr[i]/divisor);
    }
  if(sum<=threshold)
    return divisor;
}
return -1;

//T.C:O(max*n)
//S.C:O(1)

//whenever we have to find answers like minimum or maximum we have to use binary search on answers.

//pesudo code

function(arr, threshold){
  int low=1, high=maxi, ans=-1;
   while(low<=high){
     int mid=(low+high)/2;

     if(sumOfDivisions(arr,mid)<=threshold){
         ans=mid;
         high=mid-1;
     }
     else
       low=mid+1;
   }
}

//T.C:log2(max)*n
//S.C:O(1)

//leetcode solution:
class Solution {
public:
    int sumByD(vector<int>& nums, int div){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/(double)(div));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();  
       if(n>threshold) return -1;//when divisor is not possible
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(sumByD(nums,mid)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

//this works when it always has a divisor, what happens when it does not have a divisor
