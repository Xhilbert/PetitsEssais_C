#include "stdafx.h"
#include <map>

using namespace std;

class Classe { public : int v; };

typedef map<float,Classe> mapGL;
mapGL PGL;

Classe* GetState(float d) {
	mapGL::iterator it=PGL.lower_bound(d); 
	if(d<it->first && (it!=PGL.begin())) it--; 
	return &(it->second);
}

int main()
{
	PGL[0] .v=0;
	PGL[10].v=10;
	PGL[20].v=20;
	PGL[30].v=30;
	for (auto p:PGL) printf("%f %d\n",p.first,p.second.v);
	
	Classe* pt = GetState(-1);
	pt->v = 15;

	for (auto p:PGL) printf("%f %d\n",p.first,p.second.v);

	getchar();
    return 0;
}

