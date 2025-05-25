               //Subsets

          //POWERSET:
//S="abc" -> "",a,b,c,ab,bc,ac,abc.
//If length of string if n, the number of substrings that can be generated:2^n (empty substring is also included).

//Bit manipulation:
//bit no. :     2 1 0
// binary of 5: 1 0 1
//ques: If ith bit is set or not?

//    1 0 1
// &  1 0 0    (1<<2) 1 left shift 2 : 1 0 0 
// =  1 0 0 (!=0) non-zero number

//place 1 right beneath that ith bit and do & operator : 
//if the number comes out (!=0) : that bit is set.
//if the number comes out (==0) : that bit is not a set.
// IMPORTANT:
//(n&(1<<i)!=0) that bit is set

//leetcode solution:
class Solution {
public:
    vector<vector<int>> ans;
    void sub(vector<int> &nums, int i, vector<int> temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }

        sub(nums,i+1,temp); //exclude the current element
        temp.push_back(nums[i]);//small work
        sub(nums,i+1,temp); //include the current element
    }

    
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> temp;
       sub(nums,0,temp);
       return ans;
        }
    
};
