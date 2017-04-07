#include <stdio.h>
#include <stdlib.h>
#define BITS 10

int main(){

	int a,b,t,g=1;
	printf("Enter First Positive Integer : ");	
	scanf("%d",&a);	
	printf("Enter Second Positive Integer : ");	
	scanf("%d",&b);

	while((a%2==0) && (b%2==0)){
		a = a/2;
		b = b/2;
		g = 2*g;
	}

	while(a!=0){
		while(a%2==0){
			a = a/2;
		}
		while(b%2==0){
			b = b/2;
		}
		t = abs(a-b)/2;
		if (a>=b)
		{
			a = t;
		}else{
			b = t;
		}
	}
	printf("%d\n",g*b); 
}


