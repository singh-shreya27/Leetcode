                   //find minimum in rotated sorted array[unique].

//identify sorted half
//sorted half may or may not have the min element
//so we will pick the min from the sorted half and eliminate.

int function(vector<int>& nums, int n){
  int low=0,high=n-1,ans=INT_MAX;
  while(low<=high){
    int mid=(low+high)/2;

    //left half
    if(nums[low]<=nums[mid]){
      ans=min(ans,nums[low]);
      low=mid+1;
    }
    else{
      ans=min(ans,nums[mid]);
      high=mid-1;
    }
  }
}

//leetcode solution:
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
         int low=0,high=n-1,ans=INT_MAX;
  while(low<=high){
    int mid=(low+high)/2;

    //left half
    if(nums[low]<=nums[mid]){
      ans=min(ans,nums[low]);
      low=mid+1;
    }
    else{
      ans=min(ans,nums[mid]);
      high=mid-1;
    }
  }
  return ans;
    }
};

//T.C:O(log2)

//we can still optimise this.
//if the search space is already sorted.

//new leetcode solution:

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
         int low=0,high=n-1,ans=INT_MAX;
  while(low<=high){
    int mid=(low+high)/2;
     //if the search space is already sorted
     //then always nums[low] will be smaller in that search space
     if(nums[low]<=nums[high]){
        ans=min(ans,nums[low]);
        break;
     }
    //left half
    if(nums[low]<=nums[mid]){
      ans=min(ans,nums[low]);
      low=mid+1;
    }
    else{
      ans=min(ans,nums[mid]);
      high=mid-1;
    }
  }
  return ans;
    }
};

//T.C:O(log2n)
