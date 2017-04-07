/*******####################********
         Multiple Precision Division
********####################********
	Author : Yash Soni
E-mail : goldsmith.yashraj@gmail.com
*******#####################*******/

#include <stdio.h>
#include <stdlib.h>
#define BITS 9



int *radixb(int m, int n){
 	int i,j,q;
	static int x[10]; 	
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

int n,t;

//int division(int fDigit[],int sDigit[], int base, int a, int b){
int division(int a,int sDigit[], int base, int b){
	int quo[n-t],fDigit[BITS];
	int i,j,k,l,m,p;
	int u,v;

	for(j=0;j<=(n-t);j++){
		quo[j]=0;
	}

	while(a>=b*(power(base,(n-t)))){
		quo[n-t] = quo[n-t] + 1;
		a = a - b*(power(base,(n-t)));
    	printf("%d %d\n",quo[n-t],a );
    }

    int *first = radixb(a,base);
     for(p=0;p<BITS;p++){
				fDigit[p] = *(first+p);
			printf("%d\n",fDigit[p] ); 	
		}

    for(i=n;i>=t+1;i--){
		
		if(fDigit[i]==sDigit[t]){
    		quo[i-t-1] = base-1;
    		printf("%d\n",quo[i-t-1]);
    	}
    	else{
    		quo[i-t-1] = (fDigit[i]*base + fDigit[i-1])/sDigit[t];
    		printf("%d\n",quo[i-t-1]);
		}
    	
    	while(quo[i-t-1]*(sDigit[t]*base+sDigit[t-1]) > fDigit[i]*base*base+fDigit[i-1]*base+fDigit[i-2]){
	    	quo[i-t-1] = quo[i-t-1] - 1;
			printf("%d\n" ,quo[i-t-1]);
		}
	    
		a = a-(quo[i-t-1]*b*(power(base,(i-t-1))));
		printf("%d\n",a );
		if(a<0){
	    	a = a + b*(power(base,(i-t-1)));
	    	quo[i-t-1] = quo[i-t-1]-1;
	    	printf("%d %d\n",quo[i-t-1],a );
	    }
	    
	    //a = abs(a);
	   int *newdigits = radixb(a,base);
	    
	    for(m=0;m<BITS;m++){
				fDigit[m] = *(newdigits+m);
			printf("%d\n",fDigit[m] ); 	
		}


    }

	printf("Remainder = %d\n",a);
	int *rem = radixb(a,base);
	
	printf("Quotient = ");
	for(l=n-t;l>=0;l--){
		printf("%d",quo[l]);
	}
    
    printf("\n");
}


int main(){

	int a,b,base;
	
	int i,j,k,l,sum[BITS+1],c=0;
	int fDigit[BITS],sDigit[BITS];

	printf("Enter Dividend Integer (more than 1 digit): ");
 	scanf("%d",&a);
 	printf("Enter Divisor Integer (more than 1 digit) : ");
 	scanf("%d",&b);
 	printf("Enter Base Value : ");
 	scanf("%d",&base);
	
	int *first = radixb(a,base);

	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}
	
	int *second = radixb(b,base);
    
    for(j=0;j<BITS;j++){
		sDigit[j] = *(second+j);
	}
    
    for(k=BITS-1;k>=0;k--){
		if(fDigit[k]!=0){
    		n = k;
    		break;
    	} 
    }
    	
    for(l=BITS-1;l>=0;l--){
    	if(sDigit[l]!=0){
    		t = l;
    		break;
    	} 
   }
   
	//division(fDigit,sDigit,base,a,b);
	division(a,sDigit,base,b);
	
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













