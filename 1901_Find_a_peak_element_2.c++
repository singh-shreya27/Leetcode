                                                    //Find a peak element -2.
//none of the two adjacent cells will be same.

//brute force approach:

//T.C:O(n*m*4)
//we can only optimise the worst case scenario, not the best and average case scenario.
//but T.C: will be only O(n*m) not good.

//optimal approach:

function(mat,n,m){
  low=0, high=m-1;
  while(low<=high){
    mid=(high+low)/2;
    row=maxElement(mat,n,m,mid);
    left=mid-1>=0 ? mat[row][mid-1]:-1;
    right=mid+1<m?mat[row][mid+1]:-1;
    if(mat[row][mid]>left && mat[row][mid]>right)
      return (row,mid);
    else if(mat[row][mid]<left)
      high=mid-1;
    else low=mid+1;
  }
  return(-1,-1);
}

//leetcode function:

class Solution {
public:


int findMaxIndex(vector<vector<int>>&mat, int n, int m, int col){
    int maxValue=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxValue){
            maxValue = mat[i][col];
            index=i;
        }
    }
    return index;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0, high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int maxRowIndex=findMaxIndex(mat,n,m,mid);
            int left=mid-1>=0 ? mat[maxRowIndex][mid-1]:-1;
            int right=mid+1<m ? mat[maxRowIndex][mid+1]:-1;
            if(mat[maxRowIndex][mid]>left && mat[maxRowIndex][mid]>right){
                return {maxRowIndex,mid};
            }
            else if(mat[maxRowIndex][mid]<left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return{-1,-1};
    }
};
//T.C:O(log2m* n)
//S.C:O(1)
