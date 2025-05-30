class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        
        for (auto s : strs)
        {   
            int count[26] = {0};
            for (char c : s) {
                count[c - 'a']++;
            }

            string key;
            for (int i = 0; i < 26; ++i) {
                key += '#'; 
                key += to_string(count[i]);
            }

            mp[key].push_back(s);



        }

        vector<vector<string>> result;
        for (auto& pair : mp) {
            result.push_back(pair.second);
        }
        return result;
    }

    
    
};