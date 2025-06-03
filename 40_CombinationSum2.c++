       //Combination sum2 
//the numbers should be in lexigographical order.

//brute force approach:
// slight change in combination sum 1 code...make set<list<integer>>ans and we need to move to next index even after picking the element here .

class Solution{
private void findCombinations(int ind , int[] arr, int target, Set<List<Integer>> ans , List <Integer> ds){
  if(ind == arr.length){
    if(target == 0){
      ans.add(new ArrayList<>(ds));
    }
    return;
  }
  if(arr[ind] <== target){

    ds.add(add[ind]);
    findCombination(ind+1, arr, target-arr[ind], ans, ds);
    ds.remove(ds.size()-1);
  }
  findCombination(ind+1, arr, target, ans,ds);
}

public List<List<Integer>> CombinationSum(int[] candidates, int target){
  Set<List<Integer>> ans= new ArrayList<>();
  findCombination(0, candidates, target, ans, newArrayList<>());
  //hashSet can be converted to a list of list, then return the list
  return ans;
  }
}

//HERE T.C: 2^t * klogn because we are putting the elements in a set here.
//so Optimise.

class Solution{
public:
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int>&ds){
  if(target==0){
    ans.push_back(ds);
    return;
  }
  for(int i=ind; i<arr.size();i++){
    if(i>ind && arr[i]==arr[i-1]) continue;
    if(arr[i]>target) break;
    ds.push_back(arr[i]);
    findCombination(i+1, target-arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
public:
vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
   sort(candidates.begin(),candidates.end());
  vector<vector<int>> ans;
  vector<int> ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}
};

//T.C:2^n*k (number of subsequences that the array generates is 2^n) 
//S.C:k*x
 
