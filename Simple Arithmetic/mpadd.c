
/*******####################********
         Multiple Precision Addition
********####################********
	Author : Yash Soni
E-mail : goldsmith.yashraj@gmail.com
*******#####################*******/

#include <stdio.h>
#define BITS 8



int *radixb(int m, int n){
 	int i,j,q;
	static int x[10]; 	
 	x[0]=m;
 	q=x[0]/n;
 	x[0]=x[0]-q*n;
 	
 	for(i=1;i<BITS;i++){
 		x[i]=q;
 		q=x[i]/n;
 		x[i]=x[i]-q*n;	 
 	}
 	
	for(j=BITS-1;j>=0;j--){
		printf("%d",x[j]);
	}

	printf("\n");
	return x; 	
}


int main(){
	int a,b,base;
	int i,j,k,l,sum[BITS+1],c=0;
	int fDigit[BITS],sDigit[BITS];

	printf("Enter First Integer : ");
 	scanf("%d",&a);
 	printf("Enter Second Integer : ");
 	scanf("%d",&b);
 	printf("Enter Base Value : ");
 	scanf("%d",&base);
	
	int *first = radixb(a,base);

	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}
	
	int *second = radixb(b,base);
    
    for(j=0;j<BITS;j++){
		sDigit[j] = *(second+j);
	}
       
	for(k=0;k<BITS;k++){
		sum[k] = (fDigit[k]+sDigit[k]+c)%base;
		if((fDigit[k]+sDigit[k]+c)<base){
			c=0;
		} 
		else{
			c=1;
		}
	}

	sum[BITS]=c;

	for(l=BITS;l>=0;l--){
	printf("%d",sum[l]);
	}
	
	return 0;
}














