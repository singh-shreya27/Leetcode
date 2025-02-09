          //Median of two sorted arrays

//merge the two sorted array into one .

//pseudo code:
arr3=[], i=0,j=0;
int n1=arr1.size();
int n2=arr2.size();
while(i<n1 && j<n2){
   if(arr1[i]<arr2[j]) arr3.add(arr1[i++]);
   else arr3.add(arr2[j++]);
}
  while(i<n1) arr3.add(arr1[i++]);
  while(j<n2) arr3.add(arr2[j++]);
int n=n1+n2;
if(n%2 ==1)
  return arr3[n/2];
else
  (arr3[n/2]+arr3[n/2+1])/2;

//leetcode solution:
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n1=nums1.size(), n2=nums2.size();
        int i=0;
        int j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]) nums3.push_back(nums1[i++]);
            else nums3.push_back(nums2[j++]);
        }
        while(i<n1) nums3.push_back(nums1[i++]);
        while(j<n2) nums3.push_back(nums1[j++]);
        int n=(n1+n2);
        if(n%2 ==1){
            return nums3[n/2];
        }
        return (double)((double)(nums3[n/2])+(double)(nums3[n/2-1]))/2.0;
    }
};

//creating this third array is giving TLE(partially correct) ..so we need to optimise this

//we are creating a third array which is storing all the elements but we don't need all the elements, we just need
//the nearby two elements or the mid element.

//leetcode solution:
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int n1=nums1.size(),n2=nums2.size();
      int i=0;
      int j=0;
      int n=(n1+n2);
      int ind2=n/2;
      int ind1=ind2-1;
      int cnt=0;  //index tracker
      int ind1el=-1, ind2el=-1;
      while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            if(cnt==ind1) ind1el=nums1[i];
            if(cnt==ind2) ind2el=nums1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt==ind1) ind1el=nums2[j];
            if(cnt==ind2) ind2el=nums2[j];
            cnt++;
            j++;
        }
      }
      while(i<n1){
        if(cnt == ind1) ind1el=nums1[i];
        if(cnt == ind2) ind2el=nums1[i];
        cnt++;
        i++;
      }
      while(j<n2){
        if(cnt == ind1) ind1el=nums2[j];
        if(cnt == ind2) ind2el=nums2[j];
        cnt++;
        j++;
      }
      if(n%2 ==1){
        return ind2el;
      }
      return (double)((double)(ind1el+ind2el))/2.0;
    }
};

//PART2
