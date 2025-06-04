
 //Letter combinations of a phone number

class Solution {
    private:
    void printKeypad(int index,string &digits, string output,vector<string>&ans, string options[]){
        if(index==digits.size()){
            ans.push_back(output);
            return;
        }
        int digit=digits[index]-'0';
        string letters=options[digit];
        for(char ch:letters){
            printKeypad(index+1,digits,output+ch,ans,options);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        string output="";
        string options[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        printKeypad(0,digits,output,ans,options);
        return ans; 
    }
};
