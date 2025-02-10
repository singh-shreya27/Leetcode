             //Search in a 2D Matrix(sorted)

//brute force solution:
//traversing the entire matrix and checking if the target is there or not.

for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
    if(mat[i][j]==target)
      return true;
  }
  return false;
}
//T.C:O(n*m)
//S.C:O(1)

//row->
//column (down)

//better solution:
for(int i=0;i<n;i++){
  if(mat[i][0]<=target && target<=mat[i][m-1]){
    return bs(mat[i],target);     //this happens only once
  }
}

//T.C:O(n)+log2m  ~O(n)
//S.C:O(1)

//optimal approach:
//If we can hypothetically flatten a 2D into a 1D matrix of size(n*m)
//then convert 1D coordinate into 2D coordinate.

low=0, high=n*m-1
  while(low<=high){
     mid=(low+high)/2;
     row=mid/m, col=mid%m;
   if(mat[row][col]==target) return true;
   else if(mat[row][col]==target) low=mid+1;
   else high=mid-1;
  }
return false;

//T.C:O(n*m)
//S.C:O(1)

//leetcode solution:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0, high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};
