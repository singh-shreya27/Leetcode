    //Long Pressed Name

//2 pointers approach:

 class Solution {
public:
    bool isLongPressedName(string name, string typed) {
     int n1=name.size();
     int n2=typed.size();
     int idx1=0, idx2=0;
     while(idx1<n1 && idx2<n2){
        if(name[idx1]==typed[idx2]){
            idx1++;
            idx2++;
            continue;
        }
        if(idx1>0 && name[idx1-1]==typed[idx2]){
            idx2++;
        }
        else
           return false;
     }
      if(idx1<n1)
          return false;
      while(idx2<n2){
        if(name[n1-1]!=typed[idx2]){
            return false;
        }
        idx2++;
    }
    return true;
    }
};

//T.C:O(n1 + n2)
