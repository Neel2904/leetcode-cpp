class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> frequency(3, 0);
        for (char ch : s)
            frequency[ch - 'a']++;
        if (frequency[0] < k || frequency[1] < k || frequency[2] < k) {
            return -1;
        }

        int n = s.size();
        int ans = n; // Here the major issue is concerned if we don't initialize ans variable it will give wrong ans and even go in above bas case if condition!!
        for (int start = 0, end = 0; end < n; end++) {
            frequency[s[end] - 'a']--;

            while (start <= end &&
                   any_of(frequency.begin(), frequency.end(), [k](int f) { return f < k; })) {
                frequency[s[start] - 'a']++;
                start++;
            }
            ans = min(ans, n - (end - start + 1));
        }
        return ans;
    }
};