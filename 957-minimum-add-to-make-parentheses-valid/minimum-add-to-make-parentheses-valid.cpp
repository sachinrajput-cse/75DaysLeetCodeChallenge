class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> myStack;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')' && myStack.size() > 0 && myStack.top() == '('){
                myStack.pop();
                continue;
            }
            myStack.push(s[i]);
        }
        return myStack.size();
    }
};