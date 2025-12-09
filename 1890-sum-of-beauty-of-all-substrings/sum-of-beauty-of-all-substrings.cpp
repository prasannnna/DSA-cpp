class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<char, int>frq;
            
            for(int j = i; j < n; j++) {
                frq[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
               for(auto f : frq){
                    maxi = max(f.second, maxi);
                    mini = min(f.second, mini);
                }
                sum += maxi - mini;
            }
            
        }
        return sum;
    }
};