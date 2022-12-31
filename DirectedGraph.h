#pragma once
#include"LinkList.h"
#include"Stack.h"
#include"Queue.h"
struct opairs
{
	int nodev;
	int ideg;
	opairs()
	{
		nodev = 0;
		ideg = 0;
	}
};
class Graph {
	int V;
public:
	List* list;
	Graph(int V)
	{
		this->V = V;
		list = new List[V];
	}
	void addEdge(int m, int v, int r)
	{
		list[m].add(v);
		list[m].odegree++;
		list[m].source = r;
	}
	void addsrc(int l, int s)
	{
		list[l].source = s;

	}
	void print(int l, int checkvar)
	{
		for (int i = 0; i < l; i++)
		{
			if (list[i].source == checkvar)
			{
				Node* temp = list[i].getHead();
				cout << list[i].source << " -> ";
				while (temp != NULL)
				{
					cout << temp->val << " ";
					temp = temp->next;
				}
				cout << endl;
				break;
			}
		}
	}



	void srchck(int until)
	{
		bool test;
		int counter = 0;
		bool chk = false;
		bool fai;
		for (int i = 0; i < until; i++)
		{
			fai = false;
			int k = list[i].source;
			for (int t = 0; t < until; t++)
			{
				Node* temp = list[t].getHead();
				while (temp != NULL)
				{

					if (temp->val == list[i].source)
					{
						fai = true;
						break;
					}
					temp = temp->next;
				}
				if (fai)
				{
					break;
				}

			}
			if (!fai)
			{
				counter++;
			}
		}



		/*for (int i = 0; i < until; i++)
		{
			Node*temp = list[i].getHead();
			if ( temp== NULL )
			{

				test=false;
				for ( int s=0 ; s<until ; s++ ){
					Node* star = list[s].getHead();
					while (star != NULL){
						if ( star->val == list[i].source ){
							test = true;
							break ;
							}
						star = star->next;
					}
					if ( test )
					{	break;	}
				}
				if ( !test ){
					counter++;
				}
			}
			else
			{
				cout << "hello";
				while (temp != NULL)
				{

					if (temp->idegree == 0)
					{
						counter++;
						chk = true;
					}
					temp = temp->next;
				}
			}
		}*/

		cout << "\n\n\t\t==================================" << endl;
		cout << "\n\t\tThe no of source nodes : " << counter;
		cout << "\n\n\t\t==================================" << endl;


	}


	void sinkchck(int until)
	{
		int counter = 0;
		bool chk = false;
		for (int i = 0; i < until; i++)
		{
			int t;
			t = list[i].odegree;
			if (t == 0)
			{
				counter++;
				chk = true;
			}
		}
		if (chk)
		{
			cout << "\n\n\t\t==================================" << endl;
			cout << "\n\t\tThe no of sink nodes : " << counter;
			cout << "\n\n\t\t==================================" << endl;
		}
		else
		{
			cout << "\n\n\t\t==================================" << endl;
			cout << "\n\t\tThere are no sink nodes";
			cout << "\n\n\t\t==================================" << endl;
		}
	}


	/*void  degdistib()
	{
		int pc=0;
		for (int i = 0; i < 5242; i++)
		{
			Node* temp = list[i].getHead();
			if (list[i].odegree == 3)
			{
				pc++;
			}
		}

		double d = (pc * 1.0) / 5242;
		cout <<d<<endl;
	}*/


	opairs* ptr;
	void idegreemaker(int n)
	{
		ptr = new opairs[n];
		for (int i = 0; i < n; i++)
		{
			ptr[i].nodev = list[i].source;
			for (int r = 0; r < n; r++)
			{
				Node* temp = list[r].getHead();
				while (temp != NULL)
				{
					if (temp->val == ptr[i].nodev)
					{
						ptr[i].ideg = ptr[i].ideg + temp->idegree;
					}
					temp = temp->next;
				}
			}

		}
	}

	/*void distib(int l)
	{
		int scount = 0;
		for (int i = 0; i < 5242; i++)
		{
			if (ptr[i].ideg == l)
			{
				scount++;
			}
		}
		cout << scount << endl;
	}*/


	int maxc(int n)
	{
		int max = ptr[0].ideg;
		for (int i = 0; i < n; i++)
		{
			if (ptr[i].ideg > max)
			{
				max = ptr[i].ideg;
			}
		}
		return max;
	}

	void isolatedcheck(int until)
	{
		bool test;
		int counter = 0;
		int tempo = 0;
		bool chk = false;
		for (int i = 0; i < until; i++)
		{
			Node* temp = list[i].getHead();
			if (temp == NULL)
			{
				test = false;
				for (int s = 0; s < until; s++) {
					Node* star = list[s].getHead();
					while (star != NULL) {
						if (star->val == list[i].source) {
							test = true;
							break;
						}
						star = star->next;
					}
					if (test)
					{
						break;
					}
				}
				if (!test) {
					counter++;
				}
			}
			while (temp != NULL)
			{
				for (int j = 0; j < until; j++)
				{
					if (temp->val == list[j].source)
					{
						tempo = j;
						break;
					}
				}
				if (temp->idegree == 0 && list[tempo].odegree == 0)
				{

					counter++;
					chk = true;
				}
				temp = temp->next;
			}
		}
		cout << "\n\n\t\t==================================" << endl;
		cout << "\n\t\tThe no of isolated nodes : " << counter;
		cout << "\n\n\t\t==================================" << endl;

	}

