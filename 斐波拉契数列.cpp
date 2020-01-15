#include<iostream>
#include<cstdio>
using namespace std;

int Fib1(int x);
int Fib2(int x);
int Fib3(int x);
int Fib4(int x,int ,int );
int Fib5(int a,int b,int p,int q,int x);

int main()
{
	int a;
	cin>>a;
	cout<<Fib5(1,0,0,1,a)<<endl;
	
 } 

int Fib1(int x)     //递归，时间复杂度为O(2^n),空间复杂度O(n) 
{
	if(x==1||x==2)
		return 1;
	if(x<1)
		return -1;
	if(x>2)
		return Fib1(x-1)+Fib1(x-2);	
}

int Fib2(int x)      //利用数组记录了前两项的值，时间复杂度为O(n),空间复杂度O(n)
{
	int *a= new int[x-1];
	a[0]=1;
	a[1]=1;
	for(int i=2;i<x;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	return a[x-1];	
}

int Fib3(int x)      //迭代法，时间复杂度为O(n),空间复杂度O(1)
{
	if(x==1||x==2)
		return 1;
	if(x<1)
		return -1;
	int s1=1,s2=1;
	if(x>2)
	{
		for(int i=3;i<=x;i++)
		{
			s2=s1+s2;
			s1=s2-s1;
		}
	} 
	return s2; 
}

int Fib4(int x,int a,int b)     //a=1,b=0,时间复杂度为O(n),空间复杂度O(1)
{
	if(x==1)
	{
		return a;
	}
	return Fib4(x-1,a+b,a);
}

int Fib5(int a,int b,int p,int q,int x)      //a=1,b=0,p=0,q=1,时间复杂度为O(logn)
{
    if (x == 0)
        return b;
    else
        if (x%2)
            return Fib5(b*p+a*q+a*p,b*p+a*q,p,q,x-1);
        else
            return Fib5(a,b,p*p+q*q,q*q+2*p*q,x/2);
}


