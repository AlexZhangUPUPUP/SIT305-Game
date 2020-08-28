#include<iostream>
#include<string>
#include <windows.h>
#include<stdio.h>
#include<time.h>
using namespace std;
int sizeofOri; //������ַ����ĳ���
string OutPut = " ";
//adhkjahsdjkhakjhdjkhasjdkhajkshdjk ���ڲ��Ե��ַ���
int sizeofOut = 0;

double rateOfCom =0;
struct huffTree {
	int parent;
	int lchild;
	int rchild;
	int weight;
	string flag;
};//��������

struct Lowest_Node {
	char ch;
	int ch_num;
};


void coding(int length, huffTree tree[], int n, int &a, int &b) {
	int i;
	int r, s;
	r = s = length;
	for (i = 0; i < n; i++) {
		if ((tree[i].weight < r) && (tree[i].parent == -1)) {
			r = tree[i].weight;
			a = i;
		}
	}
	for (i = 0; i < n; i++) {
		if ((tree[i].weight < s) && (i != a) && (tree[i].parent == -1)) {
			s = tree[i].weight;
			b = i;
		}
	}
}

void frequency(string str) {
	int length = str.length();                    //����
	Lowest_Node *node = new Lowest_Node[length];  //������0�ڵ�
	int i, j;            
	for (i = 0; i < length; i++) {
		node[i].ch_num = 0;         //��ʼ��Ƶ��
	}
	int char_type_num = 0;          //��ʼΪ0���ַ�
	for (i = 0; i < length; i++) {          //ѭ�������ַ���
		for (j = 0; j < char_type_num; j++) {
			if (str[i] == node[j].ch || (node[j].ch >= 'a'&&node[j].ch <= 'z'&&str[i] + 32 == node[j].ch))
				break;
		}
		if (j < char_type_num) { node[j].ch_num++; }
		else {
			if (str[i] >= 'A'&& str[i] <= 'Z')
				node[j].ch = str[i] + 32;
			else node[j].ch = str[i];
			node[j].ch_num++;
			char_type_num++;
		}
	}

	//��Ƶ�ȴӴ�С����
	for (i = 0; i < char_type_num; i++) {
		for (j = i; j < char_type_num; j++) {
			if (node[j].ch_num < node[j + 1].ch_num) {//���ǰһ��С�ں�һ��������
				int temp;                      
				char ch_temp;                   
				temp = node[j].ch_num;
				ch_temp = node[j].ch;
				node[j].ch_num = node[j + 1].ch_num;
				node[j].ch = node[j + 1].ch;
				node[j + 1].ch_num = temp;
				node[j + 1].ch = ch_temp;
			}
		}
	}

	huffTree *huff = new huffTree[2 * char_type_num - 1];
	huffTree temp;
	string *code = new string[2 * char_type_num - 1];
	for (i = 0; i < 2 * char_type_num - 1; i++) {             //�ڵ��ʼ��
		huff[i].parent = -1;
		huff[i].lchild = -1;
		huff[i].rchild = -1;
		huff[i].flag = -1;
	}
	for (j = 0; j < char_type_num; j++) {               
		huff[j].weight = node[j].ch_num;
	}
	int min1, min2;
	for (int k = char_type_num; k < 2 * char_type_num - 1; k++) {       //��ֵ0�����ϵĽڵ�
		coding(length, huff, k, min1, min2);
		huff[min1].parent = k;
		huff[min2].parent = k;
		huff[min1].flag = "0";
		huff[min2].flag = "1";
		huff[k].lchild = min1;
		huff[k].rchild = min2;
		huff[k].weight = huff[min1].weight + huff[min2].weight;
	}
	for (i = 0; i < char_type_num; i++) {
		temp = huff[i];
		while (1) {
			code[i] = temp.flag + code[i];
			temp = huff[temp.parent];
			if (temp.parent == -1)break;
		}
	}
	cout << "\n\n�ַ�����ÿ���ַ���huffman����Ϊ��" << endl;
	for (i = 0; i < char_type_num; i++) {
		cout << node[i].ch << " " << code[i] << endl;
	}
	cout << "\n\n�ַ����ı���Ϊ��" << endl;
	for (i = 0; i < length; i++) {
		for (j = 0; j < char_type_num; j++) {
			if (str[i] == node[j].ch) {
			
				cout << code[j] << ""; //�������

				int k = code[j].size();//�õ�����ĳ���

				sizeofOut = sizeofOut + k;
		
			
			}
		}
	}

}

int main() {

	int length = 0;               //�ַ������ȣ�
	string str;                 //Ŀ���ַ�����



	cout << "���ǹ���������\n�������ַ�����";
	cin >> str;


	sizeofOri = str.size() * 8; //ԭ�����ڴ�
	unsigned time1 = clock();
	

	frequency(str);              //������ַ�����Ƶ��
	unsigned time2 = clock();

	rateOfCom = ((double) sizeofOut) / ((double)sizeofOri);//ѹ���ȣ�ѹ�����/ѹ��ǰ��
	cout << "\nԭ�����ڴ�Ϊ��" << sizeofOri << endl;
	cout << "ѹ������ڴ�Ϊ��" << sizeofOut << endl;
	cout << "\n\nѹ����Ϊ��" << rateOfCom << endl;
	cout << "\n\n����ʱ���ǣ� " << time2 - time1 << endl;

	getchar();
	getchar();
	return 0;
}