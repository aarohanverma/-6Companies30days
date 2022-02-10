class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(); 
        int low = 0;
        int high = n-1;
		
        //Finding the index of peak element
        while(low<=high){
          int mid = low + (high-low)/2;
         if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        } 
        int peak_idx = low;
        
        //Binary Search on the ascending range
        low = 0;
        high = peak_idx;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        //Binary Search on the descending range
        low = peak_idx + 1;
        high = n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mountainArr.get(mid)== target){
                return mid;
            }
            else if(mountainArr.get(mid) > target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};
