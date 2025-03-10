               //Reverse words in a string

//store the words in vector.
//Traverse backward in the vector and store the words in string and  " " appended to each string.
//except the first one.(index=0) 

class Solution {
public:
    string reverseWords(string s) {
    stringstream str(s); //used for breaking words.
    string word;         //to store individual words.

    //to store words
    vector<string>temp;
    //to store the ans.
    string ans="";

    while(str>>word){
        temp.push_back(word);
    }
    //now store the words in reverse order and add the extra space at the end of each word.
    //except the first one.

    for(int i=temp.size()-1;i>=0;i--){
        if(i!=0)
           ans+=temp[i]+" ";
        else
           ans+=temp[i];
    }
    return ans;
    }
};
