#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxPartitionsAfterOperations(string S, int K) {
        int N = S.length();
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            A[i] = 1 << (S[i] - 'a');
        }
        unordered_map<int, int> cache;
        function<int(int, bool, int)> dp = [&](int i, bool option, int mask) {
            if (i == N) {
                return 0;
            }
            int mask2 = mask | A[i];
            if (__builtin_popcount(mask2) > K) {
                int ans = 1 + dp(i + 1, option, A[i]);
                return ans;
            } else {
                int ans = dp(i + 1, option, mask2);
                if (option) {
                    for (int j = 0; j < 26; j++) {
                        mask2 = mask | (1 << j);
                        if (__builtin_popcount(mask2) > K) {
                            ans = max(ans, 1 + dp(i + 1, false, 1 << j));
                        } else {
                            ans = max(ans, dp(i + 1, false, mask2));
                        }
                    }
                }
                return ans;
            }
        };
        return dp(0, true, 0) + 1;
    }
};

int main() {
    Solution solution;
    string S = "abcde";
    int K = 2;
    int result = solution.maxPartitionsAfterOperations(S, K);
    cout << result << endl;
    return 0;
}


