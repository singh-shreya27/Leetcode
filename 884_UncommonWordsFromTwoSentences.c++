             //Uncommon words from two sentences


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
        istringstream iss1(s1), iss2(s2);
        string word;

        // Count words in s1
        while (iss1 >> word) {
            wordCount[word]++;
        }

        // Count words in s2
        while (iss2 >> word) {
            wordCount[word]++;
        }

        vector<string> uncommonWords;
        for (auto& pair : wordCount) {
            if (pair.second == 1) { // Check if the word appears exactly once
                uncommonWords.push_back(pair.first); // Add it to the uncommon words list
            }
        }

        return uncommonWords;
    }
};
