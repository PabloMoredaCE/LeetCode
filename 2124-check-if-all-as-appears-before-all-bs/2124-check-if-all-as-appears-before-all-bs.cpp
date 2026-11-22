class Solution {
public:
    bool checkString(string s) {
        // Final solution O(n) time O(1) space
        auto b = s.find('b');
        if(b != std::string::npos && s.find('a', b + 1) != std::string::npos) {
            return false;
        }
        return true;

        /* O(n) O(1) Easier method: traverse the string only once 
        bool found = false;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'b' && !found) {
                found = true;
            }

            if(s[i] == 'a' && found) {
                return false;
            }
        }
        return true;
        */

        /* Initial brute force idea: O(n^2)
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'b') {
                for(int j = s.size() - 1; j >= i; j--) {
                    if(s[j] == 'a') {
                        return false;
                    }
                }
            }
        }
        return true;
        */
    }
};