//errichto's video
// leetcode week 4
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i,answer=0,pref=0,r=0,n=nums.size();
        unordered_map<int,int> count;
        count[0]++;
        for(i=0;i<n;i++){
            pref+=nums[i];
            int need=pref-k;
            answer+=count[need];
            count[pref]++;
        }
        return answer;
    }
};
