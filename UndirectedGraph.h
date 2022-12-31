#pragma once
#include"LinkList.h"
#include"Stack.h"

class UGraph {
	int V;
public:
	List* list;

	UGraph(int V) 
	{
		this->V = V;
		list = new List[V];
	}
	
	
	
	void addEdge(int m, int v, int r)
	{
		bool zap = true;
		Node*t=list[m].getHead();
			while (t!=NULL)
			{
				if (t->val == v)
				{
					zap = false;
				}
				t = t->next;
			}
		if (zap)
		{
			list[m].add(v);
			list[m].source = r;
		}
	}
	
	
	
	void addsrc(int l, int s)
	{
		list[l].source = s;
	}
	
	
	
	void print(int m)
	{
		for (int i = 0; i < m; i++)
		{
			Node* temp = list[i].getHead();
			cout << list[i].source << " -> ";
			while (temp != NULL)
			{
				cout << temp->val << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	
	


	












	
	int BDFS(int s,int fn,int tn,int asize )
	{
		int* visited = new int[asize];
		int k = 0;
		int mv;
		Stack<int> S1;
		S1.Push(s);

		visited[k] = s;
		k = k + 1;
		Node* Temp = NULL;
		while (!S1.isEmpty())
		{			
			int v = S1.Peak();
			S1.Pop();
			Node* pk;
			for (int i = 0; i < asize; i++)
			{
				if (v == list[i].source)
				{
					mv = list[i].source;
					Temp = list[i].getHead();
					break;
				}
			}
			while (Temp != NULL)
			{
				if (mv == fn && Temp->val == tn)
				{
					Temp = Temp->next;
					continue;
				}
				bool check = false;
				int t2 = Temp->val;
				for (int j = 0; j < k; j++)
				{
					if (t2 == visited[j])
					{
						check = true;
					}
				}
				if (check == false)
				{
					visited[k] = t2;
					k = k + 1;
					S1.Push(t2);
				}
				Temp = Temp->next;
			}
		}
		return k;
	}



	int ADFS(int s,int c,int asize)
	{

		int* visited = new int[asize];
		int k = 0;
		int mv=0;
		Stack<int> S1;
		S1.Push(s);

		visited[k] = s;
		k = k + 1;
		Node* Temp = NULL;
		while (!S1.isEmpty())
		{
			int v = S1.Peak();
			S1.Pop();
			Node* pk;
			for (int i = 0; i < asize; i++)
			{
				if (v == list[i].source)
				{
					mv = list[i].source;
					Temp = list[i].getHead();
					break;
				}
			}
			if (mv != c)
			{
				while (Temp != NULL)
				{
					if (Temp->val == c)
					{
						Temp = Temp->next;
						continue;
					}
					bool check = false;
					int t2 = Temp->val;
					for (int j = 0; j < k; j++)
					{
						if (t2 == visited[j])
						{
							check = true;
						}
					}
					if (check == false)
					{
						visited[k] = t2;
						k = k + 1;
						S1.Push(t2);
					}
					Temp = Temp->next;
				}
			}
		}
			return k;
	}


	int chkbfs(int s, int asize)
	{
		int t = 0;
		queue<int> q;
		int ccount = 0;
		bool var = false;
		int v;
		int* reachable = new int[asize];
		for (int i = 0; i < asize; i++) {
			reachable[i] = 0;
		}
		reachable[ccount] = s;
		ccount++;

		q.enqueue(s);
		while (!q.isEmpty())
		{
			v = q.dequeue();
			for (int i = 0; i < asize; i++)
			{
				if (list[i].source == v)
				{
					Node* temp = list[i].getHead();
					while (temp != NULL)
					{
						var = false;
						for (int q = 0; q < ccount; q++)
						{
							if (temp->val == reachable[q])
							{
								var = true;
							}
						}
						if (!var)
						{
							q.enqueue(temp->val);
							t++;
							reachable[ccount] = temp->val;
							ccount++;
						}
						temp = temp->next;
					}
					break;
				}
			}
		}
		return t;
	}




	void Bridge(int gnodes)
	{
		int count=0;
		int gtest = 11;
		int **arr=new int* [gnodes];
		for (int i = 0; i < gnodes; i++)
		{
			arr[i] = new int[2];
		}
		int r = 0;
		int c = 0;
		int ret = 0;
		//int alpha = 0;
	for (int i = 0; i < gnodes; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < gnodes; i++)
		{
			Node*tem = list[i].getHead();
			while (tem != NULL)
			{
				int test = chkbfs(tem->val,gnodes);
				c = 0;
				ret = BDFS(list[i].source, list[i].source, tem->val,gnodes);
				if (ret < test)
				{
					cout << list[i].source << "     " << tem->val << endl;
					arr[r][c] = list[i].source;
					c++;
					arr[r][c] = tem->val;
					r++;
					count++;					
				}
				tem = tem->next;
			}
		}
		cout<<"\n\n\t\t=================================="<<endl;
		cout<<"\n\t\tThe number of bridges are : "<<count/2;
		cout<<"\n\n\t\t=================================="<<endl;	
	}

	void articulation(int gnodes)
	{
		int counter=0;
		int test;
		int *arr=new int [gnodes];
		int m;
		for (int i = 0; i < gnodes; i++){
			arr[i] = 0;
		}
		
		for (int i = 0; i < gnodes; i++)
		{
			test = chkbfs(list[i+1].source, gnodes);
			m = ADFS(list[i].source,list[i+1].source,gnodes);
			if (m < (test-1))
			{
				//cout << list[i + 1].source<<endl;
				counter++;
			}
		}
		m = ADFS(list[1].source, list[0].source,gnodes);
		test = chkbfs(list[0].source, gnodes);
		if (m < (test - 1))
		{
			counter++;
		//	cout  << list[0].source << endl;
		}
		cout<<"\n\n\t\t=================================="<<endl;
		cout<<"\n\t\tThe number of articulation nodes are : "<<counter;
		cout<<"\n\n\t\t=================================="<<endl;	
	}



	int* cbfs(int s,int asize)
	{
		queue<int> q;
		int ccount = 0;
		bool var = false;
		int v;
		int* reachable = new int[asize];
		for (int i = 0; i < asize; i++) {
			reachable[i] = 0;
		}
		reachable[ccount] = s;
		ccount++;

		q.enqueue(s);
		while (!q.isEmpty())
		{
			v = q.dequeue();
			for (int i = 0; i < asize; i++)
			{
				if (list[i].source == v)
				{
					Node* temp = list[i].getHead();
					while (temp != NULL)
					{
						var = false;
						for (int q = 0; q < ccount; q++)
						{
							if (temp->val == reachable[q])
							{
								var = true;
							}
						}
						if (!var)
						{
							q.enqueue(temp->val);
							reachable[ccount] = temp->val;
							ccount++;
						}
						temp = temp->next;
					}
					break;
				}
			}
		}
		return reachable;
	}



	void WCC( bool var,int gnodes )
	{
		int rcount = 0;
		int** unique = new int* [gnodes];
		int** wcc = new int* [gnodes];
		for (int i = 0; i < gnodes; i++)
		{
			unique[i] = new int[gnodes];
			wcc[i] = new int[gnodes];
		}
		for (int i = 0; i < gnodes; i++)
		{
			for (int j = 0; j < gnodes; j++)
			{
				unique[i][j] = -1;
				wcc[i][j] = -1;
			}
		}
		
		
		
				
			 

		for(int i=0;i<gnodes;i++)
		{
			int* temp = cbfs(list[i].source,gnodes);
			
			
			for (int k = 0; k < gnodes; k++)
			{
				wcc[i][k] = temp[k];
			}
		}

		for (int i = 0; i < gnodes; i++)
		{
			bool match = false;
			for (int j = 0; j < i; j++)
			{
				match = true;
				for (int k = 0; k < gnodes; k++)
				{

					if (wcc[i][k] != wcc[j][k])
					{
						match = false;

					}
				}
				if (match)
				{
					break;
				}
			}
			if (!match)
			{
				for (int t = 0; t < gnodes; t++)
				{
				
					unique[rcount][t] = wcc[i][t];
				}
				rcount++;
			}
		}

		int maxs = 0;
		int counter;
		int* largestnetwotk = new int[gnodes];


		for (int i = 0; i < gnodes; i++)
		{
			largestnetwotk[i] = -1;
		}

		int saviour;
		for (int i = 0; i < gnodes; i++)
		{
			counter = 0;
			for (int j = 0; j < gnodes; j++)
			{
				if (unique[i][j] != -1&&unique[i][j]!=0)
				{
					counter++;
				}
				else
				{
					break;
				}
			}
			if (counter > maxs)
			{
				maxs = counter;
				saviour = i;
			}
		}

		for (int j = 0; j < gnodes; j++)
		{
			if (unique[saviour][j] != -1)
				largestnetwotk[j] = unique[saviour][j];
		}


		//ya wala part 1 k lia ha
		if (var) {
			cout<<"\n\t\t=================================="<<endl;	
			cout << "\n\t\tThe size of largest WCC is : " <<maxs<< endl;
			cout<<"\n\t\t=================================="<<endl;
			cout << "\n\t\tLargest Network  is : "  << endl<<endl;
			cout<<"\t\t";
			for (int i = 0; i < gnodes; i++)
			{
				if(largestnetwotk[i]!=-1 && largestnetwotk[i] != 0)
				cout << largestnetwotk[i] << "\t";
			}
			cout<<"\n\n\t\t=================================="<<endl;
		}

		int* holder = new int[maxs];
		int counth = 0;
		int ccount;
		for (int l = 1; l <= maxs; l++)
		{

			counth = 0;
			for (int i = 0; i < gnodes; i++)
			{
				ccount = 0;
				for (int j = 0; j < gnodes; j++)
				{
					if (wcc[i][j] != -1&&wcc[i][j]!=0/*&& wcc[i][j]!=-99999*/)
					{
				
						ccount++;
					}
					else
					{
						break;
					}

				}
			//	cout << ccount<<endl;
				if (ccount == l)
				{
					
					counth++;

				}
			}
			//cout << "test" << counth << endl;
			holder[l - 1] = counth;
		}

		if (!var)
		{
			cout<<"\n=============================================================";
			cout<<"\n\tNetwork size \t || \t Network distribution"<<endl;
			cout<<"=============================================================";
			for (int i = 0; i <maxs; i++)
			{
				cout<<"\n\t    "<<i+1<<"\t\t ||\t\t"<< holder[i] << endl;	
				cout<<"=============================================================";		
			}
			cout<<endl;
		}
	}

};