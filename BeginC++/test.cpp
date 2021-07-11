#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

int main() {

	cout << "Hello world" << endl;
	cout << "\141" << endl;	//8进制转义字符，d范围0~7
	cout << "\x61" << endl;//16进制转义字符，h范围0~9，a~f，A~F

	//字符串
	char str1[] = "abcd";	//c风格
	string str2 = "abcd";	//c++风格	要加头文件#include<string>

	cout << str1 << endl;
	cout << str2 << endl;


	//布尔类型bool
	//作用：布尔数据类型代表真或假的值 
	//bool类型只有两个值：
	//true  -- - 真（本质是1）
	//false -- - 假（本质是0）

	bool flag = true;
	cout << flag << endl;	//1

	flag = false;
	cout << flag << endl;	//0


	////数据的输入
	////作用：用于从键盘获取数据
	////关键字:cin
	////语法：cin >> 变量 
	////1.整型
	//int a = 0;
	//cout << "请输入整型变量：" << endl;
	//cin >> a;
	//cout << a << endl;
	////2.浮点型
	//double d = 0;
	//cout << "请输入浮点型变量：" << endl;
	//cin >> d;
	//cout << d << endl;
	////3.字符型
	//char c = 0;
	//cout << "请输入字符型变量:" << endl;
	//cin >> c;
	//cout << c << endl;
	////4.字符串型
	//string str;
	//cout << "请输入字符串型变量：" << endl;
	//cin >> str;
	//cout << str << endl;
	////5.布尔类型(布尔类型本质是整型，只能依靠整数转换，若是输入0.1，在编译时会被截断变成0）
	//bool flag1 = false;
	//cout << "请输入布尔型变量：" << endl;
	//cin >> flag;
	//cout << flag << endl;
	

	
	//数组，与c语言使用方法一致
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "整个数组所占内存空间为： " << sizeof(arr1) << endl;
	cout << "每个元素所占内存空间为： " << sizeof(arr1[0]) << endl;
	cout << "数组的元素个数为： " << sizeof(arr1) / sizeof(arr1[0]) << endl;

	//可以通过数组名获取到数组首地址
	cout << "数组首地址为： " << (int)arr1 << endl;	//不转换为int的话默认输出16进制
	cout << "数组中第一个元素地址为： " << (int)&arr1[0] << endl;
	cout << "数组中第二个元素地址为： " << (int)&arr1[1] << endl;

	int arr2[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	//地址
	cout << "二维数组首地址：" << arr2 << endl;
	cout << "二维数组第一行地址：" << arr2[0] << endl;
	cout << "二维数组第二行地址：" << arr2[1] << endl;

	cout << "二维数组第一个元素地址：" << &arr2[0][0] << endl;
	cout << "二维数组第二个元素地址：" << &arr2[0][1] << endl;


	//二维字符数组比c语言多了一种表示	
	//在此window环境下，采用GBK编码，一个中文汉字站占据2个字节,在此列的长度最少是5,不同环境下可能各有不同
	char name1[3][5]= { "张三","李四","王五" };
	string name2[3] = { "张三","李四","王五" };
	for (int i = 0; i < 3; i++)
	{
		cout << name1[i] << endl;
		cout << name2[i] << endl;

	}


	return 0;
}


