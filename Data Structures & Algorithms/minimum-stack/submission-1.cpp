class MinStack {
public:
    stack<int> st;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();       
    }
    
    int getMin() {
        stack <int> temp = st;
        int min = temp.top();
        while(!temp.empty()){
            if(temp.top()<=min){
                min = temp.top();
            }
            temp.pop();
        }
        return min;
    }
};
