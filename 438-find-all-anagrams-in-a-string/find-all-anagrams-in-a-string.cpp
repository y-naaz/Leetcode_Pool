class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int reqCount = p.size();

        vector<int> counter(26, 0);

        for (char ch : p) {
            counter[ch - 'a']++;
        }

        vector<int> ans;
        int i = 0, j = 0;

        while (j < n) {
            counter[s[j]-'a']--;
            if (counter[s[j] - 'a'] >= 0) {
                reqCount--;
            }
            while (reqCount == 0) {
                if (j - i + 1 == p.size()) {
                    ans.push_back(i);
                }
                counter[s[i]-'a']++;
                if (counter[s[i] - 'a'] > 0) {
                    reqCount++;  
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};
