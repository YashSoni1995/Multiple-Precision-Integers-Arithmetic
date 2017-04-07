#include <stdio.h>
#define BITS 10


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

int main(){

	int i,j,k,n;
	int g,e,fDigit[BITS];

	printf("Enter value of element g belong to G : ");
	scanf("%d",&g);

	printf("Enter value of e>=1 : ");
	scanf("%d",&e);

	int *first = radixb(e,2);

 	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}

	for(j=BITS-1;j>=0;j--){
		if(fDigit[j]!=0 ){
    		n = j;printf("%d\n",n );
    		break;
    	} 
    }

	int A = 1;
	
	for(k=n;k>=0;k--){
		A = A*A;
		if(fDigit[k]==1){
			A = A*g;
		}
	}

	printf("Value of g^e = %d\n",A);
}