#include <graphics.h>
#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
int main(){
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   float x,y;
   cout<<"Enter the coordinates (x,y) of the circle :"<<endl;
   cin>>x>>y;
   putpixel(x,y,WHITE);
   getch();
}
   
