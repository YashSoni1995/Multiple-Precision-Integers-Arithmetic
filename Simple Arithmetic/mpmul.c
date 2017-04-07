
/*******####################********
         Multiple Precision Multiplication
********####################********
	Author : Yash Soni
E-mail : goldsmith.yashraj@gmail.com
*******#####################*******/

#include <stdio.h>
#define BITS 8

int *radixb(int m, int n){
 	int i,j,q;
	static int x[BITS]; 	
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

int mul[2*BITS+2];

int multiply(int fDigit[], int sDigit[], int base){
	
	int i,j,k,v,u,l;
	
	for(i=0;i<(2*BITS+1);i++){
		mul[i]=0;
	}

	for(j=0;j<BITS;j++){
		int c=0;
		
		for(k=0;k<BITS;k++){
		int v,u;	
		int compute = mul[j+k]+(sDigit[k]*fDigit[j]+c);
		
		if(compute > base-1){
			v = compute%base;
			u = compute/base;
		}else{
			v = compute;
			u = 0;
		}
	
		mul[j+k]=v;
		c=u;
	}
}

	for(l=2*BITS+1;l>=0;l--){
		printf("%d",mul[l]);
	}

	printf("\n");
}

int main(){
	int a,b,base;
	int i,j,k,l;
	int fDigit[BITS],sDigit[BITS];
	printf("Enter First Integer : ");
 	scanf("%d",&a);
 	printf("Enter Second Integer : ");
 	scanf("%d",&b);
 	printf("Enter Base Value : ");
 	scanf("%d",&base);
	
	printf("First Number : ");
	int *first = radixb(a,base);

	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}

	printf("Second Number : ");
	int *second = radixb(b,base);
    
    for(j=0;j<BITS;j++){
		sDigit[j] = *(second+j);
	}
     
    printf("Answer : ");   
	multiply(fDigit,sDigit,base);
	return 0;
}














