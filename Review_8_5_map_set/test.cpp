#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <set>

using namespace std;


void test1()
{
	multiset<int> s;
	s.insert(1);
	s.insert(3);
	s.insert(4);
	s.insert(3);
	s.insert(3);
	s.insert(3);
	s.insert(3);
	cout << s.count(3) << endl;

	auto ret = s.equal_range(3);
	auto low = ret.first;
	auto up = ret.second;

	s.erase(low, up);
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test1();
	return 0;
}

//692. 前K个高频单词
class Solution {
public:
    struct Greater
    {
        bool operator()(const pair<string, int>& p1, const pair<string, int>& p2)
        {
            return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> countmap;
        for (auto& e : words)
        {
            countmap[e]++;
        }

        vector<pair<string, int>> kvmap(countmap.begin(), countmap.end());
        //稳定的排序
        //stable_sort(kvmap.begin(), kvmap.end(), Greater());
        //自己仿函数控制比较逻辑
        sort(kvmap.begin(), kvmap.end(), Greater());

        vector<string> ret;

        for (int i = 0; i < k; ++i)
        {
            ret.push_back(kvmap[i].first);
        }

        return ret;
    }
};


//349. 两个数组的交集
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> t1(nums1.begin(), nums1.end());
        set<int> t2(nums2.begin(), nums2.end());

        auto it1 = t1.begin();
        auto it2 = t2.begin();
        vector<int> ret;
        while (it1 != t1.end() && it2 != t2.end())
        {
            if (*it1 < *it2)
            {
                ++it1;
            }
            else if (*it1 > *it2)
            {
                ++it2;
            }
            else
            {
                ret.push_back(*it1);
                ++it1;
                ++it2;
            }
        }
        return ret;
    }
};