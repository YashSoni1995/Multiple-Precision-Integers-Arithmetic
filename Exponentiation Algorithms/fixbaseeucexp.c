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

	int i,j,k,p,q,r,s,t,Q,M,N;
	int g,e,n,h,fDigit[BITS];
	int a,c,d,f,temp;

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
    		n = j;
    		//printf("%d\n",n );
    		break;
    	} 
    }

	int b[n+1];
    for(k=0;k<=n;k++){
    	b[k] = power(h,k);
		//printf("Value of b[%d] = %d\n",k,b[k]);
	}

	int g_arr[n+1];
	int x[n+1];
	int arr[n+1];
	
	for(p=0;p<=n;p++){
		//printf("%d\n",b[p] );
		g_arr[p] = power(g,b[p]);
		x[p] = fDigit[p];
		//printf("x[%d] = %d gar=%d\n",p,x[p],g_arr[p]);
	}
	
	for(s=0;s<=n;s++){
		arr[s]=x[s];
	}

	for(q=0;q<=n;q++){
        for(r=q+1;r<=n;r++){
            if(arr[r] < arr[q]){
                temp = arr[q];
                arr[q] = arr[r];
                arr[r] = temp;
            }
        }
    }
 
 	for(t=0;t<=n;t++){
		if(arr[n]==x[t]){
			M = t;
		}
		if(arr[n-1]==x[t]){
			N = t;
		}
	} 
 	
 	printf("M=%d N=%d\n",M,N);

	while(x[N]!=0){
		//printf("m=%d n=%d\n",M,N);
		Q = x[M]/x[N];
		g_arr[N] = power(g_arr[M],Q)*g_arr[N];
		x[M] = x[M]%x[N];
		//printf("%d %d %d\n",Q,g_arr[N],x[M]);
		//printf("%d %d %d\n",g_arr[0],g_arr[1],g_arr[2]);

		for(a=0;a<=n;a++){
		arr[a]=x[a];
		}

		for(c=0; c<=n; c++){
        	for(d=c+1; d<=n; d++){
            	if(arr[d] < arr[c]){
                	temp = arr[c];
                	arr[c] = arr[d];
                	arr[d] = temp;
            	}
        	}
    	}
 
 		for(f=0;f<=n;f++){
			if(arr[n]==x[f]){
				M = f;
			}
			if(arr[n-1]==x[f]){
			N = f;
			}
		} 
	}

	int Answer = power(g_arr[M],x[M]);

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