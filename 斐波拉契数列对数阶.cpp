#include<iostream>
using namespace std;
int**mult(int **a,int **b)
{
	int**c = new int*[2];
    for (int i = 0; i < 2; ++i) 
	        c[i] = new int[2];
	c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    return c;
}

int**matrix_fast(int **a,int n)
{
	if (n==1)
	{
		return a;
		
	}
	else if(n%2!=0)
	{
		return mult(a,matrix_fast(a,n-1));
	}
	else 
	    return mult((matrix_fast(a,n/2)),(matrix_fast(a,n/2)));
}

int main()
{
    int **a = new int*[2];
    for (int i = 0; i < 2; ++i) 
	        a[i] = new int[2];
	int n;
	cin>>n;
	a[0][0]=1;
	a[0][1]=1;
	a[1][0]=1;
	a[1][1]=0;
	int **p = matrix_fast(a,n-1);     //n-1个矩阵相乘
	printf("%d",p[0][0]);
}
