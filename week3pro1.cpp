#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A[3],max,min;
	scanf("%d",&A[0]);
	min = A[0];
	max = A[0];
	for(int i=1;i<3;i++)
	{
		scanf("%d",&A[i]);
		if(A[i]>max)
		{
			max = A[i];
		}
		if(A[i]<min)
		{
			min = A[i];
		}
	}
	printf("%d", max + min);

	return 0;
}