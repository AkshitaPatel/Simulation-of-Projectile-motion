		  //vt= 1.051 sqrt(mg)/r
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	char snum[50];
	int gd=DETECT,gm,i=0;
	double origx,origy,dupx=1,dupy=1,del,z,r,x,theta=10,y,g=10,h=1,v=45,vt=25,expo=0,t=0,m=0,rhigh,rlow;
	double rad,xmax=0.0,hmax=0.0;
	initgraph(&gd,&gm,"..\\BGI");
      do{
		cleardevice();
		printf("Enter the angle of projection (deg) (0-90):");
		scanf("%lf",&theta);
		printf("enter the value of mass of sphere (1-10000):");
		scanf("%lf",&m);
		rlow=sqrt(m*g)/300;
		rhigh=sqrt(m*g)/16;
		printf("enter the value of radius of sphere (%lf-%lf):",rlow,rhigh);
		scanf("%lf",&r);
		vt=sqrt(m*g)/r;
		printf("enter the value of initial velocity (2-30000):");
		scanf("%lf",&v);
		rad = (theta*3.14)/180;
		t=0.0;
		h=1;
		del=1.0/(v*cos(rad));
		while(h>=0)
		{
			expo=-(g*t)/vt;
			x=(v*cos(rad)*vt)*(1-exp(expo))/g;
			h = ((v*sin(rad)+vt)*x)/(v*cos(rad)) - vt*t;
			if(x>xmax)xmax = x;
			if(h>hmax)
			{
				y=x;
				hmax = h;
			}
			t+=del;
		}
		origx=xmax;
		origy=hmax;
		if(xmax>640)
		{
			dupx=xmax/600;
		}
		if(hmax>480)
		{
			dupy=hmax/475;
		}
		t=0.0;
		h=1;
		xmax=0;hmax=0;
		del=1.0/(v*cos(rad));
		while(h>=0)
		{
			expo=-(g*t)/vt;
			x=(v*cos(rad)*vt)*(1-exp(expo))/g;
			h = ((v*sin(rad)+vt)*x)/(v*cos(rad)) - vt*t;
			putpixel(x/dupx,475-(h/dupy),WHITE);
			if(x/dupx>xmax)xmax = x/dupx;
			if(h/dupy>hmax)
			{
				y=x/dupx;
				hmax = h/dupy;
			}
			t+=del;
		}
		line(0,475,xmax,475);
		line(y,475,y,475-hmax);
		sprintf(snum,"%lf",origx);
		outtextxy(xmax/2,465,snum);
		sprintf(snum,"%lf",origy);
		outtextxy(y-25,475-hmax/2,snum);
      }while(getch()!='a');

}