#include <iostream>
#include<string>
#include<vector>
#include<time.h>

using namespace std;

vector<string> DC;
bool exist(string s)  {

	for (int i = 0; i < DC.size(); i++) {

		if (DC[i] == s)
		{
			
			return true;
		}
	
	}
	return false;
}//�ж��µ��ַ��Ƿ�������ֵ䵱��

int outCode(string s){

	for (int i = 0; i < DC.size(); i++) {
		if (DC[i] == s){

			cout << "����ַ����ı�����:  " << i <<"  ����ַ��ǣ�"<<" "<< s<< endl;
			return i;
		
		}
	}
	return 0;
}//����ַ����ı���

int main() {

	double Compressionrate;
	string  ss;
	cout << "������LZW��������Ҫѹ�����ַ���:  ";
	cin>>ss;
	unsigned time1 = clock();

	int sizeofOriginal = ss.size();
	int sizeofOutput = 0;

	char c = ss[0];
	string sd;
	sd = c; 

	DC.push_back(" "); //0

	DC.push_back("s");//1
	DC.push_back("f");//2
	DC.push_back("d");//3
	DC.push_back("g");//4
  
	

	char p = ss[0];
	string first;
	first = p;

	string kk;
	
	string next;

	for (int i = 0; i < ss.size()-1; i++) {

		char m = ss[i + 1];
		
		next = m;

		string ff = first + next;

		if (exist(ff) == true){
		    
			first = first + next;

		}
		else{

			int size =  outCode(first); //�õ�����ַ��ĳ��̣�������ַ�
			if (size >=10)
			{
				size = 2;
			}
			else
			{
				size = 1;
			}
			sizeofOutput = sizeofOutput + size;


			string mm = first + next;
 
			DC.push_back(mm);

			first = next;

			
		}
	}
	outCode(first);
	unsigned time2 = clock();

	cout << "\n\n�������ֵ������" << endl << endl << endl;
	for (int i = 0; i < DC.size(); i++) {
		
		cout << "���룺" << i << "   �ַ�����" << DC[i] << endl;
	}


	Compressionrate = ((double)sizeofOutput) / ((double)sizeofOriginal);
	cout << "\n\nԭ���Ĵ�С��" << sizeofOriginal << endl;
	cout << "����Ĵ�С��" << sizeofOutput << endl;
	cout << "ѹ����Ϊ:  " << Compressionrate << endl;
	cout << "\n����ʱ���ǣ� " << time2 - time1 << endl;
	getchar();
	getchar();

	return 0;



}