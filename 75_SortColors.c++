                //Sort an array of 0's,1's and 2's.
//brute force solution:
//using merge sort
//T.C:O(nlogn) and S.C:O(n)

//better solution:
//using 3 variables and storing the counts of 0's, 1's or 2's.
int cnt0=0 , cnt1=1, cnt2=2;
for(int i=0;i<n;i++){              //O(n)
  if(a[i] ==0) cnt0++;                         
  elseif(a[i] ==1) cnt1++;
  else cnt2++;
}
for(int i=0;i<cnt0;i++) a[i]=0;
for(int i=cnt0;i<cnt0+cnt1;i++) a[i]=1;              //O(n)
for(int cnt0+cnt1;i<n;i++) a[i]=2;
//T.C:O(2n) 
//S.C:O(1)

//optimal solution:
//DUTCH NATIONAL FLAG ALGORITHM:
//using three pointers.
//everything between 0 to low-1 will be 0 which is extreme left.
//everything between 0 to mid-1 will be 1 .
//everything between high +1 to n-1 will be 2 which is extreme right.


//leetcode solution:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid <= high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};




















