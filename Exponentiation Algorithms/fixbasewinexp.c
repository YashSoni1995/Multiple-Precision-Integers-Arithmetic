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

	int i,j,k,p,q,n;
	int g,e,h,fDigit[BITS];

	printf("Enter value of element g : ");
	scanf("%d",&g);

	printf("Enter value of e>=1 : ");
	scanf("%d",&e);

	printf("Enter value of h : ");
	scanf("%d",&h);

	int *first = radixb(e,h);

 	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}

	for(j=BITS-1;j>=0;j--){
		if(fDigit[j]!=0 ){
    		n = j;printf("%d\n",n );
    		break;
    	} 
    }
	int b[n+1];
    for(k=0;k<=n;k++){
    	b[k] = power(h,k);
		printf("Value of b[%d] = %d\n",k,b[k]);
}
	int A = 1, B = 1;
	
	
	for(p=h-1;p>=1;p--){
		for(q=0;q<=n;q++){
			printf("%d %d %d\n",p,q,fDigit[q]);
			if(fDigit[q]==p){
				B = B*power(g,b[q]);
				//printf("%d\n",B);
			}
		}
		A = A*B;
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