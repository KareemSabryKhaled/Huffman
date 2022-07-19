#include <iostream>
#include <string>
using namespace std;
class Ctnode
{
public:
	int x;
	char y[100];
	string z = "";
	Ctnode* pldown = NULL;
	Ctnode* prdown = NULL;
};
class Cnode
{
public:
	int x;
	char y[500];
	string z = "";
	Ctnode* pdown = NULL;
	Cnode* Pnext = NULL;
};

class Clist
{
public:
	Cnode* pHead;
	Cnode* pTail;

	Clist()
	{
		pHead = NULL;
		pTail = NULL;
	}

	void insert(Cnode* pnn)
	{
		if (pHead == NULL)
		{
			pHead = pnn;

		}
		else
		{
			Cnode* pb = NULL;
			Cnode* ptrav = pHead;
			while (ptrav != NULL)
			{
				if (ptrav->x > pnn->x)
				{
					break;
				}
				pb = ptrav;
				ptrav = ptrav->Pnext;
			}
			if (pb != NULL)
			{
				pb->Pnext = pnn;
			}
			else
			{
				pHead = pnn;
			}
			pnn->Pnext = ptrav;
		}

	}
	Cnode* pop()
	{
		if (pHead == NULL)
		{
			return NULL;
		}
		Cnode* ptrav = pHead;
		pHead = pHead->Pnext;
		ptrav->Pnext = NULL;
		return ptrav;
	}


