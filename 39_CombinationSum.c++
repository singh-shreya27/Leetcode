                       //Combination Sum
//arr[] =[2,3,6,7] , target=7 

//Recursion:
//We need to find out what to pick and what not to pick from the array , also how many times we are picking it.

// function(index,target, ds)
//initially, we are at 0th index ,then we have 7 as target and the ds is empty.


class Solution {
    public:
    void findCombination(int index, int target, vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds) {
        //base case
        if(index==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        //pick up the element
        if(arr[index]<=target){
            ds.push_back(arr[index]);
            findCombination(index,target-arr[index], arr, ans, ds);
            ds.pop_back();
        }
        findCombination(index+1, target, arr, ans, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,target, candidates, ans, ds);
        return ans;
    }
};
//TC = O(k * 2^T)
//Where k is the average size of each combination, since every valid combination is stored in the ans vector.

//SC = O(target + R * k)
//R be the number of valid combinations, and k be the average length of a combination.

