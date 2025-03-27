
              //N repeated element in size 2n array.

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
    unordered_map<int,int> freq;
    for(int num:nums){
        if(++freq[num] == nums.size()/2){
            return num;
        }
    }


  return -1;

    }
};

// nums.size() / 2 (which is n because nums.size() is 2 * n) .

//T.C:O(n)
