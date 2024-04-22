
int random(int min, int max){
	srand(time(NULL)*2500);
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
} 
int random2(int min, int max){
	srand(time(NULL)+15000);
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

char strScore[20];

void myDraw(int screenWidth, int screenHeight, int &x, int &y, int px, int py, bool &standing, bool &up, bool collide, int &gamestate, int eI, int i, double &ssscore ){
	//charRend();
	if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{
		iSetColor(0, 255 , 255);
		iShowImage(0,0,screenWidth,screenHeight,room);
		iShowImage(x,y,100,100,e[eI]);
		if(!standing){

			standCounter++;
			if(standCounter>15){ 
				standing=true;
				standCounter=0;

			}
			iShowImage(px,py,300,180,cStateJ[i]);


		}else if(!up&&standing){
			iShowImage(px,py,300,180,cStateJ[4]);
		}
		if(up){
			jumpCounter++;
			standing=true;
			iShowImage(px,py,300,180,jump);
			iShowImage(px+123,py+10,40,40,thurst);
			if(jumpCounter>30){
				up=false;
				jumpCounter=0;

			}
		}

		if(collide){
			gamestate=100;
		}
	}
}




void rightLeft(int ini, int &newD){

	if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{
		if(ini>683){
			newD=-1;	
		}else
		{
			newD=1;		
		}
	}
}
void reset(int &x,int &y,int &px,int &py){
	if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{	
		x=100;
		y=300;
		px=900;
		py=600;
	}
}
void check(int &x,int &y,int &px,int &py){
	if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{
		while(abs(x-px)<500&&abs(y-py)<250){
			if(abs(x-px)<10){

				x= rand()%660;

			}
			else{

				y=rand()%360 ;

			}
		}}
}




void collision(int x1, int y1, int x2, int y2){

	if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{
		if((x1> x2 && x2+210 > x1)&&(y1+50> y2 && y2+130 > y1)){	
			collideState=gamestate;
			collide= true;
			x=100;
			y=300;
			px=900;
			py=600;
			newD=-1;
			stopWatch=clock()/CLOCKS_PER_SEC;
			stoppedWatch=0;
			ssscore=total_t;
			scoreIncrement=false;
			itoa(score,str4,10);
			check(x,y,px,py);
			passed= false;

		}
		else collide=false;
	}}
void change2(){
	
	if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{
		if(abs(x-px)<400 && abs (y-py)<300){
			if(x>px){
				e3++;
				if(e3>12) e3=8;
				eI=e3;
			}
			else{
				e4++;
				if(e4>17) e4=13;
				eI=e4;
			}
		}
		else if(newD<=0){

			e2++;
			if(e2>7) e2=4;
			eI=e2;
		}else{
			eI++;
			if(eI>3) eI=0;
		}}
}



void chase2(int &x1, int &y1, int &x2, int &y2){

	if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{
		if(x1>=x2){
			if(y1>=y2){
				x1-=ddx;
				y1-=ddy;
				if(x<=px){

					newD=1;
				}else{
					newD=-1;
				}
			}else if(y2>=y1){
				x1-=ddx;
				y1+=ddy;
				if(newD<=0){

					newD=1;
				}else{
					newD=-1;
				}
			}
			return;
		}
		else if(x2>=x1){
			if(y1>=y2){
				y1-=8;
				x1+=8;
				if(newD<=0){

					newD=1;
				}else{
					newD=-1;
				}
			}else if(y2>=y1){
				y1+=8;
				x1+=8;
				if(newD<=0){

					newD=1;
				}else{
					newD=-1;
				}
			}
			return;
		}

	}}


void change (){

	switch(gamestate){
	case 5 : ssscore=40;
	break;
	case 8: ssscore=80;
	break;
	case 11: ssscore=120;
	break;
	case 14: ssscore=150;
	break;
	}
	if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
	{
		if(total_t>=scoreLimit) {
			
			collideState=gamestate;
			score+=ssscore;
			gamestate=100;

			//if(gamestate>14) gamestate==0;
			
			itoa(score,str4,10);
			stopWatch=clock()/CLOCKS_PER_SEC;
			scoreIncrement=false;
			passed=true;
		}
		collision(x,y,px,py);
		//if(gamestate==5||gamestate==8||gamestate==11||gamestate==14)
		//{
		stoppedWatch=clock()/CLOCKS_PER_SEC;

		//}

		if(scoreIncrement)
			total_t = (double)(stoppedWatch - stopWatch);
		if(!scoreIncrement) stopWatch=clock()/CLOCKS_PER_SEC;
		itoa(total_t,str, 10);
		itoa(stopWatch,str2, 10);
		itoa(stoppedWatch,str3, 10);
		if(!collide&&(gamestate==5||gamestate==8||gamestate==11||gamestate==14)){
			scoreIncrement=true;
			if(abs(x-px)<400 && abs (y-py)<300){
				chase2(x,y,px,py);
			}
			else if(ini>683){
				x+=dx;
				y+=dy;
			}else{
				x-=dx;
				y-=dy;
			}
		}

		if(x<=0 || x>= screenWidth-100){
			newD*=-1;
			dx=dx*-1;
		}
		if(y<=-10 || y>= screenHeight-90){
			dy=dy*-1;

		}
		if(px<=-110){
			px=-110;
		}
		if( px>= screenWidth-200){
			px= screenWidth-200;
		}
		if(py<=-10){
			py=-10;
		}
		if(py>= screenHeight-150) py=screenHeight-150;

	} else scoreIncrement=false;

}








