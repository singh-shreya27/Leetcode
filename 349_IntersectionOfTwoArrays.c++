                            //Intersection of two arrays.

//Using hashset and hashmap.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> set1(nums1.begin(),nums1.end());//set1 that contains nums1 elements in its set
      unordered_set<int> common;
      for(auto el:nums2){
        if(set1.contains(el))common.insert(el);
      }
      vector<int> ans(common.begin(),common.end());
      return ans;
    }
};


//T.C:O(n+m)
//S.C:O(n+m)
