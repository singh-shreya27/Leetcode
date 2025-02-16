           //Sign of a product of an array.

class Solution {
public:
   
    int arraySign(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int num :nums){
            if(num ==0)
              return 0;
            else if (num<0)
                count++;
        }
       return (count%2 == 0 )?1:-1;    
    }
};

//What does int num : nums do?
//It iterates over each element of the vector nums, assigning the current value to num in 
//each iteration.

//Why use it?
//Simplifies the Code

// No need to use an index (i), making the loop cleaner.
// Avoids potential index-related bugs.
// Improves Readability

// Focuses on values directly rather than worrying about indices.
// Easier to understand at a glance.
// Performance (for const references)

// If working with large objects, using const auto& num : nums avoids unnecessary copying.



