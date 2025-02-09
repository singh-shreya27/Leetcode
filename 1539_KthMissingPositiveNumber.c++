    //Find Kth missing number

//brute force approach:
for(int i=0;i<n;i++){
  if(arr[i]<=k)
    k++;
  else
    break;
}
//T.C:O(n)
//S.C:O(1)

//sorted+increasing+better than O(n)->Binary Search
//optimal approach:
//we know the answer is between first and last index, if we can figure out the two nearby indexes
//then we can figure out how to get the answer.

function (arr,k){
int low=0;
int high=n-1;
while(low<=high){
  int mid=(low+high)/2;
  int missing=arr[mid]-(mid+1);
    if(missing<k)
      low=mid+1;
  else
      high=mid-1;
}
  return (high+1+k); //or (low+k)
}

//T.C:O(log2n)
//S.C:O(1)

//ans->arr[high]+more
//more=(k-missing)
//missing=arr[high]-(high+1)
//ans= high+1+k
//low=high+1
//ans=low+k

//leetcode solution:
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=(high+low)/2;
            int missing=arr[mid]-(mid+1);
            if(missing<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high+1+k;
    }
};
