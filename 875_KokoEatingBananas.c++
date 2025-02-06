               //koko eating bananas
//return the minimum integer k such that koko can eat all bananas within h hours.

//brute force solution:
//pseudo code:
//linear search
for(int i=1;i<max(arr);i++){
  reqTime=func(arr,i);
  if(reqTime<=h)
    return i;                      //T.C:O(max(arr)*n) this will give you TLE(Time limit exceeded).
}

func(arr,hourly){
  int totalhrs=0;
  for(i=0->n-1){
    totalhrs+=ceil(arr[i]hourly);
  }
  return total hrs;
}

//Binary search on answers.

//leetcode solution:
class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int> &piles,int hourly){
        long long totalH=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            totalH += (piles[i]+hourly-1)/hourly;
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findMax(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long long totalH = calculateTotalHours(piles,mid);
            if(totalH<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

//T.C:O(n)*log2(max element)
