#include"wqw.h"

int main(){
	 FirstMenu();
	 return 0;
}
void initMenu(){

 setfont(20,0,"����");
	//���õ�һ���˵��ľ���
	rectangle(WINDOW_WIDTH/4,WINDOW_HEIGHT/6,WINDOW_WIDTH/6+200,WINDOW_HEIGHT/6+40);
	//���õ�һ���˵���λ��
	RECT r = {WINDOW_WIDTH/4,WINDOW_HEIGHT/6,WINDOW_WIDTH/6+200,WINDOW_HEIGHT/6+40};
	if(curMenu == 0 ||curMenu == 1 ){
		setfillcolor(RED);
    	settextcolor(WHITE);
		curMenu = 1;
	}else{
	
	    setfillcolor(BLUE);
    	settextcolor(RED);
	}

	//�Ѳ˵���λ����䵽��������
	fillrectangle(r.left,r.top,r.right,r.bottom);
	
	//�����˵�������
 	drawtext("��ʼ��Ϸ", &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);



		//���õڶ����˵��ľ���
	rectangle(WINDOW_WIDTH/4,WINDOW_HEIGHT/6+40,WINDOW_WIDTH/6+200,WINDOW_HEIGHT/6+80);
	//���õڶ����˵���λ��
	RECT r2 = {WINDOW_WIDTH/4,WINDOW_HEIGHT/6+40,WINDOW_WIDTH/6+200,WINDOW_HEIGHT/6+80};
	//�Ѳ˵���λ����䵽��������
	if(curMenu == 2){
		setfillcolor(RED);
    	settextcolor(WHITE);
		 
	}else{
	
	    setfillcolor(BLUE);
    	settextcolor(RED);
	}


	//	setfillcolor(BLUE);
	fillrectangle(r2.left,r2.top,r2.right,r2.bottom);

	//�����˵�������
	drawtext("��Ϸ˵��", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

  
    		//���õ������˵��ľ���
	rectangle(WINDOW_WIDTH/4,WINDOW_HEIGHT/6+80,WINDOW_WIDTH/6+200,WINDOW_HEIGHT/6+120);
	//���õڶ����˵���λ��
	RECT r3 = {WINDOW_WIDTH/4,WINDOW_HEIGHT/6+80,WINDOW_WIDTH/6+200,WINDOW_HEIGHT/6+120};
	//�Ѳ˵���λ����䵽��������
	 	if(curMenu == 3){
		setfillcolor(RED);
    	settextcolor(WHITE);
		 
	}else{
	
	    setfillcolor(BLUE);
    	settextcolor(RED);
	}
	//	settextcolor(WHITE);
	fillrectangle(r3.left,r3.top,r3.right,r3.bottom);

	//�����˵�������
	drawtext("��Ϸ�˳�", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);



}




void keyControl(){
   int i;
	if(kbhit()){
	

	char ch='\0';
    char ch1='\0';
	ch = getch();
	fflush(stdin);
 
	switch(ch){
	case 13:       //�س�
		if(curMenu==1)
		{
		printf("Game start\n");
		isStart = 1;
		}
		if(curMenu==2)
			isStart=2;
		if(curMenu==3)
			exit(0);
		break;
	case 32:         //�ո�
		if(isStart==1){
		printf("Jump up!\n");
	   bird_y-=50;
	   birdup=1;
	   	BirdJumpSound();
		}
		break;
	case 72:        //���� ��
		 curMenu--;
		 
		 if(curMenu <=0){
		 curMenu = 3;
		 }
		initMenu();
		printf("up\n");
		break;
	case 80:        //���� ��
		curMenu++;
		if(curMenu > 3){
			curMenu=0;
		}
		initMenu();
		printf("down\n");
		break;
	case 8:         //��ͣ
     
         while(ch1!=8)
		 {
		   ch1=getch();
           fflush(stdin);
		 }
		  break;
	case 27:         //esc
		isStart=0;
		curMenu=0;
		printf("back");
        FirstMenu();
		break;
	}  
}


}



void moveStone(){

	Sleep(10);
	if(stone_x <= -140){
	  stone_y=-(rand() % (200))-350;
	  printf("%d",stone_y);
	  stone_x = WINDOW_WIDTH;
	}
		if(stoned_x <= -140){
	 stoned_y=-(rand()%(200))+550;
	 	  printf("%d",stoned_y);
	  stoned_x = WINDOW_WIDTH;
	}
		if(coin_x<-32||isHit==2){
		coin_y=(rand()%(200))+150;
		coin_x=350;
		}
	BeginBatchDraw();
	putimage(0,0,&bg);
	//setbkmode(TRANSPARENT);
    if(birdup==1&&birdup1<30){
	    	putimage(100,bird_y,&birdUp2,NOTSRCERASE); 	
		putimage(100,bird_y,&birdUp,SRCINVERT);

	birdup1++;
	}
	
	else{
	putimage(100,bird_y,&bird1,NOTSRCERASE);
	putimage(100,bird_y,&bird2,SRCINVERT);
	birdup1=0;
	birdup=0;
	}
	isHit=1;
	showCoin(coin_x,coin_y);//��ҵ�λ��
    if(coin_x<=134&&coin_x>=68)//��ҵ���ײ���
	{
		if(coin_y<(bird_y+32)&&coin_y>(bird_y-24)) 
		{
			isHit=2;
			coin_x=350;
			if(CoinNumber<9)
				CoinNumber++;
			else{
				CoinNumber1++;
				CoinNumber=0;
			}
			printf("get");
		}
	}

	stone(stone_x,stone_y);
	CoinN(CoinNumber1,CoinNumber);
	coin_x-=4;
	bird_y += 2;
	stone_x -= 3;
	stoned_x-=2;
    EndBatchDraw();

	if(bird_y<=600+stone_y&&stone_x<134&&stone_x>-40)
	             isHit=0;
    	if(bird_y>=stoned_y-24&&stoned_x<134&&stoned_x>-40)
              isHit=0;
		  else if(bird_y>=576||bird_y<=0)
		     	 isHit=0;

	fflush(stdin);
                 
}

void FirstMenu()
{

	
	char gameName[] ="�����С��";
	 MenuSound();
	PlaySound("menu.wav",NULL,SND_ASYNC|SND_FILENAME);
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT,SHOWCONSOLE);
  load();
	putimage(0,0,&bg);
	setbkmode(TRANSPARENT);
    //����������ɫ
	settextcolor(RED);
 //���������С
	setfont(50,0,"����");
	//��ӡ�ַ���
	outtextxy(70,30,gameName);
	initMenu();
	printf("hello\n");
	while(1)
	{
		
       keyControl();
    
	   if(isStart == 1){
			  if(isHit!=0)
			 moveStone();
			  if(isHit==0){
				  while(1)
					  {
					  Sleep(10);
					  gameover();
					  }   
			  }
	   }
	 if(isStart==2)
	{
       putimage(0,0,&beforegame);
	 }
	
	}

}

