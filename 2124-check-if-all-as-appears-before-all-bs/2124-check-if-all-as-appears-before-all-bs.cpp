class Solution {
public:
    bool checkString(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'b') {
                for(int j = s.size(); j >= i; j--) {
                    if(s[j] == 'a') {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};