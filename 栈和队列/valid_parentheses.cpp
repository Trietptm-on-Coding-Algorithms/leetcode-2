problem:
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
---------------------------------------------
solution:
1、堆栈典型例子，括号匹配

class Solution {
public:
    bool isValid(string s) {
        string left="([{";
        string right=")]}";
		stack<char> stk;

		for(auto c : s){
			if (left.find(c) != string::npos)
			{
				stk.push(c);
			}
			else
			{
				// 这句太牛啦，判空和找到left中与右边对应位置的括号
				if(stk.empty() || stk.top() != left[right.find(c)])
					return false;
				else 
					stk.pop();
			}
		}
		return stk.empty();
    }
};