        //Difference between element sum and digit sum of an array.
 
class Solution {
public:
          int sum=0;
        int elementSum(vector<int>&nums){
            for(int num:nums){
                sum+=num;
            }
            return sum;
        }
          int digSum=0;
        int digitSum(vector<int>&nums){
            for(int num:nums){
                while(num>0){
               digSum+= num%10;
               num/=10;
             }
            }
            return digSum;
        }
    
    int differenceOfSum(vector<int>& nums) {
        int sum=elementSum(nums);
        int digSum=digitSum(nums);
        return abs(sum-digSum);
    }
};
