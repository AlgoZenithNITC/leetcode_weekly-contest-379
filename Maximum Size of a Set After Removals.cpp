class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2, u;
        //s1 = set(nums1)  and  s2 = set(nums2)
        //u= s1 union s2

        int n = nums1.size() / 2;   // number of elements to be choosen from each array
        for(auto x:nums1){
            s1.insert(x);
            u.insert(x);
        }
        for(auto x:nums2){
            s2.insert(x);
            u.insert(x);
        }
        int common = s1.size() + s2.size() - u.size();   // size of s1 intersection s2
        int n1 = s1.size();
        int n2 = s2.size();

        int ans = 0;
        ans += min(n, n1-common);   // take all elements from s1-s2  [maximum n elements]
        ans += min(n, n2-common);   // take all elements from s2-s1
        ans += common;              // now take common elements
        ans = min(ans, n * 2);      // if nukber of elements taken are more than 2*n make the answer 2*n
        return ans;
    }
};
