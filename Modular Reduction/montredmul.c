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

int tDigit[BITS];

int main(){

	int a,b,m,base,m_dash;
	int i,j,k,l,p,q,r,s,t;
	int n,T,U[n];
	int mDigit[BITS],fDigit[BITS],sDigit[BITS];

	printf("**** PLEASE ENTER m AND b SO THAT gcd(m,b)=1 ****\n" );
	
 	printf("Enter First Number: ");
 	scanf("%d",&a);
 	printf("Enter Second Number: ");
 	scanf("%d",&b);
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
 	
	int *second = radixb(b,base);

 	for(k=0;k<BITS;k++){
		sDigit[k] = *(second+k); 	
	}

 	for(l=BITS-1;l>=0;l--){
		if(fDigit[l]!=0 || sDigit[l]!=0 || mDigit[l]!=0 ){
    		n = l+1;
    		printf("n = %d\n",n );
    		break;
    	} 
    }

 	int R = power(base,n);
	printf("Value of R = %d\n",R);

	for(p=0; ; p++){
 		if(((p*m)+1)%base==0){
 			m_dash = p;
 			printf("Value of m' = %d\n",m_dash);
 			break;
 		}
 	}

 	T=0;
	
	int *third = radixb(T,base);
	
	for(q=0;q<BITS;q++){
		tDigit[q] = *(third+q); 
	}

	for(r=0;r<n;r++){
		U[r]=0;
	} 	

    
	for(s=0;s<n;s++){


		U[s] = ((tDigit[0]+(fDigit[s]*sDigit[0]))*m_dash)%base;
		printf("%d\n",U[s]);
		T = (T + (fDigit[s]*b) + (U[s]*m))/base;
		printf("T=%d\n",T);
		tDigitChange(T,base);	
		
	}
	
	
	if(T>=m){
		T = T-m;
	}
    
    printf("Montgomery Reduction = %d\n",T);
    	
}

int tDigitChange(int T, int base){
	int *fnew = radixb(T,base);
	int t;
 	for(t=0;t<BITS;t++){
		tDigit[t] = *(fnew+t); 	
	}
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
