           //Find words containing characters.

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
       for(int i=0;i<words.size();i++){
        for(int j=0;j<words[i].size();j++){
            if(words[i][j]==x){
                result.push_back(i);
                break;
            }
        }
       }
       return result;
    }
};


//T.C:O(n*m)
//n:number of strings in words array.
//m: length of each string in words.
