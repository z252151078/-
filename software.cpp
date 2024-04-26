#include <iostream>
using namespace std;
typedef int KeyType;
//二叉排序树的结构体定义
typedef struct BSTNode {
	KeyType data; //数据域
	struct BSTNode* lchild, * rchild; //二叉排序树中的左子树和右子树
}BSTNode, * BSTree;

//声明
KeyType Delete(BSTree* p);
void Search();
void Insert();
void Del();

//二叉排序树插入节点算法 递归
void BSTNodeInsert(BSTree& T, KeyType key) {
	if (key < T->data) { //走左子树
		if (T->lchild == NULL) { //如果左子树为空 则直接赋值给左子树
			T->lchild = new BSTNode;
			T->lchild->data = key;
			T->lchild->lchild = NULL;
			T->lchild->rchild = NULL;
		}
		else { //如果左子树不为空 则递归继续找左子树
			BSTNodeInsert(T->lchild, key);
		}
	}
	else { //当key比根节点的值大时 找右子树
		if (T->rchild == NULL) { //如果右子树为空 直接赋值
			T->rchild = new BSTNode;
			T->rchild->data = key;
			T->rchild->lchild = NULL;
			T->rchild->rchild = NULL;
		}
		else { //否则继续递归找右子树
			BSTNodeInsert(T->rchild, key);
		}
	}
}

//创建二叉排序树算法
void CreatBSTree(BSTree& T) {
	T = new BSTNode;
	T->lchild = NULL;
	T->rchild = NULL;
	int i;
	cin >> i; //输入序列值
	if (i != -1) { //初始化操作，给根节点赋初值
		T->data = i;
	}
	while (i != -1) {
		cin >> i;
		if (i != -1) //双重判断 不然-1会加进序列
			BSTNodeInsert(T, i);
	}

	cout << "创建成功！" << endl;
}

//递归打印创建好的二叉排序树
void PrintBSTree(BSTree T) { //采用中序遍历 可以得到从小到大的有序序列
	if (T != NULL) {
		PrintBSTree(T->lchild);
		cout << T->data << " ";
		PrintBSTree(T->rchild);
	}
}

//二叉排序树的递归查找算法
int SearchBSTree(BSTree T, int key) {
	if (T == NULL)
		return 0;
	if (T->data == key)
		return 1;
	if (key < T->data)
		SearchBSTree(T->lchild, key);
	else
		SearchBSTree(T->rchild, key);
}

//二叉排序树的删除操作函数定义
KeyType DeleteBST(BSTree* T, int key)
{
	if (!*T)
		return false;
	else
	{
		if (key == (*T)->data)
		{
			return Delete(T);
		}
		else if (key < (*T)->data)
		{
			return DeleteBST(&(*T)->lchild, key);
		}
		else
		{
			return DeleteBST(&(*T)->rchild, key);
		}
	}
}

//根据情况来删除节点
KeyType Delete(BSTree* p)
{
	BSTree q, s;
	if ((*p)->rchild == NULL)
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	else if ((*p)->lchild == NULL)
	{
		q = *p; *p = (*p)->rchild; free(q);
	}
	else
	{
		q = *p; s = (*p)->lchild;
		while (s->rchild)
		{
			q = s; s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return true;
}



BSTree T;

int main() {

	cout << "请输入序列：(以-1为结束数)" << endl;
	CreatBSTree(T);
	cout << "创建好的二叉排序树中序遍历结果为：" << endl;
	PrintBSTree(T);
	cout << endl;
	cout << "**************************************************************" << endl;
	cout << "执行编号：" << endl;
	cout << "1：查找		2：插入		3：删除		4: 结束运行" << endl;
	cout << "**************************************************************" << endl;

	while (1)
	{
		int menu;
		cout << "请输入执行编号：";
		cin >> menu;
		switch (menu)
		{
		case 1:Search(); break;//查找
		case 2:Insert(); break;//插入
		case 3:Del();	 break;//删除
		case 4:goto end; break;//结束运行
		default:cout << "输入错误，编号不存在。"; break;
		}
	}

end:
	return 0;
}

void Search()//查找操作
{
	int i;
	cout << "请输入要查找的数字：" << endl;
	cin >> i;
	if (SearchBSTree(T, i) == 0)
		cout << "查找失败！该序列中没有此数！" << endl;
	if (SearchBSTree(T, i) == 1)
		cout << "查找成功！该序列中存在此数！" << endl;
}

void Insert()//插入操作
{
	int i;
	cout << "请输入需要插入的数字：";
	cin >> i;
	BSTNodeInsert(T, i);//插入函数
	cout << "插入后的二叉排序树中序遍历结果为：" << endl;
	PrintBSTree(T);
	cout << endl;
}

void Del()//删除操作
{
	int i;
	cout << "请输入需要删除的数字：";
	cin >> i;
	DeleteBST(&T, i);//删除函数
	cout << "删除后的二叉排序树中序遍历结果为：" << endl;
	PrintBSTree(T);
	cout << endl;
}