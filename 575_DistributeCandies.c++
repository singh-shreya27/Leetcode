                                //Distribute Candies

//first find out how many different types of candies are there.
//easiest way:SET because it only stores a single instance of a type.


class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        //set to store the different kinds of candies
        set<int>s;
        for(auto candy:candyType) 
        s.insert(candy);
        int m=s.size();
        return min(n/2,m);
    }
};

// Time Complexity:
// Inserting Elements into Set (s.insert(candy)): Inserting an element into a set typically takes 
// 𝑂(log𝑚)
// O(logm) time, where m is the number of unique elements (different kinds of candies) inserted so far.

// Iterating through candyType Vector: This involves iterating through all n elements of the candyType vector once.

// Therefore, the overall time complexity is 
//t.c: 𝑂(𝑛log𝑚)
// O(nlogm), where n is the number of elements in the candyType vector, and m is the number of unique kinds of candies.

// Space Complexity: 
// 𝑂(𝑚) 
// where 𝑚 is the number of unique candy types.
