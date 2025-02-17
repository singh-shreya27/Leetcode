                      //Check if the sentence is a pangram

class Solution {
public:
    bool checkIfPangram(string sentence) {
        //creating a vector with all values false.
        vector<bool> position(26,false);
            for(int i=0;i<sentence.length();i++){
                position[sentence[i]-'a']=true;
            }
            for(int i=0;i<26;i++){
                if(position[i]==false){
                    return false;
                }
            }
            return true;
        }
};
