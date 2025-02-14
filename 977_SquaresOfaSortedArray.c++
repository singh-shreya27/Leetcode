           //Squares of a sorted array

//brute force approach:

//sqare all then sort 
//using quick sort:O(nlogn)

//Optimal solution:;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //create a result array of same length
        vector<int> result(nums.size());
        int n=nums.size();
        //square all elements
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*nums[i];
        }
        //2-pointer approacg
        int head=0;
        int tail=nums.size()-1;

        //set them at right place in the result array
        //filling result array from last to first
        for(int x=nums.size()-1;x>=0;x--){
             if(nums[head]>nums[tail]){
                result[x]=nums[head];
                head++;
             }else{
                result[x]=nums[tail];
                tail--;
             }
        }
       return result;
    }
};

//T.C:O(n) we are iterating through entire array only once.
//S.C:O(n) new array created.
