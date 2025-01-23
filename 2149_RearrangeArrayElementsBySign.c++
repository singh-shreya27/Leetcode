       //Rearrange array elements by sign.

//brute force approach:
//take a positive and a negative array/list of size n/2.
int pos[];int neg[];
for(int i=0;i<n/2;i++){
  arr[2*i]=pos[i];
  arr[2*i+1]=neg[i];
}

//T.C:O(n)+O(n)(to reassign them into array)
//S.C:O(n)

//better approach:
//we cannot optimise the extra space

//optimal approach:
//we know all positive will be at even index.

//leetcode solution
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n =nums.size();
        vector<int> ans(n,0);
        int posIndex=0, negIndex=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negIndex]=nums[i];
                negIndex+=2;
            }
            else{
                ans[posIndex]=nums[i];
                posIndex+=2;
            }
        }
        return ans;
    }
};

//T.C:O(n)
//S.C:O(n)
