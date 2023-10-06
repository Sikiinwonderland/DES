#include<iostream>
#include <random>
#include <sstream>
#include <bitset>
using namespace std;

void makeK(bool a[])
{
	std::mt19937 rng; // 随机数生成器
	std::uniform_int_distribution<int> distr(0, 1); // 分布范围为0到1
	for (int i = 0; i < 10; i++)
	{
		a[i] = static_cast<bool>(distr(rng));
	}
}

int shift(bool a[],int len)
{
	bool c=a[0];
	bool d=a[len/2];
	for (int i = 1; i < len/2; i++)
	{
		a[i - 1] = a[i];
	}
	a[len/2-1] = c;
	for (int j = len / 2 + 1; j < len; j++)
	{
		a[j - 1] = a[j];
	}
	a[len - 1] = d;
	return 0;
}

void p10(bool a[],bool b[])
{
	b[0] = a[2];
	b[1] = a[4];
	b[2] = a[1];
	b[3] = a[6];
	b[4] = a[3];
	b[5] = a[9];
	b[6] = a[0];
	b[7] = a[8];
	b[8] = a[7];
	b[9] = a[5];
}

void p81(bool b[], bool c[])
{
	c[0]=b[5];
	c[1]=b[2];
	c[2]=b[6];
	c[3]=b[3];
	c[4]=b[7];
	c[5]=b[4];
	c[6]=b[9];
	c[7]=b[8];
}

void p82(bool b[], bool c[])
{
	c[0] = b[5];
	c[1] = b[2];
	c[2] = b[6];
	c[3] = b[3];
	c[4] = b[7];
	c[5] = b[4];
	c[6] = b[1];
	c[7] = b[0];
}

void swapIP(bool a[], bool b[])//第一个为置换后的数码
{
	a[0] = b[1];
	a[1] = b[5];
	a[2] = b[2];
	a[3] = b[0];
	a[4] = b[3];
	a[5] = b[7];
	a[6] = b[4];
	a[7] = b[6];
}

void swapPI(bool a[], bool b[])//第二个为置换后的数码
{
	b[0] = a[3];
	b[1] = a[0];
	b[2] = a[2];
	b[3] = a[4];
	b[4] = a[6];
	b[5] = a[1];
	b[6] = a[7];
	b[7] = a[5];
}

void swap(bool a[])//左右交换
{
	for (int i = 0; i < 4; i++)
	{
		int c = a[i];
		a[i] = a[i + 4];
		a[i + 4] = c;
	}
}

void swapF(bool a[],bool b[])
{
	a[0] = b[1];
	a[1] = b[3];
	a[2] = b[2];
	a[3] = b[0];
}

void Right(bool m[],bool R[])
{
	for (int i = 0; i < 4; i++)
	{
		R[i] = m[i + 4];
	}
}

void huge(bool R[],bool H[])
{
	H[0] = R[3];
	H[1] = R[0];
	H[2] = R[1];
	H[3] = R[2];
	H[4] = R[1];
	H[5] = R[2];
	H[6] = R[3];
	H[7] = R[0];
}

void F(bool H[],bool k1[],bool Y[])
{
	for (int i = 0; i < 8; i++)
	{
		Y[i] = H[i] ^ k1[i];
	}
}

void XOR(bool mi[], bool R[])
{
	bool L[4];
	for (int i = 0; i < 4; i++)
	{
		L[i] = mi[i] ^ R[i];
	}
	for (int i = 0; i < 4; i++)
	{
		mi[i] = L[i];
	}
}

void BOX(bool Y[], bool S[])
{
	int i = Y[0]*2 + Y[3], j = Y[1]*2 + Y[2], k = Y[4]*2+Y[7], n = Y[5]*2+Y[6];
	int P[4][4] = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,0,2}};
	int Q[4][4] = {{0,1,2,3},{2,3,1,0},{3,0,1,0},{2,1,0,3}};
	if (P[i][j] == 0) {
		S[0] = 0;
		S[1] = 0;
	}
	else if (P[i][j] == 1) {
		S[0] = 0; 
		S[1] = 1;
	}
	else if(P[i][j] == 2) {
	    S[0] = 1;
	    S[1] = 0;
    }
    else if(P[i][j] == 3) {
        S[0] = 1;
        S[1] = 1;
    }
	if (Q[k][n] == 0) {
		S[2] = 0;
		S[3] = 0;
	}
	else if (Q[k][n] == 1) {
		S[2] = 0;
		S[3] = 1;
	}
	else if (Q[k][n] == 2) {
		S[2] = 1;
		S[3] = 0;
	}
	else if (Q[k][n] == 3) {
		S[2] = 1;
		S[3] = 1;
	}
}

int makemi(bool ming[],bool k1[],bool k2[])
{
	bool  mi[8],R[4],H[8],Y[8],S[4],X[4];
	
	swapIP(mi, ming);  //初始置换
	Right(mi, R);//获得右半部分
	huge(R, H);//扩展
	F(H, k1, Y);//k1加密
	BOX(Y, S);//替换盒
	swapF(X, S);//直接置换
	XOR(mi, X);//异或
	swap(mi);//交换
	Right(mi, R);//重复
	huge(R, H);
	F(H, k2, Y);//k2加密
	BOX(Y, S);
	swapF(X, S);
	XOR(mi, X);
	swapPI(mi, ming);//ming为最后密文

	return 0;
}

