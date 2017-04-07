#include <stdio.h>

int main(){

	int i,j,k,l,p,q;
	int n,t,u,x,entry,seq;

	printf("Number of values of m : ");
	scanf("%d",&n);
	
	printf("Enter all values of m with gcd(m_i,m_j)=1 : ");	
	
	int m[n],M=1;
	
	for(i=0; i<n;i++){
		scanf("%d",&entry);
		m[i] = entry;
		M = M*m[i];
	}

	printf("Number of values in v(x) : ");
	scanf("%d",&t);
	
	int v[t],C[t];
	
	printf("Enter sequence of digits in v(x) : ");
	
	for(j=0;j<t;j++){
		scanf("%d",&seq);
		v[j] = seq;
	}
	
	C[0] = 1;

	for(k=1;k<t;k++){
		C[k] = 1;
		for(l=0;l<k;l++){
			u = inverseFunction(m[l],m[k]);
			printf("u = %d\n",u);
			C[k] = u*C[k]%m[k];
		}		
	}

	u = v[0];
	x = u;
	
	for(p=1;p<t;p++){
		u = ((((v[p]-x)*C[p])%m[p])+m[p])%m[p];
		
		int temp_M = 1;
		for(q=0;q<p;q++){
			temp_M = temp_M*m[q];
		}
		x = x+(u*temp_M);
	}
	printf("Integer x in residue number system = %d\n",x);
}

int inverseFunction(int x, int y){

	int a,b,g=1;
	int u,v,A,B,C,D;
	
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

   return a;
}
