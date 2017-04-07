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
 	
	return x; 	
}

int main(){

	int i,j,k,l,p,q,s,r,y,v,w,t;
    int m=0,n=0,x=1;
	int g;

    printf("Enter number of values of g : ");
	scanf("%d",&g);

    int g_value[g],e[g],fDigit[g][BITS];
    
    printf("Enter value of element g belong to G : ");
	for(i=0;i<g;i++){
        scanf("%d",&g_value[i]);
    }

    printf("Enter values of element e belonging to each g : ");
    for(j=0;j<g;j++){
        scanf("%d",&e[j]);
        
    }

    while(m<g){
        int *first = radixb(e[m],2);
        for(l=0;l<BITS;l++){
            fDigit[m][l] = *(first+l);
        }
        m++;
    }

    for(q=0;q<g;q++){
        for(p=BITS-1;p>=0;p--){
            if(fDigit[q][p]!=0 ){
                if(n<=p){
                    n = p+1;
                }
            } 
        }
    }


    int G[power(2,g)];
    for(r=0;r<power(2,g);r++){
        int *second = radixb(r,2);
        int product = 1;
        for(s=0;s<g;s++){
            product = product*power(g_value[s],*(second+s));
        }
        G[r] = product;
    }

    int sum[n+1];
    for(y=0;y<=n;y++){
        sum[y] = 0;
    }

    for (w=n-1;w>=0;w--){
        for(v=0;v<g;v++){
            sum[x] = sum[x] + fDigit[v][w]*power(2,v);
        }
        x=x+1;
    }

    int A = 1;
    
    for(t=1;t<=n;t++){
        A = A*A;
        A = A*G[sum[t]];
    }
    printf("A = %d\n",A );
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
