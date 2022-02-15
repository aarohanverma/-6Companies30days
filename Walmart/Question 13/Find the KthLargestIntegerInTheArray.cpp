class Solution {
public:
    static bool comparator(const string &s1,const string &s2)
    {
        return s1.size() == s2.size() ? s1 > s2 : s1.size() > s2.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),comparator);
        return nums[k-1];
    }
};