void stone(int stone_x,int stone_y){

		putimage(stone_x,stone_y,&stoneUp2,NOTSRCERASE);
		putimage(stone_x,stone_y,&stoneUp1,SRCINVERT);	
			putimage(stoned_x,stoned_y,&stoneDown2,NOTSRCERASE);
			putimage(stoned_x,stoned_y,&stoneDown1,SRCINVERT);	

}
void gameover(){
	BeginBatchDraw();
    		putimage(0,0,&bg);		  
 			putimage(90,250,&over1,NOTSRCERASE); 
	   	putimage(90,250,&over,SRCINVERT); 
		             	putimage(100,bird_y,&birdDown2,NOTSRCERASE); 
	putimage(100,bird_y,&birdDown,SRCINVERT); 
		    EndBatchDraw();
  	mciSendString("stop menu_music",NULL,0,NULL);
	mciSendString("play dead_music from 0 ",NULL,0,NULL);
	bird_y +=6;
}
void showCoin(int x,int y)
{
	putimage(x,y,32,32,&coin,0,9*32,SRCAND);
    putimage(x,y,32,32,&coin,0,8*32,SRCPAINT);

}
void MenuSound()
{
   //PlaySound("menu.wav",NULL,SND_ASYNC | SND_FILENAME);

   mciSendString("open  ./sound/menu.mp3 alias menu_music", NULL, 0, NULL);
   mciSendString("open  ./sound/jump.mp3 alias jump_music", NULL, 0, NULL);
   mciSendString("open  ./sound/dead.mp3 alias dead_music", NULL, 0, NULL);
   mciSendString("open  ./sound/cions.mp3 alias cions_music", NULL, 0, NULL);
   mciSendString("open  ./sound/select.mp3 alias select_music", NULL, 0, NULL);
   mciSendString("play menu_music from 0",NULL,0,NULL);
}
void BirdJumpSound()
{
 
   mciSendString("play jump_music from 0 ",NULL,0,NULL);

}
void load(){

	 loadimage(&bg,"source/bg.jpg");
		loadimage(&bird1,"bird1-1.gif");
		loadimage(&bird2,"bird1-2.gif");
          //������״̬
			loadimage(&birdUp,"source/bird3-2.gif");
			loadimage(&birdUp2,"source/bird3-1.gif");
             //������״̬
				loadimage(&birdDown,"source/bird4-2.gif");
				loadimage(&birdDown2,"source/bird4-1.gif");
                //������״̬
					loadimage(&over,"source/gameover2.gif");
					loadimage(&over1,"source/gameover1.gif");
                      //��Ϸ����
						loadimage(&stoneUp1,"stone_up1.gif");
						loadimage(&stoneUp2,"stone_up2.gif");
                          //��ˮ��
							loadimage(&stoneDown1,"source/stone_down1.gif");
							loadimage(&stoneDown2,"source/stone_down2.gif");
                               //��ˮ��
								loadimage(&coin,"source/ani.bmp");
								  //Ӳ��
								    //0
    								loadimage(&zero1,"source/0_1.jpg");
									loadimage(&zero,"source/0_2.jpg");
									//1
									loadimage(&one1,"source/1_1.jpg");
									loadimage(&one,"source/1_2.jpg");
									//2
									loadimage(&two1,"source/2_1.jpg");
									loadimage(&two,"source/2_2.jpg");
									//3
									loadimage(&three1,"source/3_1.jpg");
									loadimage(&three,"source/3_2.jpg");
									//4
									loadimage(&four1,"source/4_1.jpg");
									loadimage(&four,"source/4_2.jpg");
									//5
									loadimage(&five1,"source/5_1.jpg");
									loadimage(&five,"source/5_2.jpg");
									//6
									loadimage(&six1,"source/6_1.jpg");
									loadimage(&six,"source/6_2.jpg");
									//7
									loadimage(&seven1,"source/7_1.jpg");
									loadimage(&seven,"source/7_2.jpg");
									//8
									loadimage(&eight1,"source/8_1.jpg");
									loadimage(&eight,"source/8_2.jpg");
									//9
									loadimage(&nine1,"source/9_1.jpg");
									loadimage(&nine,"source/9_2.jpg");
	                                    //˵������
										loadimage(&beforegame,"source/beforegame.jpg");
}
void CoinN(int x,int y){
      switch(x){
	case 0:
		putimage(24,36,&zero1,NOTSRCERASE);
		putimage(24,36,&zero,SRCINVERT);
		break;
    case 1:
		putimage(24,36,&one1,NOTSRCERASE);
		putimage(24,36,&one,SRCINVERT);
	   break;
	case 2:
		putimage(24,36,&two1,NOTSRCERASE);
		putimage(24,36,&two,SRCINVERT);
	   break;
	case 3:
		putimage(24,36,&three1,NOTSRCERASE);
		putimage(24,36,&three,SRCINVERT);
	   break;
	case 4:
		putimage(24,36,&four1,NOTSRCERASE);
		putimage(24,36,&four,SRCINVERT);
	   break;
	case 5:
		putimage(24,36,&five1,NOTSRCERASE);
		putimage(24,36,&five,SRCINVERT);
	   break;
	case 6:
		putimage(24,36,&six1,NOTSRCERASE);
		putimage(24,36,&six,SRCINVERT);
	   break;
	case 7:
		putimage(24,36,&seven1,NOTSRCERASE);
		putimage(24,36,&seven,SRCINVERT);
	   break;
	case 8:
		putimage(24,36,&eight1,NOTSRCERASE);
		putimage(24,36,&eight,SRCINVERT);
	   break;
	case 9:
		putimage(24,36,&nine1,NOTSRCERASE);
		putimage(24,36,&nine,SRCINVERT);
	   break;
	  }
	switch(y){
	case 0:
		putimage(48,36,&zero1,NOTSRCERASE);
		putimage(48,36,&zero,SRCINVERT);
	   break;
	case 1:
		putimage(48,36,&one1,NOTSRCERASE);
		putimage(48,36,&one,SRCINVERT);
	   break;
	case 2:
		putimage(48,36,&two1,NOTSRCERASE);
		putimage(48,36,&two,SRCINVERT);
	   break;
	case 3:
		putimage(48,36,&three1,NOTSRCERASE);
		putimage(48,36,&three,SRCINVERT);
	   break;
	case 4:
		putimage(48,36,&four1,NOTSRCERASE);
		putimage(48,36,&four,SRCINVERT);
	   break;
	case 5:
		putimage(48,36,&five1,NOTSRCERASE);
		putimage(48,36,&five,SRCINVERT);
	   break;
	case 6:
		putimage(48,36,&six1,NOTSRCERASE);
		putimage(48,36,&six,SRCINVERT);
	   break;
	case 7:
		putimage(48,36,&seven1,NOTSRCERASE);
		putimage(48,36,&seven,SRCINVERT);
	   break;
	case 8:
		putimage(48,36,&eight1,NOTSRCERASE);
		putimage(48,36,&eight,SRCINVERT);
	   break;
	case 9:
		putimage(48,36,&nine1,NOTSRCERASE);
		putimage(48,36,&nine,SRCINVERT);
	   break;
	}
}
