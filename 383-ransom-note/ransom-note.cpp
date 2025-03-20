class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int list[26];

        for(char ch: magazine)
        {
            list[ch-'a']++;
        }

        for(char ch: ransomNote)
        {
            if(list[ch -'a'] ==0) return false;
            list[ch-'a']--;
        }
        return true;
    }
};