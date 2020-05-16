#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
	int player1=0,player2=0;
	int const speed_rect=5;
	int x,y;
	int recx[2],recy[2];
	int cx=-1,cy=1;
void draw()
{
	int i;
	for(i=0;i<15;i++)
	{
		setcolor(1);
		line(0,i,getmaxx(),i);
		line(0,getmaxy()-i,getmaxx(),getmaxy()-i);
	}
}
void paddle1()
{
	setfillstyle(1,3);
	bar(recx[0],recy[0],recx[0]+15,recy[0]+40);
}
void paddle2()
{
	setfillstyle(1,3);
	bar(recx[1],recy[1],recx[1]+15,recy[1]+40);
}
void ball(int i)
{
	setcolor(i);
	circle(x,y,5);
}
void movepaddle_up(int i)
{
	if(recy[i]>18)
	{
		setfillstyle(1,0);
		bar(recx[i],recy[i],recx[i]+15,recy[i]+40);
		recy[i]-=speed_rect;
	}
}
void movepaddle_down(int i)
{
	if(recy[i]<(getmaxy()-18))
	{
		setfillstyle(1,0);
		bar(recx[i],recy[i],recx[i]+15,recy[i]+40);
		recy[i]+=speed_rect;
	}
}
void bounce()
{
	if(y<20)
	{
		y=20;
		cy=0-cy;
	}
	if(y>getmaxy()-20)
	{
		y=getmaxy()-20;
		cy=0-cy;
	}
	if((x<=35)&&(y>=recy[0])&&(y<=(recy[0]+40)))
	{
	     x=35;
	     cx=0-cx;
	     player1++;
	}
	if((x>=(getmaxx()-50))&&(y>=recy[1])&&(y<=(recy[1]+40)))
	{
		x=getmaxx()-50;
		cx=0-cx;
		player2++;
	}
}
void main()
{
	int z=1,op;
	char ch;
	char sc1[3]="0",sc2[3]="0";
	int gdriver=DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	recy[0]=getmaxy()/2-20;
	recy[1]=getmaxy()/2-20;
	recx[0]=15;
	recx[1]=getmaxx()-45;
	x=getmaxx()/2;
	y=getmaxy()/2;
	moveto(x,y);
	cout<<"Rules:\n->Press 'w' to move up and 'z' to move down for player 1.\n->Press 'i' to move up and 'm' to move down for player 2.\n\n\nLEVEL:\n1.Easy\n2.Medium\n3.Hard\nEnter Choice:";
	cin>>op;
	if(op==2)
	{
		cx=2;
		cy=-2;
	}
	else if(op==3)
	{
		cx=3;
		cy=-3;
	}
	cleardevice();
	draw();
	ball(15);
	outtextxy(15,30,"PLAYER 1:");
	outtextxy(getmaxx()-120,30,"PLAYER 2:");
	while(z!=0)
	{
		delay(15);
		paddle1();
		paddle2();

		ball(0);
		x+=cx;
		y+=cy;
		bounce();
		ball(15);

		if(kbhit())
		{
			ch=getch();
			if(ch=='w')
				movepaddle_up(0);
			if(ch=='z')
				movepaddle_down(0);
			if(ch=='i')
				movepaddle_up(1);
			if(ch=='m')
				movepaddle_down(1);
			if(ch=='e')
				z=0;
		}
		if(x<30)
		{
			x=15;
			z=0;
		}
		else if(x>(getmaxx()-45))
		{
			x=getmaxx()-15;
			z=0;
		}

		setcolor(0);



		//prints previous scores in black
		outtextxy(100,30,sc1);
		outtextxy(getmaxx()-30,30,sc2);

		sprintf(sc1,"%d",player1);
		sprintf(sc2,"%d",player2);

		setcolor(15);

		//prints new scores in white
		outtextxy(100,30,sc1);
		outtextxy(getmaxx()-30,30,sc2);
	}

	setcolor(13);
	settextstyle(8,0,6);
	if(player2>player1)
	{
		outtextxy(getmaxx()/2-120,getmaxy()/2-150,"Player 1");
		outtextxy(getmaxx()/2-120,getmaxy()/2-50,"You Lose!");
	}
	else if(player1> player2)
	{
		outtextxy(getmaxx()/2-120,getmaxy()/2-150,"Player 2");
		outtextxy(getmaxx()/2-120,getmaxy()/2-50,"You Lose!");
	}
	else
		outtextxy(getmaxx()/2-150,getmaxy()/2-50,"TIE!");
       getch();
}
