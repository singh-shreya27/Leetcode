//Find the first and last occurrence of x.

//brute force solution:
//first=-1,last=-1, then do a linear search and update the first and last with the index .

int first=-1,last=-1;
for(int i=0;i<n-1;i++){
  if(nums[i]==target){
    if(first==-1) first=i;  //first is updated only when it is -1(for the first time only)
     last=i;    //last is updated everytime.
  }
}

//T.C:O(n)

//the interviewr will not be happy with this and ask you to optimise this.
//the given array is sorted, so search+sorted=binary search.

//lower bound= nums[idx]>=target
//upper bound= nums[idx]>target

//leetcode solution already present there:
class Solution {
public:
    int firstOcc(vector<int>& nums,int n,int target){
   int start=0;
   int end=n-1;
   int mid=start +(end-start)/2;
   int ans=-1;
   while(start <=end){
    if (target>nums[mid]){
     start=mid+1;
    }
    else if(target<nums[mid]){
      end=mid-1;
    }
    else if(target==nums[mid]){
       ans=mid;
       end=mid-1; 
    }
    mid=start+(end-start)/2;
   }
   return ans;
}

int lastOcc(vector<int>& nums,int n,int target){
   int start=0;
   int end=n-1;
   int mid=start +(end-start)/2;
   int ans=-1;
   while(start <=end){
    if (target>nums[mid]){
     start=mid+1;
    }
    else if(target<nums[mid]){
      end=mid-1;
    }
    else if(target==nums[mid]){
       ans=mid;
       start=mid+1; 
    }
    mid=start+(end-start)/2;
   }
   return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left_most=firstOcc(nums,n,target);
        int right_most=lastOcc(nums,n,target);
        return{left_most,right_most};
    }
};

//leetcode solution striver:
class Solution {
public:
    int lowerBound(vector<int> nums,int target){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            //maybe an answer
            if(nums[mid]>=target){                            //T.C:O(log2n)
                ans=mid;
                //look for more small index on left
                high=mid-1;
            }
            else{
                //look for right
                low=mid+1; 
            }
        }
        return ans;
    }

    int upperBound(vector<int> &nums, int target){
        int n=nums.size();
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            //maybe an answer
            if(nums[mid]>target){                                      //T.C:O(log2n)
                ans=mid;
                //look for more small index on left
                high=mid-1;
            }
            else{
                low=mid+1; //look for right
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerBound(nums,target);
        if(lb==n || nums[lb] !=target) return {-1,-1};
        return{lb,upperBound(nums,target)-1};

    } 
};

//T.C: 2*O(log2n)
//S.C:O(1)

//but some interviewer will ask you to not go into lower and upper bound concept.

//Obviously, in a single binary search we cannot find both fist and last occurrences.

class Solution {
public:
    int firstOccurrence(vector<int>& nums,int target){
        int n=nums.size();
        int low=0,high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                first = mid;
                high=mid-1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return first;
    }
    int lastOccurrence(vector<int>& nums,int target){
        int n=nums.size();
        int low=0,high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                last = mid;
                low=mid+1;
            }
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first=firstOccurrence(nums,target);
        if(first==-1) return {-1,-1};
        int last=lastOccurrence(nums,target);
        return{first,last};
    }
};

//T.C:
