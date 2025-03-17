           //Find K closest elements.

//Three approaches:
//1.Using heap:
//T.C:O(nlogn)

//2.Using two pointers:
//T.C:O(n)

//3.Using binary search:
//T.C:O(logn)

//1.Using heap:
//IMPORTANT CONCEPT:
//Use MAX Heap wherever closest, smallest,nearest is given .
//Use MIN Heap wherever largest,farthest,greatest is given.


//we will store pair{arr[i]-x,arr[i]} in max heap and push elements until size is<=k ..if size>k we will pop that element.

//2.Using two pointers.
//take i=first element and j=last element.
if  (x-arr[i]<arr[j]-x) {
           j--;
}
  else{
             i++;
  }

//3.Using binary search
//SORTED :given in question so think of binary search.
int low=0,
int high=arr.size()-k;  //important
int mid=(low+high)/2;
while(low<high){
if(x-arr[mid])<(arr[mid+k]-x)
           high=mid;
  else
    low=mid+1;
}


//leetcode solution:
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     int low=0,high=arr.size()-k;
     while(low<high){
        int mid=low+(high-low)/2;
        if(x-arr[mid]>arr[mid+k]-x){
            low=mid+1;
        }else{
            high=mid;
        }
     }   
     vector<int>ans;
     for(int i=0;i<k;i++){
        ans.push_back(arr[low+i]);
     }
     return ans;
    }
};

//T.C:O(logn)
