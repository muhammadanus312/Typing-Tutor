#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>
void gotoxy(short x, short y)                                                          
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int sect,i,a,hour,minute,second,hr,min,sec;float l1,l2;
char c[20]={"PASSED"},d[20]={"FAILED"};
FILE *fp;
struct scores{
	char name[20];
	int min1;
	int sec1;
	float speed;
	float accuracy;
}s;

	
	void start_game(int opt) {
	char name[20],ch1[500],paragraph1[500],ch2[500],paragraph2[500],ch3[600],paragraph3[600],ch4[600],paragraph4[600],ch5[800],paragraph5[800],ch6[900],paragraph6[900],ch7[1200],paragraph7[1200],ch8[1400],paragraph8[1400],ch9[1500],paragraph9[1500],ch10[1600],paragraph10[1600];
	FILE *fp;
	int speed1,min1,sec1,accu1,speed2,min2,sec2,accu2;
    fp=fopen("pro.txt","a");	
	if(fp==NULL){
		printf("error!! file not found");
		exit(0);
	}
	printf("\n\n\t\t\tENTER YOUR NAME:");
    //fflush(stdin);
    scanf("%s",s.name);
	fprintf(fp,"\n%s\n",s.name);
	fclose(fp);
    printf("\n\n\n\t\t\tCHOOSE ANY ONE\n\n");
	printf("\t\t\t1. level 1\n");
	printf("\t\t\t2. level 2\n");
	printf("\t\t\t3. level 3\n");
	printf("\t\t\t4. level 4\n");
	printf("\t\t\t5. level 5\n");
	printf("\t\t\t6. level 6\n");
	printf("\t\t\t7. level 7\n");
	printf("\t\t\t8. level 8\n");
	printf("\t\t\t9. level 9\n");
	printf("\t\t\t10. level 10\n");
	printf("\t\t\t11. back\n");
	printf("\n\t\t\tenetr your choice:");
	scanf("%d",&opt);
	system("cls");
	switch (opt) 
	{
		
case 1:
level_1(ch1,paragraph1);
break;		
case 2:
level_2(ch2,paragraph2);
break;
case 3:
level_3(ch3,paragraph3);
break;
case 4:
level_4(ch4,paragraph4);
break;
case 5:
level_5(ch5,paragraph5);
break;
case 6:
level_6(ch6,paragraph6);
break;		
case 7:
level_7(ch7,paragraph7);
break;
case 8:
level_8(ch8,paragraph8);
break;
case 9:
level_9(ch9,paragraph9);
break;
case 10:
level_10(ch10,paragraph10);
break;
case 11:
	start_game(opt);
	break;
	default:
		{
			printf("\t\t\t\n\n\nplease enter a valid number...");
			printf("\t\t\t\n\n\n\npress enter key for going back...");
			getch();
			system("cls");
			start_game(opt);
		}
	}
	}
int level_1(char ch1[500],char paragraph1[500])
{
	char c1[500]={"computer science is the third most popular major amongst international students coming"},ch2[600],paragraph2[600];
FILE *fp;
int error=0;char d1[10]={"level 1"};
strcpy(paragraph1,c1);

	fp=fopen("pro.txt","a+");
	gotoxy(15,1);
	printf("%s",d1);
	fprintf(fp,"%s\t\t",d1);
    gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 30 sec)");
	gotoxy(1,8);
    puts(paragraph1);	
    l1=strlen(paragraph1);
	
	time_t t1;
    struct tm* start;
    t1 = time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
         
    gotoxy(1,12);
    fflush(stdin);
	gets(ch1);
	l2=strlen(ch1);
	
    time_t t2;
    struct tm* stop;
    t2 = time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	for(i=0;i<l2;i++) {
	 	if(ch1[i]!=paragraph1[i]){
	 		error++;
		 }
	 } 
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0){
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	 sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,15);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
    fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\t\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
    
    
	 if(l2>=l1*90/100)
    {
    if(sect<=30){
    	fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!!\n\n");
   	printf("\t\t\tYOU FINISH YOUR TASK IN GIVEN TIME\n\n");
   	printf("\t\t\tPress ENTER key to go for next level\n");
   	getch();
   	system("cls");
   	level_2(ch2,paragraph2);
    		}
    else{
    fprintf(fp,"%s\n",d);
   printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO FINISH YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    system("cls");
    level_1(ch1,paragraph1);
  	}
}
else
{
	    fprintf(fp,"%s\n",d);
		printf("\n\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_1(ch1,paragraph1);
}
fclose(fp);
}
int level_2(char ch2[500],char  paragraph2[500])
{

char c1[300]={"The disciplines encompassed by a computer science degree are incredibly vast and an international student must  how\nto study computer science"};
char ch3[600],paragraph3[600];

int error=0;char d1[10]={"level 2"};

strcpy(paragraph2,c1);

	fp=fopen("pro.txt","a+");
	gotoxy(15,1);
	printf("%s",d1);
    fprintf(fp,"%s\t\t",d1);
	gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 1 minute)");
	gotoxy(1,8);
    puts(paragraph2);	
    l1=strlen(paragraph2);
	
	time_t t1;
    struct tm* start;
    t1 = time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
         
    gotoxy(1,12);
    fflush(stdin);
	gets(ch2);
	l2=strlen(ch2);
	
    time_t t2;
    struct tm* stop;
    t2 = time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	 for(i=0;i<l2;i++)	 {
	 	if(ch2[i]!=paragraph2[i]){
	 		error++;
		 }
	 }
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0)
    {
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	
    sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,15);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
    fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\t\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
       if(l2>=l1*90/100)
    {
	
    if(sect<=60)
    {
    fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!!\n\n");
   	printf("\t\t\tYOU FINISH YOUR TASK IN GIVEN TIME\n\n");
   	printf("\t\t\tPress ENTER key to go for next level\n");
   	getch();
   	level_3(ch3,paragraph3);
    		}
    else
    {
    	fprintf(fp,"%s\n",d);
    printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO FINISH YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    system("cls");
    level_2(ch2,paragraph2);
  	}
  	fclose(fp);
  }
  	else
  	{fprintf(fp,"%s\n",d);
  		printf("\n\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_2(ch2,paragraph2);
	  }
  	}
  	int level_3(char ch3[600],char paragraph3[600])
{
char c1[600]={"in other words, how to effectively navigate amongst this sea of sub disciplines and specializations Here are a few\npossible areas of specialization available to students pursuing computer science degrees"};
char ch4[700],paragraph4[700];
int error=0;char d1[10]={"level 3"};
strcpy(paragraph3,c1);
fp=fopen("pro.txt","a+");
    gotoxy(15,1);
	printf("%s\t",d1);
	fprintf(fp,"%s\t\t",d1);
    gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 1 min 30 sec)");
	gotoxy(1,8);
	puts(paragraph3);
	fflush(stdin);	
    l1=strlen(paragraph3);
	time_t t1;
    struct tm* start;
    t1= time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
         gotoxy(1,12);
    fflush(stdin);
	gets(ch3);
	l2=strlen(ch3);
	    time_t t2;
    struct tm* stop;
    t2 = time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	 for(i=0;i<l2;i++)
	 {
	 	if(ch3[i]!=paragraph3[i])
	 	{
	 		error++;
		 }
	 }
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0)
    {
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,15);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
    fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\t\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
       if(l2>=l1*90/100)
    {
	
    if(sect<=90)
    {
    fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!!\n\n");
   	printf("\t\t\tYOU FINISH YOUR TASK IN GIVEN TIME\n\n");
   	printf("\t\t\tPress ENTER key to go for next level\n");
   	getch();
   	system("cls");
   	level_4(ch4,paragraph4);
    		}
    else
    {fprintf(fp,"%s\n",d);
    printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO FINISH YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    level_3(ch3,paragraph3);
  	}
  }
  	else
  	{fprintf(fp,"%s\n",d);
  		printf("\n\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_3(ch3,paragraph3);
	  }
	  fclose(fp);
  	}
  	
int level_4(char ch4[600],char paragraph4[600])
{
char c1[600]={"The very earliest computers were actually programmed by changing ones and zeros manually, alternating the circuit and\nthe wiring. Of course, it was not easy to create many programs as most were used for specific applications only and\nthey were gigantic in size"};
char ch5[700],paragraph5[700];
int error=0;char d1[10]={"level 4"};
strcpy(paragraph4,c1);
	fp=fopen("pro.txt","a+");
	gotoxy(15,1);
	printf("%s",d1);
	fprintf(fp,"%s\t\t",d1);
    gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 2 minutes )");
	gotoxy(1,8);
    puts(paragraph4);	
    l1=strlen(paragraph4);
	
	time_t t1;
    struct tm* start;
    t1 = time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
         
    gotoxy(1,12);
    fflush(stdin);
	gets(ch4);
	l2=strlen(ch4);
	    time_t t2;
    struct tm* stop;
    t2= time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	 for(i=0;i<l2;i++)
	 {
	 	if(ch4[i]!=paragraph4[i])
	 	{
	 		error++;
		 }
	 }
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0)
    {
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,15);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
    fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\t\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
    if(l2>=l1*90/100)
    {
	if(sect<=120)
    {
    fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!!\n\n");
   	printf("\t\t\tYOU FINISH YOUR TASK IN GIVEN TIME\n\n");
   	printf("\t\t\tPress ENTER key to go for next level\n");
   	getch();
   	system("cls");
   	level_5(ch5,paragraph5);
		}
    else
    {
    	fprintf(fp,"%s\n",d);
    printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO FINISH YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    level_4(ch4,paragraph4);
  	}
  	}
  	else
  	{fprintf(fp,"%s\n",d);
  		printf("\n\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_4(ch4,paragraph4);
	  }
	  fclose(fp);
  	}
  	int level_5(char ch5[800],char paragraph5[800])
{
char c1[800]={"The code is pretty much like writing a paragraph of instruction or creating a to-do list to computers. Unlike us humans\nthe to-do list and instructions you write for the computer has to be extremely detailed and written in some logic. With\ncode and programming, you can get the computer to draw complex shapes and create rich computer graphics, and then create\nprograms that understand game"};
char ch6[800],paragraph6[800];
int error=0;char d1[10]={"level 5"};
	strcpy(paragraph5,c1);
	fp=fopen("pro.txt","a+");
	gotoxy(15,1);
	printf("%s",d1);
	fprintf(fp,"%s\t\t",d1);
    gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 2 min 30 sec )");
	gotoxy(1,8);
    puts(paragraph5);	
    l1=strlen(paragraph5);
		time_t t1;
    struct tm* start;
    t1= time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
         gotoxy(1,13);
    fflush(stdin);
	gets(ch5);
	l2=strlen(ch5);
	 time_t t2;
    struct tm* stop;
    t2= time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	 for(i=0;i<l2;i++) {
	 	if(ch5[i]!=paragraph5[i])
	 	{
	 		error++;
		 }
	 }
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0)
    {
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	
    sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,15);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
    fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\t\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
       if(l2>=l1*90/100)
    {
	    if(sect<=150)
    {
    fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!!\n\n");
   	printf("\t\t\tYOU FINISH YOUR TASK IN GIVEN TIME\n\n");
   	printf("\t\t\tPress ENTER key to go for next level\n");
   	getch();
   	system("cls");
   	level_6(ch6,paragraph6);
    		}
    else
    {
    	fprintf(fp,"%s\n",d);
    printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO FINISH YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    level_5(ch5,paragraph5);
  	}
  }
  	else
  	{fprintf(fp,"%s\n",d);
      	printf("\n\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_5(ch5,paragraph5);
	  }
	  fclose(fp);
  	}
  	int level_6(char ch6[900],char paragraph6[900])
{

char c1[900]={"At its heart, coding is expression and problem solving. You can focus on its applications, on programming languages, butno matter how you practice it, you’ll cultivate these two essential skills, which will help you in all aspects of life. Besides existential value, learning to code proficiently will offer you myriad job opportunities, the ability to create your own schedule work from anywhere, high wages for less hours of labor, eager to please"};
char ch7[1000],paragraph7[1000];

int error=0;char d1[10]={"level 6"};

	strcpy(paragraph6,c1);
	fp=fopen("pro.txt","a+");
	gotoxy(15,1);
	printf("%s",d1);
	fprintf(fp,"%s\t\t",d1);
	    gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 3 minutes )");
	gotoxy(1,8);
    puts(paragraph6);	
    l1=strlen(paragraph6);
	
	time_t t1;
    struct tm* start;
    t1 = time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
         gotoxy(1,13);
    fflush(stdin);
	gets(ch6);
	l2=strlen(ch6);
	time_t t2;
    struct tm* stop;
    t2 = time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	 for(i=0;i<l2;i++)
	 {
	 	if(ch6[i]!=paragraph6[i])
	 	{
	 		error++;
		 }
	 }
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0)
    {
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,15);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
    
    fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\t\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
       if(l2>=l1*90/100)
    {
 if(sect<=150)
    {
    fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!!\n\n");
   	printf("\t\t\tYOU FINISH YOUR TASK IN GIVEN TIME\n\n");
   	printf("\t\t\tPress ENTER key to go for next level\n");
   	getch();
   	system("cls");
   	level_6(ch6,paragraph6);
    		}
    else
    {
     	fprintf(fp,"%s\n",d);
    printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO FINISH YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    level_6(ch6,paragraph6);
  	}
  }
  	else
  	{fprintf(fp,"%s\n",d);
      	printf("\n\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_6(ch6,paragraph6);
	  }
	  fclose(fp);
  	}
   		int level_7(char ch7[1200],char paragraph7[1200])
{
char c1[1200]={"Python, developed in the 80s, is considered one of the easiest coding languages to learn. Its free, open source, and most often classified as a scripting language. Its one of the most ubiquitous programming languages today, and used by the likes of Google, Yahoo! and NASA. Ruby is a similar beginner-accessible, extremely prevalent scripting language. It dynamic, object-oriented scripting language used to develop websites and mobile apps. Ruby was designed by Yukihiro Matsumoto to be easy, logical"};
char ch8[1700],paragraph8[1400];
int error=0;char d1[10]={"level 7"};
	strcpy(paragraph7,c1);
	fp=fopen("pro.txt","a+");
	gotoxy(15,1);
	printf("%s",d1);
	fprintf(fp,"%s\t\t",d1);
    gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 3 min 30 sec)");
	gotoxy(1,8);
    puts(paragraph7);	
    l1=strlen(paragraph7);
	
	time_t t1;
    struct tm* start;
    t1= time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
             gotoxy(1,15);
    fflush(stdin);
	gets(ch7);
	l2=strlen(ch7);
	
    time_t t2;
    struct tm* stop;
    t2 = time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	 for(i=0;i<l2;i++)
	 {
	 	if(ch7[i]!=paragraph7[i])
	 	{
	 		error++;
		 }
	 }
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0)
    {
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	
    sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,23);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
       fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
	   
	   
	   if(l2>=l1*90/100)
    {
	
    if(sect<=210)
    {
    fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!\n\n");
   	printf("\t\t\tYOU COMPLETE YOUR TASK IN GIVEN TIME\n\n");
   	printf("\t\t\tPress ENTER key for next level\n");
   	getch();
   	system("cls");
   	level_8(ch8,paragraph8);
    		}
    else
    {
    	fprintf(fp,"%s\n",d);
    printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO COMPLETE YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    level_7(ch7,paragraph7);
  	}
  }
  	else
  	{fprintf(fp,"%s\n",d);
  		printf("\n\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_7(ch7,paragraph7);
	  }
	  fclose(fp);
  	}
int level_8(char ch8[1400],char paragraph8[1400])
{
char c1[1400]={"Many programmers and coders dont go to school to learn their trade. There are different ways to measure aptitude for\ncoding, but nothing can substitute the effort a person makes, on their own. Its one of the few areas in the world where  self-taught hard work can lead to a lucrative, highly demanded career. What you won’t need to have learned, or have abilities, will be mitigated by how closely you can pay attention to details. The understand of the interconnectivity in commands,general awareness and lingual precision are all extremely important parts of a coder’s toolkit. One way to do this isthrough organization."};
char ch9[1500],paragraph9[1500];
int error=0;char d1[10]={"level 8"};

	strcpy(paragraph8,c1);
	fp=fopen("pro.txt","a+");
	gotoxy(15,1);
	printf("%s",d1);
	fprintf(fp,"%s\t\t",d1);
    gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 4 minutes )");
	gotoxy(1,8);
    puts(paragraph8);	
    l1=strlen(paragraph8);
	
	time_t t1;
    struct tm* start;
    t1 = time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
         
    gotoxy(1,16);
	fflush(stdin);
	gets(ch8);
	l2=strlen(ch8);
	
    time_t t2;
    struct tm* stop;
    t2 = time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	 for(i=0;i<l2;i++)
	 {
	 	if(ch8[i]!=paragraph8[i])
	 	{
	 		error++;
		 }
	 }
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0)
    {
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	
    sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,24);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
    fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\t\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
       if(l2>=l1*90/100)
    {
	if(sect<=240)
    {
    fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!\n\n");
   	printf("\t\t\tYOU COMPLETE YOUR TASK IN GIVEN TIME\\n\n");
   	printf("\t\t\tpress ENTER key for next level\n");
   	getch();
   	system("cls");
   	level_9(ch9,paragraph9);
    		}
    else
    {
    	fprintf(fp,"%s\n",d);
    printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO FINISH YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    level_8(ch8,paragraph8);
  	}
  	fclose(fp);
  }
  	else{
	  fprintf(fp,"%s\n",d);
  		printf("\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_8(ch8,paragraph8);
	  }
  	}
  	int level_9(char ch9[1500],char paragraph9[1500])
{
char c1[1500]={"Some of the greatest achievements in programming have been creating algorithms that get computers to think in more\nindependent, brilliant and productive ways. Look into algorithms like Quicksort, Huffman Compression, the Fast Fourier\nTransform, and the Monte Carlo method to see what I mean. All of these have helped develop a major goal for coders getingcomputers to do more of the heavy lifting through artificial intelligence, yet doing so in a way that is useful, focused and does not lead to our species destruction.So when you are coding, try to think the way a computer does, and use your\nattention to detail skills to make sure you specify exactly what you want, without leaving anything to chance or adaptation. You won’t have to specify everything, some calculations will be made automatically to free you up to directing the program"};
char ch10[1500],paragraph10[1500];
int error=0;char d1[10]={"level 9"};
	strcpy(paragraph9,c1);
	fp=fopen("pro.txt","a+");
	gotoxy(15,1);
	printf("%s",d1);
	fprintf(fp,"%s\t\t",d1);
    gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 4 min 5 sec )");
	gotoxy(1,8);
    puts(paragraph9);	
    l1=strlen(paragraph9);
		time_t t1;
    struct tm* start;
    t1 = time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
         gotoxy(1,17);
    fflush(stdin);
	gets(ch9);
    l2=strlen(ch9);
	time_t t2;
    struct tm* stop;
    t2 = time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	 for(i=0;i<l2;i++)
	 {
	 	if(ch9[i]!=paragraph9[i])
	 	{
	 		error++;
		 }
	 }
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0)
    {
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,24);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
    fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\t\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
       if(l2>=l1*90/100)
    {
	if(sect<=270)
    {
    fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!\n\n");
   	printf("\t\t\tYOU COMPLETE YOUR TASK IN GIVEN TIME\n\n");
   	printf("\t\t\tPress ENTER key for next level\n");
   	getch();
   	system("cls");
   	level_10(ch10,paragraph10);
    		}
    else{
    	fprintf(fp,"%s\n",d);
    printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO FINISH YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    level_9(ch9,paragraph9);
  	}
  }
  	else
  	{fprintf(fp,"%s\n",d);
  		printf("\n\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_9(ch9,paragraph9);
	  }
	  fclose(fp);
  	}
  	  	  	
int level_10(char ch10[1600],char paragraph10[1600])
{
char c1[1600]={"Perhaps the most overlooked aspect of programming has little to do with the manual and mental labor of writing code.\nCoding is an insular world that effects our lives more each day. Coders need to be able to work with, and explain what\nthey do to employers, clients, consumers and coworkers that dont understand what they do. Writing clean, effective code  is great, but when you pair it with strong empathy and communication skills for beginning coders, end users, you become  the rising cream.Elite coders listen to feedback and adjust, even if those providing it dont understand the ramification their words. An effective coder can manage expectations,interpret vague desires and honestly assess and communicate what is, and is not possible. Coders are known for their egos, but those willing to patiently give and accept advice and direction are far more respected "};
int error=0;char d1[10]={"level 10"};
	strcpy(paragraph10,c1);
	fp=fopen("pro.txt","a+");
	gotoxy(15,1);
	printf("%s",d1);
	fprintf(fp,"%s\t",d1);
    gotoxy(11,4);
	printf("TYPE GIVEN PARAGRAPH");
	gotoxy(11,5);
	printf("(Time Limit : 5 minutes )");
	gotoxy(1,8);
    puts(paragraph10);	
    l1=strlen(paragraph10);
	
	time_t t1;
    struct tm* start;
    t1= time(NULL);
        start = localtime(&t1);
        minute=start->tm_min;
        second=start->tm_sec;
         
    gotoxy(1,20);
	fflush(stdin);
	gets(ch10);
	l2=strlen(ch10);
	
    time_t t2;
    struct tm* stop;
    t2= time(NULL);
        stop = localtime(&t2);
        min=stop->tm_min;
        sec=stop->tm_sec;
	 for(i=0;i<l2;i++)
	 {
	 	if(ch10[i]!=paragraph10[i])
	 	{
	 		error++;
		 }
	 }
	s.min1=min-minute;
    s.sec1=sec-second;
    if(s.sec1<0)
    {
    	s.min1=0;
    	s.sec1=60+s.sec1;
    	}
	
    sect=(s.min1*60)+s.sec1;
    s.speed=l2/sect;
    s.accuracy=(l2-error)/l2*100;
		gotoxy(7,27);
    printf("time: %d min %d sec\t\t",s.min1,s.sec1);
    printf("speed: %.2f\t\t",s.speed);
    printf("accuracy: %.2f%\t\terrors:%d\n\n",s.accuracy,error);
    fprintf(fp,"time: %d min %d sec\tspeed: %.2f\taccuracy:%.2f\t\terrors:%d\t\t",s.min1,s.sec1,s.speed,s.accuracy,error);
       if(l2>=l1*90/100)
    {
	
    if(sect<=300)
    {
    fprintf(fp,"%s\n",c);
    printf("\t\t\t\tCONRATULATIONS!!!\n\n");
   	printf("\t\t\tYOU FINISH YOUR TASK IN GIVEN TIME\n\n");
   	printf("\t\t\tPress ENTER key to go to in main menu\n");
   	getch();
   	system("cls");
   	main();
    		}
    else
    {
    	fprintf(fp,"%s\n",d);
    printf("\t\t\t\tLOSER!!!\n\n");
    printf("\t\tYOU FAILED TO FINISH YOUR TASK IN GIVEN TIME\n");
    printf("\t\t\tPlay again this level..\n\n");
    printf("\t\t\t\tPress ENTER key to play again\n");
    getch();
    level_10(ch10,paragraph10);
  	}
  }
  	else
  	{fprintf(fp,"%s\n",d);
  		printf("\n\n\nYOU DID'NT COMPLETE YOUR PARAGRAPH\n\n");
  		printf("WANNA PLAY AGAIN?\n\n");
  		printf("Press ENTER key to play again");
  		getch();
  		system("cls");
  		level_10(ch10,paragraph10);
	  }
	  fclose(fp);
  	}
  	void score()
  	{
  		FILE* fp;
  		fp=fopen("pro.txt","r+");
  		if(fp==NULL)
  		{
  			printf("file not found");
		  }
		  char buf[128];
		  while(fgets(buf,sizeof(buf),fp))
		  	{
		  		printf("%s",buf);
			  }
printf("\n\n\n\n\t\tpress enter key for going back.....");getch();
system("cls");main();
		  fclose(fp);
}

int main() 
{
	int opt,option;	
		  
    
time_t t;   
    time(&t);    
gotoxy(45,1);
printf("%s", ctime(&t));
    
		gotoxy(45,6);
		printf("WELCOME TO TYPING TUTORIAL!!");
			gotoxy(30,10);
		printf("___PLEASE CHOOSE ANY ONE CHOICE___\n\n");
			gotoxy(45,12);
		printf("1.Start ");
			gotoxy(45,14);
		printf("2.Score");
			gotoxy(45,16);
		printf("3.About game");
			gotoxy(45,18);
		printf("4.Exit");
			gotoxy(45,20);		
		printf("Enter your choice:");
		scanf("%d",&option);
		system("cls");
		switch (option)
	{
		case 1:
			start_game(opt);
			break;
		case 2:

        score();
			break;
		case 3:
			
			printf("\n\n\n\n\t\tTHIS IS A SIMPLE TYPING GAME TO DEVELOP HAND EYE COORDINATION.BY PLAYING THIS GAME,YOU CAN EASILY\n\n\t\tENHANCE YOUR TYPING SKILL !!");
			printf("\n\n\n\t\tINSTRUCTION:\n\t\tDo not press ENTER KEY when you changing the line during typing. ");
			printf("\n\n\n\npress enter key for going back.....");getch();
			system("cls");
			main();
			break;
		case 4:
			exit(1);
			break;
	
	default:{
      printf("\t\t\t\n\n\nplease enter a valid number");
      printf("\t\t\t\n\n\npress enter for going back.....");
      getch();
      system("cls");
      main();
	}
		return 0;
			}
	}
