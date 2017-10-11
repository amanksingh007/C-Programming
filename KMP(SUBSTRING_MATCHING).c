//MATCHING SUB-STRING USING KMP  :O(n+m)
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


LL int patt[1000];
void prefix(char *str,LL int length){
	LL int i,j;
	char *p=str;
	patt[0]=0;
	j=0;i=1;
	while(i<length){
		//printf("%c ",str[j]);
	if(str[j]==str[i]){
		patt[i]=j+1;
		j++;i++;
	}
	else{
		j=patt[j-1];
		if(j==0 and str[i]!=str[j]){
			patt[i]=0;
			i++;
		}
	}
	}
return; 
}

void find(char *str,LL int l,char *p,LL int m){
	LL int i,j;
	i=0;j=0;
	while(i<=l and j!=m){
		//printf("%d %d\n ",i,j);
		if(str[i]==p[j]){
			if(j==m-1){
				printf("FOUND AT INDEX:%lld",i);
				return;
			}
			i++;j++;
			}
		else
		{
			j=patt[j-1];
			if(j==0 )//and str[i]!=str[j])
				i++;
		}
	}
	printf("NOT-FOUND");
	return;
}

int main(){
	char str[1000],match[1000];LL int l,m,i;

	printf("ENTER PARENT STRING:");
	scanf("%s%n",str,&l);
	//fflush(stdout);
	fflush(stdin);
	printf("ENTER SUB-STRING:");
	scanf("%s%n",match,&m);
	prefix(match,m);
	//printf("%s%lld%s%lld\n",str,l,match,m);
	//for(i=0;i<m;i++)
	//	printf("%lld ",patt[i]);
	
	
	find(str,l,match,m);
	
	return 0;
}