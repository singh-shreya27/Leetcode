                                   //Missing number
               
               //brute force solution:
//using linear search:
for(int i=1;i<=n;i++){
    int flag=0;
   for(int j=0;j<n-1;j++){
     if(arr[j] ==i){
     flag=1;                                   //T.C:O(n^2)
     break;                                    //S.C:O(1)
     }
   }
   if(flag==0){
   return i;
   }
}

              //better solution:
//using hashing:
hash[n+1] =[0];
for(int i=0;i<n-1;i++){                  //T.C:O(n+n)=O(2n)
  hash[arr[i]] =1;                       //S.C:O(n) because we are using a hash array of n size.
}
for(int i=1;i<n;i++){
  if(hash[i]==0)
    return i; 
}

           //optimal solution:
//this problem can have 2 optimal solution:
//1. using SUM
//2.using XOR

//1. using sum
int sum=n(n+1)/2;
int s2=0;
for(int i=0;i<n-1;i++){         //T.C:O(n)            
  s2+=arr[i];                 //S.C:O(1)
}
return sum-s2;

//if n is very large~10^5, sum will be 10^10 which cannot be stored , so it will overflow.
//then we will have to take long

//XOR of all numbers will not be that big , so this is more appropriate solution.
//2.using XOR:
//concept: 2^2=0 but 0^2 =2 0 xor with any number is the number itself

//taking from 1 to 5
//XOR1=1^2^3^4^5;
// XOR2=1^2^4^5;
//XOR1^XOR2 =3;

int XOR1=0;
for(int i=1;i<n;i++){
  XOR1=XOR1^i;
}       
int XOR2=0;                   //T.C:O(2n)
for(int i=0;i<n-1;i++){
  XOR2=XOR2^arr[i];
}
return XOR1^XOR2;

//but we can change this
int XOR1=0;
int XOR2=0;                     //T.C:O(n)
for(int i=0;i<n-1;i++){         //S.C:O(1)
  XOR2=XOR2^arr[i];              
  XOR1=XOR1^(i+1);
}
XOR1=XOR1^n;
return XOR1^XOR2;

//leetcode solution:
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N=nums.size();
        int xor1=0,xor2=0;
       // int n=N-1;
        for(int i=0;i<N;i++){
            xor2=xor2^nums[i];
            xor1=xor1^(i);
        }
        xor1=xor1^N;
        return xor1^xor2;
    }
};
