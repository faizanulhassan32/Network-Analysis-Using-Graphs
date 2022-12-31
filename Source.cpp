#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include"LinkList.h"
#include "stack.h"
#include "queue.h"
#include"DirectedGraph.h"
#include"UndirectedGraph.h"
#include<windows.h>
using namespace std;

// Global declarations
Graph* graph ;
UGraph* ugraph;
int* uarr ;
int nodes=0;
int edges=0;



void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



void initializer(int val)
{
	graph = new Graph(val);
	ugraph = new UGraph(val);
	uarr = new int[val];
}





void display()
{
	Color(11);
	cout<<endl<<endl;
	cout<<"\t                              *"<<endl;
	cout<<"\t                    *********************"<<endl;
	cout<<"\t          *****************************************"<<endl;
	cout<<"\t*************************************************************"<<endl;
	cout<<"\t*\t\t\t\t\t\t\t    *"<<endl;
	cout<<"\t *\t\t\t\t\t\t\t   *"<<endl;
	cout<<"\t  *\t\t\t\t\t\t\t  *"<<endl;
	cout<<"\t   *\t\t\t\t\t\t\t *"<<endl;
	cout<<"\t    *\t\t\t\t\t\t\t*"<<endl;
	cout<<"\t     *\t\t\t\t\t\t       *"<<endl;
	cout <<"\t<<<<<=     Welcome to Network Analysis Using Graphs    =>>>>>" << endl;
	cout<<"\t     *\t\t\t\t\t\t       *"<<endl;
	cout<<"\t    *\t\t\t\t\t\t\t*"<<endl;
	cout<<"\t   *\t\t\t\t\t\t\t *"<<endl;
	cout<<"\t  *\t\t\t\t\t\t\t  *"<<endl;
	cout<<"\t *\t\t\t\t\t\t\t   *"<<endl;
	cout<<"\t*\t\t\t\t\t\t\t    *"<<endl;
	cout<<"\t*************************************************************"<<endl;
	cout<<"\t          *****************************************"<<endl;
	cout<<"\t                    *********************"<<endl;
	cout<<"\t                              *"<<endl;

	cout << "\n\n";
	cout<<"\tSelect an option from the following "<<endl;
	cout<<"=============================================================================================================================";
	cout<<"\n||\t1.  To display number of nodes. \t\t || \t 2.  To display number of edges.\t\t\t   ||"<<endl;
	cout<<"=============================================================================================================================";
	cout<<"\n||\t3.  To display number of source nodes. \t\t || \t 4.  To display number of sink nodes.\t\t\t   ||"<<endl;
	cout<<"=============================================================================================================================";
	cout<<"\n||\t5.  To display number of isolated nodes. \t || \t 6.  To display number of bridge edges\t\t\t   ||"<<endl;
	cout<<"=============================================================================================================================";
	cout<<"\n||\t7.  To display number of articulation nodes \t || \t 8.  To display the shortest path length distribution.\t   ||"<<endl;
	cout<<"=============================================================================================================================";
	cout<<"\n||\t9.  To display the diameter of graph \t\t || \t 10.  To display in-degree distribution.\t\t   ||"<<endl;
	cout<<"=============================================================================================================================";
	cout<<"\n||\t11.  To display out-degree distribution. \t || \t 12.  To display the size of largest SCC.\t\t   ||"<<endl;
	cout<<"=============================================================================================================================";
	cout<<"\n||\t13.  To display size distribution of all SSCs. \t || \t 14.  To display the size of largest WCC\t\t   ||"<<endl;
	cout<<"=============================================================================================================================";
	cout<<"\n||\t15.  To display size distribution of all WSCs \t || \t 0.  To Exit the program.\t\t\t\t   ||"<<endl;
	cout<<"=============================================================================================================================";
}



void displaynodes()
{
	cout<<"\n\n\t\t=================================="<<endl;
	cout<<"\n\t\t The number of nodes are : "<<nodes;
	cout<<"\n\n\t\t=================================="<<endl;
}



void displayedges()
{
	cout<<"\n\n\t\t=================================="<<endl;
	cout<<"\n\t\t The number of edges are : "<<edges;
	cout<<"\n\n\t\t=================================="<<endl;
}



void indegreetable(int index,float degree)
{
	cout<<"\t\t"<<index<<"\t\t || \t\t  "<<degree<<"\t\t   ||"<<endl;
	cout<<"============================================================================="<<endl;
}
void forindegree(int val)
{
	cout<<"\n\n\n";
	cout<<"============================================================================="<<endl;
	cout<<"||\t Vertex Degree \t\t || \t Indegree Vertex Distribution\t   ||"<<endl;
	cout<<"============================================================================="<<endl;
	graph->idegreemaker(val);
	int maxin = graph->maxc(val);
	int testdegree=0;
	for ( int i=0 ; i<=maxin ; i++ )
	{
		for ( int j=0 ; j<val ; j++ )
		{
			if ( i == graph->ptr[j].ideg )
			{
				testdegree++;
			}
		}
		float ODD1 = (testdegree*1.0)/val;
		if (ODD1!=0){
		indegreetable(i,ODD1);
		}
		testdegree=0;
	}
}



