//royal pain in the crack
//O(m) solution here in both tc and sc
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int min_length = 0, pos;
        int sum = t.length();
        int map_char[128] = {0};
        for (int i = 0; i < t.length(); i++) {
            map_char[t[i]]++;
        }
        while(right < s.length()) {
            map_char[s[right]]--;
            if (map_char[s[right]] >= 0) sum--;
            while(sum == 0 && left <= right) {
                if (min_length == 0 || min_length > right - left + 1) {
                    min_length = right - left + 1;
                    pos = left;
                }
                if (++map_char[s[left++]] > 0) {
                    sum++;
                }
            }
            right++;
        }
        if (min_length == 0) return "";
        return s.substr(pos, min_length);
    }
};
