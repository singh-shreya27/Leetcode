//Find Words that can be formed by characters.


  class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
    //step 1: Count character frequencies in chars
    vector<int> charCount(26,0);
    for(char c:chars){
        charCount[c-'a']++;
    }
    int totalLength=0;

    //Step 2:Check each word in words
    for(const string& word:words){
        vector<int> wordCount(26,0);
        bool canBeFormed =true;

        //count characters in the current word
        for(char c:word){
            wordCount[c-'a']++;
            if(wordCount[c-'a']>charCount[c-'a']){
                canBeFormed=false;
                break; //stop checking if we already exceed the allowed count
            }
        }

        //If the word can be formed, add its length to totalLength
        if(canBeFormed){
            totalLength+=word.length();
        }
    }
    return totalLength;
    }
};

//T.C:O(W * L)
//W = number of words
//L = average word length
