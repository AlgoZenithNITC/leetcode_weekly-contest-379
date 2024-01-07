class Solution:
    def maximumSetSize(self, nums1, nums2):
        s1 = set()
        s2 = set()
        u = set()
        
        n = len(nums1) // 2
        for x in nums1:
            s1.add(x)
            u.add(x)
        for x in nums2:
            s2.add(x)
            u.add(x)
        
        common = len(s1) + len(s2) - len(u)
        n1 = len(s1)
        n2 = len(s2)
        ans = 0
        ans += min(n, n1 - common)
        ans += min(n, n2 - common)
        ans += common
        ans = min(ans, n * 2)
        return ans


