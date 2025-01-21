         //Two sum
//Brute force approach:
for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++){
    // if(i==j) continue;
    if(arr[i]+arr[j]==target){
      return i,j;
    }
  }
}

//T.C:O(n^2)

//better solution:
