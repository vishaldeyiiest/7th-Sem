#include <bits/stdc++.h>
#include "lexical.hpp"
using namespace std;

#define E 600
#define T 601
#define E1 602
#define T1 603
#define F 604
#define EMPTY 605
#define START 606
#define mk_p make_pair
#define pb push_back

typedef struct Grammar
{
	vector<int> V;
	vector<int> sigma;
	vector<map<int, vector<int> > > R;
	int start;  
}Grammar;

typedef map<pair<int,int>, vector<int> > mpv;
typedef pair<int, int> pp;

map<pair<int,int>, vector<int> > ptable;


void populate()
{
	ptable[mk_p(E, ID_TOK)].pb(T);
	ptable[mk_p(E, ID_TOK)].pb(E1);
	ptable[mk_p(E, LPAREN_TOK)].pb(T);
	ptable[mk_p(E, LPAREN_TOK)].pb(E1);
	ptable[mk_p(E1, ADDITION_TOK)].pb(ADDITION_TOK);
	ptable[mk_p(E1, ADDITION_TOK)].pb(T);
	ptable[mk_p(E1, ADDITION_TOK)].pb(E1);
	ptable[mk_p(E1, RPAREN_TOK)].pb(EMPTY);
	ptable[mk_p(E1, START)].pb(EMPTY);
	ptable[mk_p(T, ID_TOK)].pb(F);
	ptable[mk_p(T, ID_TOK)].pb(T1);
	ptable[mk_p(T, LPAREN_TOK)].pb(F);
	ptable[mk_p(T, LPAREN_TOK)].pb(T1);
	ptable[mk_p(T1, ADDITION_TOK)].pb(EMPTY);
	ptable[mk_p(T1, MULTI_TOK)].pb(MULTI_TOK);
	ptable[mk_p(T1, MULTI_TOK)].pb(F);
	ptable[mk_p(T1, MULTI_TOK)].pb(T1);
	ptable[mk_p(T1, RPAREN_TOK)].pb(EMPTY);
	ptable[mk_p(T1, START)].pb(EMPTY);
	ptable[mk_p(F, ID_TOK)].pb(ID_TOK);
	ptable[mk_p(F, LPAREN_TOK)].pb(LPAREN_TOK);
	ptable[mk_p(F, LPAREN_TOK)].pb(E);
	ptable[mk_p(F, LPAREN_TOK)].pb(RPAREN_TOK);

}

bool check_nonterminal(int a)
{
	if(a == E || a == T || a == E1 || a == T1 || a == F)
		return true;
	return false;
}

void display_map()
{
	mpv::iterator it;
    for(it = ptable.begin(); it != ptable.end(); it++)	
    {
    	pp left = it->first;
    	vector<int> vv = it->second;
    	printf("[%d %d] : ", left.first, left.second);
    	for(int i = 0; i < vv.size(); i++)
    		printf("%d ", vv[i]);
    	printf("\n");
    }
}
int parse(vector<int> a)
{
	stack<int> Stack;
	Stack.push(START);
	Stack.push(E);
	//int a[] = {ID_TOK, ADDITION_TOK, ID_TOK, MULTI_TOK, ID_TOK, START};
	int i = 0;
	int top = Stack.top();
	while(top != START)
	{
		printf("%d %d\n", top, a[i]);
		//check if stack end or terminals
		if(top == START || !check_nonterminal(top))
		{
			if(top == a[i])
			{
				Stack.pop();
				i++;
			}
			else{
				printf("ERROR: Terminals: %d not matching %d\n", top, a[i]);
				exit(1);
			}
		}
		else
		{
			vector<int> temp = ptable[mk_p(top, a[i])];
			if(temp.empty())
			{
				printf("ERROR: no such rule\n");
				exit(1);
			}
			Stack.pop();
			for(int it = temp.size()-1; it >= 0; it--)
				if(temp[it] != EMPTY)
					Stack.push(temp[it]);
		}
		top = Stack.top();
	}
	if(a[i] != START)
		return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	ifstream fpin;
	if(argc > 1)
		fpin.open(argv[1]);
	istream &in = (argc >= 2) ? fpin : cin;

	vector<int> buffer;
	
	while (true)
	{
    	int x;
    	fpin >> x;
    	if(fpin.eof()) 
    		break;
    	buffer.pb(x);
	}

	fpin.close();
	buffer.pb(START);
	for(int i = 0; i < buffer.size(); i++)
		printf("%d ", buffer[i]);
	printf("\n");

	populate();
	printf("Production Rules: \n");
	display_map();
	printf("Parsing started......!\n");
	if(parse(buffer))
		printf("Error: Characters in Buffer left..! :(\n");
	else
		printf("SUCCESS..!!..No syntax error... :)\n");
	return 0;
}
