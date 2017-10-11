#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define LL long long
#define and &&
#define or ||
#define max(a,b) (a>b)?a:b;
#define s(n) scanf("%lld",&n)
#define ss(n,m) scanf("%lld%lld",&n,&m)
#define sss(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)


LL int kadane(LL int *arr,LL int n){
	LL int i,curmax,res;
	curmax=arr[1];
	res=arr[1];
	for(i=2;i<=n;i++){
		curmax=max(arr[i],arr[i]+curmax);
		res=max(res,curmax);
	}
	return(res);
}

int main(){
	LL int arr[100000],t,i,n;
	s(t);
	while(t--){
		s(n);
	    for(i=1;i<=n;i++){
		s(arr[i]);
		}
	
	printf("%lld %lld\n",kadane(arr,n),sum);       //CHECK FOR ALL -VE NUMBERS;
	}
return 0;

	}