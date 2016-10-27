#include <iostream>
#include <graphics.h>
#include <time.h>
#include <math.h>

using namespace std;

int main(){
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);

	float xa=100.0, ya=100.0, xb=100.0, yb=200.0, xc=200.0, yc=200.0, xd=200.0, yd=100.0;
	float thab=0.0, thbc=0.0, thcd=0.0, thd=0.0;
	float dab, dbc, dcd, t, delt, k;
	float va=35.0, vb=25.0, vc=15.0, vd=10.0;
	t=0.01,delt=0.0;
	int i=1;
	dab=sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
	dbc=sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
	dcd=sqrt((xd-xc)*(xd-xc)+(yd-yc)*(yd-yc));
	while(t<=2){
		delay(100);
		xa=xa+va*t*(xb-xa)/dab;
		ya=ya+ya*t*(yb-ya)/dab;

		xb=xb+vb*t*(xc-xb)/dbc;
		yb=yb-yb*t*(yc-yb)/dbc;

		xc=xc;
		yc=yc-vc*t*(xd-xc)/dcd;

		xd=xd;
		yd=yd-vd*t;

		outtextxy(100,100," A ");
		outtextxy(200,100," B ");
		outtextxy(200,200," C ");
		outtextxy(200,100," D ");


		circle(xa,ya,1);
		circle(xb,yb,1);
		circle(xc,yc,1);
		circle(xd,yd,1);


		dab=sqrt((xb-xa)*(xb-xa)+(yb-ya)*(yb-ya));
		dbc=sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
		dcd=sqrt((xd-xc)*(xd-xc)+(yd-yc)*(yd-yc));
		
		cout<<"Case: "<<i<<"\n";	
		cout<<"Time: "<<t<<" A:"<<xa<<", "<<ya<<"   B:"<<xb<<", "<<yb<<"   C:"<<xc<<", "<<yc<<"   D:"<<xd<<", "<<yd<<"\n";
		cout<<"Distancs: "<<"AB:"<<dab<<" BC:"<<dbc<<" CD:"<<dcd<<"\n\n";
		t+=0.05;
		i++;
	
		if(dab<5){
			cout<<"A hits B\n";
			break;
		}
		if(dbc<5){
			cout<<"B hits C\n";
			break;
		}
		if(dcd<5){
			cout<<"C hits D\n";
			break;
		}
		
	}
	if(t>=2)
		cout<<"Chase Ends, No one caught\n";

	getch();
	closegraph();

}