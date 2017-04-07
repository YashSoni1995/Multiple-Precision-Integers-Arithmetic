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

	int m,b,g=0,m_dash,n,T,U[BITS],p;
	
	int i,j,k,l,sum[BITS+1],c=0,d;
	int fDigit[BITS],sDigit[BITS],tDigit[2*BITS];


	printf("**** PLEASE ENTER m AND b SO THAT gcd(m,b)=1 ****\n" );
	printf("Enter Modulo (m): ");
 	scanf("%d",&m);
 	printf("Enter Base Value (b) : ");
 	scanf("%d",&b);
 	
 	int *first = radixb(m,b);

 	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}
 	
 	for(k=BITS-1;k>=0;k--){
		if(fDigit[k]!=0){
    		n = k+1;
    		printf("n = %d\n",n );
    		break;
    	} 
    }

 	int R = power(b,n);
printf("Value of R = %d\n",R);
for(i=0; ; i++){
 	if(((i*m)+1)%b==0){
 		m_dash = i;
 		printf("Value of m' = %d\n",m_dash);
 		break;
 	}
 }

 	printf("Enter Value of T (<%d) : ",m*R);
 	scanf("%d",&T);
	int *second = radixb(T,b);
	
	for(j=0;j<BITS;j++){
		tDigit[j] = *(second+j); 
	//	printf("%d\n",tDigit[j] );	
	}

for(k=0;k<n;k++){
	U[l]=0;
} 	

for(l=0;l<n;l++){
	U[l] = ((tDigit[l]%b)*m_dash)%b;
	
	T = T + (U[l]*m*power(b,l));

	printf("%d\n",T);

	int *fnew = radixb(T,b);
	    
	    for(p=0;p<2*n;p++){
			tDigit[p] = *(fnew+p); 	
		}
}
	
	
T = T/R;

if(T>=m){
T = T-m;
}
    printf("Montgomery Reduction = %d\n",T);
    	
    
   
/*for(d=0; ; d++){
 	if(((100*d)-1)%m==0){
 	
 		printf("Value of d = %d\n",d);
 		break;
 	}
 }*/
	
}

int gcd(int a,int b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
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
