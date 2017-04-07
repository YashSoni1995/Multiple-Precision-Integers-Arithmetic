#include <stdio.h>
#define BITS 15

int main(){

	int i,j,k,p,q,r,t,s;
	

	printf("Number of Digits in base 2 : ");
	scanf("%d",&t);
	int e[t];
	printf("Enter values of e_2 from right to left : ");
	for(s=0;s<t;s++){
		scanf("%d",&e[s]);
	}

	printf("Enter value for k : ");
	scanf("%d",&k);
	
	
	while(k>=2){
		for(i=t-1;i>=(k-1);i--){
			int count = 0;
			for(j=i;j>=(i-k+1);j--){
				if(e[j]==1){
					count = count + 1;
				}
			}
			if(count==k){
				for(p=i;p>=(i-k+1);p--){
					if(p==(i-k+1)){
						e[p] = power(2,k)-1;
					}
					else{
						e[p] = 0;
					}
				}		
			}
		}
		for(q=BITS-1;q>=0;q--){
			printf("%d",e[q]);
		}
		printf("\n");
		k=k-1;
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