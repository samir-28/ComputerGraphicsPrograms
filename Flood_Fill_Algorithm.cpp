#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
using namespace std;

void flood_fill(int x,int y,int old_color,int new_color){
	int value=getpixel(x,y);
	if(value==old_color)
	{
		putpixel(x,y,new_color);
		flood_fill(x-1,y,old_color,new_color);
		flood_fill(x+1,y,old_color,new_color);
		flood_fill(x,y-1,old_color,new_color);
		flood_fill(x,y+1,old_color,new_color);
		
	}
}
int main(){
	 int gd = DETECT, gm;
     initgraph(&gd, &gm, "");
	 int x,y,old_color,new_color;
	 cout<<"Enter the seed point(x,y):"<<endl;
	 cin>>x>>y;
	 cout<<"Enter the old color:"<<endl;
	 cin>>old_color;
	 cout<<"Enter the new color:"<<endl;
	 cin>>new_color;
	 circle(100,200,30);
	 flood_fill(x,y,old_color,new_color);
	
	 getch();


}
