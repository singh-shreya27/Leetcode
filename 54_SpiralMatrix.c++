      //Spiral Matrix

//This problem just has one solution:Optimal solution
//Reasons:
//1. Implementation skills.
//2.How clean code you can write.

//right->bottom->left->top

//right:

//for(int i=left->right)
//a[top][i];
//top++;

//for(int i=top->bottom)
//a[i][right];
//right--;

//for(i=right->left)
//a[bottom][i];
//bottom--;

//for(i=bottom->top)
//a[i][left];
//left++;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0,right=m-1;
        int top=0,bottom=n-1;
        vector<int>ans;

        while(top<=bottom && left<=right){
        //right:
        for(int i=left;i<=right;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
        for(int i=right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
        }
        bottom--;
        }
        if(left<=right){
        for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
        }
        left++;
        }
      }
      return ans;
    }
};

//T.C:O(n*m)
