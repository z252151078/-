#include <iostream>
using namespace std;
typedef int KeyType;
//�����������Ľṹ�嶨��
typedef struct BSTNode {
	KeyType data; //������
	struct BSTNode* lchild, * rchild; //�����������е���������������
}BSTNode, * BSTree;

//����
KeyType Delete(BSTree* p);
void Search();
void Insert();
void Del();

//��������������ڵ��㷨 �ݹ�
void BSTNodeInsert(BSTree& T, KeyType key) {
	if (key < T->data) { //��������
		if (T->lchild == NULL) { //���������Ϊ�� ��ֱ�Ӹ�ֵ��������
			T->lchild = new BSTNode;
			T->lchild->data = key;
			T->lchild->lchild = NULL;
			T->lchild->rchild = NULL;
		}
		else { //�����������Ϊ�� ��ݹ������������
			BSTNodeInsert(T->lchild, key);
		}
	}
	else { //��key�ȸ��ڵ��ֵ��ʱ ��������
		if (T->rchild == NULL) { //���������Ϊ�� ֱ�Ӹ�ֵ
			T->rchild = new BSTNode;
			T->rchild->data = key;
			T->rchild->lchild = NULL;
			T->rchild->rchild = NULL;
		}
		else { //��������ݹ���������
			BSTNodeInsert(T->rchild, key);
		}
	}
}

//���������������㷨
void CreatBSTree(BSTree& T) {
	T = new BSTNode;
	T->lchild = NULL;
	T->rchild = NULL;
	int i;
	cin >> i; //��������ֵ
	if (i != -1) { //��ʼ�������������ڵ㸳��ֵ
		T->data = i;
	}
	while (i != -1) {
		cin >> i;
		if (i != -1) //˫���ж� ��Ȼ-1��ӽ�����
			BSTNodeInsert(T, i);
	}

	cout << "�����ɹ���" << endl;
}

//�ݹ��ӡ�����õĶ���������
void PrintBSTree(BSTree T) { //����������� ���Եõ���С�������������
	if (T != NULL) {
		PrintBSTree(T->lchild);
		cout << T->data << " ";
		PrintBSTree(T->rchild);
	}
}

//�����������ĵݹ�����㷨
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

//������������ɾ��������������
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

//���������ɾ���ڵ�
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

	cout << "���������У�(��-1Ϊ������)" << endl;
	CreatBSTree(T);
	cout << "�����õĶ�������������������Ϊ��" << endl;
	PrintBSTree(T);
	cout << endl;
	cout << "**************************************************************" << endl;
	cout << "ִ�б�ţ�" << endl;
	cout << "1������		2������		3��ɾ��		4: ��������" << endl;
	cout << "**************************************************************" << endl;

	while (1)
	{
		int menu;
		cout << "������ִ�б�ţ�";
		cin >> menu;
		switch (menu)
		{
		case 1:Search(); break;//����
		case 2:Insert(); break;//����
		case 3:Del();	 break;//ɾ��
		case 4:goto end; break;//��������
		default:cout << "������󣬱�Ų����ڡ�"; break;
		}
	}

end:
	return 0;
}

void Search()//���Ҳ���
{
	int i;
	cout << "������Ҫ���ҵ����֣�" << endl;
	cin >> i;
	if (SearchBSTree(T, i) == 0)
		cout << "����ʧ�ܣ���������û�д�����" << endl;
	if (SearchBSTree(T, i) == 1)
		cout << "���ҳɹ����������д��ڴ�����" << endl;
}

void Insert()//�������
{
	int i;
	cout << "��������Ҫ��������֣�";
	cin >> i;
	BSTNodeInsert(T, i);//���뺯��
	cout << "�����Ķ�������������������Ϊ��" << endl;
	PrintBSTree(T);
	cout << endl;
}

void Del()//ɾ������
{
	int i;
	cout << "��������Ҫɾ�������֣�";
	cin >> i;
	DeleteBST(&T, i);//ɾ������
	cout << "ɾ����Ķ�������������������Ϊ��" << endl;
	PrintBSTree(T);
	cout << endl;
}