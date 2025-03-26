      //Occurrences After Bigram.

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        istringstream iss(text);
        string prev,curr,next;

        //read the first two words
        if(!(iss>>prev)) return result;
        if(!(iss>>curr)) return result;

        //iterate through the remaining words
        while(iss >> next){
            if(prev == first && curr == second){
                result.push_back(next);
            }
            //move to the next pair of words
            prev=curr;
            curr=next;
        }
        return result;
    }
};


//T.C:O(n)    
