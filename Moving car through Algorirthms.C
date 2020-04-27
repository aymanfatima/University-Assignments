#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
//for making line
void line1(int x1, int y1, int x2, int y2, int color)
{
	float x,y,dx,dy,step,i;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>=dy)
		step=dx;
	else
		step=dy;
	dx=dx/step;
	dy=dy/step;
	x=x1;
	y=y1;
	i=1;
	while(i<=step)
	{
		putpixel(x,y,color);
		x=x+dx;
		y=y+dy;
		i=i+1;
			}
}
//for circle drawing thorugh mid point algorithm
void drawcircle(int x0, int y0, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
	putpixel(x0 + x, y0 + y, color);
	putpixel(x0 + y, y0 + x, color);
	putpixel(x0 - y, y0 + x, color);
	putpixel(x0 - x, y0 + y, color);
	putpixel(x0 - x, y0 - y, color);
	putpixel(x0 - y, y0 - x, color);
	putpixel(x0 + y, y0 - x, color);
	putpixel(x0 + x, y0 - y, color);

	if (err <= 0)
	{
	    y += 1;
	    err += 2*y + 1;
	}

	if (err > 0)
	{
	    x -= 1;
	    err -= 2*x + 1;
	}
    }
}
//for flood filling
void floodFill(int x,int y,int oldcolor,int newcolor)
{
	if(getpixel(x,y) == oldcolor)
	{
		putpixel(x,y,newcolor);
		floodFill(x-1,y,oldcolor,newcolor);
		floodFill(x+1,y,oldcolor,newcolor);
		floodFill(x,y-1,oldcolor,newcolor);
		floodFill(x,y+1,oldcolor,newcolor);
			}
}
void scenery()
{
	//name
outtextxy(200,10,"HAVE A GOOD DAY AHEAD!");

//tree 1 construction
setcolor(WHITE);
line1(475,200,475,300,15);
line1(510,200,510,300,15);
line1(475,200,510,200,15);
line1(475,300,510,300,15);
floodFill(495,220,0,BROWN);
drawcircle(490,180,30,15);
drawcircle(430,180,30,15);
drawcircle(550,180,30,15);
drawcircle(460,130,30,15);
drawcircle(520,130,30,15);
drawcircle(490,80,30,15);
floodFill(491,179,0,GREEN);
floodFill(431,179,0,GREEN);
floodFill(551,179,0,GREEN);
floodFill(461,129,0,GREEN);
floodFill(521,129,0,GREEN);
floodFill(491,79,0,GREEN);

//tree 2 construction
line1(70,200,70,300,15);
line1(105,200,105,300,15);
line1(70,200,105,200,15);
line1(70,300,105,300,15);
floodFill(90,220,0,BROWN);
drawcircle(93,180,30,15);
drawcircle(35,180,30,15);
drawcircle(153,180,30,15);
drawcircle(65,130,30,15);
drawcircle(125,130,30,15);
drawcircle(95,80,30,15);
floodFill(94,179,0,GREEN);
floodFill(36,179,0,GREEN);
floodFill(154,179,0,GREEN);
floodFill(66,129,0,GREEN);
floodFill(126,129,0,GREEN);
floodFill(96,79,0,GREEN);

//line below house
setcolor(WHITE);
line1(1,300,639,300,15);

//create flowers stem
line1(445,240,445,300,2);
line1(10,240,10,300,2);
line1(40,240,40,300,2);
line1(130,240,130,300,2);
line1(550,240,550,300,2);
line1(580,240,580,300,2);
line1(610,240,610,300,2);
line1(155,240,155,300,2);
line1(180,240,180,300,2);
//create red top of flower
drawcircle(445,240,8,15);
floodFill(447,239,0,RED);

drawcircle(10,240,8,15);
floodFill(11,239,0,RED);

drawcircle(40,240,8,15);
floodFill(41,239,0,RED);

drawcircle(130,240,8,15);
floodFill(131,239,0,RED);

drawcircle(550,240,8,15);
floodFill(551,239,0,RED);

drawcircle(12,240,8,15);
floodFill(13,239,0,RED);

drawcircle(580,240,8,15);
floodFill(581,239,0,RED);

drawcircle(155,240,8,15);
floodFill(156,239,0,RED);

drawcircle(180,240,8,15);
floodFill(181,239,0,RED);

drawcircle(610,240,8,15);
floodFill(611,239,0,RED);

//draw house
line1(200,200,200,300,15);  //the most left
line1(290,200,290,300,15);  //rectangle left
line1(420,200,420,300,15);  //rectangle right
//upper
line1(200,200,290,200,15);    //below circle
line1(290,200,420,200,15);   //rectangle top
line(200,200,250,150);    // left above circle
line1(250,150,290,200,15);  //right above circle
line1(250,150,380,150,15);    //top above rectangle
line1(380,150,420,200,15);   //the most right
line1(290,300,420,300,15);

line1(200,250,290,250,6);
floodFill(220,230,0,6);
floodFill(220,270,0,6);
//coloring centre
line1(355,200,355,300,4);
line1(290,250,420,250,4);
floodFill(310,220,0,RED);
floodFill(375,220,0,RED);
floodFill(310,270,0,RED);
floodFill(375,270,0,RED);
line1(326,150,364,200,1);
floodFill(270,170,0,BLUE);
floodFill(346,170,0,BLUE);
//door
line1(270,250,270,300,15);
line1(220,250,220,300,15);
line1(220,250,270,250,15);
floodFill(240,260,6,RED);
circle(245,179,15);
floodFill(246,180,0,YELLOW);
}
void car()
{
int i;
//translation in car
for (i = 0; i <= 400; i = i+20)
{
line1(70+i,350,250+i,350,15);
line1(70+i,350,70+i,400,15);
line1(250+i,350,280+i,400,15);
line1(70+i,400,280+i,400,15);
line1(280+i,400,310+i,400,15);
line1(310+i,400,310+i,450,15);
line1(50+i,400,70+i,400,15);
line1(50+i,400,50+i,450,15);
line1(50+i,450,310+i,450,15);
drawcircle(120+i,464,15,15);
drawcircle(250+i,464,15,15);
//coloring
floodFill(121+i,461,0,YELLOW);
floodFill(251+i,461,0,YELLOW);
line1(181+i,350,181+i,400,1);
floodFill(190+i,370,0,BLUE);
floodFill(90+i,370,0,BLUE);
//coloring
line1(50+i,405,310+i,405,7);
line1(50+i,410,310+i,410,7);
line1(50+i,415,310+i,415,7);
line1(50+i,420,310+i,420,7);
line1(50+i,425,310+i,425,7);
line1(50+i,430,310+i,430,7);
line1(50+i,435,310+i,435,7);
line1(50+i,440,310+i,440,7);
line1(50+i,445,310+i,445,7);


setcolor(BLACK);
//color set to black
line1(70+i,350,250+i,350,0);
line1(70+i,350,70+i,400,0);
line1(250+i,350,280+i,400,0);
line1(70+i,400,280+i,400,0);
line1(280+i,400,310+i,400,0);
line1(310+i,400,310+i,450,0);
line1(50+i,400,70+i,400,0);
line1(50+i,400,50+i,450,0);
line1(50+i,450,310+i,450,0);
drawcircle(120+i,464,15,0);
drawcircle(250+i,464,15,0);
//coloring
floodFill(121+i,461,YELLOW,0);
floodFill(251+i,461,YELLOW,0);
line1(181+i,350,181+i,400,0);
floodFill(190+i,370,BLUE,0);
floodFill(90+i,370,BLUE,0);
//coloring
line1(50+i,405,310+i,405,0);
line1(50+i,410,310+i,410,0);
line1(50+i,415,310+i,415,0);
line1(50+i,420,310+i,420,0);
line1(50+i,425,310+i,425,0);
line1(50+i,430,310+i,430,0);
line1(50+i,435,310+i,435,0);
line1(50+i,440,310+i,440,0);
line1(50+i,445,310+i,445,0);	
}
}

void main()
{
int x1, x2, y1, y2,color,i;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
scenery();
car();
getch();
closegraph();
}
