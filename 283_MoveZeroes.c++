//move all zeroes to the end of the array.

//brute force solution
//all non-zeroes numbers at the front.

//step1:
temp=[];
for(int i=0;i<n;i++){
if(arr[i]!=0)                           //O(n)
  temp.add(add[i]);
  }

//step 2:
int nz=temp.size();
for(int i=0;i<nz;i++){   //all the non-zero numbers will move to the front.
arr[i] = temp[i];                            //O(x)
}                                 
//step3:
for(int i=nz;i<n;i++){
  arr[i]=0;                             //O(n-x)
}

//T.C:O(2n)
//S.C:O(x)  at max O(n) where no zero is present

//there is no better solution

//optimal solution:
//using two pointer approach

//step1:
int j=-1;
for(int i=0;i<n;i++){            //  O(x)
  if(arr[i]==0){           
    j=i;
    break;
  }
}
//step2
for(int i=j+1;i<n;i++){                //O(n-x)
  if(arr[i]!=0){
    swap(arr[i],arr[j]);
    j++;                              
  }
}

//T.C:O(n)
//S.C:O(1)

//leetcode solution:
class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int j=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        //no non-zero numbers
        if(j==-1) return nums;

        for(int i=j+1;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return nums;
    }
};
