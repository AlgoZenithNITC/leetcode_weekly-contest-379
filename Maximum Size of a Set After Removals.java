import java.util.HashSet;

class Solution {
    public int maximumSetSize(int[] nums1, int[] nums2) {
        HashSet<Integer> s1 = new HashSet<>();
        HashSet<Integer> s2 = new HashSet<>();
        HashSet<Integer> u = new HashSet<>();
        
        int n = nums1.length / 2;
        
        for (int x : nums1) {
            s1.add(x);
            u.add(x);
        }
        
        for (int x : nums2) {
            s2.add(x);
            u.add(x);
        }
        
        int common = s1.size() + s2.size() - u.size();
        int n1 = s1.size();
        int n2 = s2.size();
        int ans = 0;
        
        ans += Math.min(n, n1 - common);
        ans += Math.min(n, n2 - common);
        ans += common;
        ans = Math.min(ans, n * 2);
        
        return ans;
    }
}


