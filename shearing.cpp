#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;
void coordinates(float x,float y,float shx,float shy){
	cout<<"\t"<< "("<< x<<","<<y<<")"<<"\t"<<"\t";
	cout<<"("<< x+(shx*y)<<","<<y <<")"<<"\t"<<"\t";
	cout<<"("<< x<<","<<(x*shy)+y<<")"<<endl;
}
void shear(float a,float b,float c,float d,float shx,float shy){
	line((a+shx*b),b,(c+shx*d),d);
	line(a,(a*shy+b),c,(c*shy+d));
}
int main(){
	 int gd = DETECT, gm;
     initgraph(&gd, &gm, "");
	 float x1,y1,x2,y2,x3,y3,x4,y4,shx,shy;
	 cout<<"Enter all the coordinates:"<<endl;
	 cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	 cout<<"Enter Shearing factors:"<<endl;
	 cin>>shx>>shy;
	 line(x1,y1,x2,y2);
	 line(x2,y2,x3,y3);
	 line(x3,y3,x4,y4);
	 line(x4,y4,x1,y1);
	 cout<<"\t"<<"Coordinates after Shearing:"<<endl;
	 cout<<   "Original Coordinate"<<"\t"<<"X-direction"<<"\t"<<"Y-direction"<<endl;
	 coordinates(x1,y1,shx,shy);
	 coordinates(x2,y2,shx,shy);
	 coordinates(x3,y3,shx,shy);
	 coordinates(x4,y4,shx,shy);
	 shear(x1,y1,x2,y2,shx,shy);
	 shear(x2,y2,x3,y3,shx,shy);
	 shear(x3,y3,x4,y4,shx,shy);
	 shear(x4,y4,x1,y1,shx,shy); 
	 getch();
}
	 
