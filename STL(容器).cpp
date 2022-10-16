#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>
//#include<algorithm>  //标准算法头文件——在STL里面用,大部分用于各种算法的实现
 class t_1
{
public:   //默认访问不了，要给个访问权限
	int a_t;
	char b_t;
	t_1(int a, char b)//构造函数对成员初始化/赋值 
	{
		a_t = a;
		b_t = b;
	}
};
 void print(vector<int>&v)
 {
	 for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	 {
		 cout << *it << "  ";
	 }
	 cout << endl;
 }
 void print(deque<int>& v)
 {
	 for (deque<int>::iterator it = v.begin(); it != v.end(); it++)
	 {
		 cout << *it << "  ";
	 }
	 cout << endl;
 }
 void print(list<int>& v)
 {
	 for (list<int>::iterator it = v.begin(); it != v.end(); it++)
	 {
		 cout << *it << "  ";
	 }
	 cout << endl;
 }
 void print(set<int>& v)
 {
	 for (set<int>::iterator it = v.begin(); it != v.end(); it++)
	 {
		 cout << *it << "  ";
	 }
	 cout << endl;
 }
 void print(map<int,string>& v)
 {
	 for (map<int, string>::iterator it = v.begin(); it != v.end(); it++)
	 {
		 cout << "key = " << it->first << " -> value = " << it->second << endl;
	 }
	 cout << endl;
 }

