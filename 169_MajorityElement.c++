                   //Majority Element

//brute force approach:
for(int i=0;i<n;i++){
  count=0;
  for(int j=0;j<n;j++){
    if(arr[j] == arr[i])
      count++;
  }
  if(count>n/2) return arr[i];
}

//T.C:O(n^2)

//Better solution:
//using hashing:
int majorityElement(vector<int> v){
  map<int,int>mpp;
  //nlogn
  for(int i=0;i<v.size();i++){
    mpp[v[i]]++;
  }
  //O(n)
  for(auto it:mpp){
    if(it.second >(v.size()/2){
      return it.first;
    }
  }
  return -1;
}
//T.C: for ordered map O(nlog n)+O(n)
//S.C:O(N) only if the array contains all unique elements.

//Optimal solution:

//MOORE'S VOTING ALGORITHMN:
//taking element and count
//verify the element to be majority or not.

//leetcode solution:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element;
        for(int i=0;i<nums.size();i++){
            if(count ==0){
                count=1;
                element=nums[i];
            }
            else if(nums[i] == element){
                count++;
            }
            else{
                count--;
            }
        }
        int count1 =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == element) count1++;
        }
        if(count1 > (nums.size()/2)) {
            return element;
        }
        return -1;
    }
};

//T.C:O(n)
//S.C:O(1)
