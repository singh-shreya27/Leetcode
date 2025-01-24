          //Next Permutation.

//brute force solution:

//1.generate all permutation in sorted order.(using recursion)         O(n!)
//2.do a linear search and find the given order.               O(n)
//3.next index permutation will be my answer.

//T.C:O(n!*n)
//this is very high time 5!=120, 15!~10^12 ..so we don't use this.

//better approach:
//using STL in c++
vector<int> nextGreaterPermutation(vector<int> &A){
  next_permutation(A.begin(),A.end());         //it will automatically change the array into next permuted array.
  return A;
}

//optimal approach:

//dictionary order:
//longer prefix match
a[i]<a[i+1]

