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

int fDigit[BITS],new_m;

int longestString(int n, int k){

    int length=0;
    while(k>=0){
        if(fDigit[n-k+1]==1){
            length=k;
           // new_m = n-k+1;
            break;
        }else{
            k = k-1;
        }
    
    }
    return length;
}

int binaryToDecimal(int m, int length){
    int Decimal = 0;
    while(length>0){
        Decimal = Decimal + fDigit[m]*power(2,length-1);
        m = m-1;
        length--;
    }
    return Decimal;
}

int main(){

	int i,j,k,l,m,n;
	int g,e;

	printf("Enter value of element g belong to G : ");
	scanf("%d",&g);

	printf("Enter value of e>=1 : ");
	scanf("%d",&e);

	printf("Enter value of k : ");
	scanf("%d",&k);	

	int base = power(2,k); 
	
	printf("Radix representation of e = ");

	int *first = radixb(e,2);

 	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}

	for(j=BITS-1;j>=0;j--){
		if(fDigit[j]!=0 ){
    		n = j;
            //printf("%d\n",n );
    		break;
    	} 
    }

    int g_arr[base];
  	g_arr[1] = g;
  	g_arr[2] = power(g,2);
  	
  	for(l=1;l<base;l++){
  		g_arr[(2*l)+1] = g_arr[(2*l)-1]*g_arr[2];
	}

	int A = 1;
    m=n;

    while(m>=0){
        int length;
        int new_g;
        if(fDigit[m]==0){
            A = A*A;
            m = m-1;

        }else{
            //printf("Hello\n");
            length = longestString(m,k);
            //printf("m = %d k = %d Length = %d\n",m,k,length);
            new_g = binaryToDecimal(m,length);
            //printf("Decimal = %d\n",new_g);
            A = power(A,length)*power(g,new_g);
            //printf("A=%d\n",A);
            m = m-length;
        }

    }

	printf("Value of g^e = %d\n",A);
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
