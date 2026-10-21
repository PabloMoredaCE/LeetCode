#include <algorithm>

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> memory;
        for(int i = 0; i < static_cast<int>(ransomNote.size()); ++i) {
            int letter = magazine.find(ransomNote[i]);
            if(letter == string::npos) {
                return false;
            } 
            magazine[letter] = '*';
        }
        return true;
    }
};