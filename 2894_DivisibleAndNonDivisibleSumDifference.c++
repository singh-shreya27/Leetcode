              //Divisible and Non Divisible Sum

class Solution {
public:
    
    int sum1=0;
    int numm1(int n, int m){
        for(int i=1;i<=n;i++){
            if(i%m!=0){
                sum1+=i;
            } 
        }
        return sum1;
    }
    int sum2=0;
    int numm2(int n, int m){
        for(int i=1;i<=n;i++){
            if(i%m==0){
                sum2+=i;
            }
        }
            return sum2;
    }
    int differenceOfSums(int n, int m) {
        int num1=numm1(n,m);
        int num2=numm2(n,m);
        return num1-num2;
    }
};
