class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n);
        bool check = false;
        for(int i = 1; i <= n; i++) {
            if(i == 1) {result[i-1] = to_string(i); continue;}
            if((i % 3) == 0) {
                result[i-1] = "Fizz";
                check = true;
            }
            if((i % 5) == 0) {
                result[i-1] += "Buzz";
            } else if(!check) {
                result[i-1] = to_string(i);
            }
            check = false;

        }
        
        return result;
    }
};