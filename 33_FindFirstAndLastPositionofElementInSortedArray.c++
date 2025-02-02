
class Solution {
public:
    int firstOcc(vector<int>& nums,int n,int target){
   int start=0;
   int end=n-1;
   int mid=start +(end-start)/2;
   int ans=-1;
   while(start <=end){
    if (target>nums[mid]){
     start=mid+1;
    }
    else if(target<nums[mid]){
      end=mid-1;
    }
    else if(target==nums[mid]){
       ans=mid;
       end=mid-1; 
    }
    mid=start+(end-start)/2;
   }
   return ans;
}

int lastOcc(vector<int>& nums,int n,int target){
   int start=0;
   int end=n-1;
   int mid=start +(end-start)/2;
   int ans=-1;
   while(start <=end){
    if (target>nums[mid]){
     start=mid+1;
    }
    else if(target<nums[mid]){
      end=mid-1;
    }
    else if(target==nums[mid]){
       ans=mid;
       start=mid+1; 
    }
    mid=start+(end-start)/2;
   }
   return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left_most=firstOcc(nums,n,target);
        int right_most=lastOcc(nums,n,target);
        return{left_most,right_most};
    }
};
