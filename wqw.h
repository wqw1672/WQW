#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include<stdlib.h>
#include <windows.h>
#include<MMSYSTEM.H>
#pragma comment(lib, "winmm.lib")
#define WINDOW_WIDTH  350
#define WINDOW_HEIGHT 600
#define START 0
int isHit=1;
int curMenu = 0;//没有默认菜单
int isStart = 0;
int bird_y = 175;
int stone_x =300;
int stoned_x=330;
int stone_y=-450;
int stoned_y=450;
int coin_x=350,coin_y=350;
int birdup=0;
int birdup1=0;
int CoinNumber=0;
int CoinNumber1=0;
	IMAGE bg,beforegame,over,over1;
	IMAGE bird1,bird2;
	IMAGE birdDown,birdDown2;
	IMAGE birdUp,birdUp2;
	IMAGE stoneUp1,stoneDown1;
	IMAGE stoneUp2,stoneDown2;
	IMAGE coin;
	IMAGE zero,one,two,three,four,five,six,seven,eight,nine;
	IMAGE zero1,one1,two1,three1,four1,five1,six1,seven1,eight1,nine1;
void initMenu();
void showCoin(int x,int y);
void gameover();
void keyControl();
void moveStone();
void FirstMenu();
void stone(int stone_x,int stone_y);
void load();
void CoinN(int x,int y);
void MenuSound();
void BirdJumpSound();