int makeming(bool ming[], bool k1[], bool k2[])
{
	bool  mi[8], R[4], H[8], Y[8], S[4], X[4];
	swapIP(mi, ming);
	Right(mi, R);
	huge(R, H);
	F(H, k2, Y);
	BOX(Y, S);
	swapF(X, S);
	XOR(mi, X);
	swap(mi);
	Right(mi, R);
	huge(R, H);
	F(H, k1, Y);
	BOX(Y, S);
	swapF(X, S);
	XOR(mi, X);
	swapPI(mi, ming);
	return 0;
}

string Binary(int x)
{
	string s = "";
	while (x) {
		if (x % 2 == 0) s = '0' + s;
		else s = '1' + s;
		x /= 2;
	}
	return s;
}

int Build(bool ming[], bool mi[])
{
	string str, s;
	for (int i = 0; i < 8; i++) {
		str += std::to_string(ming[i]);
	}
	for (int i = 0; i < 8; i++) {
		s += std::to_string(mi[i]);
	}
	if (str == s)
		return 1;
	else
		return 0;
}

void Solve(bool ming[],bool mi[])
{
	bool k[10], b[10], k1[8], k0[8], k2[8];
	string s;
	for (int i = 0; i <= 1023; i++)
	{
		s = Binary(i);
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '1')
				k[i+10-s.length()] = 1;
		}
		for (int i = 0; i < 10; i++)
		{
			if (k[i] == 1)
				k[i] = 1;
			else if (k[i] != 1)
				k[i] = 0;
		}
		p10(k, b);
		shift(b, sizeof(b) / sizeof(b[0]));
		p81(b, k1);//得到k1
		p81(b, k0);
		shift(k0, sizeof(k0) / sizeof(k0[0]));
		p82(k1, k2);//得到k2
		makemi(ming, k1, k2);
		int j = Build(ming, mi);
		if (j == 1)
		{
			for (int i = 0; i < 10; i++)
			{
				cout << k[i];
			}
			cout << endl;
		}
		fill(k, k + 10, 0);
	}
}

void start()
{
	bool a[10], b[10], k1[8], k0[8], k2[8], ming[8],mi[8];
	string s;
	makeK(a);//获得K
	p10(a, b);
	shift(b, sizeof(b) / sizeof(b[0]));
	p81(b, k1);//得到k1
	p81(b, k0);
	shift(k0, sizeof(k1) / sizeof(k1[0]));
	p82(k1, k2);//得到k2
	cout << "请选择加密或是解密，加密输入1，解密输入2,获取密钥输入3" << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "请输入8位明文" << endl;
		cin >> s;
		if (s.size() > 8) {
			cout << "请输入8位明文" << endl;
			start();
		}
		for (int i = 0; i < 8; i++)
		{
			if (s[i] == '0')
				ming[i] = 0;
			else if (s[i] == '1')
				ming[i] = 1;
			else if (s[i] != '0' && s[i] != '1')
			{
				cout << "请输入0或1" << endl;
				start();
			}
		}
		makemi(ming, k1, k2);
		cout << "密文为：";
		for (int i = 0; i < 8; i++)
		{
			cout << ming[i];
		}
	}
	else if(n==2)
	{
		cout << "请输入8位密文" << endl;
		cin >> s;
		if (s.size() > 8) {
			cout << "请输入8位密文" << endl;
			start();
		}
		for (int i = 0; i < 8; i++)
		{
			if (s[i] == '0')
				ming[i] = 0;
			else if (s[i] == '1')
				ming[i] = 1;
			else if (s[i] != '0' && s[i] != '1')
			{
				cout << "请输入0或1" << endl;
				start();
			}
		}
		makeming(ming, k1, k2);
		cout << "明文为：";
		for (int i = 0; i < 8; i++)
		{
			cout << ming[i];
		}
	}
	else if (n == 3)
	{
		cout << "请输入8位明文" << endl;
		cin >> s;
		if (s.size() > 8) {
			cout << "请输入8位明文" << endl;
			start();
		}
		for (int i = 0; i < 8; i++)
		{
			if (s[i] == '0')
				ming[i] = 0;
			else if (s[i] == '1')
				ming[i] = 1;
			else if (s[i] != '0' && s[i] != '1')
			{
				cout << "请输入0或1" << endl;
				start();
			}
		}
		cout << "请输入8位密文" << endl;
		cin >> s;
		if (s.size() > 8) {
			cout << "请输入8位密文" << endl;
			start();
		}
		for (int i = 0; i < 8; i++)
		{
			if (s[i] == '0')
				mi[i] = 0;
			else if (s[i] == '1')
				mi[i] = 1;
			else if (s[i] != '0' && s[i] != '1')
			{
				cout << "请输入0或1" << endl;
				start();
			}
		}
		Solve(ming, mi);
	}
	cout << endl;
	start();
}

int main()
{
	start();
	return 0;
}