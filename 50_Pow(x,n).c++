                   //Pow(x,n)

//Brute force approach:
double myPow(double x, int n){
      double ans=1.0;
      for(int i=0;i<n;i++){
         ans=ans*x;  
        }
      return ans;
  }
//T.C:O(n)
//S.C:O(1)
//optimise

//2^10=(2*2)^5=(4)^5 
//4^5= 4*4^4
//4^4= (4*4)^2=(16)^2
//16^2=(16*16)^1=256^1
//(256)^1= 256*(256)^0

//OBSERVATION:
//[n%2==0]-> (x*x)^n/2
//n%2==1 -> ans=ans*x , n=n-1

//T.C:O(log2n)
//S.C:O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long nn=n;
        if(nn<0) {
            nn=-1*nn;
        }
        while(nn){
            if(nn%2){
                ans=ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0) ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};

//T.C:O(log n)
//S.C:O(1)
