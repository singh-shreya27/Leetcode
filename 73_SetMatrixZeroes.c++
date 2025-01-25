               //Set matrix zeroes

//brute force approach:
//firstly mark as -1 ..
markRow(i){
  for(int j=0;j<m;j++){
    if(arr[i][j]!=0)           //O(m)
      arr[i][j]=-1;
  }
}
markCol(j){
  for(int i=0;i<n;i++){        //O(n)
    if(arr[i][j]!=0)
      arr[i][j]=-1;
  }
}
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
  if(arr[i][j]==0){            //O(n*m)
    markRow(i);
    markCol(j);
  }
  }
}
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
  if(arr[i][j]==-1){            //O(n*m)
    arr[i][j]=0;
  }
  }
}

//T.C:O(n*m)+O(n)+O(m)+O(n*m) ~O(n^3)

//better solution:
//create a new row and column having all 0 , then mark them as 1 
vector<vector<int> zeroMatrix(vector<vector<int>> &matrix,int n,int m){
  int col[m] ={0};
  int row[n]={0};
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++){
   if(matrix[i][j] == 0){
       row[i]=1;
      col[j]=1;
   }
  }
}
for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
  if(row[i] || col[j]){
   matrix[i][j]=0;
  }
 }
}
return matrix;
}
//T.C:O(2*n*m) ~O(n^2)
//S.C:O(n)+O(m)

//optimal approach:
//we know minimum in order to travel a matrix is n^2 , so we need to optimise the space complexity.

class Solution {
public:
    vector <vector<int>> setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // int col[m]={0};-> matrix[0][..]
        //int row[n]={0};->matrix[..][0]
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    //mark the i-th row
                    matrix[i][0]=0;
                    ///mark the j-th col
                    if(j!=0)
                        matrix[0][j]=0;
                    else
                            col0=0;                    
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=0){
                    //check the col and row
                    if(matrix[0][j]==0 || matrix[i][0]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++)matrix[0][j]=0;
        }
        if(col0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        return matrix;
    }

};

//T.C:O(2*n*m)
//S.C:just one variable  int col0=1;
