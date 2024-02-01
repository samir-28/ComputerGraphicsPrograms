#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;

int main(){
	 int gd = DETECT, gm;
     initgraph(&gd, &gm, "");
	 int x1,y1,x2,y2,x3,y3,sx,sy;
	 cout<<"Enter all the coordinates:"<<endl;
	 cin>>x1>>y1>>x2>>y2>>x3>>y3;
	 line(x1,y1,x2,y2);
	 line(x2,y2,x3,y3);
	 line(x3,y3,x1,y1);
	 cout<<"Enter the scaling factors:"<<endl;
	 cin>>sx>>sy;
 	 line(x1*sx,y1*sy,x2*sx,y2*sy);
	 line(x2*sx,y2*sy,x3*sx,y3*sy);
	 line(x3*sx,y3*sy,x1*sx,y1*sy);
	 cout<<endl;

	 getch();


}
