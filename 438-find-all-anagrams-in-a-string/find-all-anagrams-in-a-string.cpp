class Solution {
public:
    bool allzeros(vector<int>& counter) {
        for (int &i : counter) {
            if (i != 0) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        vector<int> counter(26, 0);

        // Count frequency of characters in pattern
        for (char ch : p) {
            counter[ch - 'a']++;
        }

        vector<int> ans;
        int i = 0, j = 0;

        while (j < n) {
            // Add the current character to the window
            counter[s[j] - 'a']--;

            // When the window size matches the pattern size
            if (j - i + 1 == k) {
                if (allzeros(counter)) {
                    ans.push_back(i);
                }

                // Before sliding the window, restore s[i] and move i forward
                counter[s[i] - 'a']++;
                i++;
            }

            j++;
        }

        return ans;
    }
};
