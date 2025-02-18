                                 //Three consecutive odds


class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int num:arr){
            if(num%2!=0){
                count++;

                if(count==3){
                return true;
            }
            }
            else{
              count=0;   //reset count if the number is even
            }
    }
    return false;
    }
};

