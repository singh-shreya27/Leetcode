             //Search index position          
 //similar to lower bound

//leetcode solution:

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            //maybe an answer
            if(nums[mid]>=target){
                ans=mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

//lower bound:smallest index such that arr[idx]>=x;
