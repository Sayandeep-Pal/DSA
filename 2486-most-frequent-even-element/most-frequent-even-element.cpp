class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map<int, int> seen;

        for (int n : nums) {
            if (n % 2 == 0) {
                seen[n]++;
            }
        }

        if (seen.size() == 0)
            return -1;

        int maxfreq = 0, res = -1;
        for (auto& [num, freq] : seen) {
            if (freq > maxfreq || (freq == maxfreq && num < res)) {
                maxfreq = freq;
                res = num;
            }
        }
        return res;
    }
};