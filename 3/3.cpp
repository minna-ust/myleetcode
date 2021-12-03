class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        std::set<int> st;
        st.insert(s[0]);
        for (int i = 1; i < s.size(); ++i)
        {
            if (st.find(s[i]) != st.end())
            {

    }
};
