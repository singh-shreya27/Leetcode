            //Least capacity to ship packages within D days.


//the minimum capacity has to be the maximum weight, otherwise we will not be able to ship each and every product.

//the answer will be between the max element and the summation of array.
//brute force solution:
//pseudo code:
int function(weight,capacity){
  int days=1,load=0;
  for(int i=0;i<n;i++){
    if(load+weight[i]>capacity){
      days=days+1;
      load=weight[i];
    }
    else
      load+=weight[i]
  }
  return days;
}
for(capacity between (max->sum)){
  it daysReq = function(weight,capacity){
    if(daysReq<=days)
      return daysReq;
  }
}

//T.C:O(sum-max+1)*O(n) ~O(n^2)

//optimal solution:
function(weight,days){
  low=maxi,high=sum(arr);
  while(low<=high){
    int mid=(low+high)/2;
    noOfDays=function(weight,mid);
    if(noOfDays<=days){
      high=mid-1;
    }
    else
      low=mid+1;
  }
  return low;
}
//T.C:O(log2(sum-max+1)*O(n)
//S.C:O(1)

//leetcode solution:
class Solution {
public:
  int findDays(vector<int> &weights, int cap){
    int days=1,load=0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]+load>cap){
            days+=1;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
  }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int numberOfDays=findDays(weights,mid);
            if(numberOfDays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
