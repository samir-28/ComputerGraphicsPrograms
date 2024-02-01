#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;
void rotation(float p,float q,float r,float s, float t){
		 line((p*cos(t))-(q*sin(t)),(p*sin(t))+(q*cos(t)),
		 (r*cos(t))-(s*sin(t)),(r*sin(t))+(s*cos(t)));
}

int main(){
	 int gd = DETECT, gm;
     initgraph(&gd, &gm, "");
	 float x1,y1,x2,y2,x3,y3,a,t;
	 float x4,y4,x5,y5,x6,y6;
	 cout<<"Enter all the coordinates:"<<endl;
	 cin>>x1>>y1>>x2>>y2>>x3>>y3;
	 line(x1,y1,x2,y2);
	 line(x2,y2,x3,y3);
	 line(x3,y3,x1,y1);
	 cout<<"Enter the angle for rotation:"<<endl;
	 cin>>a;
	 t=a*(3.14/180);	 
     rotation(x1,y1,x2,y2,t);
     rotation(x2,y2,x3,y3,t);
     rotation(x3,y3,x1,y1,t);
    
	 getch();


}
