//Check if the array is sorted.

//we don't need brute,better,optimal for this.

//CODING NINJAS:
int isSorted(int n, vector<int> a){
  for(int i=1;i<n;i++){
if(a[i]>=a[i-1]) {
} else{
  return false;
}
  }
return true;
}
