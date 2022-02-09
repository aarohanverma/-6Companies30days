class Solution {
public:
    
    bool check(int mid,vector<int>& nums,int m) {
        int ct=1;
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(sum>mid) {
                if(nums[i]>mid)
                    return false;
                sum=nums[i];
                ct++;
            }
        }
        if(ct>m) {
            return false;
        }
        return true;
        
    }
    int bs(int low,int high,vector<int>& nums,int m) {
        
        if(low>high)
            return -1;
        if(low==high)
            return low;
        
        int mid = low+(high-low)/2;
        if(check(mid,nums,m)) {
            return bs(low,mid,nums,m);
        } else {
            return bs(mid+1,high,nums,m);
        }
    }
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        for(auto it:nums) {
            sum+=it;
        }
        return bs(0,sum,nums,m);
    }
};
