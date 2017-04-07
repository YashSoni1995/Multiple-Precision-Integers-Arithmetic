#include <stdio.h>
#define BITS 15

int main(){

	int x,y,b;
	

	printf("Enter value for x : ");
	scanf("%d",&x);

	printf("Enter value of y : ");
	scanf("%d",&y);

	printf("Enter base : ");
	scanf("%d",&b);

	

	while(y>=b){
		int x_bar = x;
		int y_bar = y;
		while(x_bar>b){
			x_bar = x_bar/b;
		}
		while(y_bar>b){
			y_bar = y_bar/b;
		}
		
		printf("%d %d\n",x_bar,y_bar);
		int A=1, B=0, C=0, D=1;
		int t,q,q_dash;

		while((y_bar+C)!=0 && (y_bar+D)!=0){
			q = (x_bar+A)/(y_bar+C);
			q_dash = (x_bar+B)/(y_bar+D);
			printf("%d %d\n",q,q_dash);
			if(q==q_dash){
				t=A-q*C;
				A=C;
				C=t;
				t=B-q*D;
				B=D;
				D=t;
				t=x_bar-q*y_bar;
				x_bar=y_bar;
				y_bar=t;
			}
			else{
				break;
			}
		}
		//printf("%d %d %d %d\n",A,B,C,D);
			
		int T,u;
		if(B==0){
			T = x%y;
			x=y;
			y=T;
		}
		else{
			T=(A*x)+(B*y);
			u=(C*x)+(D*y);
			x=T;
			y=u;
		}
	}
	int v = gcd(x,y);
	printf("V = %d\n",v);
}

int gcd(int a,int b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}