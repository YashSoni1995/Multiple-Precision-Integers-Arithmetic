#include <stdio.h>
#define BITS 15

int main(){

	int i,j,s;
	int g,k,t;

	printf("Enter value for k : ");
	scanf("%d",&k);

	printf("Enter value of g : ");
	scanf("%d",&g);
	
	printf("Number of Digits in base e_SR(k) : ");
	scanf("%d",&t);

	int e[t];
	
	printf("Enter values of e in SR(%d) from right to left : ",k);
	for(s=0;s<t;s++){
		scanf("%d",&e[s]);
	}
	
	int g_arr[t];
	g_arr[1]=g;
	
	for(i=2;i<=k;i++){
		g_arr[power(2,i)-1]	= power(g_arr[power(2,i-1)-1],2)*g;
		printf("%d\n",g_arr[power(2,i)-1]);
	}

	int A=1;

	for(j=t-1;j>=0;j--){
		printf("j=%d\n",j);
		A = A*A;
		printf("A=%d\n",A);
		if(e[j]!=0){
			A = A*g_arr[e[j]];
			printf("a=%d\n",A);
		}
	}
	printf("A = %d\n",A);
}

int power(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}