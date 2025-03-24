  //Shortest Completing Word.


class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
            // Step 1: Normalize licensePlate :to store character frequencies
        unordered_map<char, int> lpFreq;
        //isalpha(c): Ensures only alphabetic characters are considered (ignores numbers, spaces, etc.).
        for (char c : licensePlate) {
            if (isalpha(c)) {
                lpFreq[tolower(c)]++;
            }
        }                                                                              
       
        // Step 2: Find the shortest completing word
        string shortestWord;
        int minLength = INT_MAX;
        
        for (const string& word : words) {
            // Count frequency of letters in current word
            unordered_map<char, int> wordFreq;
            for (char c : word) {
                wordFreq[c]++;
            }
            
            // Check if word is completing
            bool isCompleting = true;
            for (auto& it : lpFreq) {
                char letter = it.first;
                int requiredCount = it.second;
                
                if (wordFreq[letter] < requiredCount) {
                    isCompleting = false;
                    break;
                }
            }
            
            // If word is completing and shorter than current shortestWord, update shortestWord
            if (isCompleting && word.length() < minLength) {
                shortestWord = word;
                minLength = word.length();
            }
        }
        
        return shortestWord;
    
    }
};

//T.C:O(n+m*w)
//where N is the length of licensePlate.
//M is the number of words.
//W is the average length of each word.

