                           //Heaters

//binary search approach:
class Solution {
public:
    int binarySearchCeil(vector<int> &arr, int n, int key){
        int ans=-1,s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==key){
                ans=arr[mid];
                return ans;
            }
            else if(arr[mid]>key){
                ans=arr[mid];
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
    int binarySearchFloor(vector<int> &arr, int n, int key){
        int ans=-1,s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==key){
                ans=arr[mid];
                return ans;
            }
            else if(arr[mid]<key){
                ans=arr[mid];
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size();
        int m=heaters.size();
        int ans=0;
        //we don't need to sort houses.
        sort(heaters.begin(),heaters.end());
        for(int i=0;i<n;i++){
            int h=houses[i];
            int floorValue=binarySearchFloor(heaters,m,h);
            int ceilValue=binarySearchCeil(heaters,m,h);
            if(floorValue==-1){
                floorValue=ceilValue;
            }
            if(ceilValue=-1){
                ceilValue=floorValue;
            }
            int mn=min(abs(h-floorValue), abs(h-ceilValue));
            ans=max(ans,mn);
        }
        return ans;
    }
};


//two pointer approach:
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

       int i=0, radius=0;  // i -> pointer for heaters, radius -> max minimum distance
       for(int house:houses){
        //move to the next heater if it's closer to the current house
        while(i<heaters.size()-1 && abs(heaters[i]-house)>=abs(heaters[i+1]-house)){
            i++;
        }
        //compute distance to the closest heater
        radius=max(radius, abs(heaters[i]-house));
       }
       return radius;
    }
};

//sorting takes:
//Single pass through houses:𝑂(𝑛)
//Total complexity:O(nlogn+mlogm+n)=O(nlogn+mlogm)
