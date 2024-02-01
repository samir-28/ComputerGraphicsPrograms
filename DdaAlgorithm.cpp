#include <graphics.h>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<math.h>
using namespace std;

int main(){
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   float x1,y1,x2,y2,dx,dy,steplength ,xIncrement,yIncrement,x,y;
   int i=0;
   cout<<"Enter the starting point(x1,y1) and ending point(x2,y2) of the line :"<<endl;
   cin>>x1>>y1>>x2>>y2;
   dx=x2-x1;
   dy=y2-y1;
   
   if(abs(dx)>abs(dy)){
   	steplength=abs(dx);
   }
   else{
   	steplength=abs(dy);
   }
   
    xIncrement= dx/steplength;
	yIncrement=dy/steplength;
	x=x1;
	y=y1;
	putpixel(round(x),round(y),WHITE);
	cout<<"   Iteration"<<"\t"<<  "X"<<"\t"<<"\t"<< "Y"<<"\t"<< "(Xk+1,yk+1)"<<"\t"<< "Round value"<<endl<<endl;
	for(int i=0;i<steplength;i++)
	{   putpixel(round(x),round(y),WHITE);
	    cout<<"\t"<<i<<"\t";
		cout<<x<<"\t"<<"\t";
		cout<<y<<"\t";
		cout<<"("<< x+xIncrement<<","<< y+yIncrement <<")" << "\t";
		cout<<"\t""("<< round(x+xIncrement) << "," << round(y+yIncrement)<<")"<<endl;
		x=x+xIncrement;
	    y=y+yIncrement;
	}   
		getch();
   
	  
}
