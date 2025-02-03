         //single element in sorted array

//brute force solution:

if(n==1) return arr[0] ; //size 1 array
for(int i=0;i<n;i++){
  if(i==0){ //first element
  if(arr[i] != arr[i+1] return arr[0];
  }
  else if(i==n-1){ //last element
    if(arr[i]!=arr[i-1] return arr[i];
  }
   else{
     if(arr[i] !=arr[i+1] && arr[i]!=arr[i-1])
       return arr[i];
   } 
}

//T.C:O(n)


//think of binary search->think of elimination->even and odd index
//(even,odd) ->element is on the right half, eliminate left
//(odd,even) -> element is on the left half,eliminate right

int function(vector<int>& nums,int n){
  if(n==1) return nums[0];
  if(nums[0] !=nums[1]) return nums[0];
  if(nums[n-1]!=nums[n-2]) return nums[n-1];
  //elimination: eliminate the part where your element is not there.
  int low=1, high=n-2;
  while(low<=high){
    mid=(low+high)/2;
    if(nums[mid] !=nums[mid+1] && nums[mid]!=nums[mid-1])
      return nums[mid];
    //left half
    if((mid%2 ==1 && (nums[mid-1] == nums[mid])) || (mid%2==0 && (nums[mid] == nums[mid+1])))
      low=mid+1;  //eliminate the left half.
    else
      high=mid-1; //eliminate the right half.
  }
  return -1;
}

//leetcode solution:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
  if(nums[0] !=nums[1]) return nums[0];
  if(nums[n-1]!=nums[n-2]) return nums[n-1];
  //elimination: eliminate the part where your element is not there.
  int low=1, high=n-2;
  while(low<=high){
   int mid=(low+high)/2;
    if(nums[mid] !=nums[mid+1] && nums[mid]!=nums[mid-1])
      return nums[mid];
    //left half
    if((mid%2 ==1 && (nums[mid-1] == nums[mid])) || (mid%2==0 && (nums[mid] == nums[mid+1])))
      low=mid+1;  //eliminate the left half.
    else
      high=mid-1; //eliminate the right half.
  }
  return -1;
    }
};

//T.C:O(log2n)