void outdegreetable(int index,float degree)
{
	cout<<"\t\t"<<index<<"\t\t || \t\t  "<<degree<<"\t\t   ||"<<endl;
	cout<<"============================================================================="<<endl;
}
void foroutdegree(int val)
{
	cout<<"\n\n\n";
	cout<<"============================================================================="<<endl;
	cout<<"||\t Vertex Degree \t\t || \t Outdegree Vertex Distribution\t   ||"<<endl;
	cout<<"============================================================================="<<endl;
	int maxout = graph->list[0].odegree;
	for (int i=0 ; i<val ; i++)
	{
			if ( graph->list[i].odegree >  maxout )
			{
				maxout = graph->list[i].odegree; 
			}
	}
	int testdegree=0;
	for ( int i=0 ; i<=maxout ; i++ )
	{
		for ( int j=0 ; j<val ; j++ )
		{
			if ( i == graph->list[j].odegree )
			{
				testdegree++;
			}
		}
		float ODD = (testdegree*1.0)/val;
		if (ODD!=0){
		outdegreetable(i,ODD);
		}
		testdegree=0;
	}
}



void start()
{
	bool sbool=false , dbool = false , finaldec = true , var = false;
	int bcount = 1 , chkvar , inp = 0 , oindex=0 , iindex=0 , myarcount = 0 , otdegree = 0 , count=0 , seli = 0;
	ifstream myfile;
	string line;

	myfile.open("CA-GrQc.txt", ios::in);
	myfile.seekg(0);

	getline(myfile, line);
	getline(myfile, line);
	getline(myfile, line);

	string temp[5];		// for line 3
	int array[2] = { -99999,-99999 };	// for source and destination
	int source, dest;

	// for getting nodes and edges	
	stringstream tok(line);
	int i = 0;
	while (getline(tok, line, ' ')) {
		temp[i] = line;
		i++;
	}

	nodes = stoi(temp[2]);
	initializer(nodes);

   	getline(myfile, line);
	
	string temporary;

	while (getline(myfile, line))  {
		temporary = line;
		stringstream tok(line);
		int j = 0;
		while (getline(tok, line, char(9) ) )  
		{
			array[j] = stoi(line); 
			j++;
		}
		source = array[0];
		if (temporary.length() == 2||temporary.length()==1)	
			dest = -99999;
		else	
			dest = array[1];	

		

		for (int i = 0; i < myarcount; i++) 
		{
			if (source == uarr[i]) 
			{
				sbool = true;
			}
			if (dest==uarr[i]) 
			{
				dbool = true;
			}
		}
		if (!sbool&&source!=-99999) 
		{
			uarr[myarcount] = source;
			myarcount++;
		}
		for (int i = 0; i < myarcount; i++) 
		{
			if (dest == uarr[i]) 
			{
				dbool = true;
			}
		}
		if (!dbool&&dest!=-99999)
		{
			uarr[myarcount] = dest;
			myarcount++;
		}
		for (int i = 0; i < myarcount; i++) 
		{
			if (source == uarr[i]) 
			{
				oindex = i;
			}
			if (dest == uarr[i])
			{
				iindex = i;
			}
		}
		if (source != dest) 
		{
			
			
				ugraph->addEdge(oindex, dest, source);
				if (dest != -99999)
				{
				ugraph->addEdge(iindex, source, dest);
			}
		}
		if (bcount == 1) 
		{	
			chkvar = source;
		}
		if (source == chkvar) 
		{
			if (dest != -99999)
			{
				graph->addEdge(inp,dest,source);
				edges++;
			}
			else
			{
				graph->addsrc(inp, source);
				
			}	
		}
		else if(source!=chkvar) 
		{
			
			inp++;
			if (dest != -99999) 
			{
			
				edges++;
				otdegree++;
				graph->addEdge(inp, dest, source);
				bcount = 1;
				chkvar = source;
			}
			else 
			{
				graph->addsrc(inp, source);
				chkvar = source;
			}			
		}
		var = false;
		count++;
		bcount++;
		sbool = false;
		dbool = false;
		finaldec = true;
		seli++;
	}
}



int main(){

	display();
	start();
	int choice;

	while(1){
		cout<<"\n\tEnter your choice : ";
		cin>>choice;
		if ( choice<0 ) 
		{
			cout<<"\n\tINVALID!!!!! Enter again : ";
			cin>>choice;
		}
		if (choice==0)
			return 0;

		switch(choice){
			case 1:
				displaynodes();	// total no of nodes
				break;
			case 2:
				displayedges();	// no of edges
				break;
			case 3:
				graph->srchck(nodes);	// no of source nodes
				break;
			case 4:
				graph->sinkchck(nodes);	// no of sink nodes
				break;
			case 5:
				graph->isolatedcheck(nodes);	// no of isolated nodes
				break;
			case 6:
				ugraph->Bridge(nodes);	// no of bridge edges
				break;
			case 7:
				ugraph->articulation(nodes);
				break;
			case 8:
				cout<<"CASE 8"<<endl;
				break;
			case 9:
				cout<<"CASE 9"<<endl;
				break;
			case 10:
				forindegree(nodes);		// for in-degree distribution
				break;
			case 11:
				foroutdegree(nodes);		// for out degree distribution
				break;
			case 12:
				graph->SCC(false,nodes);
				break;
			case 13:
				graph->SCC(true,nodes);
				break;
			case 14:
				ugraph->WCC(true,nodes);
				break;
			case 15:
				ugraph->WCC(false,nodes);
				break;
		}
	}
	return 0;
}