          //Next Permutation.

//brute force solution:

//1.generate all permutation in sorted order.(using recursion)         O(n!)
//2.do a linear search and find the given order.               O(n)
//3.next index permutation will be my answer.

//T.C:O(n!*n)
//this is very high time 5!=120, 15!~10^12 ..so we don't use this.

//better approach:
//using STL in c++
vector<int> nextGreaterPermutation(vector<int> &A){
  next_permutation(A.begin(),A.end());         //it will automatically change the array into next permuted array.
  return A;
}

//optimal approach:

//dictionary order:
//1.longer prefix match
//2.figure out the break point, which will be when:
a[i]<a[i+1]
//3.find someone greater than a[i] but the smallest one from them so that you stay close.
//4. try to place in sorted order.

int idx=-1;
for(int i=n-2;i>=0;i--){
         if(a[i]<a[i+1]){
          ind=i;
          break;
         }
}
     //3.swap
for(int i=n-1;i>=idx;i--){
  if(arr[i]>arr[idx]){
      swap(arr[i],arr[idx]);
 break;
     }
  }
//4.
rev(arr,idx+1,n-1);

//leetcode solution:
class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int idx=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx=i;              //O(n)
                break;
            }
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
            return nums;
        }
        for(int i=n-1;i>idx;i--){
            if(nums[i]>nums[idx]){                  //O(n)
                swap(nums[i],nums[idx]);
                break;
            }
        }
        reverse(nums.begin()+idx+1,nums.end());          //O(n) in worst case
        return nums;
    }
};

//T.C:~O(3n)
//S.C:we are modifying the array O(1)
