class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {

            if (tokens[i] != "+" && tokens[i] != "-" &&
                tokens[i] != "*" && tokens[i] != "/") {

                st.push(stoi(tokens[i]));
            }
            else {
                int a1 = st.top();
                st.pop();

                int a2 = st.top();
                st.pop();

                if (tokens[i] == "+") {
                    st.push(a2 + a1);
                }
                else if (tokens[i] == "-") {
                    st.push(a2 - a1);
                }
                else if (tokens[i] == "*") {
                    st.push(a2 * a1);
                }
                else if (tokens[i] == "/") {
                    st.push(a2 / a1);
                }
            }
        }

        return st.top();
    }
};