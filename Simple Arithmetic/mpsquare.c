
/*******####################********
         Multiple - Precision Squaring
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

int sqr[2*BITS+2];

int square(int fDigit[], int base){
	
	int i,j,k,v,u,l;
	
	for(i=0;i<(2*BITS+1);i++){
		sqr[i]=0;
	}

	for(j=0;j<BITS;j++){
		int c;
		int v,u;
		int compute = sqr[2*j]+fDigit[j]*fDigit[j];
		
		if(compute > base-1){
			v = compute%base;
			u = compute/base;
		}else{
			v = compute;
			u = 0;
		}

		sqr[2*j]=v;
		c=u;	
		
		for(k=j+1;k<BITS;k++){
			
			int acompute = sqr[j+k]+(2*fDigit[k]*fDigit[j]+c);
		
			if(acompute > base-1){
				v = acompute%base;
				u = acompute/base;
			}else{
				v = acompute;
				u = 0;
			}
	
			sqr[j+k]=v;
			c=u;
		}
    	sqr[j+BITS] = u;
	}

	for(l=2*BITS+1;l>=0;l--){
		printf("%d",sqr[l]);
	}

	printf("\n");
}

int main(){
	int a,b,base;
	int i,j,k,l;
	int fDigit[BITS],sDigit[BITS];
	printf("Enter the Integer : ");
 	scanf("%d",&a);
 	
 	printf("Enter Base Value : ");
 	scanf("%d",&base);
	
	printf("Number : ");
	int *first = radixb(a,base);

	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}

	printf("Answer : ");   
	square(fDigit,base);
	return 0;
}