//****************************************** STL(标准模板库) *******************************************
int main()
{
//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  1.string容器(处理字符串)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//说明：1.string本来就是对字符串的操作，因此大部分就用字符串格式(""),除非某个函数确实要用字符格式('')，否则别用！	
//      2.建议用函数对字符串进行操作，虽然麻烦，但进行的操作多且杂时，容易通过函数名直接看出是作何种操作	     
//		3.可以使用迭代器，且可以随机访问，即可以读和写

	//迭代器使用方法：

	//string  str = "abcd";
	//string::iterator it = str.begin();
	//cout << *(it + 2) << endl;

	//大小(元素个数)
	
	//string b = "abcd";
	//cout << b.size() << endl;

    //构造函数
	
	//string str1();           //创建空字符串，未赋值也能用，不加括号也行
	//string str2("wwwwww");   //直接赋值，只能用字符串格式(" ")，不能用字符格式(' ')
	//string str3(str2);       //copy功能
	//string str4(3,'m');      // 相当于"mmm",只能是字符，不能是字符串，且顺序不能变
	
	//赋值操作
	
	//string str5;
	//str5 = 'B';                 //直接赋值，现在才可以赋值字符了
	//string str6; 
	//str6 = str5;                //copy
	//string str7;
	//str7.assign("wowow");		  //需先定义，再用assign函数赋值
	//string str8;
	//str8.assign("hello", 3);    //用给定字符串(新的/已存在)的前3个字符组成一个新的字符串
	//string str9;     
	//str9.assign(str5);          //copy
	//string str10;
	//str10.assign(5,'c');        //5个字符'c'

	//(两个)字符串拼接
	
	//string str11 = "i";
	//str11 += " love ";			//拼接字符串
	//str11 += 'A';					//拼接字符
	//string str01 = " game ";  
	//str11 += str01;				//拼接已有字符串                            
	//str11.append("gggg ");		//或者 str11.append(str12); 
	//string str02 = "abcdef";
	//str11.append(str02, 1);		//拼接除了前n个字符之外的其他所有字符，与下面相反
	//str11.append("newio",2);      //拼接前n个字符，与上面相反
	//str11.append(str02, 0, 3);    //拼接给定字符串的部分(从某个位置(下标)开始，选n个字符，包括选定位置的字符)
	
	//字符串查找和替换
	
	//find和rfind区别:都是从左往右查找，但find是找目标第一次出现的位置，而rfind是找目标最后一次出现的位置
	//说明：都是返回目标的下标，目标是字符串时，返回该字符串的第一个字符(从左往右，rfind也一样)的下标
	//      没有找到则返回 -1 
	//string str12 = "abcdefg";
	//string str13 = "abc dd w abc fddw f";
	//string te = "def";
	//int n, m;
	//n = str12.find(te);     //在一个字符串中查找另一个已存在或临时的字符串
	//int l, r;
	//l = str13.find('w');     //第一次出现的位置
	//r = str13.rfind('w');	//最后一次出现的位置
	//cout << l << "   " << r << endl;
	//int g;
	//g = str13.find("dd", 2); //从下标为2的位置开始查找,返回的下标是绝对的,不是相对的，rfind是最后一次出现的位置	                       
	//cout << g << endl;
	//int p;
	//p = str13.find("abcw", 4, 3);//从下标为4的位置开始查找"abcw"的前3个字符的第一次出现的位置，rfind......
	//cout << p << endl;
	//string str14;
	//str14 = "abcdefg";
	//str14.replace(3, 2, "12345");// "de"替换为"12345"或已存在的字符串
	//cout << str14 << endl;

	//字符串比较
   
	//比较规则：两个字符串从第一个位置比较ASCII码的大小，直到两个不相等为止
	//结果分为：大于 -- 1 ，小于 -- -1 ，等于 -- 0
	//string str15 = "abcdef";
	//int res1;
	//res1 = str15.compare("abcfef");   // 是str15 < "abcfef" ,返回 -1
	//cout << res1 << endl;
	
	//字符串内单个字符的操作
	
	//string str16 = "abcdef";
	//for (int i = 0; i < str16.size(); i++)
	//{
	//	cout << str16[i] << "---" << str16.at(i) << endl;
	//	//修改就直接改，不多演示
	//}

	//字符串插入和删除
	
	//string str17 = "012345678";
	//str17.insert(1, "www");     //在下标为1的位置插入字符串
	//cout << str17 << endl;
	//str17.insert(0, 3, 'b');	//在下标为0的位置插入3个字符'b'
	//cout << str17 << endl;
	//str17.erase(4, 2);
	//cout << str17 << endl;      //从下标为4的位置(包括该位置)开始删除2个字符

	//获取子字符串
	
	//string str18 = "012345678";
	//string str19;
	//str19 = str18.substr(2, 3);  //下标为2开始(包括自己)选取3个字符，即"234"
	//cout << str19 << endl;

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  2.vector容器(动态数组)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// 说明：vector容器是动态扩容，一般存放int型数据，当容器容量不够时，会找一块更大的内存，
//       将原容器的数据拷贝过来，再把原内存的数据清除，
//       每当容量不够时，会进行一定量的扩容，根据内置算法进行扩容，即阶段性扩容
// 	     容量：“允许”存储数据的总和(个数)
// 	     大小：“当前”存储数据的总和(个数)
//		 可以使用迭代器，且可以随机访问，即可以读和写
	
	//**简单

	//cout << "vector[简单]：\n";
	//vector<int> a;
	// a.push_back(1);  //尾插法
	// a.push_back(2);
	// a.push_back(3);
	// a.push_back(4);
	// a.push_back(5);
	// a.push_back(6);
	//第一种遍历(最麻烦)
	//vector<int>::iterator begin = a.begin();  //类似指针
	//vector<int>::iterator end = a.end();
	// 注：a.begin()指向的是栈底元素的位置，a.end()指向的是栈顶元素的上一个位置
	//for (begin; begin != end; begin++)
	//{
	//	cout << *begin << endl;
	//}
	//第二种遍历(较麻烦）
	//for (vector<int>::iterator begin_2 = a.begin(); begin_2 != a.end(); begin_2++)
	//{
	// cout << *begin_2 << endl;
	//}
	//第三种遍历(要包含<algorithm>头文件，不太好用)
	//for_each(a.begin(), a.end(), fun());  //fun()需要自己写
	//第四种遍历(最简单)--常用
	//for (int i = 0; i < vector1.size(); i++)
	//{
	// cout << vector1[i] << endl;  
	//}

	//**复杂(比如：类-class)

	//cout << "vector[复杂-class]：\n";
	//t_1 test_1(1, 'a');
	//t_1 test_2(2, 'b');
	//t_1 test_3(3, 'c');
	//t_1 test_4(4, 'd');
	//vector<t_1> lei;
	//lei.push_back(test_1);
	//lei.push_back(test_2);
	//lei.push_back(test_3);
	//lei.push_back(test_4);
	//for (vector<t_1>::iterator te = lei.begin(); te != lei.end(); te++)
	//{
	// cout << te->a_t << "   " << te->b_t << endl;  //不能写为： (*te)->a_t 或 te.a_t
	// //te就是指向类的指针，调用成员要用：te->成员名(指针形式) 或 (*te).成员名(取内容形式)
	//}

	//**嵌套-普通型(套娃,类似二维数组)

	//cout<<"vector[嵌套]：\n";
	//vector<int> p1;
	//vector<int> p2;
	//vector<int> p3;
	//vector<vector<int>> P; 
	////给每个小容器添加3个数
	//for (int i = 1; i <= 3; i++)
	//{
	// p1.push_back(i);
	// p2.push_back(i+1);
	// p3.push_back(i+2);
	//}
	////给大容器添加小容器
	//P.push_back(p1);
	//P.push_back(p2);
	//P.push_back(p3);
	////遍历大容器
	//for (vector<vector<int>>::iterator it_1 = P.begin(); it_1 != P.end(); it_1++)
	//{
	// for (vector<int>::iterator it_2 = (*it_1).begin(); it_2 != (*it_1).end(); it_2++)//(*it_1)即第N个小容器
	// {
	//	 cout << *it_2 << "   ";
	// }
	// cout << endl;
	//}

//***********************正式内容：

	//构造函数

	//vector<int> test;
	//test.push_back(1);
	//test.push_back(2);
	//vector<int> vec1;                            //创建空容器，可以打印
	//vector<int> vec2(test.begin(),test.end());   //copy
	//vector<int> vec3(3,'c');                     // 添加 3 个 'c'，这里是整型容器，自动转化成相应的ASCII码 
	//vector<int> vec4(vec3);						 //copy
	//print(vec1);
	//print(vec2);
	//print(vec3);
	//print(vec4);

	//赋值,先构造后赋值,不要同时进行,方便与构造函数区分

	//1.尾插法  ：vector1.push_back();
	//2.直接赋值：vector2 = vector1;
	//3.assign法：vector3.assign(vector1.begin(),vector1.end());
	//            vector3.assign(4,'c');   跟上面(vec3)一样 

	//容量(....)和大小(元素个数)

	//vector<int> vec5;
	//for (int i = 0; i < 10; i++)
	//{
	//	vec5.push_back(i); 
	//}
	//cout << vec5.empty() << endl;      //判断是否为空容器，空容器 -> 1(真)，非空 -> 0(假)
	//cout << vec5.capacity() << endl;   //容量>=大小,当大小超过容量，会自动扩容
	//cout << vec5.size() << endl;       //大小，放入元素的个数
	//print(vec5);
	//vec5.resize(15);      //改变大小(10 -> 15)，多出部分都以0(默认值)代替
	//vec5.resize(15, 3);   //多出部分都以3代替,自定义
	//vec5.resize(5);       //改变大小(15 -> 5)，删除多出的部分
	//print(vec5);

	//插入和删除

	//vector<int> vec6;
	//for (int i = 0; i < 6; i++)
	//{
	//	vec6.push_back(i);
	//}
	//vector<int> vec7;
	//for (int i = 0; i < 7; i++)
	//{
	//	vec7.push_back(i);
	//}
	////正常情况(对尾进行操作):  push_back(elm) - 尾插 ，pop_back() - 尾删 ，clear() - 删除所有元素
	//             push -> 进栈            pop -> 出栈
	////指定位置(随机访问)：通过迭代器实现
	//vec6.insert(vec6.begin(), 99);						 //在头位置(0)处插入一个数
	//print(vec6);
	//vec6.insert(vec6.begin() + 3, 4, 66);					 //在头位置(0)+3处插入4个66
	//print(vec6);
	//vec7.insert(vec7.begin(), vec6.begin() + 1, vec6.end()); //在头位置(0)处插入vec6的头(0)+1处到尾的所有数
	//print(vec7);
	//vec6.erase(vec6.begin());					//删除头位置(0)的元素，要指定删除位置
	//print(vec6);
	//vec6.erase(vec6.begin(), vec6.end()-2);	//删除区间内的元素，左闭右开，因为vec6.end()不指向栈顶元素
	//print(vec6);

	//数据存取-读和写

	//vector<int> vec7;
	//for (int i = 0; i < 6; i++)
	//{
	//	vec7.push_back(i);
	//}
	//vec7[4] = 0;      //下标法修改数据
	//vec7.at(3) = 9;   //at()函数法修改数据
	////普通遍历
	//for (int i = 0; i < vec7.size(); i++)
	//{
	//	cout << vec7[i] << "  " << vec7.at(i) << endl;     //下标法 和 at()函数法
	//}
	////特殊遍历
	//cout << vec7.front() << "   " << vec7.back() << endl;  //front()第一个元素，back()最后一个元素

	//排序

	//函数：sort(.begin(),.end())    需要包含头文件<algorithm>
	//默认从小到大排序
	
	//容器交换

	//基本操作
	//vector<int> vec8;
	//vector<int> vec9;
	//for (int i = 0; i < 10; i++)
	//	vec8.push_back(i);
	//for (int i = 9; i > -1; i--)
	//	vec9.push_back(i);
	//print(vec8);
	//print(vec9);
	//swap(vec8, vec9);       //  两种形式：1. vec8.swap(vec9)   2. swap(vec8, vec9)
	//cout << "交换后：\n";
	//print(vec8);
	//print(vec9);
	//**特殊情况：用于节省空间，一般不用
	//当容器存放大量数据，但实际所需很少，即改变容器大小(size),会造成容器空间浪费
	//于是进行多余空间的清除：vector<int>(原容器).swap(原容器);
	//vector<int> test1;
	//for (int i = 0; i < 100; i++)
	//{
	//	test1.push_back(i);
	//}
	//test1.resize(5);
	//vector<int>(test1).swap(test1);
	////创建匿名容器，用原容器做参数，复制后的容量和大小都以原容器的大小为准，最后与原容器交换
	////交换后，匿名容器的数据将被自动清除
	//cout << test1.capacity() << test1.size() << endl;

	//预留空间

	//当数据量非常大时，为减少扩容次数，提前找到一块内存存储数据
	//用法：vector1.reverse(大小)  大小根据具体情况而定

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  3.deque容器(双端数组)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  注：一般存放int型数据
//		可以使用迭代器，且可以随机访问，即可以读和写
   
	//构造函数

	//deque<int> test;
	//test.push_back(1);
	//test.push_back(2);
	//deque<int> de1;                            //创建空容器，可以打印
	//deque<int> de2(test.begin(),test.end());   //copy
	//deque<int> de3(3,'c');                     // 添加 3 个 'c'，这里是整型容器，自动转化成相应的ASCII码 
	//deque<int> de4(de3);						 //copy
	//print(de1);
	//print(de2);
	//print(de3);
	//print(de4);

	//赋值,先构造后赋值,不要同时进行,方便与构造函数区分
	
	//deque<int> test;
	//test.push_back(1);
	//test.push_back(2);
	//deque<int> de5;
	//de5 = test;							  //copy
	//deque<int> de6;
	//de6.assign(test.begin(), test.end());   //copy
	//deque<int> de7;
	//de7.assign(3,6);                        //3个6

	//大小(元素个数)
	
	//函数有：
	// deque1.empty()   deque1.size()   deque1.resize(num)   deque1.resize(num,elem)
	// 空容器 -> 1(真)，非空 -> 0(假)
    
	//插入和删除
	
	//对两端进行操作：
    //函数有： 插入：push_back(elem)  push_front(elem)  删除： pop_back()  pop.front()
	//指定位置：
	//函数有：insert(pos,elem)  insert(pos,n,elem)  insert(pos，.begin(),.end())--左闭右开 
	//	      erase(pos)       erase(.begin(),.end())--左闭右开 
    //        clear()

	//数据存取-读和写
    
	//下标法:  容器[n]   at(n)法  都是从0开始
	//特殊：第一个元素：front()   最后一个元素：back()

	//排序

	//函数：sort(.begin(),.end())    需要包含头文件<algorithm>
	//默认从小到大排序
	
//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  4.stack容器(栈-后进先出)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  注：从栈顶进，也从栈顶出
//		只有栈顶元素才能被访问到，不允许遍历，不支持迭代器
//	    进栈：push   出栈：pop   栈顶元素: top()
	
	//构造函数
	
	//stack<int> st1;
	//st1.push(1);
	//st1.push(2);
	//st1.push(3);
	//stack<int> st2(st1);   //copy
	
	//赋值,先构造后赋值,不要同时进行,方便与构造函数区分
	
	//stack<int> st3;
	//st3 = st1;

	//大小(元素个数)

	//cout << st1.size() << endl;     //元素个数
	//cout << st1.empty() << endl;	//判断栈是否为空，空 -> 1(真)，非空 -> 0(假)

	//数据存取-读和写

	//stack<int> st4;
	//st4.push(2);					//插入栈顶元素-入栈
	//cout << st4.top() << endl;	//得到栈顶元素
	//st4.pop();					//移除栈顶元素-出栈

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  5.queue容器(队列-先进先出)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  注：queue读作Q
//      一端进(队尾)，另一端出(队头)
//		只有队头和队尾才能被访问到，不允许遍历，不支持迭代器
//		进队：push  出队：pop  队头元素：front()  队尾元素：back()
	
	//构造函数

	//queue<int> qu1;
	//qu1.push(1);
	//qu1.push(2);
	//qu1.push(3);
	//qu1.push(4);
	//queue<int> st2(qu1);   //copy

	//赋值,先构造后赋值,不要同时进行,方便与构造函数区分

	//queue<int> qu3;
	//qu3 = qu1;
	
	//大小(元素个数)

	//cout << qu1.size() << endl;     //元素个数
	//cout << qu1.empty() << endl;	//判断队列是否为空，空 -> 1(真)，非空 -> 0(假)

	//数据存取-读和写

	//queue<int> qu4;
	//qu4.push(5);						//插入队列元素-入队
	//qu4.push(1);
	//cout << qu4.front() << endl;		//得到队头元素
	//cout << qu4.back() << endl;		//得到队尾元素
	//qu4.pop();						//移除队列元素-出队
	//cout << qu4.front() << endl;      //移除后的队头元素

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  6.list容器(双向循环链表)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  注：先要实现双向(前一个节点的后继指向下一个节点，后一个节点的前驱指向前一个节点，两个节点之间的指向)
//		再实现循环(头节点的前驱指向尾节点，尾节点的后继指向头节点，两个节点之间的指向)
//		可以遍历，且只能用“迭代器”遍历，但不能跳跃式访问

	//构造函数
	
	//list<int> li1;
	//li1.push_back(1);
	//li1.push_back(2);
	//li1.push_back(3);
	//print(li1);
	//list<int> li2(li1);						//copy
	//print(li2);
	//list<int> li3(li1.begin(),li1.end());   //copy
	//print(li3);
	//list<int> li4(3,10);					//3个10
	//print(li4);
	
	//

    //赋值,先构造后赋值,不要同时进行,方便与构造函数区分

	//函数：assign(.begin(),.end())	   
	//		assign(n,elem)   
	//		li2 = li1("="赋值)
	
	//容器交换 :两种形式：1. swap(li6, li7)   2. li6.swap(li7)
		
	//大小

	//函数：size()   
	//		empty()				判断容器是否为空，空 -> 1(真)，非空 -> 0(假)
	//		resize(num)			重新指定大小，比原来大->多出部分以0(默认值)填充,比原来小->删除多出的部分
    //		resize(num，elem)	重新指定大小，比原来大->多出部分以指定值填充,比原来小->删除多出的部分

	//插入和删除

	////函数：  
	////两端操作： 尾：push_back(elem)  pop_back()  头：push_front(elem)  pop_front()
	////中间位置：
	//list<int> li0(3,1);
	////		单个数据：
	//li0.insert(li0.end(), 2);//位置只能用迭代器,不能指定位置,即不能 .begin() + n 跳跃式查找，但能自加(++)自减(--)
	//print(li0);
	//li0.erase(li0.begin());	 //同上
	//print(li0);
	////		多个数据：
	//li0.insert(li0.end(), 2, 3);					 //该位置插入2个3，同上
	//li0.insert(li0.begin(), li0.begin(),li0.end());  //在开头位置插入区间(可以为其他list)内的元素(左闭右开)，同上
	//li0.erase(li0.begin(), li0.end());				 //删除区间，同上
	////特殊操作： clear() -> 删除容器所有数据    remove(elem) -> 删除容器中“全部的”elem

	//数据存取-读和写

	////就两个函数：front() -> 返回第一个元素 | back() -> 返回最后一个元素
	////可以访问到该元素，则可以进行改值
	//list<int> li(3,5);
	//li.front() = 1;
	//print(li);
	//cout << li.back() << endl;

	//反转和排序

	//list<int> w;
	//w.push_back(1);
	//w.push_back(3);
	//w.push_back(2);
	//w.push_back(4);
	//print(w);
	////反转
	//w.reverse();
	//print(w);
	////排序
	//w.sort();
	//print(w);

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  7.set/multiset容器  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  说明：元素插入后会自动排序，默认从小到大
//		  可以遍历，且只能用“迭代器”遍历，但不能跳跃式访问
//		  set/multiset容器属于“关联式容器”，底层是二叉树
//		  set/multiset区别：set不允许有重复元素，而multiset可以
//		  set插入重复的元素时，先插入的元素有效，后插入的元素无效

	//构造和赋值
	
	//set<int> s;
	//s.insert(1);
	//s.insert(4);
	//s.insert(2);
	//s.insert(5);
	//s.insert(1);
	//print(s);
	//set<int> s2(s);     //copy
	//set<int> s3;
	//s3 = s;				//copy
	//set<int> s4(s.begin(),s.end());		//copy

	//大小和交换

	//set<int> s1;
	//set<int> s2;
	//大小： size() 元素个数
	//		empty() 判断容器是否为空，空 -> 1(真)，非空 -> 0(假)
	//交换：1.  swap(s1,s2)   2.  s1.swap(s2)
	
	//插入和删除																												
 
	//插入：insert(elem)
	//删除：单个位置：erase(pos)			位置用迭代器,不能跳跃式访问，但可以自加(++)自减(--)
	//		区间：erase(.begin(),.end())	左闭右开
	//		具体元素：erase(elem)  
	//清空：clear()

	//查找和统计
	
	//set<int> s2;
	//s2.insert(5);
	//s2.insert(4);
	//s2.insert(3);
	//s2.insert(2);
	//s2.insert(1); 
	//cout << *(s2.find(3)) << endl;
	////该函数返回的是迭代器，如果找到，返回当前位置的迭代器，没找到，则返回s2.end()
	//int num = s2.count(3);
	//cout << num << endl;
	////统计个数，只有两种结果：1个或0个(对于set而言)
	
    //自定义排序方式
	//**********需要用仿函数，暂时不弄********
	
//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  pair 对组  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	说明：成对出现的数据，可以返回两个数据
//        直接用，没有头文件

	////创建对组的两种方法，及用法：
	////第一种：构造
	//pair<int, string> p1(1, "b");
	//cout << p1.first << "  " << p1.second << endl;
	////第二种：make_pair(key, value)
	//pair<int, char> p2 ;
	//p2 = make_pair(2, 'c');
	//cout << p2.first << "  " << p2.second << endl;

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  8.map/multimap容器  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  说明：容器中所有元素都是"pair"，pair的第一个元素为"key"(键值)，起索引作用，第二个元素为"value"(实值)
//		  所有容器中的元素会按照"key"自动排序，默认从小到大
//		  可以遍历，且只能用“迭代器”遍历，不能跳跃式遍历
//		  map/multimap属于“关联式容器”，底层是二叉树
//        map/multimap区别：map不允许有重复的key，而multimap可以
//		  map插入key重复的元素时，先插入的元素有效，后插入的元素无效

	//以下均以key为int型，value为string为例
	
	//构造和赋值

	//map<int, string> m;
	//m.insert(pair<int, string>(1, "张三"));
	//m.insert(pair<int, string>(2, "李四"));
	//m.insert(pair<int, string>(3, "王五"));
	//map<int, string> m2(m);   //copy
	//map<int, string> m3;
	//m3 = m;					  //copy
	//print(m);

	//大小和交换

	////map<int, string> m1;
	////map<int, string> m2;
	////大小： size() 元素个数
	////		empty() 判断容器是否为空，空 -> 1(真)，非空 -> 0(假)
	////交换：1.  swap(m1,m2)   2.  m1.swap(m2)

	//插入和删除
	
	////插入
	//map<int, string> m1;
	//map<int, string> m2;
	//map<int, string> m3;
	//map<int, string> m4;
	////第一种：为保证数据类型不出错，建议使用
	//m1.insert(pair<int, string>(1, "www"));
	////第二种：在知道元素的key和value后可以快速创建元素
	//m2.insert(make_pair(2, "ddd"));
	//print(m1);
	//print(m2);
	////第三种：知道就行
	//m3.insert(map<int, string>::value_type(3, "fffff"));
	////第四种：下标->key  在创建的同时，必须要赋值value，防止创建出没有value的key，否则会容易出错
	//m4[4] = "ggggg";  //下标就是key,"ggggg"就是value
	////删除
	//m1.erase(1);						//参数为key，通过key找元素，然后删除该元素
	//m2.erase(m2.begin());				//不能跳跃式删除，但可以迭代器自加(++)自减(--)
	//m3.erase(m3.begin(), m3.end());		//区间删除,同上
	//m4.clear();							//清空

	//查找和统计
	
	//map<int, string> m1;
	//m1[1] = "dddd";
	//m1[2] = "ggggg";
	//cout << m1.find(2)->second << endl;
	////该函数返回的是迭代器，如果找到，返回当前位置的迭代器，没找到，则返回m1.end()
	//int num = m1.count(1);
	//cout << num << endl;
	////统计个数，只有两种结果：1个或0个(对于map而言)
	
	//自定义排序方式
	//**********需要用仿函数，暂时不弄********

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  额外内容  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	
//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  1.函数对象(仿函数)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	
	//说明：


//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  2.谓词  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//说明：返回bool类型的仿函数叫做"谓词"
	//		只接收1个参数的谓词称为一元谓词，只接收2个参数的谓词称为二元谓词




	
	//system("pause");
}

