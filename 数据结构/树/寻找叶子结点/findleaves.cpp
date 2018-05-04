#include<stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];
Tree BuildTree(struct TreeNode T[])
{
	int N, i, Root = -1;
	int check[11];
	char cl, cr;
	scanf("%d", &N);
	getchar();
	for (i = 0; i<N; i++)
		check[i] = 0;
	if (!N)
		return Null;
	if (N)
	{
		for (i = 0; i<N; i++)
		{
			scanf("%c %c", &cl, &cr);
			getchar();
			if (cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;
			if (cr != '-')
			{
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}
		for (i = 0; i < N; ++i) {
			if (!check[i]) {
				Root = i;
				break;

			}
		}

	}
	return Root;
}

int( *findLeaves(Tree root))[50]
{
	int (*leaves)[50];
	leaves = (int(*)[50])calloc(50, sizeof(int));
	int queue[10];
	int head = 0, rear = 0;
	int x = 0;
	queue[rear++] = root;
	while (rear - head) {
		Tree node = queue[head++];
		if (T1[node].Left == Null && T1[node].Right == Null) {    //输出叶节点  
			(*leaves)[x] = node;
			++x;
		}
		if (T1[node].Left != -1) {       //如果存在，左儿子入队  
			queue[rear++] = T1[node].Left;
		}
		if (T1[node].Right != -1) {      //如果存在，右儿子入队  
			queue[rear++] = T1[node].Right;
		}

	}

	return leaves;
}

int main()
{

	Tree R1;
	int (*result)[50];
//	(*result)[0]=0;
	R1 = BuildTree(T1);
	/*if(R1==0){
	printf("0");
	return 0;
	}*/
	result = findLeaves(R1);
	int i=0;
	int flag=0;
	if((*result)[i]==0){
	printf("%d",(*result)[i]);
	return 0;
	}
	while((*result)[i]){
		if(flag!=0){
		printf(" ");
		}
		flag=1;
		printf("%d",(*result)[i]);
		++i;
	}
    return 0;
}

