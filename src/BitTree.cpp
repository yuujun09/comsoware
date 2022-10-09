#include <iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int DataCount = 20;
int MaxData = 100;
vector<int> v;		//存储随机序列

struct BSTnode{
	int data;
	BSTnode* lchild;
	BSTnode* rchild;
};

using BSTnode = BSTnode; 


BSTnode* BSTinsert(BSTnode* root , int e)
{
	if(root == NULL)
	{
		root = (BSTnode*)malloc(sizeof(BSTnode));
		root ->data = e;
		root ->lchild =NULL;
		root ->rchild =NULL;
		return root;
	}
	else if(e < root ->data)
	{
		root ->lchild = BSTinsert(root ->lchild , e);
	}
	else
	root -> rchild = BSTinsert(root -> rchild , e);
}

void treehigh(BSTnode*p , int& high)
{
	if(p == 0)
	{
		high = 0;
	}
	else
	{
		int lhigh,rhigh;
		treehigh(p -> lchild , lhigh);
		treehigh(p->rchild , rhigh);
		if(lhigh >= rhigh)
			high = lhigh+1;
		else
			high = rhigh+1;
	}
}

int main(int argc , char** argv)
{
	cout <<	"This is the first experiment" << endl;

	srand((unsigned)time(NULL));	//初始化时间种子

	for(int i = 0 ; i<DataCount ; i++ ){
		int n = rand()%MaxData;	//保证随机数在0~100
		v.push_back(n);
		for(vector<int>::iterator it = v.begin() ; it+1 != v.end() ; it++ ){
			if(*it == n){
				v.pop_back();	//重复了则丢弃
				i--;	//追加一次循环
			}
		}	
	}	//生成不重复随机数

	cout << "The generated random list is :" << endl;
	for(vector<int>::iterator it = v.begin() ; it != v.end() ; it++ )
	{
		cout << *it << "\t" ;
	}	//输出序列

	BSTnode* root = (BSTnode*)malloc(sizeof(BSTnode));
	root -> data	= v.front();
	root -> lchild = NULL;
	root ->rchild = NULL;
	for(vector<int>::iterator it = v.begin()+1 ; it != v.end() ; it++ )
	{	
		BSTinsert(root,*it); 
	}	//构建排序二叉树
	
	int high = 0;
	treehigh(root , high);
	cout << endl <<"The depth of the tree :\t"<<high << endl;

	return 0;
}

