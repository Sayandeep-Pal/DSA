class Solution {
public:
    bool isIsomorphic(string s, string t) {

        char s_to_t[256];
        char t_to_s[256];

        for (int i = 0; i < s.length(); i++) {
            char char_s = s[i];
            char char_t = t[i];

            if (s_to_t[char_s] != 0) {
                if (s_to_t[char_s] != char_t) return false;
            } else {
                if (t_to_s[char_t] != 0) {
                    if (t_to_s[char_t] != char_s) return false;
                } else {
                    s_to_t[char_s] = char_t;
                    t_to_s[char_t] = char_s;
                }
            }
        }
        return true;
    }
};