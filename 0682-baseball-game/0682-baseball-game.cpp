class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int sm = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "C") {
                sm -= st.top();
                st.pop();
            } else if (operations[i] == "D") {
                st.push(2 * st.top());
                sm += st.top();
            } else if (operations[i] == "+") {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();

                st.push(t1);
                st.push(t1 + t2);
                sm += (t1 + t2);

            } else {
                st.push(stoi(operations[i]));
                sm += st.top();
            }
        }
        return sm;
    }
};