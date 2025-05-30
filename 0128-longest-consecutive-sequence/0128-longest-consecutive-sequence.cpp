class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        int longest=0;
        
        for(auto it :st)
        {
            if(st.find(it-1)==st.end())
            {
                int len = 1;
                while(st.find(it+len)!=st.end())
                {
                    len++;

                }
                longest =max(longest,len);

            }
        }
        return longest;
    }
};