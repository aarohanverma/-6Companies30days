class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int n= nums.size();
        int i=0, j=0, minLen=INT_MAX, curLen=0, curSum=0;
        while(j<n){
            curSum+= nums[j];
            curLen= j-i+1;
            
            if(curSum >= target){    
                while(curSum-nums[i] >= target){
                    curSum= curSum-nums[i++];
                    curLen= j-i+1;
                }
                minLen= min(minLen, curLen);
            }
            j++;
        }
        if(minLen==INT_MAX)
            return 0;
        return minLen;
    }
};
