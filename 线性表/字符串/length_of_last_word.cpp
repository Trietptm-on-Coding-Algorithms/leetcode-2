problem:
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
----------------------------------------
solution:
1、思路：本想从后往	前找，不过结束条件不好控制！ prev(s.begin()) 这样貌似不正确
2、疯狂遍历一遍，不过有个条件不太明确

class Solution {
public:
    int lengthOfLastWord(string s) {
      int len = 0;
      int i = 0;
      while(i<s.size()){
          if(s[i++] != ' ') len ++;
          // 此处为什么一定要有s[i],'\0在捣鼓'？？？？
          else if(s[i] && s[i]!= ' ') len =0;
      }
      return len;
    }
};