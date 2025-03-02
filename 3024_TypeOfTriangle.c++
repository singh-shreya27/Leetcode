                            //Type of Triangle.


class Solution {
public:
    string triangleType(vector<int>& nums) {
        //sort to ensure we always compare the largest side first
        sort(nums.begin(),nums.end());
        

        for(int i=0;i<nums.size();i++){
            if(nums[0]+nums[1]<=nums[2]){
                return "none";  //not a valid triangle
            }
            if(nums[0]==nums[1] && nums[1]==nums[2]){
                return "equilateral";
            }
            else if(nums[0]==nums[1] || nums[0]==nums[2] || nums[1]==nums[2]){
                return "isosceles";
            }
            else{
                return "scalene";
            
            }
        }
        return "none";
    }
};
