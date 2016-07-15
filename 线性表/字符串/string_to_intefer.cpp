problem:
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

solution:
1、正负号
2、连续数字
3、是否超过最大值、最小值（这个忘了考虑了）
4、忘了考虑空字符跳过问题
class Solution {
public:
    int myAtoi(string str) {
        auto it = str.begin();
        int sign = 1;
        int sum = 0;

        while(*it == ' ') it++;

        if(*it == '-') {
        	sign = -1;
        	it ++;
        }
        else if(*it== '+'){
        	sign = 1;
        	it ++;

        }
        else if (!isdigit(*it)) 
        {
        	return 0;
        }

        while(it != str.end() && isdigit(*it)){
        	// 乘以10后直接超了，或者起那么正好，后面加8达到了最大值，如果为负的为最小值，正的超过了最大值。
        	if (sum > INT_MAX/10 || sum == INT_MAX/10 && *it-'0' >7)
        	{
        		if (sign == 1) return INT_MAX;
        		else return INT_MIN;
        	}
        	// 忘了乘以10了，后面加了前面别再加了
        	sum = sum *10 + ((*it) - '0');
        	it ++;
        }
        return sign * sum;

    }
};