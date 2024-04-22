#define Width 1366
#define Height 768

void showscore();

int gamestate=-1;
int fl;

int firstYearS;
int secondYearS, thirdYearS, fourthYearS;

int bg[2];
int bas;
int bal;
int r=100; //center theke player/ enemy width and height
bool collidehia= false;
int bump=0;

int life=3;

char strjas[100], str2jas[100];
int len;

int backg[10];
int backpack,jellybeanl1o1,bottle,calculator,dragon,helicopter,laptop,notebook,pencilbox,ruler,sodacan,soundbox,book,rt,wrong,live,conti,rtcnt,rtc=0,rgc=0,cnt[8]={0},cntr[6]={0},cntw[6]={0},pl1o1=0;



struct object
{
int xhia;
int yhia;
};






object Basket;
void setBasket()
{
Basket.xhia=1000;
Basket.yhia=100;
}

object Ball;
void setBall()
{
Ball.xhia= rand()%1360;
Ball.yhia= 775;
}












struct buttonCordinate
{
	int x1jas, y1jas;
}bCordinate[4];




struct hover
{
	bool hv;
} start, play2, aboutus2, highscore2, exit2;




int xxx=0, yyy=0;
int logox= 300, logoy= 500;
int startx=550, starty=100;
int backx= 1266, backy= 668;
int musicx= 966, musicy= 20;
int mode=0, flag_1=0; 

bool musicOn=true;

char button[20];
char music;
char bc[3][50]= {"Background\\Bg-1.bmp","Background\\Bg-2.bmp","Background\\Bg-3.bmp"};
char play[15] = {"Menu2\\play.bmp"};
char highScore[30] = {"Menu2\\high score.bmp"};
char aboutUs[20] = {"Menu2\\about us.bmp"};

int text[100];
int collideState=0;
int newD=1;
int eating[5];
int p=0;
int eI=0;
int indexNumber=0;
int z=0, h=0 , g=0 , screenHeight= 768, screenWidth= 1366, dx= 8, dy= 8;
int x= 1100, y=600 ;
int ini=x,iniy=y, i=0;
int e2=4, e3=12, e4=12;
int px=140,py=600;
int cont, grati, story;

int ddx=4;
int ddy=4;
int bgrati;
int bcont;
int bstory;



int score=0;

char str[];
char str[1000];
char str2[10];
char str3[10], str4[10];


double stopWatch=0;
double stoppedWatch;
double total_t=0;
double ssscore=total_t;
double scoreLimit=15;


bool scoreIncrement=true;
bool up=false;
bool collide=false, standing= true ;
bool eat= false, passed=false;

int standCounter=0, jumpCounter=0;
int t[4],e[18], cStateJ[25], menu, menupass, room, jump, thurst;



void Buttons()
{
	button[0] = iLoadImage("Menu\\logo.png");
	button[1] = iLoadImage("Menu\\start.png");
	button[2] = iLoadImage("Menu\\play.png");
	button[3] = iLoadImage("Menu\\high score.png");
	button[4] = iLoadImage("Menu\\about us.png");
	button[5] = iLoadImage("Menu\\exit.png");
	button[6] = iLoadImage("Menu\\back.png");

	button[7] = iLoadImage("Menu\\start2.png");
	button[8] = iLoadImage("Menu\\play2.png");
	button[9] = iLoadImage("Menu\\high score2.png");
	button[10] = iLoadImage("Menu\\about us2.png");
	button[11] = iLoadImage("Menu\\exit2.png");

	music = iLoadImage("Menu\\music.png");
}

void image()
{
	jellybeanl1o1 = iLoadImage("Asset\\Shonky.png");
	backg[0]= iLoadImage("Asset\\Background.png");
	backg[1]= iLoadImage("background\\Asset 3.png");
	backpack = iLoadImage("Asset\\Bagpack.png");
	bottle = iLoadImage("Asset\\Bottle.png");
	calculator = iLoadImage("Asset\\Calculator.png");
	dragon = iLoadImage("Asset\\Dragon.png");
	helicopter = iLoadImage("Asset\\Helicopter.png");
	laptop = iLoadImage("Asset\\Laptop.png");
	notebook = iLoadImage("Asset\\Notebook.png");
	pencilbox = iLoadImage("Asset\\Pencil Box.png");
	ruler = iLoadImage("Asset\\Ruler.png");
	sodacan = iLoadImage("Asset\\Soda Can.png");
	soundbox = iLoadImage("Asset\\Sound Box.png");
	book = iLoadImage("Asset\\Teach yourself C Book.png");
	rt = iLoadImage("Asset\\right.png");
	wrong = iLoadImage("Asset\\wrong.png");
	live = iLoadImage("Asset\\live.png");
	conti = iLoadImage("Asset\\continue.png");
	bg[0]= iLoadImage("Background\\bg.png");
	bg[1]= iLoadImage("Background\\gameover.png");
	bas= iLoadImage("Basket\\blueb.png");
	bal= iLoadImage("Basket\\cgpa.png");

	cont= iLoadImage("Background\\controls.jpg");
	grati= iLoadImage("Background\\gratitude.jpg");
	story= iLoadImage("Background\\storyline.jpg");

	//bgrati=iLoadImage("Background\\gratitude.png");
	//bcont=iLoadImage("Background\\controls.png");
	//bstory=iLoadImage("Background\\storyline.png");

	text[0] = iLoadImage("Asset\\3item.png");
	text[1] = iLoadImage("Asset\\4item.png");
	text[2] = iLoadImage("Asset\\5item.png");
	text[3] = iLoadImage("Asset\\6item.png");
	text[4] = iLoadImage("Asset\\basketText.png");
}



