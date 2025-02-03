                                   //find peak element.
//arr[i-1]<arr[i]>arr[i+1]

//linear iteration:
for(int i=0;i<n;i++){
  if((i==0 || arr[i-1]<arr[i]) && (i=n-1 || arr[i]>arr[i+1]))
    return i;
}

//T.C:O(n)
//S.C:O(1)

//try to optimise, think about logn -> binary search
//array here has a sorting tendency (may have multiple peaks)

//first of all, assume array has one peak:

int function(arr,n){
  //check for manual cases:
  if(n==1) return 0;  //if only element present in array , then return thet element.
  if(arr[0]>arr[1]) return 1; //check first element
  if(arr[n-1]>arr[n-2]) return n-1; // check last element

  low=1, high=n-2;
  while(low<=high){
    mid=(low+high)/2;
  if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
    return mid;
  else if(arr[mid]>arr[mid-1]) {
    //increasing curve
    low=mid+1;
  }
    //decreasing curve
    else if(arr[mid] > arr[mid+1])
      high=mid-1;
  }
  return -1;   //function is int type , so integer return is given
}

//but this code was for one peak, will it work for multiple peaks??
//yes.
//because even though we are discarding some peaks on leaft or right, the opposite side will surely have more peaks.
//but it needs a change : when we have mid on the lowest between two peaks, then none of the above cases are executed.
//so add 
else 
low=mid+1;
//to the above code

//leetcode solution:
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int low=1, high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};

//T.C:O(log2n) simple binary search
