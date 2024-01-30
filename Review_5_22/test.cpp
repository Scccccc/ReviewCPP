#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

////917. 仅仅反转字母
//class Solution {
//public:
//    string reverseOnlyLetters(string s) {
//        string str = s;
//        int head = 0;
//        int tail = str.size() - 1;
//        while (head < tail)
//        {
//            if (!isalpha(str[head]))
//                ++head;
//            else if (!isalpha(str[tail]))
//                --tail;
//            if (isalpha(str[head]) && isalpha(str[tail]))
//            {
//                swap(str[head], str[tail]);
//                head++;
//                tail--;
//            }
//        }
//        return str;
//    }
//};

//415. 字符串相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        int carry = 0;
        string StrRet;
        while (end1 >= 0 || end2 >= 0)
        {
            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
            int ret = val1 + val2 + carry;
            carry = ret / 10;
            ret = ret % 10;

            StrRet += ('0' + ret);

            --end1;
            --end2;
        }
        if (carry == 1)
        {
            StrRet += '1';
        }

        reverse(StrRet.begin(), StrRet.end());

        return StrRet;

    }
};

int main()
{
    string s1 = "1";
    string s2 = "9";
    Solution n;
    string ret = n.addStrings(s1, s2);
    cout << ret << endl;
    
    return 0;
}