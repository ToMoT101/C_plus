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
//#include<algorithm>  //��׼�㷨ͷ�ļ�������STL������,�󲿷����ڸ����㷨��ʵ��
 class t_1
{
public:   //Ĭ�Ϸ��ʲ��ˣ�Ҫ��������Ȩ��
	int a_t;
	char b_t;
	t_1(int a, char b)//���캯���Գ�Ա��ʼ��/��ֵ 
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

//****************************************** STL(��׼ģ���) *******************************************
int main()
{
//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  1.string����(�����ַ���)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//˵����1.string�������Ƕ��ַ����Ĳ�������˴󲿷־����ַ�����ʽ(""),����ĳ������ȷʵҪ���ַ���ʽ('')��������ã�	
//      2.�����ú������ַ������в�������Ȼ�鷳�������еĲ���������ʱ������ͨ��������ֱ�ӿ����������ֲ���	     
//		3.����ʹ�õ��������ҿ���������ʣ������Զ���д

	//������ʹ�÷�����

	//string  str = "abcd";
	//string::iterator it = str.begin();
	//cout << *(it + 2) << endl;

	//��С(Ԫ�ظ���)
	
	//string b = "abcd";
	//cout << b.size() << endl;

    //���캯��
	
	//string str1();           //�������ַ�����δ��ֵҲ���ã���������Ҳ��
	//string str2("wwwwww");   //ֱ�Ӹ�ֵ��ֻ�����ַ�����ʽ(" ")���������ַ���ʽ(' ')
	//string str3(str2);       //copy����
	//string str4(3,'m');      // �൱��"mmm",ֻ�����ַ����������ַ�������˳���ܱ�
	
	//��ֵ����
	
	//string str5;
	//str5 = 'B';                 //ֱ�Ӹ�ֵ�����ڲſ��Ը�ֵ�ַ���
	//string str6; 
	//str6 = str5;                //copy
	//string str7;
	//str7.assign("wowow");		  //���ȶ��壬����assign������ֵ
	//string str8;
	//str8.assign("hello", 3);    //�ø����ַ���(�µ�/�Ѵ���)��ǰ3���ַ����һ���µ��ַ���
	//string str9;     
	//str9.assign(str5);          //copy
	//string str10;
	//str10.assign(5,'c');        //5���ַ�'c'

	//(����)�ַ���ƴ��
	
	//string str11 = "i";
	//str11 += " love ";			//ƴ���ַ���
	//str11 += 'A';					//ƴ���ַ�
	//string str01 = " game ";  
	//str11 += str01;				//ƴ�������ַ���                            
	//str11.append("gggg ");		//���� str11.append(str12); 
	//string str02 = "abcdef";
	//str11.append(str02, 1);		//ƴ�ӳ���ǰn���ַ�֮������������ַ����������෴
	//str11.append("newio",2);      //ƴ��ǰn���ַ����������෴
	//str11.append(str02, 0, 3);    //ƴ�Ӹ����ַ����Ĳ���(��ĳ��λ��(�±�)��ʼ��ѡn���ַ�������ѡ��λ�õ��ַ�)
	
	//�ַ������Һ��滻
	
	//find��rfind����:���Ǵ������Ҳ��ң���find����Ŀ���һ�γ��ֵ�λ�ã���rfind����Ŀ�����һ�γ��ֵ�λ��
	//˵�������Ƿ���Ŀ����±꣬Ŀ�����ַ���ʱ�����ظ��ַ����ĵ�һ���ַ�(�������ң�rfindҲһ��)���±�
	//      û���ҵ��򷵻� -1 
	//string str12 = "abcdefg";
	//string str13 = "abc dd w abc fddw f";
	//string te = "def";
	//int n, m;
	//n = str12.find(te);     //��һ���ַ����в�����һ���Ѵ��ڻ���ʱ���ַ���
	//int l, r;
	//l = str13.find('w');     //��һ�γ��ֵ�λ��
	//r = str13.rfind('w');	//���һ�γ��ֵ�λ��
	//cout << l << "   " << r << endl;
	//int g;
	//g = str13.find("dd", 2); //���±�Ϊ2��λ�ÿ�ʼ����,���ص��±��Ǿ��Ե�,������Եģ�rfind�����һ�γ��ֵ�λ��	                       
	//cout << g << endl;
	//int p;
	//p = str13.find("abcw", 4, 3);//���±�Ϊ4��λ�ÿ�ʼ����"abcw"��ǰ3���ַ��ĵ�һ�γ��ֵ�λ�ã�rfind......
	//cout << p << endl;
	//string str14;
	//str14 = "abcdefg";
	//str14.replace(3, 2, "12345");// "de"�滻Ϊ"12345"���Ѵ��ڵ��ַ���
	//cout << str14 << endl;

	//�ַ����Ƚ�
   
	//�ȽϹ��������ַ����ӵ�һ��λ�ñȽ�ASCII��Ĵ�С��ֱ�����������Ϊֹ
	//�����Ϊ������ -- 1 ��С�� -- -1 ������ -- 0
	//string str15 = "abcdef";
	//int res1;
	//res1 = str15.compare("abcfef");   // ��str15 < "abcfef" ,���� -1
	//cout << res1 << endl;
	
	//�ַ����ڵ����ַ��Ĳ���
	
	//string str16 = "abcdef";
	//for (int i = 0; i < str16.size(); i++)
	//{
	//	cout << str16[i] << "---" << str16.at(i) << endl;
	//	//�޸ľ�ֱ�Ӹģ�������ʾ
	//}

	//�ַ��������ɾ��
	
	//string str17 = "012345678";
	//str17.insert(1, "www");     //���±�Ϊ1��λ�ò����ַ���
	//cout << str17 << endl;
	//str17.insert(0, 3, 'b');	//���±�Ϊ0��λ�ò���3���ַ�'b'
	//cout << str17 << endl;
	//str17.erase(4, 2);
	//cout << str17 << endl;      //���±�Ϊ4��λ��(������λ��)��ʼɾ��2���ַ�

	//��ȡ���ַ���
	
	//string str18 = "012345678";
	//string str19;
	//str19 = str18.substr(2, 3);  //�±�Ϊ2��ʼ(�����Լ�)ѡȡ3���ַ�����"234"
	//cout << str19 << endl;

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  2.vector����(��̬����)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// ˵����vector�����Ƕ�̬���ݣ�һ����int�����ݣ���������������ʱ������һ�������ڴ棬
//       ��ԭ���������ݿ����������ٰ�ԭ�ڴ�����������
//       ÿ����������ʱ�������һ���������ݣ����������㷨�������ݣ����׶�������
// 	     �������������洢���ݵ��ܺ�(����)
// 	     ��С������ǰ���洢���ݵ��ܺ�(����)
//		 ����ʹ�õ��������ҿ���������ʣ������Զ���д
	
	//**��

	//cout << "vector[��]��\n";
	//vector<int> a;
	// a.push_back(1);  //β�巨
	// a.push_back(2);
	// a.push_back(3);
	// a.push_back(4);
	// a.push_back(5);
	// a.push_back(6);
	//��һ�ֱ���(���鷳)
	//vector<int>::iterator begin = a.begin();  //����ָ��
	//vector<int>::iterator end = a.end();
	// ע��a.begin()ָ�����ջ��Ԫ�ص�λ�ã�a.end()ָ�����ջ��Ԫ�ص���һ��λ��
	//for (begin; begin != end; begin++)
	//{
	//	cout << *begin << endl;
	//}
	//�ڶ��ֱ���(���鷳��
	//for (vector<int>::iterator begin_2 = a.begin(); begin_2 != a.end(); begin_2++)
	//{
	// cout << *begin_2 << endl;
	//}
	//�����ֱ���(Ҫ����<algorithm>ͷ�ļ�����̫����)
	//for_each(a.begin(), a.end(), fun());  //fun()��Ҫ�Լ�д
	//�����ֱ���(���)--����
	//for (int i = 0; i < vector1.size(); i++)
	//{
	// cout << vector1[i] << endl;  
	//}

	//**����(���磺��-class)

	//cout << "vector[����-class]��\n";
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
	// cout << te->a_t << "   " << te->b_t << endl;  //����дΪ�� (*te)->a_t �� te.a_t
	// //te����ָ�����ָ�룬���ó�ԱҪ�ã�te->��Ա��(ָ����ʽ) �� (*te).��Ա��(ȡ������ʽ)
	//}

	//**Ƕ��-��ͨ��(����,���ƶ�ά����)

	//cout<<"vector[Ƕ��]��\n";
	//vector<int> p1;
	//vector<int> p2;
	//vector<int> p3;
	//vector<vector<int>> P; 
	////��ÿ��С�������3����
	//for (int i = 1; i <= 3; i++)
	//{
	// p1.push_back(i);
	// p2.push_back(i+1);
	// p3.push_back(i+2);
	//}
	////�����������С����
	//P.push_back(p1);
	//P.push_back(p2);
	//P.push_back(p3);
	////����������
	//for (vector<vector<int>>::iterator it_1 = P.begin(); it_1 != P.end(); it_1++)
	//{
	// for (vector<int>::iterator it_2 = (*it_1).begin(); it_2 != (*it_1).end(); it_2++)//(*it_1)����N��С����
	// {
	//	 cout << *it_2 << "   ";
	// }
	// cout << endl;
	//}

//***********************��ʽ���ݣ�

	//���캯��

	//vector<int> test;
	//test.push_back(1);
	//test.push_back(2);
	//vector<int> vec1;                            //���������������Դ�ӡ
	//vector<int> vec2(test.begin(),test.end());   //copy
	//vector<int> vec3(3,'c');                     // ��� 3 �� 'c'�������������������Զ�ת������Ӧ��ASCII�� 
	//vector<int> vec4(vec3);						 //copy
	//print(vec1);
	//print(vec2);
	//print(vec3);
	//print(vec4);

	//��ֵ,�ȹ����ֵ,��Ҫͬʱ����,�����빹�캯������

	//1.β�巨  ��vector1.push_back();
	//2.ֱ�Ӹ�ֵ��vector2 = vector1;
	//3.assign����vector3.assign(vector1.begin(),vector1.end());
	//            vector3.assign(4,'c');   ������(vec3)һ�� 

	//����(....)�ʹ�С(Ԫ�ظ���)

	//vector<int> vec5;
	//for (int i = 0; i < 10; i++)
	//{
	//	vec5.push_back(i); 
	//}
	//cout << vec5.empty() << endl;      //�ж��Ƿ�Ϊ�������������� -> 1(��)���ǿ� -> 0(��)
	//cout << vec5.capacity() << endl;   //����>=��С,����С�������������Զ�����
	//cout << vec5.size() << endl;       //��С������Ԫ�صĸ���
	//print(vec5);
	//vec5.resize(15);      //�ı��С(10 -> 15)��������ֶ���0(Ĭ��ֵ)����
	//vec5.resize(15, 3);   //������ֶ���3����,�Զ���
	//vec5.resize(5);       //�ı��С(15 -> 5)��ɾ������Ĳ���
	//print(vec5);

	//�����ɾ��

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
	////�������(��β���в���):  push_back(elm) - β�� ��pop_back() - βɾ ��clear() - ɾ������Ԫ��
	//             push -> ��ջ            pop -> ��ջ
	////ָ��λ��(�������)��ͨ��������ʵ��
	//vec6.insert(vec6.begin(), 99);						 //��ͷλ��(0)������һ����
	//print(vec6);
	//vec6.insert(vec6.begin() + 3, 4, 66);					 //��ͷλ��(0)+3������4��66
	//print(vec6);
	//vec7.insert(vec7.begin(), vec6.begin() + 1, vec6.end()); //��ͷλ��(0)������vec6��ͷ(0)+1����β��������
	//print(vec7);
	//vec6.erase(vec6.begin());					//ɾ��ͷλ��(0)��Ԫ�أ�Ҫָ��ɾ��λ��
	//print(vec6);
	//vec6.erase(vec6.begin(), vec6.end()-2);	//ɾ�������ڵ�Ԫ�أ�����ҿ�����Ϊvec6.end()��ָ��ջ��Ԫ��
	//print(vec6);

	//���ݴ�ȡ-����д

	//vector<int> vec7;
	//for (int i = 0; i < 6; i++)
	//{
	//	vec7.push_back(i);
	//}
	//vec7[4] = 0;      //�±귨�޸�����
	//vec7.at(3) = 9;   //at()�������޸�����
	////��ͨ����
	//for (int i = 0; i < vec7.size(); i++)
	//{
	//	cout << vec7[i] << "  " << vec7.at(i) << endl;     //�±귨 �� at()������
	//}
	////�������
	//cout << vec7.front() << "   " << vec7.back() << endl;  //front()��һ��Ԫ�أ�back()���һ��Ԫ��

	//����

	//������sort(.begin(),.end())    ��Ҫ����ͷ�ļ�<algorithm>
	//Ĭ�ϴ�С��������
	
	//��������

	//��������
	//vector<int> vec8;
	//vector<int> vec9;
	//for (int i = 0; i < 10; i++)
	//	vec8.push_back(i);
	//for (int i = 9; i > -1; i--)
	//	vec9.push_back(i);
	//print(vec8);
	//print(vec9);
	//swap(vec8, vec9);       //  ������ʽ��1. vec8.swap(vec9)   2. swap(vec8, vec9)
	//cout << "������\n";
	//print(vec8);
	//print(vec9);
	//**������������ڽ�ʡ�ռ䣬һ�㲻��
	//��������Ŵ������ݣ���ʵ��������٣����ı�������С(size),����������ռ��˷�
	//���ǽ��ж���ռ�������vector<int>(ԭ����).swap(ԭ����);
	//vector<int> test1;
	//for (int i = 0; i < 100; i++)
	//{
	//	test1.push_back(i);
	//}
	//test1.resize(5);
	//vector<int>(test1).swap(test1);
	////����������������ԭ���������������ƺ�������ʹ�С����ԭ�����Ĵ�СΪ׼�������ԭ��������
	////�������������������ݽ����Զ����
	//cout << test1.capacity() << test1.size() << endl;

	//Ԥ���ռ�

	//���������ǳ���ʱ��Ϊ�������ݴ�������ǰ�ҵ�һ���ڴ�洢����
	//�÷���vector1.reverse(��С)  ��С���ݾ����������

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  3.deque����(˫������)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  ע��һ����int������
//		����ʹ�õ��������ҿ���������ʣ������Զ���д
   
	//���캯��

	//deque<int> test;
	//test.push_back(1);
	//test.push_back(2);
	//deque<int> de1;                            //���������������Դ�ӡ
	//deque<int> de2(test.begin(),test.end());   //copy
	//deque<int> de3(3,'c');                     // ��� 3 �� 'c'�������������������Զ�ת������Ӧ��ASCII�� 
	//deque<int> de4(de3);						 //copy
	//print(de1);
	//print(de2);
	//print(de3);
	//print(de4);

	//��ֵ,�ȹ����ֵ,��Ҫͬʱ����,�����빹�캯������
	
	//deque<int> test;
	//test.push_back(1);
	//test.push_back(2);
	//deque<int> de5;
	//de5 = test;							  //copy
	//deque<int> de6;
	//de6.assign(test.begin(), test.end());   //copy
	//deque<int> de7;
	//de7.assign(3,6);                        //3��6

	//��С(Ԫ�ظ���)
	
	//�����У�
	// deque1.empty()   deque1.size()   deque1.resize(num)   deque1.resize(num,elem)
	// ������ -> 1(��)���ǿ� -> 0(��)
    
	//�����ɾ��
	
	//�����˽��в�����
    //�����У� ���룺push_back(elem)  push_front(elem)  ɾ���� pop_back()  pop.front()
	//ָ��λ�ã�
	//�����У�insert(pos,elem)  insert(pos,n,elem)  insert(pos��.begin(),.end())--����ҿ� 
	//	      erase(pos)       erase(.begin(),.end())--����ҿ� 
    //        clear()

	//���ݴ�ȡ-����д
    
	//�±귨:  ����[n]   at(n)��  ���Ǵ�0��ʼ
	//���⣺��һ��Ԫ�أ�front()   ���һ��Ԫ�أ�back()

	//����

	//������sort(.begin(),.end())    ��Ҫ����ͷ�ļ�<algorithm>
	//Ĭ�ϴ�С��������
	
//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  4.stack����(ջ-����ȳ�)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  ע����ջ������Ҳ��ջ����
//		ֻ��ջ��Ԫ�ز��ܱ����ʵ����������������֧�ֵ�����
//	    ��ջ��push   ��ջ��pop   ջ��Ԫ��: top()
	
	//���캯��
	
	//stack<int> st1;
	//st1.push(1);
	//st1.push(2);
	//st1.push(3);
	//stack<int> st2(st1);   //copy
	
	//��ֵ,�ȹ����ֵ,��Ҫͬʱ����,�����빹�캯������
	
	//stack<int> st3;
	//st3 = st1;

	//��С(Ԫ�ظ���)

	//cout << st1.size() << endl;     //Ԫ�ظ���
	//cout << st1.empty() << endl;	//�ж�ջ�Ƿ�Ϊ�գ��� -> 1(��)���ǿ� -> 0(��)

	//���ݴ�ȡ-����д

	//stack<int> st4;
	//st4.push(2);					//����ջ��Ԫ��-��ջ
	//cout << st4.top() << endl;	//�õ�ջ��Ԫ��
	//st4.pop();					//�Ƴ�ջ��Ԫ��-��ջ

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  5.queue����(����-�Ƚ��ȳ�)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  ע��queue����Q
//      һ�˽�(��β)����һ�˳�(��ͷ)
//		ֻ�ж�ͷ�Ͷ�β���ܱ����ʵ����������������֧�ֵ�����
//		���ӣ�push  ���ӣ�pop  ��ͷԪ�أ�front()  ��βԪ�أ�back()
	
	//���캯��

	//queue<int> qu1;
	//qu1.push(1);
	//qu1.push(2);
	//qu1.push(3);
	//qu1.push(4);
	//queue<int> st2(qu1);   //copy

	//��ֵ,�ȹ����ֵ,��Ҫͬʱ����,�����빹�캯������

	//queue<int> qu3;
	//qu3 = qu1;
	
	//��С(Ԫ�ظ���)

	//cout << qu1.size() << endl;     //Ԫ�ظ���
	//cout << qu1.empty() << endl;	//�ж϶����Ƿ�Ϊ�գ��� -> 1(��)���ǿ� -> 0(��)

	//���ݴ�ȡ-����д

	//queue<int> qu4;
	//qu4.push(5);						//�������Ԫ��-���
	//qu4.push(1);
	//cout << qu4.front() << endl;		//�õ���ͷԪ��
	//cout << qu4.back() << endl;		//�õ���βԪ��
	//qu4.pop();						//�Ƴ�����Ԫ��-����
	//cout << qu4.front() << endl;      //�Ƴ���Ķ�ͷԪ��

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  6.list����(˫��ѭ������)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  ע����Ҫʵ��˫��(ǰһ���ڵ�ĺ��ָ����һ���ڵ㣬��һ���ڵ��ǰ��ָ��ǰһ���ڵ㣬�����ڵ�֮���ָ��)
//		��ʵ��ѭ��(ͷ�ڵ��ǰ��ָ��β�ڵ㣬β�ڵ�ĺ��ָ��ͷ�ڵ㣬�����ڵ�֮���ָ��)
//		���Ա�������ֻ���á�����������������������Ծʽ����

	//���캯��
	
	//list<int> li1;
	//li1.push_back(1);
	//li1.push_back(2);
	//li1.push_back(3);
	//print(li1);
	//list<int> li2(li1);						//copy
	//print(li2);
	//list<int> li3(li1.begin(),li1.end());   //copy
	//print(li3);
	//list<int> li4(3,10);					//3��10
	//print(li4);
	
	//

    //��ֵ,�ȹ����ֵ,��Ҫͬʱ����,�����빹�캯������

	//������assign(.begin(),.end())	   
	//		assign(n,elem)   
	//		li2 = li1("="��ֵ)
	
	//�������� :������ʽ��1. swap(li6, li7)   2. li6.swap(li7)
		
	//��С

	//������size()   
	//		empty()				�ж������Ƿ�Ϊ�գ��� -> 1(��)���ǿ� -> 0(��)
	//		resize(num)			����ָ����С����ԭ����->���������0(Ĭ��ֵ)���,��ԭ��С->ɾ������Ĳ���
    //		resize(num��elem)	����ָ����С����ԭ����->���������ָ��ֵ���,��ԭ��С->ɾ������Ĳ���

	//�����ɾ��

	////������  
	////���˲����� β��push_back(elem)  pop_back()  ͷ��push_front(elem)  pop_front()
	////�м�λ�ã�
	//list<int> li0(3,1);
	////		�������ݣ�
	//li0.insert(li0.end(), 2);//λ��ֻ���õ�����,����ָ��λ��,������ .begin() + n ��Ծʽ���ң������Լ�(++)�Լ�(--)
	//print(li0);
	//li0.erase(li0.begin());	 //ͬ��
	//print(li0);
	////		������ݣ�
	//li0.insert(li0.end(), 2, 3);					 //��λ�ò���2��3��ͬ��
	//li0.insert(li0.begin(), li0.begin(),li0.end());  //�ڿ�ͷλ�ò�������(����Ϊ����list)�ڵ�Ԫ��(����ҿ�)��ͬ��
	//li0.erase(li0.begin(), li0.end());				 //ɾ�����䣬ͬ��
	////��������� clear() -> ɾ��������������    remove(elem) -> ɾ�������С�ȫ���ġ�elem

	//���ݴ�ȡ-����д

	////������������front() -> ���ص�һ��Ԫ�� | back() -> �������һ��Ԫ��
	////���Է��ʵ���Ԫ�أ�����Խ��и�ֵ
	//list<int> li(3,5);
	//li.front() = 1;
	//print(li);
	//cout << li.back() << endl;

	//��ת������

	//list<int> w;
	//w.push_back(1);
	//w.push_back(3);
	//w.push_back(2);
	//w.push_back(4);
	//print(w);
	////��ת
	//w.reverse();
	//print(w);
	////����
	//w.sort();
	//print(w);

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  7.set/multiset����  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  ˵����Ԫ�ز������Զ�����Ĭ�ϴ�С����
//		  ���Ա�������ֻ���á�����������������������Ծʽ����
//		  set/multiset�������ڡ�����ʽ���������ײ��Ƕ�����
//		  set/multiset����set���������ظ�Ԫ�أ���multiset����
//		  set�����ظ���Ԫ��ʱ���Ȳ����Ԫ����Ч��������Ԫ����Ч

	//����͸�ֵ
	
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

	//��С�ͽ���

	//set<int> s1;
	//set<int> s2;
	//��С�� size() Ԫ�ظ���
	//		empty() �ж������Ƿ�Ϊ�գ��� -> 1(��)���ǿ� -> 0(��)
	//������1.  swap(s1,s2)   2.  s1.swap(s2)
	
	//�����ɾ��																												
 
	//���룺insert(elem)
	//ɾ��������λ�ã�erase(pos)			λ���õ�����,������Ծʽ���ʣ��������Լ�(++)�Լ�(--)
	//		���䣺erase(.begin(),.end())	����ҿ�
	//		����Ԫ�أ�erase(elem)  
	//��գ�clear()

	//���Һ�ͳ��
	
	//set<int> s2;
	//s2.insert(5);
	//s2.insert(4);
	//s2.insert(3);
	//s2.insert(2);
	//s2.insert(1); 
	//cout << *(s2.find(3)) << endl;
	////�ú������ص��ǵ�����������ҵ������ص�ǰλ�õĵ�������û�ҵ����򷵻�s2.end()
	//int num = s2.count(3);
	//cout << num << endl;
	////ͳ�Ƹ�����ֻ�����ֽ����1����0��(����set����)
	
    //�Զ�������ʽ
	//**********��Ҫ�÷º�������ʱ��Ū********
	
//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  pair ����  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//	˵�����ɶԳ��ֵ����ݣ����Է�����������
//        ֱ���ã�û��ͷ�ļ�

	////������������ַ��������÷���
	////��һ�֣�����
	//pair<int, string> p1(1, "b");
	//cout << p1.first << "  " << p1.second << endl;
	////�ڶ��֣�make_pair(key, value)
	//pair<int, char> p2 ;
	//p2 = make_pair(2, 'c');
	//cout << p2.first << "  " << p2.second << endl;

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  8.map/multimap����  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//  ˵��������������Ԫ�ض���"pair"��pair�ĵ�һ��Ԫ��Ϊ"key"(��ֵ)�����������ã��ڶ���Ԫ��Ϊ"value"(ʵֵ)
//		  ���������е�Ԫ�ػᰴ��"key"�Զ�����Ĭ�ϴ�С����
//		  ���Ա�������ֻ���á���������������������Ծʽ����
//		  map/multimap���ڡ�����ʽ���������ײ��Ƕ�����
//        map/multimap����map���������ظ���key����multimap����
//		  map����key�ظ���Ԫ��ʱ���Ȳ����Ԫ����Ч��������Ԫ����Ч

	//���¾���keyΪint�ͣ�valueΪstringΪ��
	
	//����͸�ֵ

	//map<int, string> m;
	//m.insert(pair<int, string>(1, "����"));
	//m.insert(pair<int, string>(2, "����"));
	//m.insert(pair<int, string>(3, "����"));
	//map<int, string> m2(m);   //copy
	//map<int, string> m3;
	//m3 = m;					  //copy
	//print(m);

	//��С�ͽ���

	////map<int, string> m1;
	////map<int, string> m2;
	////��С�� size() Ԫ�ظ���
	////		empty() �ж������Ƿ�Ϊ�գ��� -> 1(��)���ǿ� -> 0(��)
	////������1.  swap(m1,m2)   2.  m1.swap(m2)

	//�����ɾ��
	
	////����
	//map<int, string> m1;
	//map<int, string> m2;
	//map<int, string> m3;
	//map<int, string> m4;
	////��һ�֣�Ϊ��֤�������Ͳ���������ʹ��
	//m1.insert(pair<int, string>(1, "www"));
	////�ڶ��֣���֪��Ԫ�ص�key��value����Կ��ٴ���Ԫ��
	//m2.insert(make_pair(2, "ddd"));
	//print(m1);
	//print(m2);
	////�����֣�֪������
	//m3.insert(map<int, string>::value_type(3, "fffff"));
	////�����֣��±�->key  �ڴ�����ͬʱ������Ҫ��ֵvalue����ֹ������û��value��key����������׳���
	//m4[4] = "ggggg";  //�±����key,"ggggg"����value
	////ɾ��
	//m1.erase(1);						//����Ϊkey��ͨ��key��Ԫ�أ�Ȼ��ɾ����Ԫ��
	//m2.erase(m2.begin());				//������Ծʽɾ���������Ե������Լ�(++)�Լ�(--)
	//m3.erase(m3.begin(), m3.end());		//����ɾ��,ͬ��
	//m4.clear();							//���

	//���Һ�ͳ��
	
	//map<int, string> m1;
	//m1[1] = "dddd";
	//m1[2] = "ggggg";
	//cout << m1.find(2)->second << endl;
	////�ú������ص��ǵ�����������ҵ������ص�ǰλ�õĵ�������û�ҵ����򷵻�m1.end()
	//int num = m1.count(1);
	//cout << num << endl;
	////ͳ�Ƹ�����ֻ�����ֽ����1����0��(����map����)
	
	//�Զ�������ʽ
	//**********��Ҫ�÷º�������ʱ��Ū********

//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  ��������  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	
//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  1.��������(�º���)  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	
	//˵����


//  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  2.ν��  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	//˵��������bool���͵ķº�������"ν��"
	//		ֻ����1��������ν�ʳ�ΪһԪν�ʣ�ֻ����2��������ν�ʳ�Ϊ��Ԫν��




	
	//system("pause");
}

