   //search in rotated sorted array 2(duplicates)

//check part1 of this question.

//identify the sorted half
//new condition: suppose array is like [3 1 2 3 3 3 3] we cannot use the condition to identify the sorted half as used in part 1 of this question.
//so , the problem here is when:
//arr[low]=arr[mid]=arr[high]
//solution:
//shrink your search space i.e. remove the low and high (rn) because they are same and if mid is not the target, they will also not be.

//leetcode solution:
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++, high--;
                continue;
            }

            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target <=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};

//T.C:O(log2n) in average most of the cases.
//in worst case if there are a lot of duplicates , for ex: [3 3 1 3 3 3 3]
//~O(n/2)

