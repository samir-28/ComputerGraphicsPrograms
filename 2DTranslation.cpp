#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;

int main(){
	 int gd = DETECT, gm;
     initgraph(&gd, &gm, "");
	 int x1,y1,x2,y2,x3,y3,tx,ty;
	 cout<<"Enter all the coordinates:"<<endl;
	 cin>>x1>>y1>>x2>>y2>>x3>>y3;
	 line(x1,y1,x2,y2);
	 line(x2,y2,x3,y3);
	 line(x3,y3,x1,y1);
	 cout<<"Enter the translation distances:"<<endl;
	 cin>>tx>>ty;
 	line(x1+tx,y1+ty,x2+tx,y2+ty);
	line(x2+tx,y2+ty,x3+tx,y3+ty);
	line(x3+tx,y3+ty,x1+tx,y1+ty);
	
	 getch();


}
