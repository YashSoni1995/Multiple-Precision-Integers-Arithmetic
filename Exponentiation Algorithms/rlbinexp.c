#include <stdio.h>

int main(){

	int g,e;
	printf("Enter value of element g belong to G : ");
	scanf("%d",&g);

	printf("Enter value of e>=1 : ");
	scanf("%d",&e);

	int A = 1;
	int S = g;

	while(e!=0){
		if(e%2!=0){
			A = A*S;
		}
		
		e = e/2;
		
		if(e!=0){
			S = S*S;
		}
	}
	printf("Value of g^e = %d\n",A);
}