           //minimum number of days to make M bouquets.


//brute force approach:

//pseudo code:
                            
int possible(int bloomDay,int day,int m,int k){
  int count=0;
  int noOfBouquets=0;
  for(int i=0;i<n;i++){
    if(bloomDay[i]<day){
      count++;
    }else{
      noOfBouquets+=(count/k);
      count=0;
    }
  }
  noOfBouquets+=(count/k);
  if(noOfBouquets>=m) return true;
  else return false;
}
if(n<m*k) return -1; //impossible case

for(int i=mini;i<=maxi;i++){
  if(possible(bloomDay,i,m,k)==true)
    return i;
}
return -1;

//T.C:O((maxi-mini+1)*n)


//optimise this:
//we know the range in which it is not possible and in which range it is possible, so apply binary search.
int bs(bloomDay,m,k){
int low=mini;
int high=maxi;
int ans=high;
  if(n<m*k) return -1; 
while(low<=high){
     int mid=(low+high)/2;
     if(possible(bloomDay,mid,m,k)==true){
           ans=mid;
           high=mid-1;
     }
  else
       low=mid+1;
}
  return low;  //or ans
}

//T.C:O(n*log2 (search space))=O(n*log2(maxi-mini+1))
//S.C:O(1)

//leetcode solution:
class Solution {
public:
   bool possible(vector<int> &bloomDay,int day,int m,int k){
    int count=0;
    int noOfBouquets=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=day){
            count++;
        }
        else{
            noOfBouquets+=(count/k);
            count=0;
        }
    }
    noOfBouquets+=(count/k);
    return noOfBouquets>=m;
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
     long long val=m*1LL*k*1LL;
     if(val>bloomDay.size()) return -1;

     int mini=INT_MAX,maxi=INT_MIN;
     for(int i=0;i<bloomDay.size();i++){
        mini=min(mini,bloomDay[i]);
        maxi=max(maxi,bloomDay[i]);
     }        

     int low=mini,high=maxi;
     while(low<=high){
        int mid=(low+high)/2;
        if(possible(bloomDay,mid,m,k)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
     }
     return low;
    }
};

//The line:


//long long val = m * 1LL * k * 1LL;
//ensures that the multiplication result is stored as a long long integer type. Here's how it works:

//Breaking it down:
//m and k are typically int values.
//1LL is explicitly a long long literal (i.e., 1 as a long long type).
//When an int is multiplied by 1LL, the result is promoted to long long.
//This avoids integer overflow that could occur if m * k were computed using int multiplication before assigning it to val.

