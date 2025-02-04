             //search in a rotated sorted array.[unique elements]

//brute force solution:
//do linear search and find the element but T.C:O(n)

//search+sorted=>binary search should come to your brain.

//take low and high at first and last element resp., and then take mid..after that we cannot simply eliminate any part here, beacuse the array is rotated.
//so we have to identify the sorted part this time.

int function(vector<int>&nums,int n,int target){
  int low=0,high=n-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(nums[mid]==target) return mid;
    //identify the sorted half
    //left sorted
    if(nums[low]<=nums[mid]){
      if(nums[low]<=target && target<=nums[mid])
        high=mid-1;
      else 
        low=mid+1;
    }
      //right sorted
    else{
      if(nums[mid]<=target && target<=nums[high])
        low=mid+1;
      else 
        high=mid-1;
    }    
  }
  return -1;
}

//leetcode solution:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
         int low=0,high=n-1;
  while(low<=high){
    int mid=(low+high)/2;
    if(nums[mid]==target) return mid;
    //identify the sorted half
    //left sorted
    if(nums[low]<=nums[mid]){
      if(nums[low]<=target && target<=nums[mid])
        high=mid-1;
      else 
        low=mid+1;
    }
      //right sorted
    else{
      if(nums[mid]<=target && target<=nums[high])
        low=mid+1;
      else 
        high=mid-1;
    }    
  }
  return -1;
    }
};

//T.C:O(log2n)
