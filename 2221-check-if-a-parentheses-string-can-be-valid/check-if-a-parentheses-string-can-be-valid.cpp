class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2!=0)
        {
            return false;
        }
        stack<int>rigid;
        stack<int>flexible;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '0') {
                flexible.push(i);
            } else {
                if (s[i] == '(') {
                    rigid.push(i);
                } else if (s[i] == ')') {
                    if (!rigid.empty()) {
                        rigid.pop();
                    } else if (!flexible.empty()) {
                        flexible.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        while (!flexible.empty() && !rigid.empty()) {
            if (flexible.top() > rigid.top()) {
                rigid.pop();
                flexible.pop();
            } else {
                return false;
            }
        }
        return rigid.empty();
    }
};