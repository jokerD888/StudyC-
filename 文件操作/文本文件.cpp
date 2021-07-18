#define _CRT_SECURE_NO_WARNINGS 1

//程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
//通过文件可以将数据持久化
//C++中对文件操作需要包含头文件 <fstream>
//文件类型分为两种：
//1. 文本文件 -文件以文本的ASCII码形式存储在计算机中，可以读懂它
//2. 二进制文件-文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂它们

//操作文件的三大类:
//1. ofstream：写操作
//2. ifstream： 读操作
//3. fstream ： 读写操作

/*写文件步骤如下：
1. 包含头文件
#include <fstream>
2. 创建流对象
ofstream ofs;
3. 打开文件
ofs.open("文件路径", 打开方式);
4. 写数据
ofs << "写入的数据";
5. 关闭文件
ofs.close();*/

//文件打开方式：
//| ios::in | 为读文件而打开文件         |
//| ios::out | 为写文件而打开文件         |
//| ios::ate | 初始位置：文件尾           |
//| ios::app | 追加方式写文件             |
//| ios::trunc | 如果文件存在先删除，再创建 |
//| ios::binary | 二进制方式 |
//注意： 文件打开方式可以配合使用，利用 | 操作符
//例如： 用二进制方式写文件 ios::binary | ios::out

#include<iostream>	
using namespace std;
#include<fstream>		//1.包含头文件
 

//写文件
void test01()
{
	//ofstream ofs;		//2.创建流对象
	//ofs.open("test.txt", ios::out);   //3.打开方式        //如果不写路径，会默认当前程序所在路径
	//第2步第3步合并可写为
	ofstream ofs("test.txt", ios::out);		//相当于写入流的构造函数
	
	ofs << "姓名: 张三" << endl;    //4. 写数据
	ofs << "性别: 男" << endl;
	ofs << "年龄: 20" << endl;

	ofs.close();	//5. 关闭文件
}


//读文件
void test02()
{
	ifstream ifs;		//2.创建流对象
	ifs.open("test.txt", ios::in);		//3.打开方式

	if (!ifs.is_open())		//判断是否成功打开文件
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式							//4. 读数据
	//char buf[1024] = { 0 };
	//while (ifs >> buf)		//直接读取，读到空格或换行结束，ifs>>buf只有读到文件末尾才会返回false
	//{
	//	cout << buf;
	//}

	//第二种
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))		//字符数组，逐行读取，可读取空格
	//{
	//	cout << buf << endl;
	//}

	//第三种
	//string buf;
	//while (getline(ifs, buf))			//字符串读取，逐行读取，可读取空格
	//{
	//	cout << buf << endl;
	//}

	char c;
	while ((c = ifs.get()) != EOF)		//单个字符读取，可读取空格和换行，但效率低下
	{
		cout << c;
	}

	ifs.close();			//5. 关闭文件
}
int main() {

	test01();
	test02();
	return 0;
}

