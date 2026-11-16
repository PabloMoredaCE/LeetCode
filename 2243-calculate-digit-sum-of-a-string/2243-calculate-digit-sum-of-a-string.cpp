class Solution {
public:
    string digitSum(string s, int k) {
        std::string aux;

        while(s.size() > k) {
            // Division
            for(int i = 0; i < s.size(); i += k) {
                std::string push(s, i, k);

                // Sum of digits
                int sum = 0;
                for(int j = 0; j < push.size(); j++) {
                    sum += push[j] - '0';
                }

                // Merge
                aux += std::to_string(sum);
            }

            s = aux;
            aux.clear();
        }

        return s;
    }
};