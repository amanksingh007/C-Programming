#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define and &&
#define or ||
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b


int LCS[10000][10000];
// NOTE: str2 IS ALONG Y-AXIS
void find_LCS_DP(char *str1,int m,char *str2,int n){
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){                //printf("%c %c\n",str1[i-1],str2[j-1]);
			if(str1[j-1]==str2[i-1])    //  HERE INDEX IS 1 VALUE HIGHER,HENCE:(i-1,j-1);
				LCS[i][j]=1+LCS[i-1][j-1];
			else
				LCS[i][j]=max(LCS[i-1][j],LCS[i][j-1]);
				}
	}
	return;
}


void print_LCS(char *str1,int m,char *str2,int n,char *res){
	int i=n,j=m,l=LCS[n][m];
	res[l]='\0';    //  SET LAST INDEX=NULL;
	while(i>0 and j>0){
		if(str1[j-1]==str2[i-1]){
			//printf("%d %d\n",i,j);
			res[--l]=str1[j-1];
			i=i-1;j=j-1;
			//printf("%c\n",res[l]);
		}
		else
			if(LCS[i-1][j]==LCS[i][j])
				i=i-1;
			else
				j=j-1;
	}
	//printf("%d ",l);
	return;
}
	
void printDP(int m,int n){
	int i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			printf("%d ",LCS[i][j]);
		}
		printf("\n");
    }
	return;
}


int main(){
	int i,j,m,n;
	char str1[10004],str2[10004];char res[10004];
	scanf("%s%n",str1,&m);
	//fflush(stdin);
	scanf("%s%n",str2,&n);
	printf("%s\n%s",str1,str2);
	find_LCS_DP(str1,m,str2,n);    // CALCULATES DP array;
	printDP(m,n);
	//printf("%d\n",LCS[n][m]);        //PRINTS LENGTH OF LCS
	print_LCS(str1,m,str2,n,res);   //FINDS AND STORES LCS IN res array;
	printf("RESULT:%s",res);
	return 0;
}