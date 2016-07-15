problem:
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
------------------------------------------------------
solution:

思路：
1、从开始往后找，匹配则后移，不匹配则回退

class Solution {
public:
    int strStr(string haystack, string needle) {
        int length = needle.size();
        auto hit = haystack.begin();
        auto nit = needle.begin();
        auto tmpit = haystack.begin();
        int result = 0;
        // 此处只想着nit到最后忘了hit到最后了
        while(hit != haystack.end() && nit != needle.end()){

        	if (*nit != *hit)
        	{
        		tmpit++;
        		hit = tmpit;
        		result ++;
        		nit = needle.begin();
        	}
        	else
        	{
        		nit ++;
        		hit ++;
        	}

        }
        if (nit == needle.end())
        {
        	return result;
        }

        return -1;
    }
};