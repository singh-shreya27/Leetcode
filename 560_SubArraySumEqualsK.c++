                    //Number of sub arrays with sum K.
//contiguous part of array:subarray

//brute force apparoach:
int count=0;
for(int i=0;i<n;i++){
  for(int j=1;j<n;j++){
    //subarray is from i to j
    int sum=0;
    for(int k=i;k<j;k++){
      sum=sum+arr[k];
    }
    if(sum==k)
      count++;
  }
}

//T.C:O(n^3)

//better approach:
int count=0;
for(int i=0;i<n;i++){
  int sum=0;
  for(int j=1;j<n;j++){
    //subarray is from i to j 
      sum+=arr[j];
    }
    if(sum==k)
      count++;
  }
}

//T.C:O(n^2)

//optimal approach:
//using "PREFIX SUM"
//hash array:

