


struct score
{
    int scr;
    char name[1000];

};

struct score arr[100];

int scorenumber;

void showscore()
{
     if(flag_1==0){           //for reading file once
     flag_1++;
     FILE *fp;
     fp=fopen("hold.txt","r");
     fscanf(fp,"%d",&scorenumber);
     fclose(fp);
	 fp=fopen("highscore.txt","r");
     int count=0;
     char str[100];
     while(count<scorenumber)
     {
         fgets(str,sizeof(str),fp);
		 //printf("%s", str);
         sscanf(str," %[^\t]\t%d\n",&arr[count].name,&arr[count].scr);
		 //printf("HELLO ");
		 //printf("%s    %d",&arr[count].name,&arr[count].scr);
         count++;
     }
     for(int a=0;a<scorenumber;a++)///selection sorting
     {
         for(int b=a+1;b<scorenumber;b++)
         {
             if(arr[a].scr<arr[b].scr)
             {
					struct score d;
					d.scr=arr[b].scr;
					strcpy(d.name,arr[b].name);
                    strcpy(arr[b].name,arr[a].name);
                    arr[b].scr=arr[a].scr;
                    strcpy(arr[a].name,d.name);
                    arr[a].scr=d.scr;

             }
         }
     }
	 fclose(fp);
    }
	 int scrpos=450, jaas=5;
	 jaas=(scorenumber>5)?5:scorenumber;
     char ss[100];
     for(int a=0;a<jaas;a++)
     {
		 printf("%s",arr[a].name);
         itoa(arr[a].scr,ss,10);
		 iText(550,550,"Name", GLUT_BITMAP_TIMES_ROMAN_24);
		 iText(550,500,"----------------------", GLUT_BITMAP_TIMES_ROMAN_24);
		 iText(800,550,"Score", GLUT_BITMAP_TIMES_ROMAN_24);
         iText(550,scrpos,arr[a].name, GLUT_BITMAP_TIMES_ROMAN_24);
         iText(800,scrpos,ss, GLUT_BITMAP_TIMES_ROMAN_24);
		scrpos-=50;
     }



}
 void SaveScore(struct score arr)
 {
     /// scorenumber variable hold the number of highscore actually being stored in the file
     FILE *fp;
     fp=fopen("hold.txt","r");
     fscanf(fp,"%d",&scorenumber);
     scorenumber++;
     fclose(fp);
     fp=fopen("hold.txt","w");
     fprintf(fp,"%d",scorenumber);
     fclose(fp);
     fp=fopen("highscore.txt","a+");
     fprintf(fp,"%s\t%d\n",arr.name,arr.scr);
	 printf("%s\t%d\n",arr.name,arr.scr);
     fclose(fp);

 }
 void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(620, 80, 350, 60);
}
