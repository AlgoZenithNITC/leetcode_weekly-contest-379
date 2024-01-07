import java.util.HashMap;
import java.util.Map;

class Solution {
    public int maxPartitionsAfterOperations(String S, int K) {
        int N = S.length();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = 1 << (S.charAt(i) - 'a');
        }
        Map<String, Integer> cache = new HashMap<>();
        return dp(0, 1, 0, A, K, cache) + 1;
    }
    
    private int dp(int i, int option, int mask, int[] A, int K, Map<String, Integer> cache) {
        if (i == A.length) {
            return 0;
        }
        String key = i + "_" + option + "_" + mask;
        if (cache.containsKey(key)) {
            return cache.get(key);
        }
        int mask2 = mask | A[i];
        int ans;
        if (Integer.bitCount(mask2) > K) {
            ans = 1 + dp(i + 1, option, A[i], A, K, cache);
        } else {
            ans = dp(i + 1, option, mask2, A, K, cache);
        }
        if (option == 1) {
            for (int j = 0; j < 26; j++) {
                mask2 = mask | (1 << j);
                if (Integer.bitCount(mask2) > K) {
                    ans = Math.max(ans, 1 + dp(i + 1, 0, 1 << j, A, K, cache));
                } else {
                    ans = Math.max(ans, dp(i + 1, 0, mask2, A, K, cache));
                }
            }
        }
        cache.put(key, ans);
        return ans;
    }
}


