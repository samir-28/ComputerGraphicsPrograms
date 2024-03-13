#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;
void reflection(float x,float y){
	cout<<"\t"<< "("<< x<<","<< y<<")"<<"\t"<<"\t";
	cout<< "("<< x<< "," <<-y <<")"<<"\t";
	cout<< "("<< -x<<","<< y<<")"<<"\t";
	cout<< "("<< -x<<","<< -y<<")"<<endl;
	
	
}

int main(){
	 int gd = DETECT, gm;
     initgraph(&gd, &gm, "");
	 float x1,y1,x2,y2,x3,y3;
	 cout<<"Enter all the coordinates:"<<endl;
	 cin>>x1>>y1>>x2>>y2>>x3>>y3;
	 cout<<"\t"<<"Coordinates after reflection:"<<endl;
	 cout<<"Original Coordinate"<<"\t"<<"X-axis"<<"\t"<<"Y-aixs"<<"\t"<<"Origin"<<endl;
	 reflection(x1,y1);
	 reflection(x2,y2);
	 reflection(x3,y3);
	 
	 getch();
}
