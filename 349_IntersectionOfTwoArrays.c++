                            //Intersection of two arrays.

//Using hashset or hashmap.
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
//S.C:O(min(n,m))

// This code implements a function intersection in a class Solution that finds the intersection of two arrays nums1 and nums2. Here's a breakdown of what it does:

// 1.Initialization:

// It creates an unordered set set1 from nums1. This set will automatically handle duplicates and allows for O(1) average time complexity for lookups.
// 2.Finding Intersection:

// It iterates through each element el in nums2.
// Checks if el exists in set1 using set1.contains(el).
// If el exists in set1, it inserts el into the common unordered set.
// 3.Creating Output:

// Finally, it constructs a vector ans from the elements in common, which represents the intersection of nums1 and nums2.
// 4.Time Complexity (T.C.):

// Constructing set1 from nums1 takes O(n1) time, where n1 is the size of nums1.
// Checking each element in nums2 and inserting into common takes O(n2) time on average, where n2 is the size of nums2.
// Therefore, the overall time complexity is O(n1 + n2), where n1 and n2 are the sizes of nums1 and nums2, respectively.
// 5.Space Complexity (S.C.):

// The space complexity is primarily driven by the unordered sets set1 and common.
// In the worst case, if all elements are unique, the space complexity can be O(min(n1, n2)), where n1 and n2 are the sizes of nums1 and nums2, respectively, due to storing unique elements.
