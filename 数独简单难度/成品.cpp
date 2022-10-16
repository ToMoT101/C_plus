#include<iostream>
using namespace std;
#include <iomanip>  //  -->setw(x) 控制输出宽度x
int pos_num(int* p)                // 获取元素为0的元素个数         
{
	int num = 0;
	for (int i = 0; i < 81; i++)
	{
		if (p[i] == 0)
			num++;
	}
	return num;
}
int* pos_get(int* p)             // 获取并返回装有下标的数组
{
	int* p2;
	int num_get;
	int num_p2 = -1;
	num_get = pos_num(p); //2
	p2 = (int*)calloc(sizeof(int), num_get);
	if (p2 == NULL)//防报错
		exit(-1);

	for (int i = 0; i < 81; i++)
	{
		if (p[i] == 0)
		{
			num_p2++;
			p2[num_p2] = i;
		}
	}
	return p2;//返回数组
}
//三条件判断
void row_81(int* p, int n, int* p_lib) // n为元素下标     ——无BUG
{
	int row_num = n / 9;            //判断在“该行”的那一列(序号为：0~8 )
	int before_x, after_x;
	before_x = n - 9 * row_num;     //向 前 比较的次数
	after_x = 8 + 9 * row_num - n;  //向 后 比较的次数
	for (int i = 0; i < before_x; i++)  //向 前 比较
	{
		if (*p_lib == p[n - i - 1])
			*p_lib = 0;
	}
	for (int i = 0; i < after_x; i++)   //向 后 比较
	{
		if (*p_lib == p[n + i + 1])
			*p_lib = 0;
	}
}
void line_81(int* p, int n, int* p_lib)          //  无BUG  
{

	int line_num = n / 9;            //判断在“该列”的哪一行(序号为：0~8 )
	int up_x, down_x;
	up_x = n / 9;                         //向 前 比较的次数         
	down_x = (80 - n) / 9;                //向 后 比较的次数
	for (int i = 0; i < up_x; i++)        //向 前 比较
	{
		if (*p_lib == p[n - (i + 1) * 9])
		{
			*p_lib = 0;
		}
	}
	for (int i = 0; i < down_x; i++)      //向 后 比较
	{
		if (*p_lib == p[n + (i + 1) * 9])
		{
			*p_lib = 0;
		}
	}

}
bool repeat_81(int* p, int n)  // 除去该位置行和列的“其他元素”——无BUG
{
	int sum[9] = { 0 };
	switch (n)
	{
	case 0:case 3:case 6:case 27:case 30:case 33:case 54:case 57:case 60:  //左上
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n + 1 + 9 * i])
				sum[0]++;
		}
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n + 2 + 9 * i])
				sum[0]++;
		}
		if (sum[0] == 4)
			return true;
		else
			return false;
		break;
	case 1:case 4:case 7:case 28:case 31:case 34:case 55:case 58:case 61:  //上
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n - 1 + 9 * i])
				sum[1]++;
		}
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n + 1 + 9 * i])
				sum[1]++;
		}
		if (sum[1] == 4)
			return true;
		else
			return false;
		break;
	case 2:case 5:case 8:case 29:case 32:case 35:case 56:case 59:case 62:  //右上
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n - 1 + 9 * i])
				sum[2]++;
		}
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n - 2 + 9 * i])
				sum[2]++;
		}
		if (sum[2] == 4)
			return true;
		else
			return false;
		break;
	case 9:case 12:case 15:case 36:case 39:case 42:case 63:case 66:case 69:  //左
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n + i + 9])
				sum[3]++;
		}
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n + i - 9])
				sum[3]++;
		}
		if (sum[3] == 4)
			return true;
		else
			return false;
		break;
	case 10:case 13:case 16:case 37:case 40:case 43:case 64:case 67:case 70:  //中
		if (p[n] != p[n - 1 + 9])
			sum[4]++;
		if (p[n] != p[n + 1 + 9])
			sum[4]++;
		if (p[n] != p[n - 1 - 9])
			sum[4]++;
		if (p[n] != p[n + 1 - 9])
			sum[4]++;
		if (sum[4] == 4)
			return true;
		else
			return false;
		break;
	case 11:case 14:case 17:case 38:case 41:case 44:case 65:case 68:case 71:  //右
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n - i + 9])
				sum[5]++;
		}
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n - i - 9])
				sum[5]++;
		}
		if (sum[5] == 4)
			return true;
		else
			return false;
		break;
	case 18:case 21:case 24:case 45:case 48:case 51:case 72:case 75:case 78:  //左下
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n + 1 - 9 * i])
				sum[6]++;
		}
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n + 2 - 9 * i])
				sum[6]++;
		}
		if (sum[6] == 4)
			return true;
		else
			return false;
		break;
	case 19:case 22:case 25:case 46:case 49:case 52:case 73:case 76:case 79:  //下
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n + 1 - 9 * i])
				sum[7]++;
		}
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n - 1 - 9 * i])
				sum[7]++;
		}
		if (sum[7] == 4)
			return true;
		else
			return false;
		break;
	case 20:case 23:case 26:case 47:case 50:case 53:case 74:case 77:case 80:  //右下
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n - 1 - 9 * i])
				sum[8]++;
		}
		for (int i = 1; i <= 2; i++)
		{
			if (p[n] != p[n - 2 - 9 * i])
				sum[8]++;
		}
		if (sum[8] == 4)
			return true;
		else
			return false;
		break;
	}

}
// 打印数独——无BUG
void arr_print(int arr[])
{

	cout << "\n  数独为：";
	cout << "\n         ——————————————————————\n         | ";
	for (int i = 0; i < 81; i++)
	{
		cout << setw(2) << arr[i] << "  ";
		if ((i + 1) % 3 == 0)
		{
			if (i == 0)
				continue;
			cout << "| ";
		}
		if (i == 26 || i == 53)
		{
			cout << "\n         ——————————————————————\n";
		}
		else if (i == 8 || i == 17 || i == 35 || i == 44 || i == 62 || i == 71)
			cout << endl;
		if ((i + 1) % 9 == 0)
		{
			if (i == 80)
				;
			else
				cout << "\n         | ";
		}

	}
	cout << "\n         ——————————————————————\n";
}
//备选数字
int row_81_num(int* p, int n)  //判断备选个数
{
	int num = 0;
	int row_num = n / 9;            //判断在“该行”的那一列(序号为：0~8 )
	int before_x, after_x;
	before_x = n - 9 * row_num;     //向 前 比较的次数  
	after_x = 8 + 9 * row_num - n;  //向 后 比较的次数  
	for (int i = 1; i <= before_x; i++) //向 前 比较
	{
		if (p[n] == p[n - i])
			num++;
	}
	for (int i = 1; i <= after_x; i++)   //向 后 比较
	{
		if (p[n] == p[n + i])
			num++;
	}
	num++;       //加上自己也为0
	return num;
}
int* row_81_array(int* p, int n)             //  无BUG
{
	int num = row_81_num(p, n);   //  num = 1   p[n]就是位置
	int* arr = (int*)calloc(sizeof(int), num); //备选库
	if (arr == NULL)
		exit(-1);
	//找备选数字
	int row_num = n / 9;            //判断在“该行”的那一列(序号为：0~8 )
	int before_x, after_x;
	before_x = n - 9 * row_num;     //向 前 比较的次数  
	after_x = 8 + 9 * row_num - n;  //向 后 比较的次数 
	int num_test = 0;//用于逻辑判断
	int temporary = 0;
	for (int i = 0; i < num; i++)    //找num个数
	{
		for (int j = temporary + 1; j <= 9; j++)//从1开始找,防止下次找到重复的  //    
		{
			// 3,1,5 || 0,9,7 || 4,6,8
			num_test = 0;
			for (int k = 1; k <= before_x; k++)//前
			{
				if (j == p[n - k])
				{
					num_test++;
					break;
				}
			}
			for (int k = 1; k <= after_x; k++)//后
			{
				if (j == p[n + k])
				{
					num_test++;
					break;
				}
			}
			if (num_test != 1)
			{
				arr[i] = j;     //保存备选数
				temporary = j;
				break;          //找到了
			}
		}
	}
	return arr;
}
//算出备选库长度——专用——无BUG
int arr_num(int* p1)
{
	int* p2 = p1;
	int num = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (p2[i] == j)
			{
				num++;
				break;
			}
		}
	}
	return num;
}
//算出数组最后一个不为0的元素的位置(从1开始)——备选库
int arr_last_pos(int* p)
{
	int* p2 = p;
	int last = 0;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (p2[j] == i)
			{
				last = j;
				break;
			}
		}
	}
	last++;
	return last;
}
//算出数组最后一个不为0的元素的位置(从1开始)——装元素为0的下标的数组
int arr_last_pos_new(int* p, int n)
{
	int* p2 = p;
	int last = 0;
	for (int i = 0; i < n; i++)  //次数
	{
		if (p[i] >= 0)
		{
			last = i;
		}

	}
	last++;
	return last;
}
//“行”备选库——第一条件
int** num_alternative_row(int* arr)
{
	int* p = pos_get(arr);   //  装元素为0的下标的数组
	int num = pos_num(arr);  //  元素为0的个数
	//备选个数统计
	int num_2;   //每个元素为0的备填个数                     
	int** memory = (int**)calloc(sizeof(int) * 9, num); //memory是大库  memory[i]就是备选库
	if (memory == NULL)
		exit(-1);
	for (int i = 0; i < num; i++)
	{
		num_2 = row_81_num(arr, p[i]);  //每个备选库的备选个数
		//分配空间
		memory[i] = (int*)calloc(sizeof(int), num_2);
		if (memory[i] == NULL)
			exit(-1);
	}
	cout << endl;
	//接收备选库
	for (int i = 0; i < num; i++)  // num是元素为0的个数
	{
		memory[i] = row_81_array(arr, p[i]);    // 给每个小库“接收“装有备选数的数组               
	}
	//打印备选库
	/*for (int i = 0; i < num; i++)
	{
		int alternative = arr_num(memory[i]);
		for (int j=0; j < alternative; j++)
		{
			cout <<memory[i][j]<<"   ";
		}
		cout << endl;
	}*/
	return memory;    //返回大库，不是小库
}
//“列”备选库(在行查重后)——第二条件
int** num_alternative_line(int* arr, int** p_2, int n, int* pos)   //n为元素为0的个数  p_2是大库  pos是装有元素为0的下标的数组
{
	//cout << "************ 大库 ***************\n";
	//for (int i = 0; i < n; i++)   //   打印大库
	//{
	//	int alternative = arr_num(p_2[i]);
	//	for (int j = 0; j < alternative; j++)
	//	{
	//		cout << p_2[i][j] << "   ";
	//	}
	//	cout << endl;
	//}
	//cout << "************ 大库结束 ***************\n";
	int line_num;                  //判断在“该列”的哪一行(序号为：0~8 )
	int up_x, down_x;
	for (int i = 0; i < n; i++)   //打印装有元素为0的下标的数组
	{
		for (int i = 0; i < n; i++)                //   用大库进行对比
		{
			line_num = pos[i] / 9;
			up_x = pos[i] / 9;
			down_x = (80 - pos[i]) / 9;
			int alternative = arr_num(p_2[i]);
			for (int j = 0; j < alternative; j++)  //    小库
			{
				//cout << p_2[i][j] << "   ";
				for (int k = 0; k < up_x; k++)        //向 前 比较
				{
					if (p_2[i][j] == arr[pos[i] - (k + 1) * 9])   //arr是原数独，pos[0]是3  
					{
						p_2[i][j] = 0;
					}
				}
				for (int k = 0; k < down_x; k++)        //向 后 比较
				{
					if (p_2[i][j] == arr[pos[i] + (k + 1) * 9])   //arr是原数独，pos[0]是3   
					{
						p_2[i][j] = 0;
					}
				}
			}
			//cout << endl;
		}
	}
	for (int i = 0; i < n; i++)//让小库排序：比如0，0，8   排序后就是8，0，0， 即不为0的元素前面不能为0
	{
		for (int k = 1; k <= 9; k++)//控制次数
		{
			int last_pos = arr_last_pos(p_2[i]);
			for (int j = 1; j < last_pos; j++)
			{
				int turn;
				if (p_2[i][j - 1] == 0)
				{
					int i_2 = j;
					while (p_2[i][j] == 0)
					{
						int t;
						t = p_2[i][j];
						p_2[i][j] = p_2[i][i_2 + 1];
						p_2[i][i_2 + 1] = t;
						i_2++;
					}
					turn = p_2[i][j - 1];
					p_2[i][j - 1] = p_2[i][j];
					p_2[i][j] = turn;
				}
			}
		}
	}
	//cout << "**********  经过列查重后的大库(已进行过“行”查重)  ************\n";
	//for (int i = 0; i < n; i++)   //   打印大库
	//{
	//	int alternative = arr_num(p_2[i]);
	//	for (int j = 0; j < alternative; j++)
	//	{
	//		cout << p_2[i][j] << "   ";
	//	}
	//	cout << endl;
	//}
	return p_2;
}
// “九宫格”备选库(在行和列查重后)——第三条件
int** num_alternative_repeat(int* arr, int** p_3, int n, int* p_pos)//n为元素为0的个数  p_3是大库  p_pos是装元素为0的下标的数组
{
	int alternative = 0; //小库的备选个数
	// 大库接收成功
	//cout << "************ 大库 ***************\n";
	//for (int i = 0; i < n; i++)   //   打印大库
	//{
	//	alternative = arr_num(p_3[i]);
	//	for (int j = 0; j < alternative; j++)
	//	{
	//		cout << "    " << setw(2) << i + 1 << "-" << j + 1 << "-->  " << p_3[i][j] << "   ";
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	//cout << "************ 大库结束 ***************\n";
	//查重
	for (int syn = 0; syn < n; syn++)  // 同步小库和元素为0的位置
	{                            //p_3是大库    arr是原数组   p_pos[0]-下标为3  p_3[0]是第一个小库
		switch (p_pos[syn])     //先测试第一个，下标为3，备选库为2，6，8，筛选后要为2
		{
		case 0:case 3:case 6:case 27:case 30:case 33:case 54:case 57:case 60:  //左上

			alternative = arr_num(p_3[syn]);
			for (int i = 0; i < alternative; i++)
			{
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] + 1 + 9 * k])   // if (p[n] != p[n + 1 + 9 * i])
						p_3[syn][i] = 0;
				}
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] + 2 + 9 * k])
						p_3[syn][i] = 0;
				}
			}
			break;
		case 1:case 4:case 7:case 28:case 31:case 34:case 55:case 58:case 61:    //上
			alternative = arr_num(p_3[syn]);
			for (int i = 0; i < alternative; i++)
			{
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] - 1 + 9 * k])    //if (p[n] != p[n - 1 + 9 * i])
						p_3[syn][i] = 0;
				}
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] + 1 + 9 * k])    //if (p[n] != p[n + 1 + 9 * i])
						p_3[syn][i] = 0;
				}
			}
			break;
		case 2:case 5:case 8:case 29:case 32:case 35:case 56:case 59:case 62:    //右上
			alternative = arr_num(p_3[syn]);
			for (int i = 0; i < alternative; i++)
			{
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] - 1 + 9 * k])   //if (p[n] != p[n - 1 + 9 * i])
						p_3[syn][i] = 0;
				}
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] - 2 + 9 * k])    //if (p[n] != p[n - 2 + 9 * i])
						p_3[syn][i] = 0;
				}
			}
			break;
		case 9:case 12:case 15:case 36:case 39:case 42:case 63:case 66:case 69:  //左
			alternative = arr_num(p_3[syn]);
			for (int i = 0; i < alternative; i++)
			{
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] + k + 9])    //p[n] != p[n + i + 9]
						p_3[syn][i] = 0;
				}
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] + k - 9])     //p[n] != p[n + i - 9]
						p_3[syn][i] = 0;
				}
			}
			break;
		case 10:case 13:case 16:case 37:case 40:case 43:case 64:case 67:case 70:  //中
			alternative = arr_num(p_3[syn]);
			for (int i = 0; i < alternative; i++)
			{
				if (p_3[syn][i] == arr[p_pos[syn] - 1 + 9])   //p[n] != p[n - 1 + 9]
					p_3[syn][i] = 0;
				if (p_3[syn][i] == arr[p_pos[syn] + 1 + 9])   //p[n] != p[n + 1 + 9]
					p_3[syn][i] = 0;
				if (p_3[syn][i] == arr[p_pos[syn] - 1 - 9])   //p[n] != p[n - 1 - 9]
					p_3[syn][i] = 0;
				if (p_3[syn][i] == arr[p_pos[syn] + 1 - 9])   //p[n] != p[n + 1 - 9]
					p_3[syn][i] = 0;
			}
			break;
		case 11:case 14:case 17:case 38:case 41:case 44:case 65:case 68:case 71:  //右
			alternative = arr_num(p_3[syn]);
			for (int i = 0; i < alternative; i++)
			{
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] - k + 9])    //p[n] != p[n - i + 9]
						p_3[syn][i] = 0;
				}
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] - k - 9])    //p[n] != p[n - i - 9]
						p_3[syn][i] = 0;
				}
			}
			break;
		case 18:case 21:case 24:case 45:case 48:case 51:case 72:case 75:case 78:  //左下
			alternative = arr_num(p_3[syn]);
			for (int i = 0; i < alternative; i++)
			{
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] + 1 - 9 * k])   //p[n] != p[n + 1 - 9 * i]
						p_3[syn][i] = 0;
				}
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] + 2 - 9 * k])   //p[n] != p[n + 2 - 9 * i]
						p_3[syn][i] = 0;
				}
			}
			break;
		case 19:case 22:case 25:case 46:case 49:case 52:case 73:case 76:case 79:  //下
			alternative = arr_num(p_3[syn]);
			for (int i = 0; i < alternative; i++)
			{
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] + 1 - 9 * k])  //p[n] != p[n + 1 - 9 * i]
						p_3[syn][i] = 0;
				}
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] - 1 - 9 * k])  //p[n] != p[n - 1 - 9 * i
						p_3[syn][i] = 0;
				}
			}
			break;
		case 20:case 23:case 26:case 47:case 50:case 53:case 74:case 77:case 80:  //右下
			alternative = arr_num(p_3[syn]);
			for (int i = 0; i < alternative; i++)
			{
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] - 1 - 9 * k])   //p[n] != p[n - 1 - 9 * i]
						p_3[syn][i] = 0;
				}
				for (int k = 1; k <= 2; k++)
				{
					if (p_3[syn][i] == arr[p_pos[syn] - 2 - 9 * k])   //p[n] != p[n - 2 - 9 * i]
						p_3[syn][i] = 0;
				}
			}
			break;

		}// 开关结束
	}
	//给大库再次排序
	for (int i = 0; i < n; i++)//让小库排序：比如0，0，8   排序后就是8，0，0， 即不为0的元素前面不能为0
	{
		for (int k = 1; k <= 9; k++)//控制次数
		{
			int last_pos = arr_last_pos(p_3[i]);
			for (int j = 1; j < last_pos; j++)
			{
				int turn;
				if (p_3[i][j - 1] == 0)
				{
					int i_2 = j;
					while (p_3[i][j] == 0)
					{
						int t;
						t = p_3[i][j];
						p_3[i][j] = p_3[i][i_2 + 1];
						p_3[i][i_2 + 1] = t;
						i_2++;
					}
					turn = p_3[i][j - 1];
					p_3[i][j - 1] = p_3[i][j];
					p_3[i][j] = turn;
				}
			}
		}
	}
	//************* 打印大库 **********
	//cout << "************ 大库 ***************\n";
	//for (int i = 0; i < n; i++)   //   打印大库
	//{
	//	alternative = arr_num(p_3[i]);
	//	for (int j = 0; j < alternative; j++)
	//	{
	//		cout << "    " << setw(2) << i << p_pos[i] << "-" << j + 1 << "-->  " << p_3[i][j] << "   ";
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	//cout << "************ 大库结束 ***************\n";
	return p_3;
}
// 用于其他库查重
void library_row_2(int** p_4, int n, int num, int* p)// n为p的元素序号，即当前位置  num为p的长度   p为装元素为0的下标的数组
{
	int a = p[n] / 9;
	int n_2 = n;
	int b = -2;
	int c;
	int d = n;
	while (p[n] / 9 == a)  //前
	{
		b++;
		if (n == 0)  //判断是否为p数组的第一个
			break;
		if (p[n - 1] / 9 != a)   //判断前面一个是否为同一行
			break;
		else
		{
			c = arr_last_pos(p_4[n - 1]);
			for (int j = 0; j < c; j++)
			{
				if (p_4[n - 1][j] == p_4[d][0])
					p_4[n - 1][j] = 0;
			}
		}
		n--;
	}
	while (p[n_2] / 9 == a)  //后
	{
		b++;
		if (n_2 == num - 1)//判断是否为p数组的最后一个
			break;
		if (p[n_2 + 1] / 9 != a)   //判断后面一个是否为同一行
			break;
		else
		{
			c = arr_last_pos(p_4[n_2 + 1]);
			for (int j = 0; j < c; j++)
			{
				if (p_4[n_2 + 1][j] == p_4[d][0])
					p_4[n_2 + 1][j] = 0;
			}

		}
		n_2++;
	}
	/*cout << "改行有：" << b << endl;
	for (int j = 0; j < num; j++)
	{
		int alternative = arr_num(p_4[j]);
		for (int k = 0; k < alternative; k++)
		{
			cout << p_4[j][k] << "    ";
		}
		cout << endl;
	}*/

}
void library_line_2(int** p_4, int n, int num, int* p)// n为p的元素序号，即当前位置  num为p的长度   p为装元素为0的下标的数组
{
	int n_2 = n;
	int b = 0;
	int c;
	int d = n;
	switch (p[n])
	{
	case 0:case 9:case 18:case 27:case 36:case 45:case 54:case 63:case 72:
		for (n; n >= 0; n--)                  //往前面找是同一列的下标
		{
			if (n == 0)
				break;
			if (p[n - 1] == 0 || p[n - 1] == 9 || p[n - 1] == 18 || p[n - 1] == 27 || p[n - 1] == 36
				|| p[n - 1] == 45 || p[n - 1] == 54 || p[n - 1] == 63 || p[n - 1] == 72)
			{
				c = arr_last_pos(p_4[n - 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n - 1][j] == p_4[d][0])
						p_4[n - 1][j] = 0;
				}
			}

		}
		for (n_2; n_2 <= num - 1; n_2++)      //往后面找是同一列的下标
		{
			if (n_2 == num - 1)
				break;
			if (p[n_2 + 1] == 0 || p[n_2 + 1] == 9 || p[n_2 + 1] == 18 || p[n_2 + 1] == 27 || p[n_2 + 1] == 36
				|| p[n_2 + 1] == 45 || p[n_2 + 1] == 54 || p[n_2 + 1] == 63 || p[n_2 + 1] == 72)
			{
				c = arr_last_pos(p_4[n_2 + 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n_2 + 1][j] == p_4[d][0])
						p_4[n_2 + 1][j] = 0;
				}
			}
		}
		break;
	case 1:case 10:case 19:case 28:case 37:case 46:case 55:case 64:case 73:
		for (n; n >= 0; n--)                  //往前面找是同一列的下标
		{
			if (n == 0)
				break;
			if (p[n - 1] == 1 || p[n - 1] == 10 || p[n - 1] == 19 || p[n - 1] == 28 || p[n - 1] == 37
				|| p[n - 1] == 46 || p[n - 1] == 55 || p[n - 1] == 64 || p[n - 1] == 73)
			{
				c = arr_last_pos(p_4[n - 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n - 1][j] == p_4[d][0])
						p_4[n - 1][j] = 0;
				}
			}

		}
		for (n_2; n_2 <= num - 1; n_2++)      //往后面找是同一列的下标
		{
			if (n_2 == num - 1)
				break;
			if (p[n_2 + 1] == 1 || p[n_2 + 1] == 10 || p[n_2 + 1] == 19 || p[n_2 + 1] == 28 || p[n_2 + 1] == 37
				|| p[n_2 + 1] == 46 || p[n_2 + 1] == 55 || p[n_2 + 1] == 64 || p[n_2 + 1] == 73)
			{
				c = arr_last_pos(p_4[n_2 + 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n_2 + 1][j] == p_4[d][0])
						p_4[n_2 + 1][j] = 0;
				}
			}
		}
		break;
	case 2:case 11:case 20:case 29:case 38:case 47:case 56:case 65:case 74:
		for (n; n >= 0; n--)                  //往前面找是同一列的下标
		{
			if (n == 0)
				break;
			if (p[n - 1] == 2 || p[n - 1] == 11 || p[n - 1] == 20 || p[n - 1] == 29 || p[n - 1] == 38
				|| p[n - 1] == 47 || p[n - 1] == 56 || p[n - 1] == 65 || p[n - 1] == 74)
			{
				c = arr_last_pos(p_4[n - 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n - 1][j] == p_4[d][0])
						p_4[n - 1][j] = 0;
				}
			}
		}
		for (n_2; n_2 <= num - 1; n_2++)      //往后面找是同一列的下标
		{
			if (n_2 == num - 1)
				break;
			if (p[n_2 + 1] == 2 || p[n_2 + 1] == 11 || p[n_2 + 1] == 20 || p[n_2 + 1] == 29 || p[n_2 + 1] == 38
				|| p[n_2 + 1] == 47 || p[n_2 + 1] == 56 || p[n_2 + 1] == 65 || p[n_2 + 1] == 74)
			{
				c = arr_last_pos(p_4[n_2 + 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n_2 + 1][j] == p_4[d][0])
						p_4[n_2 + 1][j] = 0;
				}
			}
		}
		break;
	case 3:case 12:case 21:case 30:case 39:case 48:case 57:case 66:case 75:
		for (n; n >= 0; n--)                  //往前面找是同一列的下标
		{
			if (n == 0)
				break;
			if (p[n - 1] == 3 || p[n - 1] == 12 || p[n - 1] == 21 || p[n - 1] == 30 || p[n - 1] == 39
				|| p[n - 1] == 48 || p[n - 1] == 57 || p[n - 1] == 66 || p[n - 1] == 75)
			{
				c = arr_last_pos(p_4[n - 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n - 1][j] == p_4[d][0])
						p_4[n - 1][j] = 0;
				}
			}

		}
		for (n_2; n_2 <= num - 1; n_2++)      //往后面找是同一列的下标
		{
			if (n_2 == num - 1)
				break;
			if (p[n_2 + 1] == 3 || p[n_2 + 1] == 12 || p[n_2 + 1] == 21 || p[n_2 + 1] == 30 || p[n_2 + 1] == 39
				|| p[n_2 + 1] == 48 || p[n_2 + 1] == 57 || p[n_2 + 1] == 66 || p[n_2 + 1] == 75)
			{
				c = arr_last_pos(p_4[n_2 + 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n_2 + 1][j] == p_4[d][0])
						p_4[n_2 + 1][j] = 0;
				}
			}
		}
		break;
	case 4:case 13:case 22:case 31:case 40:case 49:case 58:case 67:case 76:
		for (n; n >= 0; n--)                  //往前面找是同一列的下标
		{
			if (n == 0)
				break;
			if (p[n - 1] == 4 || p[n - 1] == 13 || p[n - 1] == 22 || p[n - 1] == 31 || p[n - 1] == 40
				|| p[n - 1] == 49 || p[n - 1] == 58 || p[n - 1] == 67 || p[n - 1] == 76)
			{
				c = arr_last_pos(p_4[n - 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n - 1][j] == p_4[d][0])
						p_4[n - 1][j] = 0;
				}
			}

		}
		for (n_2; n_2 <= num - 1; n_2++)      //往后面找是同一列的下标
		{
			if (n_2 == num - 1)
				break;
			if (p[n_2 + 1] == 4 || p[n_2 + 1] == 13 || p[n_2 + 1] == 22 || p[n_2 + 1] == 31 || p[n_2 + 1] == 40
				|| p[n_2 + 1] == 49 || p[n_2 + 1] == 58 || p[n_2 + 1] == 67 || p[n_2 + 1] == 76)
			{
				c = arr_last_pos(p_4[n_2 + 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n_2 + 1][j] == p_4[d][0])
						p_4[n_2 + 1][j] = 0;
				}
			}
		}
		break;
	case 5:case 14:case 23:case 32:case 41:case 50:case 59:case 68:case 77:
		for (n; n >= 0; n--)                  //往前面找是同一列的下标
		{
			if (n == 0)
				break;
			if (p[n - 1] == 5 || p[n - 1] == 14 || p[n - 1] == 23 || p[n - 1] == 32 || p[n - 1] == 41
				|| p[n - 1] == 50 || p[n - 1] == 59 || p[n - 1] == 68 || p[n - 1] == 77)
			{
				c = arr_last_pos(p_4[n - 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n - 1][j] == p_4[d][0])
						p_4[n - 1][j] = 0;
				}
			}

		}
		for (n_2; n_2 <= num - 1; n_2++)      //往后面找是同一列的下标
		{
			if (n_2 == num - 1)
				break;
			if (p[n_2 + 1] == 5 || p[n_2 + 1] == 14 || p[n_2 + 1] == 23 || p[n_2 + 1] == 32 || p[n_2 + 1] == 41
				|| p[n_2 + 1] == 50 || p[n_2 + 1] == 59 || p[n_2 + 1] == 68 || p[n_2 + 1] == 77)
			{
				c = arr_last_pos(p_4[n_2 + 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n_2 + 1][j] == p_4[d][0])
						p_4[n_2 + 1][j] = 0;
				}
			}
		}
		break;
	case 6:case 15:case 24:case 33:case 42:case 51:case 60:case 69:case 78:
		for (n; n >= 0; n--)                  //往前面找是同一列的下标
		{
			if (n == 0)
				break;
			if (p[n - 1] == 6 || p[n - 1] == 15 || p[n - 1] == 24 || p[n - 1] == 33 || p[n - 1] == 42
				|| p[n - 1] == 51 || p[n - 1] == 60 || p[n - 1] == 69 || p[n - 1] == 78)
			{
				c = arr_last_pos(p_4[n - 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n - 1][j] == p_4[d][0])
						p_4[n - 1][j] = 0;
				}
			}
		}
		for (n_2; n_2 <= num - 1; n_2++)      //往后面找是同一列的下标
		{
			if (n_2 == num - 1)
				break;
			if (p[n_2 + 1] == 6 || p[n_2 + 1] == 15 || p[n_2 + 1] == 24 || p[n_2 + 1] == 33 || p[n_2 + 1] == 42
				|| p[n_2 + 1] == 51 || p[n_2 + 1] == 60 || p[n_2 + 1] == 69 || p[n_2 + 1] == 78)
			{
				c = arr_last_pos(p_4[n_2 + 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n_2 + 1][j] == p_4[d][0])
						p_4[n_2 + 1][j] = 0;
				}
			}
		}
		break;
	case 7:case 16:case 25:case 34:case 43:case 52:case 61:case 70:case 79:
		for (n; n >= 0; n--)                  //往前面找是同一列的下标
		{
			if (n == 0)
				break;
			if (p[n - 1] == 7 || p[n - 1] == 16 || p[n - 1] == 25 || p[n - 1] == 34 || p[n - 1] == 43
				|| p[n - 1] == 52 || p[n - 1] == 61 || p[n - 1] == 70 || p[n - 1] == 79)
			{
				c = arr_last_pos(p_4[n - 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n - 1][j] == p_4[d][0])
						p_4[n - 1][j] = 0;
				}
			}
		}
		for (n_2; n_2 <= num - 1; n_2++)      //往后面找是同一列的下标
		{
			if (n_2 == num - 1)
				break;
			if (p[n_2 + 1] == 7 || p[n_2 + 1] == 16 || p[n_2 + 1] == 25 || p[n_2 + 1] == 34 || p[n_2 + 1] == 43
				|| p[n_2 + 1] == 52 || p[n_2 + 1] == 61 || p[n_2 + 1] == 70 || p[n_2 + 1] == 79)
			{
				c = arr_last_pos(p_4[n_2 + 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n_2 + 1][j] == p_4[d][0])
						p_4[n_2 + 1][j] = 0;
				}
			}
		}
		break;
	case 8:case 17:case 26:case 35:case 44:case 53:case 62:case 71:case 80:
		for (n; n >= 0; n--)                  //往前面找是同一列的下标
		{
			if (n == 0)
				break;
			if (p[n - 1] == 8 || p[n - 1] == 17 || p[n - 1] == 26 || p[n - 1] == 35 || p[n - 1] == 44
				|| p[n - 1] == 53 || p[n - 1] == 62 || p[n - 1] == 71 || p[n - 1] == 80)
			{
				c = arr_last_pos(p_4[n - 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n - 1][j] == p_4[d][0])
						p_4[n - 1][j] = 0;
				}
			}

		}
		for (n_2; n_2 <= num - 1; n_2++)      //往后面找是同一列的下标
		{
			if (n_2 == num - 1)
				break;
			if (p[n_2 + 1] == 8 || p[n_2 + 1] == 17 || p[n_2 + 1] == 26 || p[n_2 + 1] == 35 || p[n_2 + 1] == 44
				|| p[n_2 + 1] == 53 || p[n_2 + 1] == 62 || p[n_2 + 1] == 71 || p[n_2 + 1] == 80)
			{
				c = arr_last_pos(p_4[n_2 + 1]);
				for (int j = 0; j < c; j++)
				{
					if (p_4[n_2 + 1][j] == p_4[d][0])
						p_4[n_2 + 1][j] = 0;
				}
			}
		}
		break;
	}
}
//***************** 特别要注意“行，列，九宫格”的查重算法！如果查重有问题，可以去检查一下算法有没有问题 *****************
int main()
{
	//************************************************  初始化设置  *********************************************************
	int Sudoku[81] = {  3,1,5,/**/0,9,7,/**/4,0,0,       // 3,1,5 || 2,9,7 || 4,6,8   |  // 3,1,5,/**/0,9,7,/**/4,0,0,
						4,2,0,/**/3,0,0,/**/0,7,0,       // 4,2,6 || 3,5,8 || 1,7,9   |  // 4,2,0,/**/3,0,0,/**/0,7,0,
						7,0,8,/**/0,6,0,/**/3,0,0,       // 7,9,8 || 4,6,1 || 3,2,5   |  // 7,0,8,/**/0,6,0,/**/3,0,0,

						0,6,4,/**/0,2,9,/**/0,0,0,       // 1,6,4 || 8,2,9 || 7,5,3   |  // 0,6,4,/**/0,2,9,/**/0,0,0,
						8,3,9,/**/0,7,4,/**/0,0,2,       // 8,3,9 || 5,7,4 || 6,1,2   |  // 8,3,9,/**/0,7,4,/**/0,0,2,
						0,7,2,/**/1,0,0,/**/0,9,0,       // 5,7,2 || 1,3,6 || 8,9,4   |  // 0,7,2,/**/1,0,0,/**/0,9,0,

						0,0,0,/**/9,1,0,/**/5,8,0,       // 6,4,3 || 9,1,2 || 5,8,7   |  // 0,0,0,/**/9,1,0,/**/5,8,0,
						0,5,0,/**/0,8,3,/**/9,0,0,       // 2,5,7 || 6,8,3 || 9,4,1   |  // 0,5,0,/**/0,8,3,/**/9,0,0,
						0,8,1,/**/0,4,5,/**/2,3,6        // 9,8,1 || 7,4,5 || 2,3,6   |  // 0,8,1,/**/0,4,5,/**/2,3,6
	};
	int num_0 = pos_num(Sudoku);         //     num_0是元素为0的个数
	int* position = pos_get(Sudoku);     //     接收装有元素为0的下标的数组
	int arr_long;                        //     算数组长度
	arr_print(Sudoku);                   //打印初始数独
	int** library_row = num_alternative_row(Sudoku);  // 行查重及创建备选库——第一步  
	//  ——>可以在num_alternative_row()函数里查看大库，现为“关闭”状态,也可以看每个小库的备选个数，现为“开启”状态
	int** library_line = num_alternative_line(Sudoku, library_row, num_0, position);  // 行查重——第二步
	//  ——>可以在num_alternative_line()函数里查看大库，现为“关闭”状态
	int** library_repeat = num_alternative_repeat(Sudoku, library_line, num_0, position); //  九宫格内查重——最后一步
	//  ——>可以在num_alternative_repeat()函数里查看大库，现为“关闭”状态

//*******************************************   核心算法  ****************************************************
	
	int num_0_reduce = 0;
	// 循环开始
	while (num_0_reduce != 38)
	{
		for (int i = 0; i < num_0; i++)  //“只算”库只有一个数，且处于第一个位置的数，即能直接填入的数
		{
			arr_long = arr_num(library_repeat[i]); //算出小库长度
			if (arr_long == 1)       // 判断是不是只有一个数字
			{
				if (library_repeat[i][0] != 0)		  //判断是不是在第一个位置
				{
					Sudoku[position[i]] = library_repeat[i][0];     //是则直接填入该数字
					num_0_reduce++;  //记录填如数字的个数

					//把其他小库里面相同备选数字去除,如果除去出后只剩下一个，且刚好排在第一位，则下次就会直接填入该数字
					library_row_2(library_repeat, i, num_0, position);
					library_line_2(library_repeat, i, num_0, position);
					//先进行上面的行列“库查重”，把其他库相同数字除去，最后再进行下面两步
					library_repeat[i][0] = 0;   //填入数字后把对应库的备选数除去
					position[i] = -1;           // 把元素为0的下标的数组对应的下标去除
				}
			}
		}
		for (int i = 0; i < num_0; i++)    // 算“除能直接填入的库之外的其他库”
		{
			int last_pos = arr_last_pos(library_repeat[i]);
			for (int gg = 0; gg < last_pos; gg++)
			{
				row_81(Sudoku, position[i], &library_repeat[i][gg]);
				line_81(Sudoku, position[i], &library_repeat[i][gg]);
			}
		}
		//给库进行排序，用于下次循环
		for (int i = 0; i < num_0; i++)
		{
			for (int k = 1; k <= 9; k++)//控制次数
			{
				int last_pos = arr_last_pos(library_repeat[i]);
				for (int j = 1; j < last_pos; j++)
				{	
					int turn;
					if (library_repeat[i][j - 1] == 0)
					{				
						int i_2 = j;
						while (library_repeat[i][j] == 0)
						{
							int t;
							t = library_repeat[i][j];
							library_repeat[i][j] = library_repeat[i][i_2 + 1];
							library_repeat[i][i_2 + 1] = t;
							i_2++;
						}
						turn = library_repeat[i][j - 1];
						library_repeat[i][j - 1] = library_repeat[i][j];
						library_repeat[i][j] = turn;
					}
				}
			}
		}
	}
	//循环结束

	//*******************************************  算法结束  ********************************************

	 //打印数独(解)
	arr_print(Sudoku);
}
