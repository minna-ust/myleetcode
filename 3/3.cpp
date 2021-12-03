//abcbd
//abcb
//abc

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        if (s.size() == 1)
            return 1;
        int max_len = 0;
        std::set<char> st;
        st.insert(s[0]);
        int index_start = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            if (st.find(s[i]) != st.end())
            {
                for (int j = index_start; j < i; ++j)
                {
                    if (s[j] != s[i])
                    {
                        st.erase(s[j]);
                    }
                    else
                    {
                        max_len = std::max(max_len, i - index_start);
                        index_start = j + 1;
                        break;
                    }
                }
            }
            else
            {
                st.insert(s[i]);
            }
            if (i == s.size() - 1)
            {
                max_len = std::max(max_len, i - index_start + 1);
            }
        }
        return max_len;
    }
};
