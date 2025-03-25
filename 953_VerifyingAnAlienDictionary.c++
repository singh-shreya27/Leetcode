
                                        //Verifying an english dictionary.

//lexicographically sorted: arranging items (like words or strings) in alphabetical order, similar to how words are arranged in a dictionary. 

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> orderMap;
        for(int i=0;i<order.size();i++){
            orderMap[order[i]]=i;
        }

        for(int i=0;i<words.size()-1;i++){
            if(!isSorted(words[i],words[i+1],orderMap)){
                return false;
            }
        }
        return true;
    }

private:
bool isSorted(const string& word1, const string& word2, unordered_map<char,int>& orderMap){
    int len1=word1.size(),len2=word2.size();
    int minLen = min(len1,len2);

    for(int i=0;i<minLen;i++){
        if(word1[i]!=word2[i]){
            return orderMap[word1[i]] < orderMap[word2[i]];
        }
    }
    return len1 <= len2;
}
};

//T.C:O(n*m)
//where n is the number of words and m is the average length of the words. 