	void dispall()
	{
		Cnode* pnn = pHead;
		int i = 0;
		while (pnn != NULL)
		{
			while (pnn->y[i] != NULL)
			{
				cout << pnn->y[i];
				i++;
			}
			cout << "-";
			cout << pnn->x << " // ";
			pnn = pnn->Pnext;
		}
	}
	void Attach(Cnode*pnn)
	{
		if (pHead == NULL)
		{
			pHead = pnn;
			pTail = pnn;
		}
		else
		{
			pTail->Pnext = pnn;
			pTail = pnn;
		}
	}


};
class Tree
{

public:
	Ctnode* Root;
	Tree()
	{
		Root = NULL;
	}
	void disp(Ctnode* pt)
	{
		if (pt == NULL)
		{
			return;
		}
		disp(pt->pldown);
		cout << pt->y << "->" << pt->x << "->" << pt->z << endl;
		disp(pt->prdown);

	}
	void disp1(Ctnode* pt)
	{
		if (pt == NULL)
		{
			return;
		}
		disp(pt->pldown);
		cout << pt->y << "->" << pt->z << endl;
		disp(pt->prdown);
	}
	void zero(Ctnode* pt, Ctnode*pt2, string y, int &f)
	{
		int flag = 1;

		if (pt == NULL)
		{
			return;
		}
		pt->z = y;

		if (flag == 1 && pt->pldown != NULL)
		{

			y += "0";

		}
		zero(pt->pldown, pt2, y, f);
		y = pt->z;
		if (flag == 1 && pt->prdown != NULL)
		{
			y += "1";
		}
		zero(pt->prdown, pt2, y, f);
		pt->z = y;
	}
	void list(Ctnode* pt, Cnode*pt3,Clist &l2)
	{
		if (pt == NULL)
		{
			return;
		}
		list(pt->pldown, pt3,l2);
		if (pt->pldown == NULL&& pt->prdown==NULL)
		{
			pt3 = new Cnode;
			pt3->z += pt->z;
			pt3->y[0] = pt->y[0];
			pt3->pdown = NULL;
			pt3->Pnext = NULL;
			l2.Attach(pt3);
		}
		list(pt->prdown, pt3,l2);

	}
};
void main()
{
	Tree t;
	char x[1000];
	int i;
	Clist l;
	Cnode* pnn;
	Ctnode* pnnh;
	Ctnode* pnnl;
	Ctnode* pnnr;
	int ct = 0;
	char v;
	Cnode* ptrav;
	int flag = 1;
	gets_s(x);
	int j = 0;
	for (i = 0; x[i] != NULL; i++)
	{
		ct = 0;
		v = x[i];
		for (j = 0; x[j] != NULL; j++)
		{
			if (v == x[j])
			{
				ct++;
			}
		}
		if (l.pHead == NULL)
		{
			pnn = new Cnode;
			pnn->x = ct;
			pnn->y[0] = x[i];
			pnn->Pnext = NULL;
			pnn->pdown = NULL;
			l.insert(pnn);
		}
		else
		{
			flag = 1;
			ptrav = l.pHead;
			while (ptrav != NULL)
			{
				if (ptrav->y[0] == x[i])
				{
					flag = 0;
				}
				ptrav = ptrav->Pnext;
			}
			if (flag == 1)
			{
				pnn = new Cnode;
				pnn->x = ct;
				pnn->y[0] = x[i];
				pnn->Pnext = NULL;
				pnn->pdown = NULL;
				l.insert(pnn);
			}
		}

	}
	ptrav = l.pHead;
	for (i = 0; ptrav != NULL;)
	{
		cout << ptrav->x;
		cout << " -> ";
		cout << ptrav->y[i] << endl;
		ptrav = ptrav->Pnext;
	}
	ptrav = l.pHead;
	Cnode* ptrav2 = NULL;
	Cnode* ptrav3 = NULL;
	j = 0;
	while (l.pHead->Pnext != NULL)
	{
		ptrav2 = l.pop();
		ptrav3 = l.pop();
		if (ptrav3->pdown == NULL && ptrav2->pdown == NULL)
		{
			j = 0;
			pnnh = new Ctnode;
			pnnl = new Ctnode;
			pnnr = new Ctnode;
			pnn = new Cnode;
			pnnh->x = ptrav3->x + ptrav2->x;

			pnnl->x = ptrav2->x;

			pnnr->x = ptrav3->x;

			pnn->x = pnnh->x;

			for (i = 0; ptrav2->y[i] != NULL; i++)
			{
				pnnl->y[i] = ptrav2->y[i];
			}

			for (i = 0; ptrav3->y[i] != NULL; i++)
			{
				pnnr->y[i] = ptrav3->y[i];
			}
			for (i = 0; ptrav3->y[i] != NULL; i++)
			{
				pnnh->y[i] = ptrav2->y[i];
				pnn->y[i] = pnnh->y[i];
				pnnh->y[i + 1] = ptrav3->y[i];
				pnn->y[i + 1] = pnnh->y[i + 1];
				j++;
			}
			pnnh->pldown = pnnl;
			pnnh->prdown = pnnr;
			pnn->pdown = pnnh;
			l.insert(pnn);
		}
		else
		{
			if (ptrav3->pdown != NULL && ptrav2->pdown != NULL)
			{
				j = 0;
				pnnh = new Ctnode;

				pnn = new Cnode;
				pnnh->x = ptrav3->x + ptrav2->x;

				pnn->x = pnnh->x;
				for (i = 0; ptrav2->y[i] != NULL; i++)
				{
					pnnh->y[j] = ptrav2->y[i];
					pnn->y[j] = pnnh->y[j];
					j++;
				}
				for (i = 0; ptrav3->y[i] != NULL; i++)
				{
					pnnh->y[j] = ptrav3->y[i];
					pnn->y[j] = pnnh->y[j];
					j++;
				}
				pnnh->pldown = ptrav2->pdown;
				pnnh->prdown = ptrav3->pdown;
				pnn->pdown = pnnh;
				l.insert(pnn);
			}
			else
			{
				if (ptrav2->pdown != NULL && ptrav3->pdown == NULL)
				{
					j = 0;
					pnnh = new Ctnode;
					pnnr = new Ctnode;
					pnn = new Cnode;
					pnnh->x = ptrav3->x + ptrav2->x;
					pnnr->x = ptrav3->x;
					pnn->x = pnnh->x;

					for (i = 0; ptrav3->y[i] != NULL; i++)
					{
						pnnr->y[i] = ptrav3->y[i];
					}
					for (i = 0; ptrav2->y[i] != NULL; i++)
					{
						pnnh->y[j] = ptrav2->y[i];
						j++;
					}
					for (i = 0; ptrav3->y[i] != NULL; i++)
					{
						pnnh->y[j] = ptrav3->y[i];
						j++;
					}
					for (i = 0; pnnh->y[i] != NULL; i++)
					{
						pnn->y[i] = pnnh->y[i];
					}
					pnnh->pldown = ptrav2->pdown;
					pnnh->prdown = pnnr;
					pnn->pdown = pnnh;
					l.insert(pnn);
				}
				else
				{
					if (ptrav2->pdown == NULL && ptrav3->pdown != NULL)
					{
						j = 0;
						pnnh = new Ctnode;
						pnnl = new Ctnode;
						pnn = new Cnode;
						pnnh->x = ptrav3->x + ptrav2->x;
						pnnl->x = ptrav2->x;
						pnn->x = pnnh->x;

						for (i = 0; ptrav2->y[i] != NULL; i++)
						{
							pnnl->y[j] = ptrav2->y[i];
						}
						for (i = 0; ptrav2->y[i] != NULL; i++)
						{
							pnnh->y[j] = ptrav2->y[i];
							j++;
						}
						for (i = 0; ptrav3->y[i] != NULL; i++)
						{
							pnnh->y[j] = ptrav3->y[i];
							j++;
						}
						for (i = 0; pnnh->y[i] != NULL; i++)
						{
							pnn->y[i] = pnnh->y[i];
						}
						pnnh->pldown = pnnl;
						pnnh->prdown = ptrav3->pdown;
						pnn->pdown = pnnh;
						l.insert(pnn);
					}
				}
			}
		}
	}

	ptrav = l.pHead;

	/*for (i = 0; ptrav != NULL;)
	{
	cout << ptrav->x;
	cout << " -> ";
	cout << ptrav->y<<endl;
	ptrav = ptrav->Pnext;
	}*/
	string y;
	Ctnode *pt = ptrav->pdown;
	pt = ptrav->pdown;


	Ctnode *pt2 = pt;
	int f = 0;
	t.zero(pt, pt2, y, f);
	//t.disp1(pt);
	//t.disp(pt);
	pt = ptrav->pdown;
	Clist l2;
	Cnode* pt3=NULL;
	t.list(pt, pt3,l2);
	pt3 = l2.pHead;
	for (i = 0; pt3 != NULL;)
	{
		cout << pt3->y[i]  << " -> "<<pt3->z << endl;
		
		pt3 = pt3->Pnext;
	}
	system("pause");
	unsigned char temp= 0;
	int ibit= 7;
	char mask = 1;
	char r;
	pt3 = l2.pHead;
	flag = 1;
	unsigned char compressed[100];
	f = 0;
	int k = 0;
	for (i = 0; x[i] != NULL; i++)
	{
		pt3 = l2.pHead;
		k = 0;
		while (pt3 != NULL)
		{

			if (pt3->y[k] == x[i])
			{
				break;
			}
			pt3 = pt3->Pnext;
			
			
		}
		for (j = 0; pt3->z[j] != NULL; j++)
		{
			if (pt3->z[j] == '1')
			{
				temp = temp | (mask << ibit);
				ibit--;
			}
			else
			{
				if (pt3->z[j] == '0')
				{
					ibit--;
				}
			}
			if (ibit < 0 || x[i+1]==NULL)
			{
				compressed[f] = temp;
				temp = 0;
				f++;
				ibit = 7;
			}
			
		}

	}
	for (i = 0; i<f; i++)
	{
		cout << compressed[i]<<endl ;	
	}
	system("pause");
}



