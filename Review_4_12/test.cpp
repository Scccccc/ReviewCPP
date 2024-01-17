#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//#include <iostream>
//using namespace std;
//
////全局域
//int a = 0;
//
//int main()
//{
//	//局部域
//	int a = 1;
//	printf("%d\n", a);
//
//	printf("%d\n", ::a);//访问限定符
//	return 0;
//}



//int a = 1;
//
////命名空间
//namespace sc
//{
//	int a = 2;
//}
//
//int main()
//{
//	int a = 0;
//	printf("%d\n", a);
//	printf("%d\n", ::a);//去全局域找变量a
//	printf("%d\n", sc::a);//去指定命名空间找变量a
//	return 0;
//}


////局部域->全局域->展开了命名空间域->指定访问命名空间域
////int a = 1;
//
////命名空间
//namespace sc
//{
//	int a = 2;
//}
//using namespace sc;
//
//int main()
//{
//	//int a = 0;
//	printf("%d\n", a);//去指定命名空间找变量a
//	return 0;
//}

//
//namespace sc
//{
//	int rand = 1;
//}
//
//int main()
//{
//	printf("%d\n", sc::rand);
//	printf("%p\n", rand);
//	return 0;
//}

//命名空间嵌套

namespace sc
{
	int a = 0;
	namespace sc1
	{
		int a = 1;

		int add(int x, int y)
		{
			return x + y;
		}
	}
}

int main()
{
	printf("%d\n", sc::sc1::add(1, 1));
	printf("%d %d\n", sc::a, sc::sc1::a);
	return 0;
}

