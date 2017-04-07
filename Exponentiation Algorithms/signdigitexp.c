#include <stdio.h>
#define BITS 12

int main(){

	int i,j,k;
	int e[BITS];

	printf("Enter values of e_2 from right to left : ");
	for(i=0;i<BITS;i++){
		scanf("%d",&e[i]);
	}
	
	int c[BITS+1];
	c[0]=0;
	int d[BITS];

	for(j=0;j<BITS;j++){
		c[j+1] = (e[j]+e[j+1]+c[j])/2;
		d[j] = e[j]+c[j]-(2*c[j+1]);
	}
	
	for(k=BITS-1;k>=0;k--){
		printf("%d",d[k]);
	}
}