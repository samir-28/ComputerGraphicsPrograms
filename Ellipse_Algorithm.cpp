#include <graphics.h>
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<math.h>
using namespace std;

void display_attribute(float x, float xc, float y, float yc){
			cout<<"\t"<<"("<<x+xc<<","<<y+yc<<")"<<"\t";
		    cout<<"("<<-x+xc<<","<<y+yc<<")"<<"\t";
	        cout<<"("<<-x+xc<<","<<-y+yc<<")"<<"\t"; 
			cout<<"("<<x+xc<<","<<-y+yc<<")"<<endl;
}

void plot(float x,float xc,float y,float yc){
	    float k,l;
		putpixel(x+xc,y+yc,WHITE);
		putpixel(-x+xc,y+yc,WHITE);
		putpixel(-x+xc,-y+yc,WHITE);
  		putpixel( x+xc,-y+yc,WHITE);
}

int main(){
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   int rx,ry,xc,yc,x,y,a,b;
   float p;
   int i=0;
   cout<<"Enter the radius (rx,ry) and center(xc,yc) of the ellipse :"<<endl;
   cin>>rx>>ry>>xc>>yc;
   x=0;
  y=ry;
  p=pow(ry,2)-pow(rx,2)*ry+float(0.25)*pow(rx,2);
   cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"Region 1"<<endl<<endl;
   cout<<"Iteration"<<"\t"<<"P"<<"\t"<<"(Xk+1,yk+1)"<<"\t"<<"2ry^2Xk+1"<<"\t"<<"2rx^2Yk+1"<<"\t"
          <<"(x,y)"<<"\t"<<"(-x,y)"<<"\t"<<"(-x,-y)"<<"\t"<<"(x,-y)"<<endl;	
	do{ 
	    if(p<0)
		{  
			cout<<"\t"<<i<<"\t";
			cout<<p<<"\t";
			cout<<"("<< x+1<<","<< y <<")"<<"\t";
			cout<<"\t"<<2*pow(ry,2)*(x+1)<<"\t";
		    cout<<"\t"<<2*pow(rx,2)*y<<"\t";
		    a=2*pow(ry,2)*(x+1);
		    b=2*pow(rx,2)*y;
			x=x+1;
			y=y;
			display_attribute(x, xc, y,yc);
			plot(x,xc,y,yc);
			p=p+a+pow(ry,2);
			i++;
			
		}
		else{
			cout<<"\t"<<i<<"\t";
			cout<<p<<"\t";			cout<<"("<< x+1<<","<< y-1 <<")"<<"\t";
			cout<<"\t"<<2*pow(ry,2)*(x+1)<<"\t";
		    cout<<"\t"<<2*pow(rx,2)*(y-1)<<"\t";
		    a=2*pow(ry,2)*(x+1);
		    b=2*pow(rx,2)*(y-1);
			x=x+1;
			y=y-1;
			display_attribute(x, xc, y,yc);
			plot(x,xc,y,yc);
			p=p+a-b+ pow(ry,2);
			i++;
			}
	
   	}while(a<b);
   	
   	// Region 2
   cout<<endl<<endl<<endl;
   i=0;
   p=pow(ry,2)*pow(x+float(0.5),2)+pow(rx,2)*pow(y-1,2)-pow(rx,2)*pow(ry,2);
   cout<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"Region 2"<<endl<<endl;
   cout<<"Iteration"<<"\t"<<"P"<<"\t"<<"(Xk+1,yk+1)"<<"\t"<<"2ry^2Xk+1"<<"\t"<<"2rx^2Yk+1"<<"\t"
          <<"(x,y)"<<"\t"<<"(-x,y)"<<"\t"<< "(-x,-y)"<<"\t"<<"(x,-y)"<<endl;	
	do{ 
  	    
		if(p<=0)
		{  
			cout<<"\t"<<i<<"\t";
			cout<<p<<"\t";
			cout<<"("<< x+1<<","<< y-1 <<")"<<"\t";
			cout<<"\t"<<2*pow(ry,2)*(x+1)<<"\t";
		    cout<<"\t"<<2*pow(rx,2)*(y-1)<<"\t";
		    a=2*pow(ry,2)*(x+1);
		    b=2*pow(rx,2)*(y-1);
			x=x+1;
			y=y-1;
			display_attribute(x, xc, y,yc);
			plot(x,xc,y,yc);
			p=p+a-b+pow(rx,2);
			i++;
			
		}		else{
			cout<<"\t"<<i<<"\t";
			cout<<p<<"\t";
			cout<<"("<< x<<","<< y-1 <<")"<<"\t";
			cout<<"\t"<<2*pow(ry,2)*x<<"\t";
		    cout<<"\t"<<2*pow(rx,2)*(y-1)<<"\t";
		    a=2*pow(ry,2)*x;
		    b=2*pow(rx,2)*(y-1);
			x=x;
			y=y-1;
			display_attribute(x, xc, y,yc);
			plot(x,xc,y,yc);
			p=p-b+pow(rx,2);
			i++;
		}
	
   	}while(y!=0); 
   	
		getch();

}

