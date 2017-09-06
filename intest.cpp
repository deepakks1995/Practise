#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main()
{
    long int n,k;
    n=readInt();
    k=readInt();
    int i=0;
    long int count=0,A[n];
    while(i!=n)
    {
        A[i]=readInt();
        if(A[i]%k==0)
            count++;
        i++;
    }
    cout<<count;
}
