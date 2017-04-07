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

	int i,j,k,l,m,n;
	int g,e,fDigit[BITS];

	printf("Enter value of element g belong to G : ");
	scanf("%d",&g);

	printf("Enter value of e>=1 : ");
	scanf("%d",&e);

	printf("Enter value of k : ");
	scanf("%d",&k);	

	int base = power(2,k); 
	printf("Base(2^k) = %d\n",base);
	printf("Radix representation of e = ");

	int *first = radixb(e,base);

 	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}

	for(j=BITS-1;j>=0;j--){
		if(fDigit[j]!=0 ){
    		n = j;printf("%d\n",n );
    		break;
    	} 
    }

    int g_arr[base];
  	g_arr[0] = 1;

  	for(l=1;l<base;l++){
  		g_arr[l] = g_arr[l-1]*g;

  	}

	int A = 1;
	
	for(m=n;m>=0;m--){
		A = power(A,base);
		A = A*g_arr[fDigit[m]];
	}

	printf("Value of g^e = %d\n",A);
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