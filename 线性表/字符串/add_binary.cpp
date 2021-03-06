problem:
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

----------------------------
solution:
1、字符串逆序相加
2、字符串插入操作
iterator insert ( iterator p, char c ); 
1、记录一个最长的长度n
2、计算n次加法操作
3、最后一次看进位是否为1

class Solution {
public:
    string addBinary(string a, string b) {
    	string result;
    	const size_t n = a.size() > b.size()? a.size() : b.size();
    	reverse(a.begin(), a.end());
    	reverse(b.begin(), b.end());

    	int carry = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		const int ai = i< a.size() ? a[i]-'0': 0;
    		const int bi = i< b.size() ? b[i]-'0': 0;
    		const int val = (ai + bi+ carry) %2;
    		carry = (ai + bi + carry) /2;
    		result.insert(result.begin(), val +'0');
    	}
    	if (carry == 1)
    	{
    		result.insert(result.begin(), '1');
    	}
    	return result;
    }
};
