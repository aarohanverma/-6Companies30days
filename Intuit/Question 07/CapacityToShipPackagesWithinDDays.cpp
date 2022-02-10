class Solution {
public:
    
    
    // Exactly similar to "split array largest sum"
    // Exactly similar to "Allocated to minimum number of pages"
    bool isPossible(vector<int>&weight, int capacity, int days)
    {
        int total=0, d=1;
        for(int i=0;i<weight.size();i++){
            
            total+=weight[i];
            if(total > capacity){
                
                d++;
                total = weight[i];
            }
            
            if(d > days)
                return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        int lo = *max_element(weights.begin(), weights.end());   // minimum weight
        int hi = accumulate(weights.begin(), weights.end(), 0);  // maximum weight
        
        int ans=0;
        while(lo<=hi){
            
            int mid = lo+(hi-lo)/2;          // mid is weight capacity
            if(isPossible(weights, mid, days)){ 
                
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
