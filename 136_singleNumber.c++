                  //find the number that appears once and the others twice

//brute force approach:
//pick up every number and do a linear search 
for(int i=0;i<n;i++){
    int num=arr[i];
    int count=0;
   for(int j=0;j<n;j++){
   if(arr[j]==num){
   count++;
   }
  }
if(count==1)
  return num;
}

//T.C:O(n^2)
//S.C:O(1)

//better solution:
//using hashing.
//firstly figure out the maximum element
maxi=arr[0]
  for(int i=0;i<n;i++){
   maxi=max(maxi,arr[i]);
}                                    //O(n)
hash[maxi]=0;
for(int i=0;i<n;i++){
   hash[arr[i]]++;               //O(n)
}
for(int i=0;i<n;i++){
  if(hash[arr[i]==1)
    return arr[i];                  //O(n)
}
//T.C:O(3n)
//S.C:O(max)   depend on the input
//if the array contains negatives,very large numbers 10^9 or 10^12 we cannot hash it , so then we have to use map data structure.
//map<long long,int>

//for unordered and ordered map T.C. will vary.
for(int i=0;i<n;i++){
mpp[arr[i]]++;
//iterate the map
for(auto it:mpp){         //O(n/2+1)
if(it.second==1)
  return it.first;
}

//T.C:O(nlogm + O(n/2+1) where m is size of map , m=n/2+1
//S.C:O(n/2+1)

//optimal solution:
//using XOR:(a^a=0)
XOR=0;
for(int i=0;i<n;i++){
  XOR=XOR^arr[i];
return XOR;
  }

//T.C:O(n)
//S.C:O(1)

//leetcode solution:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr=0;
        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
        }
        return xorr;
    }
};

