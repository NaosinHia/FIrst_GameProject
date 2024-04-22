void collisionhia(int &x1, int &y1, int &x2, int &y2){
    if((x1+r> x2 && x2+r > x1)&&(y1+r> y2 && y2+r > y1))
    {
        collidehia= true;
    }
}

void Fall()
{
		if(gamestate==4)
		{
			Ball.yhia-=3;
		}
		else if(gamestate==7)
		{
			Ball.yhia-=5;
		}
		else if(gamestate==10)
		{
			Ball.yhia-=8;
		}
		else if(gamestate==13)
		{
			Ball.yhia-=9;
		}
			
	if(Ball.yhia < 80)
	{
		Ball.yhia=775;
		Ball.xhia= rand()%1330;
		life--;
		score= score-10;
	}

	collisionhia(Ball.xhia,Ball.yhia,Basket.xhia,Basket.yhia);
	if(collidehia==true)
	{
		Ball.yhia=775;
		Ball.xhia= rand()%1340;
		bump++;
		score= score+20;
		collidehia= false;	
	}
}
