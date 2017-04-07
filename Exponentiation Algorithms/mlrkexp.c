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

	int i,j,k,l,m,n,p,x,y;
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

    int h[n+1],u[n+1];

    for(p=0;p<=n;p++){
    	
    	int flag = 0;
	    
	    if(fDigit[p]==0){
    		h[p] = 0;
    		u[p] = 0;
    	
    	}else{
    		for(y=1;y<10;y=y+2){
    			
    			for(x=0;x<10;x++){
    				
    				if(fDigit[p]==power(2,x)*y){
    					h[p] = x;
						u[p] = y;
    					flag=1;
    					break;
    				}
    				
    			}
    			
    			if(flag==1){
    				break;
    			}
    		}
    	}
    }

    int g_arr[base];
  	g_arr[0] = 1;
  	g_arr[1] = g;
  	g_arr[2] = power(g,2);
  	
  	for(l=1;l<base;l++){
  		g_arr[(2*l)+1] = g_arr[(2*l)-1]*g_arr[2];
	}

	int A = 1;

	for(m=n;m>=0;m--){
		A = power((power(A,power(2,k-h[m]))*g_arr[u[m]]),power(2,h[m]));
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
