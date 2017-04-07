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

	
	int q[BITS];
	int r[BITS],rem;
	int a,b,m,base;
	int i,j,k,l;
	int n,t,U[n];
	int mDigit[BITS],fDigit[BITS];

	printf("Enter The Number: ");
 	scanf("%d",&a);
 	printf("Enter Modulo (m): ");
 	scanf("%d",&m);
 	printf("Enter Base Value (base) : ");
 	scanf("%d",&base);

 	int *mst = radixb(m,base);

 	for(i=0;i<BITS;i++){
		mDigit[i] = *(mst+i); 	
	}

	for(j=BITS-1;j>=0;j--){
		if(mDigit[j]!=0){
    		t = j+1;
    		printf("t = %d\n",t );
    		break;
    	} 
    }

    int x = power(base,t) - m;
    
    printf("c = ");
	
	int *frst = radixb(x,base);

 	for(k=0;k<BITS;k++){
		fDigit[k] = *(frst+k); 	
	}

	q[0] = a/power(base,t);
	
	r[0] = a - q[0]*power(base,t);
	
	rem = r[0];
	
	n = 0;

	while (q[n]>0){
		q[n+1] = q[n]*x/power(base,t);
		
		r[n+1] = (q[n]*x)-(q[n+1]*power(base,t));
		
		n = n+1;
		rem = rem + r[n];
		
	}

	while(rem>=m){
		rem = rem-m;
	}

	printf("Special Form Reduction = ");
	int *ans = radixb(rem,base);
 	
}

int power(int base, int exp){
    
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
