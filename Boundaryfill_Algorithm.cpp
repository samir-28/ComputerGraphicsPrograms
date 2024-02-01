#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;

void boundary_fill(int x,int y,int f_color,int b_color){
	int value=getpixel(x,y);
	if(value!=b_color && value!=f_color)
	{
		putpixel(x,y,f_color);
		boundary_fill(x+1,y,f_color,b_color);
		boundary_fill(x-1,y,f_color,b_color);
		boundary_fill(x,y+1,f_color,b_color);
		boundary_fill(x,y-1,f_color,b_color);
		
	}
}
int main(){
	 int gd = DETECT, gm;
     initgraph(&gd, &gm, "");
	 int x,y,f_color,b_color;
	 cout<<"Enter the seed point(x,y):"<<endl;
	 cin>>x>>y;
	 cout<<"Enter the fill color:"<<endl;
	 cin>>f_color;
	 cout<<"Enter the boundary color:"<<endl;
	 cin>>b_color;
	 circle(100,100,50);
	 boundary_fill(x,y,f_color,b_color);
	 
	
	 getch();


}
