          //Subsets-2


//brute force :
//put all the 2^n subsets into a set (list<list>) ..so that all the duplicates will go away.
//After recursion, we are an extra time of converting it into a set and then reconverting it back into a list<list>
//If you are putting every element into the set ..it's gonna take mlogm where m=2^n (size of set).

//so optimise the recursion.

class Solution {
    private:
      void findSubsets(int ind, vector<int> &nums, vector<int> &ds,vector<vector<int>>&ans){
      ans.push_back(ds);
      for(int i=ind; i<nums.size();i++){
        if(i!=ind && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        findSubsets(i+1, nums,ds,ans);
        ds.pop_back();
        }
      }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> ds;  //empty data structure
        sort(nums.begin(), nums.end());
        findSubsets(0,nums,ds,ans);
        return ans;
    }
};
