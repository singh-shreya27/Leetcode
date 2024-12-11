//solution

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
     int maxCount=0;   //maximum no.of spaces encountered till now.
     int currCount=0;   //spacs in current sentence.

    for(int i=0;i<sentences.size();i++){
       for(int j=0;j<sentences[i].size();j++){
        if(sentences[i][j]==' ')
        currCount++;
       }
       if(currCount>maxCount){
        maxCount= currCount;
       }
       currCount=0;
    }
    //no. of words=no. of spaces+1
    return maxCount+1;
    }
   
};
