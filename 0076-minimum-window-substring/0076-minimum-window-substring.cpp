class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (s.empty() || t.empty() || n>m) {
            return "";
        }
        map<char,int>mt;
        for(char c :t)
        {
            mt[c]++;
        }

        int cnt = n ;
         int l = 0, r = 0, minLen = INT_MAX, startIndex = 0;

         while(r < m)
         {
           if(mt[s[r]]>0)
           {
             cnt--;
           }
            mt[s[r]]--;
             r++;
           while(cnt==0)
           {
                if (r - l < minLen)
                {
                    startIndex = l;
                    minLen = r - l;
                }

                if (mt[s[l]] == 0) 
                {
                    cnt++;
                }
                mt[s[l]]++;
                l++;
           }

         }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
        
    }
};