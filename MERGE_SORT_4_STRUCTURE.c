#include<stdio.h>
#include<stdlib.h>
#define LL long long
#define s(n) scanf("%d",&n)
#define and &&
#define or ||
int n;
struct ar{
	LL int low;
	LL int high;
}str[10],temp[10];
void sort(LL int l,LL int h);
void merge(LL int low,LL int mid,LL int high);

void sort(LL int l,LL int h){
	LL int m;
	m=(l+h)/2;
	if(l<h){
		sort(l,m);
		sort(m+1,h);
		merge(l,m,h);
	}
}

void merge(LL int low,LL int mid,LL int high){
	LL int i,k,l,h,m;
	l=low;
	m=mid+1;
	i=low;
	h=high;
	
	while((l<=mid) && (m<=high)){
		if(str[l].low<str[m].low){
			temp[i]=str[l];
			l++;
		}
		else
			if((str[l].low==str[m].low) and (str[l].high<=str[m].high)){
			temp[i]=str[l];
			l++;
		}
			
		else{
			temp[i]=str[m];
			m++;
		}
		
	//	printf("l:%d,i:%d,j:%d,temp[i]:%d\n",l,i,j,temp[i]);
      i++;
	}
	if(l>mid){
  
	  for(k=m;k<=high;k++){
	  temp[i]=str[k];
	  i++;
  }
	}
	else{
  for(k=l;k<=mid;k++){
     temp[i]=str[k];
      i++;
  }
	}
  for(k=low;k<=high;k++)
	  str[k]=temp[k];
  return;
}
	
int main(){
	//system("cls");
	LL int i;
	s(n);
	
	for(i=1;i<=n;i++){
		s(str[i].low);
	     s(str[i].high);
	  }
	
	sort(1,n);
	
	for(i=1;i<=n;i++)
		printf("%lld %lld\n",str[i].low,str[i].high);
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%lld %lld\n",temp[i].low,temp[i].high);
	return 0;
}