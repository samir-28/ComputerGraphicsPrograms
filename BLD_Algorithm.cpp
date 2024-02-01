#include <graphics.h>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<math.h>
using namespace std;

int main(){
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   float x1,y1,x2,y2,dx,dy,p,x,y,m;
   int i=1;
   cout<<"Enter the starting point(x1,y1) and ending point(x2,y2) of the line :"<<endl;
   cin>>x1>>y1>>x2>>y2;
   dx=abs(x2-x1);
   dy=abs(y2-y1);
   x=x1;
   y=y1;
   m=dy/dx;
   if(m<=1){
    p=2*dy-dx;
	cout<<"   Iteration"<<"\t"<<  "X"<<"\t"<< "Y"<<"\t"<<"Pk"<<"\t"<<"(Xk+1,yk+1)"<<endl<<endl;
	for(int i=1;i<=dx;i++)
	{  
	 if(p<0)
	{   
		putpixel(x,y,WHITE);
		cout<<"\t"<<i<<"\t";
		cout<<x<<"\t";
		cout<<y<<"\t";
		cout<<p<<"\t";
		cout<<"("<< x+1 <<","<< y <<")"<<endl;
		x=x+1;
		p=p+2*dy;
	}
	else{
		putpixel(x,y,WHITE);
		cout<<"\t"<<i<<"\t";
		cout<<x<<"\t";
		cout<<y<<"\t";
		cout<<p<<"\t";
		cout<<"("<< x+1 <<","<< y+1 <<")"<<endl;
		x=x+1;
		y=y+1;
		p=p+2*dy-2*dx;
	}
}
}
else{
	 p=2*dx-dy;
	cout<<"   Iteration"<<"\t"<<  "X"<<"\t"<< "Y"<<"\t"<<"Pk"<<"\t"<<"(Xk+1,yk+1)"<<endl<<endl;
	for(int i=1;i<=dy;i++)
	{  
	 if(p<0)
	{   
		putpixel(x,y,WHITE);
		cout<<"\t"<<i<<"\t";
		cout<<x<<"\t";
		cout<<y<<"\t";
		cout<<p<<"\t";

		cout<<"("<< x <<","<< y+1 <<")"<<endl;
		y=y+1;
		p=p+2*dx;
	}
	else{
		putpixel(x,y,WHITE);
		cout<<"\t"<<i<<"\t";
		cout<<x<<"\t";
		cout<<y<<"\t";
		cout<<p<<"\t";
		cout<<"("<< x+1 <<","<< y+1 <<")"<<endl;
		x=x+1;
		y=y+1;
		p=p+2*dx-2*dy;
	}
}
}
		getch();

	  
}
