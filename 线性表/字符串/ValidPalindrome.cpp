problem:
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
-----------------------------------------
solution:
1、求出字符串长度
2、前后指针向中间逼近
3、注意：全部转为小写、只考虑字母和数字，其他忽略
template < class InputIterator, class OutputIterator, class UnaryOperator >
  OutputIterator transform ( InputIterator first1, InputIterator last1,
                             OutputIterator result, UnaryOperator op );

template < class InputIterator1, class InputIterator2,
           class OutputIterator, class BinaryOperator >
  OutputIterator transform ( InputIterator1 first1, InputIterator1 last1,
                             InputIterator2 first2, OutputIterator result,
                             BinaryOperator binary_op );
  // transform algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int op_increase (int i) { return ++i; }
int op_sum (int i, int j) { return i+j; }

int main () {
  vector<int> first;
  vector<int> second;
  vector<int>::iterator it;

  // set some values:
  for (int i=1; i<6; i++) first.push_back (i*10); //  first: 10 20 30 40 50

  second.resize(first.size());     // allocate space
  transform (first.begin(), first.end(), second.begin(), op_increase);
                                                  // second: 11 21 31 41 51

  transform (first.begin(), first.end(), second.begin(), first.begin(), op_sum);
                                                  //  first: 21 41 61 81 101

  cout << "first contains:";
  for (it=first.begin(); it!=first.end(); ++it)
    cout << " " << *it;

  cout << endl;
  return 0;
}


class Solution {
public:
    bool isPalindrome(string s) {
    	// transform函数用错了，少了s.begin(),tolower加了括号
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		auto left = s.begin(), right = prev(s.end());
		while(left < right){
			if(!::isalnum(*left)) ++left;
			else if(!::isalnum(*right)) --right;
			else if(*left != *right) return false;
			else {
				left ++;
				right --;
			}
		}
		return true;
    }
};