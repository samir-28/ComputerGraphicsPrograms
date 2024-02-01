#include <graphics.h>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<math.h>
using namespace std;

void display_attribute(float x, float xc, float y, float yc){
			cout<<"("<< x+xc <<","<< y+yc  <<")" <<"\t";
		    cout<<"("<< -x+xc <<","<< y+yc <<")" <<"\t";
		    cout<<"("<< x+xc <<","<< -y+yc <<")" <<"\t"; 
			cout<<"("<< -x+xc <<","<<-y+yc <<")" <<"\t";
			cout<<"("<< y+xc <<","<< x+yc  <<")" <<"\t";
			cout<<"("<< -y+xc <<","<< x+yc<<")"<<"\t";
			cout<<"("<< y+xc <<","<< -x+yc <<")" <<"\t";
			cout<<"("<< -y+xc <<","<< -x+yc <<")"<<endl;
}

int main(){
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   float r,xc,yc,p,x,y;
   int i=1;
   cout<<"Enter the radius and center(xc,yc) of the circle :"<<endl;
   cin>>r>>xc>>yc;
   x=0;
   y=r;
   p=1-r;
   cout<<"    Iteration"<<"\t"<<"P"<<"\t"<<"(Xk+1,yk+1)"<<"\t"<<"2(Xk+1)"<<"\t"<<" 2(Yk+1)"<<endl<<endl;
   while(x<y)
   {
   	    putpixel(x+xc,y+yc,WHITE);
   		putpixel(-x+xc,y+yc,WHITE);
   		putpixel(x+xc,-y+yc,WHITE);
   		putpixel(-x+xc,-y+yc,WHITE);
   		putpixel(y+xc,x+yc,WHITE);
   		putpixel(-y+xc,x+yc,WHITE);
   		putpixel(y+xc,-x+yc,WHITE);
		putpixel(-y+xc,-x+yc,WHITE);
		
		if(p<0)
		{  
			cout<<"\t"<<i<<"\t";
			cout<<p<<"\t";
			cout<<"("<< x+1<<","<< y <<")"<<"\t";
			cout<<"\t"<<2*(x+1)<<"\t";
		    cout<<2*y<<endl;
			x=x+1;
			y=y;
			p=p+2*x+1;
			i++;
			
		}
		else{
			cout<<"\t"<<i<<"\t";
			cout<<p<<"\t";
			cout<<"("<< x+1<<","<< y-1 <<")"<<"\t";
			cout<<"\t"<<2*(x+1)<<"\t";
		    cout<<2*(y-1)<< endl;
			x=x+1;
			y=y-1;
			p=p+2*x+1-2*y;
			i++;
			
		}
   	}
   	x=0;
   	y=r;
   	p=1-r;
   	cout<<endl<<endl<<endl;
   	cout<<"(x,y)"<<"\t"<<"(-x,y)"<<"\t"<<"(x,-y)"<<"\t"<<"(-x,-y)"<<"\t"<<"(y,x)"<<"\t"<<"(-y,x)"<<"\t"<<"(y,-x)"<<"\t"<<"(-y,-x)"<<endl<<endl;
   while(x<=y)
   {       
		if(p<0)
		{  	
		
			// symmetry points 
		    display_attribute(x, xc, y,yc);
		    x=x+1;
			y=y;
			p=p+2*x+1;
		
			
		}
		else{
		
		
				// symmetry points 
		    display_attribute(x, xc, y, yc);
		    x=x+1;
			y=y-1;
			p=p+2*x+1-2*y;	
		}	
   	}
   
  
		getch();

}
