#include <stdio.h>
#define BITS 10

int main(){

	int i,j,k,g,e,l,len;

	printf("Enter element g : \n");
	scanf("%d",&g);

	printf("Enter element e : \n");
	scanf("%d",&e);	

	printf("Enter length of addition chain : \n");
	scanf("%d",&len);

	int w[len+1][2];
	
	for(i=1;i<=len;i++){
		printf("Enter elements for w%d : ",i);
		for(j=1;j<=2;j++){
			scanf("%d",&w[i][j]);
		}
	}
	
	printf("Addition Chain is : ");
	int u[len+1];
	u[0] = 1;
	printf("%d\t",u[0]);
	for(l=1;l<=len;l++){
		u[l] = u[w[l][1]]+u[w[l][2]];
		printf("%d\t",u[l]);
	}

	int g_arr[len+1];
	g_arr[0] = g;
	for(k=1;k<=len;k++){
		g_arr[k] = g_arr[w[k][1]]*g_arr[w[k][2]];
		//printf("g_arr = %d\n",g_arr[k]);
	}
	printf("Ans = %d\n",g_arr[len]);
}