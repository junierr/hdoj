#include<cstdio>
#include<cstdlib>
using namespace std;

typedef struct BTNode *BTree;
struct BTNode
{
	char data;
	BTree lchild,rchild;
};

BTree CreateTree(char z[],char h[],int n)
{
	int i; 
	if(n==0) return NULL;
	BTree btRoot= new BTNode;
	btRoot->data=h[n-1];
	char lz[100],lh[100],rz[100],rh[100];
	int n1,n2;
	n1=n2=0;
	for(i=0;i<n;i++)
	{
		if(i<=n1&&z[i]!=btRoot->data)
		  lz[n1++]=z[i];
		else if(z[i]!=btRoot->data)
		  rz[n2++]=z[i];  
	}
	int m1,m2;
	m1=m2=0;
	for(i=0;i<n-1;i++)
	{
		if(i<n1)
		  lh[m1++]=h[i];
		else   
		  rh[m2++]=h[i];
	}
	btRoot->lchild=CreateTree(lz,lh,n1);
	btRoot->rchild=CreateTree(rz,rh,n2);
	return btRoot;
}
void pp(BTree bt)
{
	if(bt!=NULL)
	{
	  
	  printf("%c",bt->data);
	  pp(bt->lchild);
	  pp(bt->rchild);
    }
	return;
}
int main()
{
	int n;
	char z[100],h[100];
	scanf("%d%s%s",&n,z,h);
	BTree bt=CreateTree(z,h,n);
	pp(bt);
	return 0;
} 
