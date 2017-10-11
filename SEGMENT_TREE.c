#include<stdio.h>
#include<stdlib.h>
#define and &&
#define or ||
#define s(n) scanf("%d",&n)
#define max(x,y) x>y?x:y

int arr[100];
int tree[202];
void build(int node,int start,int end){
  if(start==end)
     tree[node]=arr[start];
  else{
	  int mid=(start+end)>>1;
	  build(node<<1,start,mid);
	  build((node<<1)+1,mid+1,end); 
	 tree[node]=tree[node<<1]+tree[(node<<1)+1];
	 //tree[node]=max(tree[node<<1],tree[(node<<1)+1]);
  }
  return;
}

void update(int node,int start,int end,int idx,int val){
	if(start==end){
		//printf("FINAL-MID:%d,NODE:%d,val:%d \n",start,node,val);
		arr[idx]+=val;
		tree[node]+=val;
		return;
	}
	else{
		int mid=(start+end)>>1;
		
		if(start<=idx and idx<=mid){
			//printf("LEFT-AT-MID:%d,NODE:%d \n",mid,node);
			update((node<<1),start,mid,idx,val);
		}
		else{
			//printf("RIGHT-AT-MID++%d,NODE:%d  \n",mid+1,node);
			update((node<<1)+1,mid+1,end,idx,val);
	}
	}
	tree[node]=tree[node<<1]+tree[(node<<1)+1];
	//tree[node]=max(tree[(node<<1)],tree[(node<<1)+1]);
//printf("tree[%d]:%d\n",node,tree[node]);
	return;
}

int query(int node,int start,int end,int l,int r){
	if(r<start  or end<l)
		return(0);
	if(l<=start and r>=end)
		return(tree[node]);
	int mid=(start+end)>>1;
	int a=query(node<<1,start,mid,l,r);
	int b=query((node<<1)+1,mid+1,end,l,r);
	    return(a+b);
}

int main(){

	   int low,high,val,index,q,n,type,i;
	printf("ENTER NO OF ELEMENTS:");
	s(n);
	printf("ENTER ELEMENTS:");
		for(i=1;i<=n;i++)
			scanf("%d",&arr[i]);
		build(1,1,n);
	printf("ENTER NO OF QUERIES:");
	s(q);
	
	while(q--){
		printf("ENTER TYPE OF QUERY:");
		s(type);
		switch(type){
			case 0:printf("ENTER POSITION and VALUE TO UPDATE:");
			       s(index);s(val);
				   update(1,1,n,index,val);
				   break;
			case 1:printf("ENTER UPPER AND LOWER BOUND:");
			       s(low);s(high);
				   printf("RESULT FOR[%d,%d] :%d",low,high,query(1,1,n,low,high));
				   break;
		   default:printf("INVALID ENTRY\n");
		}
	}


	  return 0;
}

	 