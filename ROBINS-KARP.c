//MATCHING SUB-STRING O(n*m)/O(n+m)
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define LL long long
#define and &&
#define or ||
#define max(a,b) (a>b)?a:b;
#define s(n) scanf("%lld",&n)
#define ss(n,m) scanf("%lld%lld",&n,&m)
#define sss(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

LL int hash(char *str,LL int l){
LL int i,val=0;
for(i=0;*str!='\0';i++){
	val+=(*str)*pow(l,i);
	str++;
}
return(val);
}

LL int rehash(LL int val,char end,char start,LL int l){
	//printf("%c %c\n",start,end);
	val=((val-start)/l)+end*pow(l,l-1);
	return(val);
}


LL int match(char *s,char *t,LL int l1,LL int l2){
	char temp[100000],*p;
	p=s;
   LL int i=0,x=0,res=0;
   x=hash(t,l2);
	while(i<l2){
		temp[i]=*p;
		i++;p++;
	}
	temp[i]='\0';
    res=hash(temp,l2);

	if(res==x)
		return(1);

	while(*p!='\0'){
		res=rehash(res,*p,*(p-l2),l2);
		if(res==x)
	     	return(1);
	    p++;
	}
	return(0);
		}



int main(){
	char str[100000],patt[100];
	LL int l1,l2;
	printf("ENTER YOUR STRING:");
	scanf("%s%n",str,&l1);
	//printf("%lld\n",l1);
	fflush(stdin);
	printf("ENTER YOUR SUBSTRING TO SEARCH:");
	scanf("%s%n",patt,&l2);
	
	if(match(str,patt,l1,l2))
		printf("FOUND");
	else
		printf("NOT FOUND");
	
	return 0;
}