class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string cur;

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {

                if (cur == "..") {
                    if (!st.empty())
                        st.pop();
                }
                else if (!cur.empty() && cur != ".") {
                    st.push(cur);
                }

                cur.clear();
            }
            else {
                cur += path[i];
            }
        }

        if (st.empty())
            return "/";

        vector<string> dirs;
        while (!st.empty()) {
            dirs.push_back(st.top());
            st.pop();
        }

        reverse(dirs.begin(), dirs.end());

        string ans;
        for (string &dir : dirs) {
            ans += "/" + dir;
        }

        return ans;
    }
};