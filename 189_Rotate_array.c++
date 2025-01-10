//Left rotate the array by one place

#include<bits/stdc++.h>
vector<int> rotateArray(vector<int> &arr,int n){
int temp=arr[0];
   for(int i=1;i<n;i++){
    arr[i-1]=arr[i];
   }
arr[n-1]=temp;
return arr;
}

//T.C:O(n)
//S.C:O(1)

//left rotate the array by D places
                      //brute force aproach
//D=3
//arr[]=[1,2,3,4,5,6,7]
temp[]=[1,2,3]    
//shifting
//
