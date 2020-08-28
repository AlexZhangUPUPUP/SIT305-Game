#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include<time.h>

using namespace std;
#define N 40  //������ַ�Ӧ�ò�����40��

struct L     
{
	char ch; //�ַ�
	int num; //�ַ����ֵĴ���
	double f;//�洢�ַ��ĸ��� 
};



//����ʺ���,���أ����鳤�ȣ�
int proba(string str, char c[], long double p[], int count);
//����ʵĸ�������
int search(vector<L> arch, char, int n);
//���뺯�� ���������
long double bma(char c[], long double p[], string str, int number, int size);
//С��ת��Ϊ2����
void change(double x);

int main()
{
	string str;                //����Ҫ�����String�����ַ���
	int number = 0, size = 0;  //number--�ַ����в��ظ����ַ�������size--�ַ�������
	char c[N];                 //���ڴ洢���ظ����ַ�
	long double p[N], output;   //output--������

	cout << "��������������\n����Ҫ������ַ���:";
	getline(cin, str);          //����Ҫ������ַ���
	unsigned time1 = clock();



	size = str.length();         //�ַ�������
	number = proba(str, c, p, size);

	cout.setf(ios::fixed);     
	cout.setf(ios::showpoint);   
	cout.precision(10);

	output = bma(c, p, str, number, size);//���ñ��뺯�������ر�����

	cout << "\n\nת��Ϊ2����֮��";
	change(output);
	unsigned time2 = clock();

	cout << "\n\n����ʱ���ǣ� " << time2 - time1 << endl;

	getchar();
	getchar();
	return 0;
}


//����ʺ���
int  proba(string str, char c[], long double p[], int count)
{
	cout.setf(ios::fixed);   
	cout.setf(ios::showpoint);
	cout.precision(3);

	vector<L>pt;                  
	L temp;                  
	temp.ch = str[0];        
	temp.num = 1;
	temp.f = 0.0;
	pt.push_back(temp);      //�����ַ��������ѹ������ 
	for (int i = 1; i < count; i++)//�������ַ�������ɨ��
	{
		temp.ch = str[i];      
		temp.num = 1;
		temp.f = 0.0;

		for (int j = 0; j < pt.size(); j++)  
		{                                    //���ظ������ַ�������1��������ѭ��
			int k;                           //�����ظ�����ѹ����ַ���������ѭ��
			k = search(pt, str[i], pt.size());
			if (k >= 0)
			{
				pt[k].num++;
				break;
			}
			else
			{
				pt.push_back(temp);
				break;
			}
		}

	}
	for (int i = 0; i < pt.size(); i++)             //���㲻�ظ��ַ����ֵĸ���
	{
		pt[i].f = double(pt[i].num) / count;
	}
	int	number = pt.size();                 
	cout << "���ַ��������£�\n";
	for (int i = 0; i < number; i++)                
	{
		if (count == 0)
		{
			cout << "NO sample!\n";
		}
		else
		{
			c[i] = pt[i].ch;
			p[i] = pt[i].f;
			cout << c[i] << "�ĸ���Ϊ��" << p[i] << endl;
		}
	}
	return number;         //���ز��ظ��ַ��ĸ���
}

//�������������ظ��ַ�����������Ĭ�Ϸ���-1
int search(vector<L> arch, char ch1, int n)
{
	for (int i = 0; i < n; i++)
		if (ch1 == arch[i].ch) return i;
	return -1;
}

//���뺯��
long double bma(char c[], long double p[], string str, int number, int size)
{
	long double High = 0.0, Low = 0.0, high, low, range;
	//High����һ��������������ޣ�Low����һ��������������ޣ�
	//high����һ��������������ޣ�

	//range����һ�����������䳤��
	int i, j = 0;
	for (i = 0; i < number; i++)
		if (str[0] == c[i]) break;      //�����һ���ַ�
	while (j < i)
		Low += p[j++];              //Ѱ�Ҹ��ַ��ĸ�����������
	range = p[j];                   //�õ����ַ��ĸ��ʳ���
	High = Low + range;             //�õ����ַ�������������

	for (i = 1; i < size; i++)          //��ʼ����ڶ����ַ�
		for (j = 0; j < number; j++)    //Ѱ�Ҹ��ַ���c�����е�λ��
		{
			if (str[i] == c[j])
			{
				if (j == 0)         
				{
					low = Low;     
					high = Low + p[j] * range;
					High = high;
					range *= p[j]; 
				}
				else              //�����ַ�������c�����еĵ�һ���ַ�
				{
					float proba_next = 0.0;
					for (int k = 0; k <= j - 1; k++)
						proba_next += p[k];            
					low = Low + range * proba_next;         //������������
					high = Low + range * (proba_next + p[j]);//������������
					Low = low;                         //������������
					High = high;                       //������������
					range *= p[j];                     //�������䳤��
				}
			}
			else continue;                           //������һ���ַ�
		}
	cout << endl;
	cout << "�����ַ����ı���Ϊ:" << Low << endl;
	return Low;
}

//��С��ת��Ϊ2����
void change(double x)
{
	
	double n = 0;                                       //xΪ����С��
	int i = 0;                                          
	int j = 0;
	int a[8];
	for (int i = 0; i < 8; i++)
	{
		a[i] = 0;
	}
	if (x < 0) {
		x = -x;
		j = 1;
	}
	while (i < 8)
	{
		int k;
		n = x * 2;
		k = floor(n);
		a[i] = k;
		x = n - k;
		i = i + 1;

	}
	if (j == 1)
	{
		cout << "-0.";
	}
	else
	{
		cout << "0.";
	}
	for (int k = 0; k < 8;)
	{
		for (int l = 0; l < 4; l++)
		{
			cout << a[k];

			

			k++;
		}
		if (k != 8)
		{
			cout << "";
		}
	}

}

