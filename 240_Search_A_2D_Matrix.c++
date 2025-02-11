              //Search a 2D Matrix.
//individual rows and columns are sorted.

//brute force approach:

//go through every element and return if it is present.
//T.C:O(n*m)

//better solution:

//i->row

for(int i=0;i<n;i++){
    idx= bs(mat[i],target);
  if(idx!=-1)
    return{i,idx};
}
return(-1,-1);

//T.C:O(n*log2m)

//optimal solution:
//we will start from top left or bottom right of the matrix and do the elimination.

row=0,col=m-1;
while(row<n && col>=0){
  if(mat[row][col]==target)
    return (row,col);
  else if(mat[row][col]<target)
    row++;
  else
    col--;
      }
return(-1,-1);

//T.C:O(n+m)
//S.C:O(1)

//leetcode solution:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0, col=m-1;
        while(row<n && col>=0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) row++;
            else col--;
        }
        return false;
    }
};

//we did not applied binary search straight away but the 
//concept of binary search was still applied i.e. elimination.