	void DFS(int s, int asize)
	{
		int* visited = new int[asize];
		int k = 0;

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
				//pk = list[i].getHead();

				if (v == list[i].source)
				{
					Temp = list[i].getHead();
					break;
				}
				//pk = pk->next;
			}


			while (Temp != NULL)
			{

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
		//cout << "K :" << k << std::endl;
	}

	int* cbfs(int s, int asize)
	{
		queue<int> q;
		int ccount = 0;
		bool var = false;
		int v;
		int* reachable = new int[asize];
		for (int i = 0; i < asize; i++)
		{

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




	int* in(int s, int asize)
	{
		int* testptr;
		int* Inarray = new int[asize];
		for (int i = 0; i < asize; i++)
		{

			Inarray[i] = 0;

		}
		int icount = 0;
		for (int i = 0; i < asize; i++)
		{
			testptr = cbfs(list[i].source, asize);
			for (int z = 0; z < asize; z++)
			{
				if (s == testptr[z])
				{
					Inarray[icount] = list[i].source;
					icount++;
					break;
				}
			}

		}
		return Inarray;
	}


	int* out(int m, int asize)
	{
		int* oarray = new int[asize];
		for (int i = 0; i < asize; i++)
		{
			oarray[i] = 0;
		}
		oarray = cbfs(m, asize);
		return oarray;
	}


	int** SCC(bool var, int until)
	{
		int rc = 0;
		int* tp1;
		int* tp2;

		int rcount = 0;
		int** scc = new int* [until];
		int** unique = new int* [until];
		for (int i = 0; i < until; i++)
		{
			unique[i] = new int[until];
			scc[i] = new int[until];
		}
		int uc = 0;





		for (int i = 0; i < until; i++)
		{
			for (int j = 0; j < until; j++)
			{
				unique[i][j] = -1;
				scc[i][j] = -1;
			}
		}
		for (int m = 0; m < until; m++)
		{
			rc = 0;
			tp1 = in(list[m].source, until);
			tp2 = out(list[m].source, until);
			for (int i = 0; i < until; i++)
			{
				int k = tp1[i];
				for (int j = 0; j < until; j++)
				{
					if (tp2[j] == k && tp2[j] != 0)
					{
						scc[m][rc] = k;
						rc++;
					}

				}
			}

		}

		for (int i = 0; i < until; i++)
		{
			bool match = false;
			for (int j = 0; j < i; j++)
			{
				match = true;
				for (int k = 0; k < until; k++)
				{

					if (scc[i][k] != scc[j][k])
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
				for (int t = 0; t < until; t++)
				{
					unique[rcount][t] = scc[i][t];
				}
				rcount++;
			}
		}

		int maxs = 0;
		int counter;
		int* largestnetwotk = new int[until];


		for (int i = 0; i < until; i++)
		{
			largestnetwotk[i] = -1;
		}


		int saviour;


		for (int i = 0; i < until; i++)
		{
			counter = 0;
			for (int j = 0; j < until; j++)
			{
				if (unique[i][j] != -1)
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

		for (int j = 0; j < until; j++)
		{
			if (unique[saviour][j] != -1)
				largestnetwotk[j] = unique[saviour][j];
		}

		if (!var) {
			cout << "\n\t\t==================================" << endl;
			cout << "\n\t\tThe size of largest SCC is : " << maxs << endl;
			cout << "\n\t\t==================================" << endl;
			cout << "\n\t\tLargest Network is" << endl << endl;
			cout << "\t\t";
			for (int i = 0; i < until; i++)
			{
				if (largestnetwotk[i] != -1)
					cout << largestnetwotk[i] << "\t";
			}
			cout << "\n\n\t\t==================================" << endl;
		}
		int* holder = new int[maxs];
		int counth = 0;
		int ccount;
		for (int l = 1; l <= maxs; l++)
		{

			counth = 0;
			for (int i = 0; i < until; i++)
			{
				ccount = 0;
				for (int j = 0; j < until; j++)
				{
					if (scc[i][j] != -1)
					{
						ccount++;
					}
					else
					{
						break;
					}

				}
				if (ccount == l)
				{

					counth++;

				}
			}

			holder[l - 1] = counth;
		}
		
		if (var) {
			cout << "\n=============================================================";
			cout << "\n\tNetwork size \t || \t Network distribution" << endl;
			cout << "=============================================================";
			for (int i = 0; i < maxs; i++)
			{
				cout << "\n\t    " << i + 1 << "\t\t ||\t\t" << holder[i] << endl;
				cout << "=============================================================";
			}
			cout << endl;
		}
		return unique;
	}
};