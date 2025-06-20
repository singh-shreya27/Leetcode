            //House Robber2


class Solution {
public:
    int maximumNonAdjacentSum(vector<int> &num){
        int n=num.size();
        int prev=num[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=num[i];
            if(i>1) take+=prev2;
            int notTake=0+prev;
            int curi=max(take,notTake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1, temp2;
        int n= nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
    }
};
