                    //Remove element

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        int right=0;

        while(left<nums.size()){
            if(nums[left]!=val){
                nums[right]=nums[left];
                right++;
            }
            left++;
        }
      return right;

    }
};

//T.C:O(n)
