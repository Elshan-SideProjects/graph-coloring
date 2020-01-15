#include <iostream>
#include <stdio.h>
#define m 100
using namespace std;

struct vertex 
{
  
int adj[m];
   
int color;
 
};

int
main () 
{
  
bool reng[m];
  
int rr = 0;
  
for (rr = 0; rr < m; rr++)
    
    {
      
reng[rr] = false;
    
}
  
struct vertex V[m];
  
int aa = 0;
  
int bb = 0;
  
int cc = 0;
  
for (aa = 0; aa < m; aa++)
    
    {
      
for (bb = 0; bb < m; bb++)
	
	{
	  
V[aa].adj[bb] = 222;
	
}
    
}
  
for (cc = 0; cc < m; cc++)
    
    {
      
V[cc].color = 111;
    
}
  
cout << "Enter the number of nodes" << endl;
  
int n = 0;
  
scanf ("%d", &n);
  
int qq = 0;
  
int ff = 0;			// to count adj nodes
  int ww = 0;			// to count neigbours
  int st = 10000;
  
for (qq = 0; qq < n; qq++)
    
    {
      
cout << "How many adjacent nodes does " << qq << " have\?" << endl;
      
scanf ("%d", &ff);
      
cout << "Please enter them" << endl;
      
for (ww = 0; ww < ff; ww++)
	{
	  scanf ("%d", &st);
	  st = V[qq].adj[ww];
	}
    
}
  
V[0].color = 0;
  
int n_c = 1;
  
//bool rab = false;
  int ii = 1;
  
int jj = 0;
  
int kk = 0;
  
int c = 0;			// to clean the reng array
  int storage = 999;
  
for (ii = 1; ii < n; ii++)
    
    {
      
while (V[ii].adj[jj] < 222)
	
	{
	  
if (V[V[ii].adj[jj]].color < 111)
	    
	    {
	      storage = V[ii].adj[jj];
	      
reng[storage] = true;
	    
}
	  
jj++;
	
}
      
int shot = 0;
      
for (kk = 0; kk < n_c; kk++)
	
	{
	  
if (reng[kk] == false)
	    {
	      V[ii].color = kk;
	    }
	  
	  else if (reng[kk] == true)
	    {
	      shot++;
	    }
	  
if (shot == n_c)
	    {
	      V[ii].color = n_c;
	      n_c++;
	    }
	
}
      
	// rab = false;
	for (c = 0; c < m; c++)
	{
	  reng[c] = false;
	}
    
}
  
int ee = 0;
  
for (ee = 0; ee < n; ee++)
    
    {
      
printf ("color of %d is %d\n", ee, V[ee].color);
    
}
  
return 0;
}
