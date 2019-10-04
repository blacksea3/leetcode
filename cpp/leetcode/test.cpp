#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int hammingDistance(int x, int y) {
	int *a = (int*)malloc(sizeof(int) * 31);
	int *b = (int *)malloc(sizeof(int) * 31);
	int i = 0;
	int j = 0;
	int sum = 0;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	while(x>0||y>0)
	{
		a[i]=x%2;
		b[j]=y%2;
		i++;
		j++;
	    x=x/2;
		y=y/2;
	}   
	for (i = 0; i < 31; i++)
	{
		if (a[i] != b[i])
		{
			sum += 1;
		}
	}
	return sum;
}
