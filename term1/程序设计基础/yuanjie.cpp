#include<iostream>
#include <algorithm>
#include<cmath>
using namespace std;

int num = 0;//定义全局变量num 用来记录f g调用的总次数

int myzhi(int n)//该函数用于判断是否为质数,返回1则为质数 返回0则不为质数
{
	if (n == 2)
	{
		return 1;
	}
	int i = 2;
	for (; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
    return i == n;
}

long long int myf(long long int x)//给出函数f
{
	num++;
	long long int a;
	a = min(x + ceil(x / 10) + 123456, 2 * pow(10, 9) - x);
	return a;
}

long long int myg(long long int x)//给出函数g
{
	num++;
	long long int n = x;
	int a[15];
	int i = 0;
	while (n > 0)
	{
		i++;
		a[i] = n % 10;
		n /= 10;
	}
	int sum = 0;
	//思路  第一遍循环 找到第一个偶数（不为零，从高到低找）  第二遍循环  去除后面的奇数
	int j = i;
	for (; j >= 1; j--)
	{
		if (a[j] % 2 == 0 && a[j] != 0)
		{
			break;
		}
		else;
	}
	int m = 0;
	for (int k = 1; k <= j; k++)
	{
		if (a[k] % 2 == 0)
		{
			sum += a[k] * pow(10, m);
			m++;
		}
		else;
	}
	return sum;
}

long long int myh(long long int x)//给出函数h
{
	int result = 0;
	if (myzhi(num) == 1)
	{
		result = myf(myg(x));
		cout << "fg" << endl;
		return result;
	}
	if (myzhi(num) == 0)
	{
		result = myg(myf(x));
		cout << "gf" << endl;
		return result;
	}
    return result;
	
}
int main()
{
	long long int x;
	int m;
	cin >> x >> m;
	char a;
	for (int i = 1; i <= m; i++)
	{
		cin >> a;
		if (a == 'f')
		{
			x = myf(x);
			cout << x << endl;

		}
		else if (a == 'g')
		{
			x = myg(x);
			cout << x << endl;
		}
		else if (a == 'h')
		{
			x = myh(x);
			cout << x << endl;
		}
	}
	cout << x;
	return 0;
	cout << myzhi(1) << '\n';

}
