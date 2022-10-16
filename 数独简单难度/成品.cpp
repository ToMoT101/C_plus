#include<iostream>
using namespace std;
#include <iomanip>  //  -->setw(x) ����������x
int pos_num(int* p)                // ��ȡԪ��Ϊ0��Ԫ�ظ���         
{
	int num = 0;
	for (int i = 0; i < 81; i++)
	{
		if (p[i] == 0)
			num++;
	}
	return num;
}
int* pos_get(int* p)             // ��ȡ������װ���±������
{
	int* p2;
	int num_get;
	int num_p2 = -1;
	num_get = pos_num(p); //2
	p2 = (int*)calloc(sizeof(int), num_get);
	if (p2 == NULL)//������
		exit(-1);

	for (int i = 0; i < 81; i++)
	{
		if (p[i] == 0)
		{
			num_p2++;
			p2[num_p2] = i;
		}
	}
	return p2;//��������
}
//�������ж�
void row_81(int* p, int n, int* p_lib) // nΪԪ���±�     ������BUG
{
	int row_num = n / 9;            //�ж��ڡ����С�����һ��(���Ϊ��0~8 )
	int before_x, after_x;
	before_x = n - 9 * row_num;     //�� ǰ �ȽϵĴ���
	after_x = 8 + 9 * row_num - n;  //�� �� �ȽϵĴ���
	for (int i = 0; i < before_x; i++)  //�� ǰ �Ƚ�
	{
		if (*p_lib == p[n - i - 1])
			*p_lib = 0;
	}
	for (int i = 0; i < after_x; i++)   //�� �� �Ƚ�
	{
		if (*p_lib == p[n + i + 1])
			*p_lib = 0;
	}
}
void line_81(int* p, int n, int* p_lib)          //  ��BUG  
{

	int line_num = n / 9;            //�ж��ڡ����С�����һ��(���Ϊ��0~8 )
	int up_x, down_x;
	up_x = n / 9;                         //�� ǰ �ȽϵĴ���         
	down_x = (80 - n) / 9;                //�� �� �ȽϵĴ���
	for (int i = 0; i < up_x; i++)        //�� ǰ �Ƚ�
	{
		if (*p_lib == p[n - (i + 1) * 9])
		{
			*p_lib = 0;
		}
	}
	for (int i = 0; i < down_x; i++)      //�� �� �Ƚ�
	{
		if (*p_lib == p[n + (i + 1) * 9])
		{
			*p_lib = 0;
		}
	}

}
bool repeat_81(int* p, int n)  // ��ȥ��λ���к��еġ�����Ԫ�ء�������BUG
{
	int sum[9] = { 0 };
	switch (n)
	{
	case 0:case 3:case 6:case 27:case 30:case 33:case 54:case 57:case 60:  //����
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
	case 1:case 4:case 7:case 28:case 31:case 34:case 55:case 58:case 61:  //��
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
	case 2:case 5:case 8:case 29:case 32:case 35:case 56:case 59:case 62:  //����
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
	case 9:case 12:case 15:case 36:case 39:case 42:case 63:case 66:case 69:  //��
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
	case 10:case 13:case 16:case 37:case 40:case 43:case 64:case 67:case 70:  //��
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
	case 11:case 14:case 17:case 38:case 41:case 44:case 65:case 68:case 71:  //��
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
	case 18:case 21:case 24:case 45:case 48:case 51:case 72:case 75:case 78:  //����
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
	case 19:case 22:case 25:case 46:case 49:case 52:case 73:case 76:case 79:  //��
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
	case 20:case 23:case 26:case 47:case 50:case 53:case 74:case 77:case 80:  //����
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
// ��ӡ����������BUG
void arr_print(int arr[])
{

	cout << "\n  ����Ϊ��";
	cout << "\n         ��������������������������������������������\n         | ";
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
			cout << "\n         ��������������������������������������������\n";
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
	cout << "\n         ��������������������������������������������\n";
}
//��ѡ����
int row_81_num(int* p, int n)  //�жϱ�ѡ����
{
	int num = 0;
	int row_num = n / 9;            //�ж��ڡ����С�����һ��(���Ϊ��0~8 )
	int before_x, after_x;
	before_x = n - 9 * row_num;     //�� ǰ �ȽϵĴ���  
	after_x = 8 + 9 * row_num - n;  //�� �� �ȽϵĴ���  
	for (int i = 1; i <= before_x; i++) //�� ǰ �Ƚ�
	{
		if (p[n] == p[n - i])
			num++;
	}
	for (int i = 1; i <= after_x; i++)   //�� �� �Ƚ�
	{
		if (p[n] == p[n + i])
			num++;
	}
	num++;       //�����Լ�ҲΪ0
	return num;
}
int* row_81_array(int* p, int n)             //  ��BUG
{
	int num = row_81_num(p, n);   //  num = 1   p[n]����λ��
	int* arr = (int*)calloc(sizeof(int), num); //��ѡ��
	if (arr == NULL)
		exit(-1);
	//�ұ�ѡ����
	int row_num = n / 9;            //�ж��ڡ����С�����һ��(���Ϊ��0~8 )
	int before_x, after_x;
	before_x = n - 9 * row_num;     //�� ǰ �ȽϵĴ���  
	after_x = 8 + 9 * row_num - n;  //�� �� �ȽϵĴ��� 
	int num_test = 0;//�����߼��ж�
	int temporary = 0;
	for (int i = 0; i < num; i++)    //��num����
	{
		for (int j = temporary + 1; j <= 9; j++)//��1��ʼ��,��ֹ�´��ҵ��ظ���  //    
		{
			// 3,1,5 || 0,9,7 || 4,6,8
			num_test = 0;
			for (int k = 1; k <= before_x; k++)//ǰ
			{
				if (j == p[n - k])
				{
					num_test++;
					break;
				}
			}
			for (int k = 1; k <= after_x; k++)//��
			{
				if (j == p[n + k])
				{
					num_test++;
					break;
				}
			}
			if (num_test != 1)
			{
				arr[i] = j;     //���汸ѡ��
				temporary = j;
				break;          //�ҵ���
			}
		}
	}
	return arr;
}
//�����ѡ�ⳤ�ȡ���ר�á�����BUG
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
//����������һ����Ϊ0��Ԫ�ص�λ��(��1��ʼ)������ѡ��
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
//����������һ����Ϊ0��Ԫ�ص�λ��(��1��ʼ)����װԪ��Ϊ0���±������
int arr_last_pos_new(int* p, int n)
{
	int* p2 = p;
	int last = 0;
	for (int i = 0; i < n; i++)  //����
	{
		if (p[i] >= 0)
		{
			last = i;
		}

	}
	last++;
	return last;
}
//���С���ѡ�⡪����һ����
int** num_alternative_row(int* arr)
{
	int* p = pos_get(arr);   //  װԪ��Ϊ0���±������
	int num = pos_num(arr);  //  Ԫ��Ϊ0�ĸ���
	//��ѡ����ͳ��
	int num_2;   //ÿ��Ԫ��Ϊ0�ı������                     
	int** memory = (int**)calloc(sizeof(int) * 9, num); //memory�Ǵ��  memory[i]���Ǳ�ѡ��
	if (memory == NULL)
		exit(-1);
	for (int i = 0; i < num; i++)
	{
		num_2 = row_81_num(arr, p[i]);  //ÿ����ѡ��ı�ѡ����
		//����ռ�
		memory[i] = (int*)calloc(sizeof(int), num_2);
		if (memory[i] == NULL)
			exit(-1);
	}
	cout << endl;
	//���ձ�ѡ��
	for (int i = 0; i < num; i++)  // num��Ԫ��Ϊ0�ĸ���
	{
		memory[i] = row_81_array(arr, p[i]);    // ��ÿ��С�⡰���ա�װ�б�ѡ��������               
	}
	//��ӡ��ѡ��
	/*for (int i = 0; i < num; i++)
	{
		int alternative = arr_num(memory[i]);
		for (int j=0; j < alternative; j++)
		{
			cout <<memory[i][j]<<"   ";
		}
		cout << endl;
	}*/
	return memory;    //���ش�⣬����С��
}
//���С���ѡ��(���в��غ�)�����ڶ�����
int** num_alternative_line(int* arr, int** p_2, int n, int* pos)   //nΪԪ��Ϊ0�ĸ���  p_2�Ǵ��  pos��װ��Ԫ��Ϊ0���±������
{
	//cout << "************ ��� ***************\n";
	//for (int i = 0; i < n; i++)   //   ��ӡ���
	//{
	//	int alternative = arr_num(p_2[i]);
	//	for (int j = 0; j < alternative; j++)
	//	{
	//		cout << p_2[i][j] << "   ";
	//	}
	//	cout << endl;
	//}
	//cout << "************ ������ ***************\n";
	int line_num;                  //�ж��ڡ����С�����һ��(���Ϊ��0~8 )
	int up_x, down_x;
	for (int i = 0; i < n; i++)   //��ӡװ��Ԫ��Ϊ0���±������
	{
		for (int i = 0; i < n; i++)                //   �ô����жԱ�
		{
			line_num = pos[i] / 9;
			up_x = pos[i] / 9;
			down_x = (80 - pos[i]) / 9;
			int alternative = arr_num(p_2[i]);
			for (int j = 0; j < alternative; j++)  //    С��
			{
				//cout << p_2[i][j] << "   ";
				for (int k = 0; k < up_x; k++)        //�� ǰ �Ƚ�
				{
					if (p_2[i][j] == arr[pos[i] - (k + 1) * 9])   //arr��ԭ������pos[0]��3  
					{
						p_2[i][j] = 0;
					}
				}
				for (int k = 0; k < down_x; k++)        //�� �� �Ƚ�
				{
					if (p_2[i][j] == arr[pos[i] + (k + 1) * 9])   //arr��ԭ������pos[0]��3   
					{
						p_2[i][j] = 0;
					}
				}
			}
			//cout << endl;
		}
	}
	for (int i = 0; i < n; i++)//��С�����򣺱���0��0��8   ��������8��0��0�� ����Ϊ0��Ԫ��ǰ�治��Ϊ0
	{
		for (int k = 1; k <= 9; k++)//���ƴ���
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
	//cout << "**********  �����в��غ�Ĵ��(�ѽ��й����С�����)  ************\n";
	//for (int i = 0; i < n; i++)   //   ��ӡ���
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
// ���Ź��񡱱�ѡ��(���к��в��غ�)������������
int** num_alternative_repeat(int* arr, int** p_3, int n, int* p_pos)//nΪԪ��Ϊ0�ĸ���  p_3�Ǵ��  p_pos��װԪ��Ϊ0���±������
{
	int alternative = 0; //С��ı�ѡ����
	// �����ճɹ�
	//cout << "************ ��� ***************\n";
	//for (int i = 0; i < n; i++)   //   ��ӡ���
	//{
	//	alternative = arr_num(p_3[i]);
	//	for (int j = 0; j < alternative; j++)
	//	{
	//		cout << "    " << setw(2) << i + 1 << "-" << j + 1 << "-->  " << p_3[i][j] << "   ";
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	//cout << "************ ������ ***************\n";
	//����
	for (int syn = 0; syn < n; syn++)  // ͬ��С���Ԫ��Ϊ0��λ��
	{                            //p_3�Ǵ��    arr��ԭ����   p_pos[0]-�±�Ϊ3  p_3[0]�ǵ�һ��С��
		switch (p_pos[syn])     //�Ȳ��Ե�һ�����±�Ϊ3����ѡ��Ϊ2��6��8��ɸѡ��ҪΪ2
		{
		case 0:case 3:case 6:case 27:case 30:case 33:case 54:case 57:case 60:  //����

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
		case 1:case 4:case 7:case 28:case 31:case 34:case 55:case 58:case 61:    //��
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
		case 2:case 5:case 8:case 29:case 32:case 35:case 56:case 59:case 62:    //����
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
		case 9:case 12:case 15:case 36:case 39:case 42:case 63:case 66:case 69:  //��
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
		case 10:case 13:case 16:case 37:case 40:case 43:case 64:case 67:case 70:  //��
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
		case 11:case 14:case 17:case 38:case 41:case 44:case 65:case 68:case 71:  //��
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
		case 18:case 21:case 24:case 45:case 48:case 51:case 72:case 75:case 78:  //����
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
		case 19:case 22:case 25:case 46:case 49:case 52:case 73:case 76:case 79:  //��
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
		case 20:case 23:case 26:case 47:case 50:case 53:case 74:case 77:case 80:  //����
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

		}// ���ؽ���
	}
	//������ٴ�����
	for (int i = 0; i < n; i++)//��С�����򣺱���0��0��8   ��������8��0��0�� ����Ϊ0��Ԫ��ǰ�治��Ϊ0
	{
		for (int k = 1; k <= 9; k++)//���ƴ���
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
	//************* ��ӡ��� **********
	//cout << "************ ��� ***************\n";
	//for (int i = 0; i < n; i++)   //   ��ӡ���
	//{
	//	alternative = arr_num(p_3[i]);
	//	for (int j = 0; j < alternative; j++)
	//	{
	//		cout << "    " << setw(2) << i << p_pos[i] << "-" << j + 1 << "-->  " << p_3[i][j] << "   ";
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	//cout << "************ ������ ***************\n";
	return p_3;
}
// �������������
void library_row_2(int** p_4, int n, int num, int* p)// nΪp��Ԫ����ţ�����ǰλ��  numΪp�ĳ���   pΪװԪ��Ϊ0���±������
{
	int a = p[n] / 9;
	int n_2 = n;
	int b = -2;
	int c;
	int d = n;
	while (p[n] / 9 == a)  //ǰ
	{
		b++;
		if (n == 0)  //�ж��Ƿ�Ϊp����ĵ�һ��
			break;
		if (p[n - 1] / 9 != a)   //�ж�ǰ��һ���Ƿ�Ϊͬһ��
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
	while (p[n_2] / 9 == a)  //��
	{
		b++;
		if (n_2 == num - 1)//�ж��Ƿ�Ϊp��������һ��
			break;
		if (p[n_2 + 1] / 9 != a)   //�жϺ���һ���Ƿ�Ϊͬһ��
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
	/*cout << "�����У�" << b << endl;
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
void library_line_2(int** p_4, int n, int num, int* p)// nΪp��Ԫ����ţ�����ǰλ��  numΪp�ĳ���   pΪװԪ��Ϊ0���±������
{
	int n_2 = n;
	int b = 0;
	int c;
	int d = n;
	switch (p[n])
	{
	case 0:case 9:case 18:case 27:case 36:case 45:case 54:case 63:case 72:
		for (n; n >= 0; n--)                  //��ǰ������ͬһ�е��±�
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
		for (n_2; n_2 <= num - 1; n_2++)      //����������ͬһ�е��±�
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
		for (n; n >= 0; n--)                  //��ǰ������ͬһ�е��±�
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
		for (n_2; n_2 <= num - 1; n_2++)      //����������ͬһ�е��±�
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
		for (n; n >= 0; n--)                  //��ǰ������ͬһ�е��±�
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
		for (n_2; n_2 <= num - 1; n_2++)      //����������ͬһ�е��±�
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
		for (n; n >= 0; n--)                  //��ǰ������ͬһ�е��±�
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
		for (n_2; n_2 <= num - 1; n_2++)      //����������ͬһ�е��±�
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
		for (n; n >= 0; n--)                  //��ǰ������ͬһ�е��±�
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
		for (n_2; n_2 <= num - 1; n_2++)      //����������ͬһ�е��±�
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
		for (n; n >= 0; n--)                  //��ǰ������ͬһ�е��±�
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
		for (n_2; n_2 <= num - 1; n_2++)      //����������ͬһ�е��±�
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
		for (n; n >= 0; n--)                  //��ǰ������ͬһ�е��±�
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
		for (n_2; n_2 <= num - 1; n_2++)      //����������ͬһ�е��±�
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
		for (n; n >= 0; n--)                  //��ǰ������ͬһ�е��±�
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
		for (n_2; n_2 <= num - 1; n_2++)      //����������ͬһ�е��±�
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
		for (n; n >= 0; n--)                  //��ǰ������ͬһ�е��±�
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
		for (n_2; n_2 <= num - 1; n_2++)      //����������ͬһ�е��±�
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
//***************** �ر�Ҫע�⡰�У��У��Ź��񡱵Ĳ����㷨��������������⣬����ȥ���һ���㷨��û������ *****************
int main()
{
	//************************************************  ��ʼ������  *********************************************************
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
	int num_0 = pos_num(Sudoku);         //     num_0��Ԫ��Ϊ0�ĸ���
	int* position = pos_get(Sudoku);     //     ����װ��Ԫ��Ϊ0���±������
	int arr_long;                        //     �����鳤��
	arr_print(Sudoku);                   //��ӡ��ʼ����
	int** library_row = num_alternative_row(Sudoku);  // �в��ؼ�������ѡ�⡪����һ��  
	//  ����>������num_alternative_row()������鿴��⣬��Ϊ���رա�״̬,Ҳ���Կ�ÿ��С��ı�ѡ��������Ϊ��������״̬
	int** library_line = num_alternative_line(Sudoku, library_row, num_0, position);  // �в��ء����ڶ���
	//  ����>������num_alternative_line()������鿴��⣬��Ϊ���رա�״̬
	int** library_repeat = num_alternative_repeat(Sudoku, library_line, num_0, position); //  �Ź����ڲ��ء������һ��
	//  ����>������num_alternative_repeat()������鿴��⣬��Ϊ���رա�״̬

//*******************************************   �����㷨  ****************************************************
	
	int num_0_reduce = 0;
	// ѭ����ʼ
	while (num_0_reduce != 38)
	{
		for (int i = 0; i < num_0; i++)  //��ֻ�㡱��ֻ��һ�������Ҵ��ڵ�һ��λ�õ���������ֱ���������
		{
			arr_long = arr_num(library_repeat[i]); //���С�ⳤ��
			if (arr_long == 1)       // �ж��ǲ���ֻ��һ������
			{
				if (library_repeat[i][0] != 0)		  //�ж��ǲ����ڵ�һ��λ��
				{
					Sudoku[position[i]] = library_repeat[i][0];     //����ֱ�����������
					num_0_reduce++;  //��¼�������ֵĸ���

					//������С��������ͬ��ѡ����ȥ��,�����ȥ����ֻʣ��һ�����Ҹպ����ڵ�һλ�����´ξͻ�ֱ�����������
					library_row_2(library_repeat, i, num_0, position);
					library_line_2(library_repeat, i, num_0, position);
					//�Ƚ�����������С�����ء�������������ͬ���ֳ�ȥ������ٽ�����������
					library_repeat[i][0] = 0;   //�������ֺ�Ѷ�Ӧ��ı�ѡ����ȥ
					position[i] = -1;           // ��Ԫ��Ϊ0���±�������Ӧ���±�ȥ��
				}
			}
		}
		for (int i = 0; i < num_0; i++)    // �㡰����ֱ������Ŀ�֮��������⡱
		{
			int last_pos = arr_last_pos(library_repeat[i]);
			for (int gg = 0; gg < last_pos; gg++)
			{
				row_81(Sudoku, position[i], &library_repeat[i][gg]);
				line_81(Sudoku, position[i], &library_repeat[i][gg]);
			}
		}
		//����������������´�ѭ��
		for (int i = 0; i < num_0; i++)
		{
			for (int k = 1; k <= 9; k++)//���ƴ���
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
	//ѭ������

	//*******************************************  �㷨����  ********************************************

	 //��ӡ����(��)
	arr_print(Sudoku);
}
