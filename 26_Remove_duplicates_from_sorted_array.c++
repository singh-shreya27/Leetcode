                                       //brute force approach
//unique elements=> set data structure
//define a set data structure.
//A set is a data structure that represents an unordered collection of unique elements. It is used to store multiple items, ensuring that there are no duplicate values.
//first pass
set<int>st
for(int i=0;i<n;i++) 
  st.insert(arr[i])      //nlogn for first pass
//code
index=0;
for(auto it:st)
{ 
  arr[index]=it;               //n  
index++;
}

//T.C:O(nlogn+n)
//SC:O(n)                   (imagine all of them are unique elements)

//to optimise brute force approach we need to use two pointer approach.

int i=0;
for(int j=1;j<arr.size();j++){
  if(arr[i] !=arr[j]{
arr[i+1] = arr[j];
i++;
   }
}
return i+1;
}

//T.C:O(n)
//S.C:O(1)
