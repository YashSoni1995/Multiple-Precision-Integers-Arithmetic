
/*******####################********
         Number - Base Implmentation
********####################********
	Author : Yash Soni
E-mail : goldsmith.yashraj@gmail.com
*******#####################*******/

#include <stdio.h>
#include <stdint.h>
#define BITS 128

int radixb(){
	//uint64_t s = 0x259F800E0B938CBA;
	//printf("%u",s); 
	int i,j,q,b;
 	unsigned int a;
	unsigned int x[BITS];
 	printf("Enter Number : ");
 	scanf("%u",&a);
 	printf("Enter Base Value : ");
 	scanf("%d",&b);
 	x[0]=a;
 	q=x[0]/b;
 	x[0]=x[0]-q*b;
 	
 	
 		for(i=1;i<BITS;i++){
 			x[i]=q;
 			q=x[i]/b;
 			x[i]=x[i]-q*b;	 
 			}
 	
for(j=BITS-1;j>=0;j--){
	printf("%d",x[j]);
}
printf("\n");
 	}


int main(){
	radixb();
}
//50009608305755179287422364140743013300
//25004804152877589643711182070371506650
//348125533942972393307803029026422527
//28592861948372299450632177403227823163
