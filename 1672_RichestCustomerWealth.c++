   //Richest customer wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth=0;

        for(const auto& customer :accounts){
            int wealth=0;
            for(int money:customer){
                wealth+=money;
            }
            if(wealth>maxWealth){
                maxWealth = wealth;
            }
        }
        return maxWealth;
    }
}; 
