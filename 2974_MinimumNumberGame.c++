                    //Minimum number game

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end()); //sort to always remove the minimum element.
        vector<int>arr;
        int n=nums.size();
        while(!nums.empty()){
            int alice = nums.front();  // Alice removes the minimum element
            nums.erase(nums.begin()); 

            int bob = nums.front();  // Bob removes the next minimum element
            nums.erase(nums.begin());

            arr.push_back(bob);  // Bob appends first
            arr.push_back(alice); // Alice appends second
        }
        return arr;
        }
};
