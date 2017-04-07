#include <stdio.h>
#include <stdlib.h>
#define BITS 10

int main(){

	int x,y,a,b,g=1;
	int u,v,A,B,C,D;
	printf("Enter First Positive Integer : ");	
	scanf("%d",&x);	
	printf("Enter Second Positive Integer : ");	
	scanf("%d",&y);

	while((x%2==0) && (y%2==0)){
		x = x/2;
		y = y/2;
		g = 2*g;
	}

	u = x;
	v = y;
	A = 1;
	B = 0;
	C = 0;
	D = 1;

while(u!=0){	
	while(u%2==0){
		u = u/2;
		if(A%2==0 && B%2==0){
			A = A/2;
			B = B/2;
		}else{
			A = (A+y)/2;
			B = (B-x)/2;
		}
	}


	while(v%2==0){
		v = v/2;
		if(C%2==0 && D%2==0){
			C = C/2;
			D = D/2;	
		}else{
			C = (C+y)/2;
			D = (D-x)/2;
		}
	}

	if (u>=v){
		u = u-v;
		A = A-C;
		B = B-D;
	}else{
		v = v-u;
		C = C-A;
		D = D-B;
	}
	
	if(u==0){
		a = C;
		b = D;
	}
}

    printf("ax + by = v : ");
	printf("(%d)(%d) + (%d)(%d) = (%d)\n",a,x,b,y,g*v); 
}