void charRend(){
	char currentStateJelly[25][15]={"images\\1.png","images\\2.png","images\\3.png","images\\4.png","images\\5.png","images\\6.png","images\\7.png","images\\8.png","images\\9.png","images\\10.png","images\\11.png","images\\12.png","images\\13.png","images\\14.png","images\\15.png","images\\16.png","images\\17.png","images\\18.png","images\\19.png","images\\20.png","images\\21.png","images\\22.png","images\\23.png","images\\24.png","images\\25.png",};
	menu=iLoadImage("Background\\gameover.png");
	menupass= iLoadImage("Background\\gamepass.png");
	room=iLoadImage("room\\1.jpg");
	t[0]=iLoadImage("charr\\1.png");
	t[1]=iLoadImage("charr\\2.png");
	t[2]=iLoadImage("charr\\3.png");
	t[3]=iLoadImage("charr\\4.png");
	e[0]=iLoadImage("enemy\\1.png");
	e[1]=iLoadImage("enemy\\2.png");
	e[2]=iLoadImage("enemy\\3.png");
	e[3]=iLoadImage("enemy\\4.png");
	e[4]=iLoadImage("enemy\\5.png");
	e[5]=iLoadImage("enemy\\6.png");
	e[6]=iLoadImage("enemy\\7.png");
	e[7]=iLoadImage("enemy\\8.png");
	e[8]=iLoadImage("enemy\\9.png");
	e[9]=iLoadImage("enemy\\10.png");
	e[10]=iLoadImage("enemy\\11.png");
	e[11]=iLoadImage("enemy\\12.png");
	e[12]=iLoadImage("enemy\\13.png");
	e[13]=iLoadImage("enemy\\14.png");
	e[14]=iLoadImage("enemy\\15.png");
	e[15]=iLoadImage("enemy\\16.png");
	e[16]=iLoadImage("enemy\\17.png");
	e[17]=iLoadImage("enemy\\18.png");

	firstYearS=iLoadImage("Background\\1stL.png");
	secondYearS=iLoadImage("Background\\2ndL.png");
	thirdYearS=iLoadImage("Background\\3rdL.png");
	fourthYearS=iLoadImage("Background\\4thL.png");

	thurst=iLoadImage("images\\thurst.png");
	jump=iLoadImage("images\\jump.png");
	int L=0; 
	while (L<25){
		cStateJ[L]=iLoadImage(currentStateJelly[L]);
		L++;
	}

}




void setCordinate()
{
	int sum=100;
	for(int i=3;i>=0;i--)
	{
		bCordinate[i].x1jas= 520;
		bCordinate[i].y1jas= sum;
		sum+=150;
	}
}



void Menu()
{
	if(gamestate==-1)
	{
		//menu
		iShowBMP(0,0,bc[0]);
		iShowImage(logox, logoy, 800, 100, button[0]);
		iShowImage(startx, starty, 300, 300, button[1]);
		iShowImage(musicx, musicy, 350, 20, music);

		if(start.hv==true)
			iShowImage(startx, starty, 300, 300, button[7]);
	}

	else if(gamestate==0)
	{
		//menu
		mode=0;
		flag_1=0;
		iShowBMP(0,0,bc[1]);
		for(int i=0; i<4; i++)
		{
			iShowImage(bCordinate[i].x1jas, bCordinate[i].y1jas, 300, 70, button[i+2]);
		}

		if(play2.hv==true)
			iShowImage(bCordinate[0].x1jas, bCordinate[0].y1jas, 300, 70, button[8]);

		else if(highscore2.hv==true)
			iShowImage(bCordinate[1].x1jas, bCordinate[1].y1jas, 300, 70, button[9]);

		else if(aboutus2.hv==true)
			iShowImage(bCordinate[2].x1jas, bCordinate[2].y1jas, 300, 70, button[10]);

		else if(exit2.hv==true)
			iShowImage(bCordinate[3].x1jas, bCordinate[3].y1jas, 300, 70, button[11]);

		iShowImage(musicx, musicy, 350, 20, music);
		//iShowImage(150, 600, 300, 70, bgrati);
		//iShowImage(150, 400, 300, 70, bcont);
		//iShowImage(150, 200, 300, 70, bstory);
	}

	else if(gamestate==1)
	{
		iShowBMP(0,0,highScore);
		showscore();
		iShowImage(backx, backy, 50, 50, button[6]);
	}

	else if(gamestate==2)
	{
		iShowBMP(0,0,aboutUs);
		iShowImage(backx, backy, 50, 50, button[6]);
	}


}



