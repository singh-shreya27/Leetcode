             //Rotate Matrix

//brute force approach:

ans[n][n]
for(int i=0;i<n;i++){
  for(int j=0;j<n;j++){
    ans[j][n-1-i] = matrix[i][j];
  }
}

//T.C:O(n^2)
//S.C:O(n^2)

//optimal approach:
//to do this in the matrix itself:(without using extra space)
//first tranpose the matrix , then revere every row.

//leetcode solution
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //transpose
        //O(n/2*n/2)
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        //reverse every row
        //O(n*n/2)
        for(int i=0;i<n;i++){
            //row is mat[i]
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//T.C:  O(n/2*n/2)+ O(n*n/2)
//S.C:O(1)
