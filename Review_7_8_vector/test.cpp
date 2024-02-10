#define _CRT_SECURE_NO_WARNINGS 1



#include"vector.h"

//118. 杨辉三角
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows)
//    {
//        vector<vector<int>> vv;
//        vv.resize(numRows);
//        for (size_t i = 0; i < vv.size(); ++i)
//        {
//            vv[i].resize(i + 1, 0);
//            vv[i][0] = vv[i][i] = 1;
//
//            for (size_t j = 0; j < vv[i].size(); ++j)
//            {
//                if (vv[i][j] == 0)
//                {
//                    vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
//                }
//            }
//
//        }
//        return vv;
//    }
//};


class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}
	~A()
	{
		_size = 0;
	}
private:
	int _size;
};
//
//int main()
//{
//	A* p = (A*)malloc(sizeof(A));
//	//显示调用构造
//	new(p)A();//匿名对象
//	
//	p->~A();
//	free(p);
//	return 0;
//}

int main()
{
	sc::test_vector7();
	return 0;
}