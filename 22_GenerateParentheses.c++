          //Generate Parentheses


//Balanced combination:
//1. closing bracket count< opening bracket count
//2. opening bracket count< n

class Solution {
public:
    
    void helper(vector<string> &v, int n, int oc, int cc, string s){
        //base case
        if(oc==n && cc==n){
            v.push_back(s);
            return ;
        }
        if(oc<n){
            helper(v,n,oc+1,cc,s+"(");
        }
        if(cc<oc){
            helper(v,n,oc,cc+1,s+")");
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int oc=0, cc=0;
        helper(v,n,oc,cc,"");
        return v;
    }
};

//T.C:O(2^2n)
//S.C:O(2n*Cn)
// Final Space Complexity:
//O(2n⋅Cn) (for result)+O(2n) (for recursion)
//But since Cn grows faster than 2n, the dominant term is: 𝑂(2𝑛⋅𝐶𝑛).
