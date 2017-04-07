
/*******####################********
         Multiple Precision Multiplication
********####################********
	Author : Yash Soni
E-mail : goldsmith.yashraj@gmail.com
*******#####################*******/

#include <stdio.h>
#define BITS 8

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

int mul[2*BITS+2];
int mod;
int n,t;
int num=0;
int modDigit[BITS];

int multiply(int fDigit[], int sDigit[], int base){
	
	int i,j,k,v,u,l,p,q,r;
	
	for(i=0;i<(2*BITS+1);i++){
		mul[i]=0;
	}

	for(j=0;j<BITS;j++){
		int c=0;
		
		for(k=0;k<BITS;k++){
		int v,u;	
		int compute = mul[j+k]+(sDigit[k]*fDigit[j]+c);
		
		if(compute > base-1){
			v = compute%base;
			u = compute/base;
		}else{
			v = compute;
			u = 0;
		}
	
		mul[j+k]=v;
		c=u;
	}
}

	for(l=2*BITS+1;l>=0;l--){
		printf("%d",mul[l]);
	}

	printf("\n");

	for(p=2*BITS+1;p>=0;p--){
		if(mul[p]!=0){
    		n = p;
    		break;
    	} 
    }
    	
    for(q=BITS-1;q>=0;q--){
    	if(modDigit[q]!=0){
    		t = q;
    		break;
    	} 
   }

   for(r=0;r<2*BITS+2;r++){
   	num = num + mul[r]*power(base,r);

   }



   printf("%d %d\n",n,t);
   printf("%d\n",num);

	division(num,modDigit,base,mod);
}



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
    }

  int *first = radixb(a,base);
     for(p=0;p<BITS;p++){
				fDigit[p] = *(first+p);
				
		}

    for(i=n;i>=t+1;i--){
		
		if(fDigit[i]==sDigit[t]){
    		quo[i-t-1] = base-1;
    	}
    	else{
    		quo[i-t-1] = (fDigit[i]*base + fDigit[i-1])/sDigit[t];
    		
		}
    	
    	while(quo[i-t-1]*(sDigit[t]*base+sDigit[t-1]) > fDigit[i]*base*base+fDigit[i-1]*base+fDigit[i-2]){
	    	quo[i-t-1] = quo[i-t-1] - 1;
		}
	    
		a = a-(quo[i-t-1]*b*(power(base,(i-t-1))));
		
		if(a<0){
	    	a = a + b*(power(base,i-t-1));
	    	quo[i-t-1] = quo[i-t-1]-1;
		}
	    
	    int *newdigits = radixb(a,base);
	    
	    for(m=0;m<2*BITS+2;m++){
			fDigit[m] = *(newdigits+m); 	
		}


    }

	printf("Remainder = ");
	int *rem = radixb(a,base);
	
	printf("Quotient = ");
	for(l=n-t;l>=0;l--){
		printf("%d",quo[l]);
	}
    
    printf("\n");
}


int main(){
	int a,b,base;
	int i,j,k,l;
	int fDigit[BITS],sDigit[BITS];
	printf("Enter First Integer : ");
 	scanf("%d",&a);
 	printf("Enter Second Integer : ");
 	scanf("%d",&b);
 	printf("Enter Base Value : ");
 	scanf("%d",&base);

	printf("Enter Mod Value : ");
 	scanf("%d",&mod);
 	

	printf("First Number : ");
	int *first = radixb(a,base);

	for(i=0;i<BITS;i++){
		fDigit[i] = *(first+i); 	
	}

	printf("Second Number : ");
	int *second = radixb(b,base);
    
    for(j=0;j<BITS;j++){
		sDigit[j] = *(second+j);
	}

	int *third = radixb(mod,base);
    
    for(k=0;k<BITS;k++){
		modDigit[k] = *(third+k);
	}

     
    printf("Answer : ");   
	multiply(fDigit,sDigit,base);
	return 0;
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











