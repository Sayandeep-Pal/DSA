class Solution {
    // private:
    // bool help(string str)
    // {
    //     int oFirst=0, oSec=0,  oThird=0;
    //     int i=0;
    //     while(str[i]!='\0')
    //     {
    //         switch(str[i])
    //         {
    //             case '(': oFirst++; break;
    //             case ')': oFirst--; break;
    //             case '{': oSec++; break;
    //             case '}': oSec--; break;
    //             case '[': oThird++; break;
    //             case ']': oThird--; break;
    //             default: continue;
    //         }
    //         i++;
    //     }
    //     if(oFirst == 0 && oSec==0 && oThird==0)
    //     {
    //         return true;
    //     }
    //     else
    //         return false;
    // }
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if ((ch == ')' && top != '(') || (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};