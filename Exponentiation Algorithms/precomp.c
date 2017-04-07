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

	int i,j,k,p,q,n,s,t,r,Q;
	int g,e,h,fDigit[BITS];

	printf("Enter value of element g : ");
	scanf("%d",&g);

	printf("Enter value of h : ");
	scanf("%d",&h);

	printf("Enter value of e>=1 : ");
	scanf("%d",&v);

	printf("Enter value of e>=1 : ");
	scanf("%d",&a);

	printf("Enter value of e>=1 : ");
	scanf("%d",&b);

	for(i=0;i<h;i++){
		g_arr[i] = power(g,power(2,i*a));
	}

	for(j=1;j<power(2,h)){

		int *first = radixb(i,2);

 		for(i=0;i<BITS;i++){
			fDigit[i] = *(first+i); 	
		}

		int product=1;
		for(k=0;k<h;k++){
			product = product*power(g_arr[k],fDigit[k]);
		} 
		G[0][i] = product;

		for(p=1;p<v;p++){
			G[p][i] = power(G[0][i],power(2,p*b));
		}
	}

	
	
	

	printf("A = %d\n",Answer);
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