#include "Stack.cpp"
#include "Queue.cpp"

// Câu 1: Parentheses
bool isValidParentheses(string s) {
    Stack st;
    for (char c : s) {
        if (c == '{' || c == '(' || c == '[') {
            st.push(c);
        }
        else if (c == '}' || c == ')' || c == ']') {
            if (!st.isEmpty()) {
                char top = st.peek();
                st.pop();
                if ((c == '}' && top != '{') || (c == ')' && top != '(') || (c == ']' && top != '[') ) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    return true;
}

//Câu 2: Palindrome
bool isValidPalindrome(string s) {
    Queue q;
    bool isValid = false;
    if (s.length() > 0) {
        int length = s.size() / 2;
        for (int i = 0; i < length;i++) {
            q.enQueue(s[i]);
        }
        isValid = true;
        for (int i = 1; i <= length && isValid; i++) {
            isValid = q.getFront() == s[s.size() - i];
            q.deQueue();
        }
    }
    return isValid;
}


int main() {
    // Câu 1
    string test_str_1[] = {"{{((abc))}}", "{{a((tes)t}}}"};
    for (auto x : test_str_1) {
        if (isValidParentheses(x)) {
            cout << "Valid Parentheses" << endl;
        }
        else {
            cout << "Invalid Parentheses" << endl;
        }
    }

    // Câu 2
    string test_str_2[] = {"radar", "level", "madam", "test"};
    for (auto x : test_str_2) {
        if (isValidPalindrome(x)) {
            cout << "Valid Palindrome" << endl;
        }
        else {
            cout << "Invalid Palindrome" << endl;
        }
    } 
    return 0;
}