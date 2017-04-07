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

	int n,meu;
	int q1,q2,q3;
	int r,r1,r2;
	int a,m,base;
	int i,j,l;
	int mDigit[BITS],fDigit[BITS];

	printf("**** PLEASE ENTER m AND b SO THAT gcd(m,b)=1 ****\n" );
	
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

	int *first = radixb(a,base);

 	for(j=0;j<BITS;j++){
		fDigit[j] = *(first+j); 	
	}

 	for(l=BITS-1;l>=0;l--){
		if(mDigit[l]!=0 ){
    		n = l+1;
    		printf("n = %d\n",n );
    		break;
    	} 
    }

    meu = power(base,2*n)/m;
    int *second

	q1 = a/power(base,n-1);
	q2 = q1*meu;
	q3 = q2/power(base,n+1);

	r1 = a%(power(base,n+1));
	r2 = q3*m%power(base,n+1);
	r = r1-r2;

	if(r>m){
		r = r+power(base,n+1);
	}

	while(r>=m){
		r = r-m;
	}
 	
    printf("Barret Reduction = %d\n",r);
    	
}

int gcd(int a,int b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
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
