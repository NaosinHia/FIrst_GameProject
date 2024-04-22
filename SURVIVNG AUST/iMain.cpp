/*
Ahsanullah University of Science and Technology
Department of Computer Science and Engineering
Year 1, Semester 2
CSE1200 iGraphics Term Project

Section: A
Group: 02

Project Title: Surviving AUST
Project Submitted on: March 28, 2021
Group Members:
1. Syeda Farhana Ali (190204027)
2. Ahnaf Samin (190204031)
3. Naosin Akhter Hia (190204050)
4. Jaasia Anjum (190204051)

Project Supervisor:
Mohammad Rahman
Lecturer,
Department of Computer Science and Engineering,
Ahsanullah University of Science and Technology
*/



#include "iGraphics.h"
#include <string>
#include<iostream>
#include<string>
#include<fstream>
#include <cstdlib>
#include <time.h>
#include <string.h>
#include "Menu.h"
#include "highscore.h"
#include "Obstacle1.h"
#include "Obstacle2.h"
#include "Obstacle3.h"
using namespace std;


void iDraw()
{
	iClear();

	cout<<"gamestate   "<<gamestate<<endl;
	cout<<"score                                    "<<score<<endl;
	cout<<"tt   "<<total_t<<endl;
	cout<<"sssss   "<<ssscore<<endl;

	Menu();
	if(gamestate==3)
	{
		iClear();
		newgameidr();
	}
	else if(gamestate==6)
	{
		iClear();
		l2o1idr();
	}
	else if(gamestate==9)
	{
		iClear();
		l3o1idr();

	}
	else if(gamestate==12)
	{
		iClear();
		l4o1idr();
	}
	else if(gamestate==4 || gamestate==7 || gamestate==10 || gamestate==13)
	{
		iShowImage(0,0,1366,768,bg[0]);
		iShowImage(Basket.xhia,Basket.yhia,150,150,bas);
		iShowImage(0,0,1366,768,text[4]);
		iShowImage(Ball.xhia,Ball.yhia,100,100,bal);

		if((life<=0) && (bump<5))
		{
			iShowImage(0,0,1366,768,menu);
			iPauseTimer(fl);
		}
		if(bump==5) 
		{
			iShowImage(0,0,1366,768,menupass);
			iPauseTimer(fl);
		}
	}

	else if(gamestate==5){
		scoreLimit=10;

		iClear();
		myDraw(screenWidth, screenHeight, x,y,px,py,standing,up, collide, gamestate, eI, i, ssscore);

	}
	else if (gamestate==8){
		scoreLimit=15;
		iClear();
		myDraw(screenWidth, screenHeight, x,y,px,py,standing,up, collide, gamestate, eI, i, ssscore);
	}
	else if (gamestate==11){
		scoreLimit=20;
		iClear();
		myDraw(screenWidth, screenHeight, x,y,px,py,standing,up, collide, gamestate, eI, i, ssscore);
	}
	else if (gamestate==14){
		scoreLimit=25;
		iClear();
		myDraw(screenWidth, screenHeight, x,y,px,py,standing,up, collide, gamestate, eI, i, ssscore);
	}

	else if(gamestate==100){ 
		
		iClear();
		if(!passed)
		iShowImage(0,0,screenWidth,screenHeight,menu);
		else{ 
		if(collideState<7)
		iShowImage(0,0,screenWidth,screenHeight,firstYearS);
		else if(collideState<10)
		iShowImage(0,0,screenWidth,screenHeight,secondYearS);
		else if(collideState<13)
		iShowImage(0,0,screenWidth,screenHeight,thirdYearS);
		else if(collideState<16)
		gamestate=15;
		}
		//iSetColor(110,110,110);
		//iText(800,455,str4, GLUT_BITMAP_TIMES_ROMAN_24);
		total_t=0;
		stopWatch=clock()/CLOCKS_PER_SEC;
		scoreIncrement=false;

	}
	
	else if(gamestate==15){
		iClear();
		iShowImage(0,0,screenWidth,screenHeight,fourthYearS);
		drawTextBox();
		if(mode == 1)
		{
			iSetColor(255, 255, 255);
			iText(651, 101, str, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		flag_1=0;
		}
	else if(gamestate==101){
		iShowImage(0,0,screenWidth,screenHeight,grati);
	}else if(gamestate==102){
		iShowImage(0,0,screenWidth,screenHeight,cont);
	}else if(gamestate==103){
		iShowImage(0,0,screenWidth,screenHeight,story);
	}
	//iText(500,400,str, GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(600,400,str2, GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(700,400,str3, GLUT_BITMAP_TIMES_ROMAN_24);
	if(gamestate>=3&&gamestate<=100){
	if(score<0) score=0;
	itoa(score,strScore,10);
	iSetColor(0,0,0);
	iText(100,675,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(250,675,strScore,GLUT_BITMAP_TIMES_ROMAN_24);
	}
		
}



void iMouseMove(int mx, int my)
{
	xxx = mx - 150;
	yyy = my - 20;
}



void iPassiveMouseMove(int mx, int my)
{
	if(gamestate==-1)
	{
		if(mx>=startx && mx<=startx+200 && my>=starty+100 && my<=starty+300)
			start.hv= true;
		else
			start.hv= false;
	}

	else if(gamestate==0)
	{
		if(mx>=bCordinate[0].x1jas && mx<=bCordinate[0].x1jas+300 && my>=bCordinate[0].y1jas && my<=bCordinate[0].y1jas+70)
			play2.hv = true;
		else
			play2.hv= false;

		if(mx>=bCordinate[1].x1jas && mx<=bCordinate[1].x1jas+300 && my>=bCordinate[1].y1jas && my<=bCordinate[1].y1jas+70)
			highscore2.hv= true;
		else
			highscore2.hv= false;

		if(mx>=bCordinate[2].x1jas && mx<=bCordinate[2].x1jas+300 && my>=bCordinate[2].y1jas && my<=bCordinate[2].y1jas+70)
			aboutus2.hv = true;
		else
			aboutus2.hv= false;

		if(mx>=bCordinate[3].x1jas && mx<=bCordinate[3].x1jas+300 && my>=bCordinate[3].y1jas && my<=bCordinate[3].y1jas+70)
			exit2.hv = true;
		else
			exit2.hv= false;

	}
}



void iMouse(int button, int state, int mx, int my)
{
	if(gamestate==-1)
	{
		if(mx>=startx && mx<=startx+200 && my>=starty+100 && my<=starty+300)
			gamestate= 0;
	}

	else if(gamestate==0)
	{
		/*if(mx>=150 && mx<=150+300 && my>=600 && my<=600+70){
		  gamestate=101;
		}
		if(mx>=150 && mx<=150+300 && my>=600 && my<=400+70){
			gamestate=102;
		}
		if(mx>=150 && mx<=150+300 && my>=600 && my<=200+70){
			gamestate=103;
		}*/
		for(int i=0; i<4; i++)
		{
			if(mx>=bCordinate[i].x1jas && mx<=bCordinate[i].x1jas+300 && my>=bCordinate[i].y1jas && my<=bCordinate[i].y1jas+70)
			{
				if(i!=0&&i!=3)
					gamestate= i;

				else if(i==0)
					gamestate = 3;

				else if(i==3)
					exit(0);
			}
		}
	}

	else if(gamestate==1||gamestate==2)
	{
		if(mx>=backx && mx<=backx+100 && my>=backy && my<=backy+100)
			gamestate= 0;
	}
	
	if(gamestate==3)//l1o1
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if((mx>=410&&mx<=530)&&(my>=150&&my<=285))//w
				cnt[0]=1,score-=10,rgc++;
			if((mx>=310&&mx<=380)&&(my>=300&&my<=420))//r
				cnt[1]=1,score+=20,rtc++;
			if((mx>=410&&mx<=490)&&(my>=450&&my<=550))//w
				cnt[2]=1,score-=10,rgc++;
			if((mx>=810&&mx<=860)&&(my>=450&&my<=550))//w
				cnt[3]=1,score-=10,rgc++;
			if((mx>=870&&mx<=1020)&&(my>=300&&my<=450))//r
				cnt[4]=1,score+=20,rtc++;
			if((mx>=810&&mx<=879)&&(my>=150&&my<=250))//r
				cnt[5]=1,score+=20,rtc++;
		}
	}
	else if(gamestate==6)//l2o1
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if((mx>=710&&mx<=760)&&(my>=500&&my<=600))//w
				cnt[0]=1,score-=10,rgc++;
			if((mx>=485&&mx<=565)&&(my>=500&&my<=600))//w
				cnt[1]=1,score-=10,rgc++;
			if((mx>=485&&mx<=605)&&(my>=120&&my<=255))//w
				cnt[2]=1,score-=10,rgc++;
			if((mx>=360&&mx<=480)&&(my>=250&&my<=330))//w
				cnt[3]=1,score-=10,rgc++;
			if((mx>=810&&mx<=880)&&(my>=360&&my<=480))//r
				cnt[4]=1,score+=20,rtc++;
			if((mx>=360&&mx<=480)&&(my>=380&&my<=500))//r
				cnt[5]=1,score+=20,rtc++;
			if((mx>=710&&mx<=779)&&(my>=120&&my<=220))//r
				cnt[6]=1,score+=20,rtc++;
			if((mx>=810&&mx<=890)&&(my>=220&&my<=325))//r
				cnt[7]=1,score+=20,rtc++;
		}
	}
	else if(gamestate==9)//l3o1
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if((mx>=485&&mx<=535)&&(my>=120&&my<=220))//w
				cnt[0]=1,score-=10,rgc++;
			if((mx>=485&&mx<=485+80)&&(my>=500&&my<=600))//w
				cnt[1]=1,score-=10,rgc++;
			if((mx>=710&&mx<=710+180)&&(my>=500&&my<=500+120))//r
				cnt[2]=1,score+=20,rtc++;
			if((mx>=360&&mx<=360+70)&&(my>=380&&my<=380+120))//r
				cnt[3]=1,score+=20,rtc++;
			if((mx>=810&&mx<=810+120)&&(my>=360&&my<=360+120))//r
				cnt[4]=1,score+=20,rtc++;
			if((mx>=710&&mx<=779)&&(my>=120&&my<=220))//r
				cnt[5]=1,score+=20,rtc++;
			if((mx>=360&&mx<=360+80)&&(my>=250&&my<=250+105))//r
				cnt[6]=1,score+=20,rtc++;
			if((mx>=810&&mx<=930)&&(my>=220&&my<=300))//w
				cnt[7]=1,score-=10,rgc++;
		}
	}
	else if(gamestate==12)//l4o1
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if((mx>=485&&mx<=485+120)&&(my>=120&&my<=180))//r
				cnt[0]=1,score+=20,rtc++;
			if((mx>=710&&mx<=710+80)&&(my>=120&&my<=220))//w
				cnt[1]=1,score-=10,rgc++;
			if((mx>=450&&mx<=450+180)&&(my>=500&&my<=500+120))//r
				cnt[2]=1,score+=20,rtc++;
			if((mx>=810&&mx<=810+70)&&(my>=220&&my<=220+120))//r
				cnt[3]=1,score+=20,rtc++;
			if((mx>=810&&mx<=810+120)&&(my>=360&&my<=360+120))//r
				cnt[4]=1,score+=20,rtc++;
			if((mx>=710&&mx<=779)&&(my>=500&&my<=600))//r
				cnt[5]=1,score+=20,rtc++;
			if((mx>=360&&mx<=360+80)&&(my>=250&&my<=250+105))//r
				cnt[6]=1,score+=20,rtc++;
			if((mx>=360&&mx<=360+120)&&(my>=380&&my<=460))//w
				cnt[7]=1,score-=10,rgc++;

		}
	}

	else if(gamestate==15)
    {
        if(mx >= 620 && mx <= (620+350) && my >= 80 && my <= 140 && mode == 0)
		{
			mode = 1;
		}
    }


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{

	if(mode == 1)
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			for(int i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
			struct score nad;
			//copy the score also
			strcpy(nad.name,str2);
			nad.scr= score; 
			SaveScore(nad);
			gamestate=0;
		}

		else if(key==8)
        {
			len--;

			if(len<0)
				len=0;

            str[len]='\0';
        }

		else
		{
			str[len] = key;
			len++;
		}
	}



	if(gamestate==100 && key =='e')
		{
			if(!passed)
					gamestate=collideState;
				else {
					switch(collideState){
					case 5:
						gamestate=6;
						break;
					case 8:
						gamestate=9;
						break;
					case 11:
						gamestate=12;
						break;
					case 14:
						gamestate=100;
						break;
					}
					
					px=1100,py=600;
					x= 140, y=600 ;
				}
				stopWatch=clock()/CLOCKS_PER_SEC;
				scoreIncrement=true;
				up=false;
		
	}


	if(gamestate==4 ||gamestate==7||gamestate==10||gamestate==13)
	{

		if(key =='e'&&life<=0)
		{
			bump=0;
			life=3;
			Ball.yhia=775;
			iResumeTimer(fl);
		}
		if(key =='e'&&bump==5)
		{
			if(gamestate==4)
			{
				life=3;
				bump=0;
				Basket.xhia=1000;
				Basket.yhia=100;
				gamestate=5;
			}	
			else if(gamestate==7)
			{
				life=3;
				bump=0;
				Basket.xhia=1000;
				Basket.yhia=100;
				gamestate=8;
			}
			else if(gamestate==10)
			{
				life=3;
				bump=0;
				Basket.xhia=1000;
				Basket.yhia=100;
				gamestate=11;
			}
			else if(gamestate==13)
			{
				bump=0;
				gamestate=14;
			}
		}
	}

	else if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
		{
			if(key != '\b')
			{
				str[indexNumber]= key;


				indexNumber++;
				str[indexNumber]= '\0';
			}

			else
			{
				if(indexNumber <= 0)
					indexNumber=0;

				else
					indexNumber--;

				str[indexNumber]= '\0';
			}
		}


	if(gamestate==3)
	{
		if(key =='e'&&rgc==3)
		{
			rgc=0;
			rtc=0;
			rtcnt=0;
			for(int i=0;i<8;i++)
			{
				cnt[i]=0;
			}
		}
		else if(key =='e'&&rtc==3)
		{
			rgc=0;
			rtc=0;
			rtcnt=0;
			for(int i=0;i<8;i++)
			{
				cnt[i]=0;
			}

			life=3;
			bump=0;
			Basket.xhia=1000;
			Basket.yhia=100;
			iResumeTimer(fl);
			gamestate=4;
		}

	}
	if(gamestate==6)
	{
		if(key =='e'&&rgc==4)
		{
			rgc=0;
			rtc=0;
			rtcnt=0;
			for(int i=0;i<8;i++)
			{
				cnt[i]=0;
			}
		}
		else if(key =='e'&&rtc==4)
		{
			rgc=0;
			rtc=0;
			rtcnt=0;
			for(int i=0;i<8;i++)
			{
				cnt[i]=0;
			}

			life=3;
			bump=0;
			Basket.xhia=1000;
			Basket.yhia=100;
			iResumeTimer(fl);
			gamestate=7;
		}

	}

	if(gamestate==9)
	{
		if(key =='e'&&rgc==3)
		{
			rgc=0;
			rtc=0;
			rtcnt=0;
			for(int i=0;i<8;i++)
			{
				cnt[i]=0;
			}
		}
		else if(key =='e'&&rtc==5)
		{
			rgc=0;
			rtc=0;
			rtcnt=0;
			for(int i=0;i<8;i++)
			{
				cnt[i]=0;
			}

			life=3;
			bump=0;
			Basket.xhia=1000;
			Basket.yhia=100;
			iResumeTimer(fl);
			gamestate=10;
		}

	}
	if(gamestate==12)
	{
		if(key =='e'&&rgc==2)
		{
			rgc=0;
			rtc=0;
			rtcnt=0;
			for(int i=0;i<8;i++)
			{
				cnt[i]=0;
			}
		}
		else if(key =='e'&&rtc==6)
		{
			rgc=0;
			rtc=0;
			rtcnt=0;
			for(int i=0;i<8;i++)
			{
				cnt[i]=0;
			}

			life=3;
			bump=0;
			Basket.xhia=1000;
			Basket.yhia=100;
			iResumeTimer(fl);
			gamestate=13;
		}

	}
	if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{}


	if(key =='q')
    {
        gamestate=15;
    }


}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
	{
		if(musicOn)
		{
			musicOn= false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn= true;
			PlaySound("Music\\Deep-ambient-music.wav", NULL, SND_LOOP| SND_ASYNC);
		}
	}

	else if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{
		if (key == GLUT_KEY_RIGHT)
		{
			standing= false;
			up=false;
			px+=20;
			i++;
			if(i>24) i=0;


		}
		if (key == GLUT_KEY_UP)
		{
			py+=20;
			up=true;
		}

		if (key == GLUT_KEY_LEFT)
		{
			standing=false;
			px-=20;
			i--;
			up=false;

			if(i<0) i=24;
		}

		if (key == GLUT_KEY_DOWN)
		{
			py-=20;	
			up=true;
		}
	}




	else if(gamestate==4||gamestate==7||gamestate==10||gamestate==13)
	{
		if (key == GLUT_KEY_RIGHT)
		{
			if(gamestate==4)
			{
				if(Basket.xhia<1250)
					Basket.xhia+=20;
			}

			if(gamestate==7)
			{
				if(Basket.xhia<1250)
					Basket.xhia+=25;
			}

			if(gamestate==10)
			{
				if(Basket.xhia<1250)
					Basket.xhia+=30;
			}

			if(gamestate==13)
			{
				if(Basket.xhia<1250)
					Basket.xhia+=40;
			}

		}

		if (key == GLUT_KEY_LEFT)
		{
			if(gamestate==4)
			{
				if(Basket.xhia>20)
					Basket.xhia-=20;
			}

			if(gamestate==7)
			{
				if(Basket.xhia>25)
					Basket.xhia-=25;
			}

			if(gamestate==10)
			{
				if(Basket.xhia>30)
					Basket.xhia-=30;
			}

			if(gamestate==13)
			{
				if(Basket.xhia>40)
					Basket.xhia-=40;
			}
		}

	}


	if (key == GLUT_KEY_RIGHT)
	{

	}
	if (key == GLUT_KEY_LEFT)
	{

	}

	if (key == GLUT_KEY_HOME)
	{
		rgc=0;
        rtc=0;
        rtcnt=0;
        for(int i=0;i<8;i++)
            {
                cnt[i]=0;
            }
        life=3;
        bump=0;
        Basket.xhia=1000;
        Basket.yhia=100;
		score=0;
        gamestate=0;
	}

	if (key == GLUT_KEY_PAGE_DOWN)
	{
		gamestate++;
	}

}


int main()
{
	if(musicOn)
	{
		PlaySound("Music\\Dumb Ways To Die Song Instrumental Version.wav", NULL, SND_LOOP| SND_ASYNC);
	}

	len = 0;
	mode = 0;
	strjas[0]= 0;
	rightLeft(ini, newD);
	check(x,y,px,py);
	iSetTimer(100,change2);
	iSetTimer(30, change);
	setCordinate();
	setBasket();
	setBall();
	fl = iSetTimer(10,Fall);
	iInitialize(Width, Height, "Surviving AUST");
	image();
	charRend();
	Buttons();
	iStart();
	
}