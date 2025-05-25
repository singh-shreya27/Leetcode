           //Count Good Numbers 

//By obervation:
//no. of even indices=(n+1)/2;
//no. of odd indices=n/2;

//At even index we have 5 possibilities: 0,2,4,6,8
//At odd index we have 4 possibilities: 2,3,5,7

//Becomes a problem of PnC : 5*4*5*4*5*4 for n=6
//5^3*4^3

//pow(5,(n+1)/2) * pow(4,n/2);

//x^n : binary exponentiation :T.C:O(log n)

//findPower USING RECURSION: 
int findPower(x,n){
  if(n==0) return 1;

  long long half=findPower(x,n/2);
  long long result =(half*half)% M;
  if(b %2==1) {
    result=(result*x) %M;
  }
  return result;
}

//LEETCODE SOLUTION:
class Solution {
public:
    const int M= 1e9+7;
    int findPower(long long a, long long b){
        if(b==0){
            return 1;
        }
        long long half=findPower(a,b/2);
        long long result=(half*half)% M;

        if(b%2==1){
            result=(result*a) % M;         
        }
        return result; 
    }
    int countGoodNumbers(long long n) {
      return (long long)findPower(5,(n+1)/2) * findPower(4,n/2) % M;
    }
};
//T.C:O(logn)
