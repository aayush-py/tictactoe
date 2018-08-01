
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<unistd.h>

char done[10]="";
char buttvalues[10]="";
char player = 'X';
int count=0;
char restart(){
	printf("Restart the game(y/n)?\n");
	char y=getch();
	if((y=='y')||(y=='Y')) return 'y';
	else if ((y=='n')||(y=='N')) return 'n';
	else restart();
}
int win(){
	if(
		(
			((buttvalues[0]=='X')&&(buttvalues[3]=='X')&&(buttvalues[6]=='X'))||
			((buttvalues[1]=='X')&&(buttvalues[4]=='X')&&(buttvalues[7]=='X'))||
			((buttvalues[2]=='X')&&(buttvalues[5]=='X')&&(buttvalues[8]=='X'))||
			((buttvalues[0]=='X')&&(buttvalues[1]=='X')&&(buttvalues[2]=='X'))||
			((buttvalues[3]=='X')&&(buttvalues[4]=='X')&&(buttvalues[5]=='X'))||
			((buttvalues[6]=='X')&&(buttvalues[7]=='X')&&(buttvalues[8]=='X'))||
			((buttvalues[0]=='X')&&(buttvalues[4]=='X')&&(buttvalues[8]=='X'))||
			((buttvalues[2]=='X')&&(buttvalues[4]=='X')&&(buttvalues[6]=='X'))
		)
			||
		(
			((buttvalues[0]=='O')&&(buttvalues[3]=='O')&&(buttvalues[6]=='O'))||
			((buttvalues[1]=='O')&&(buttvalues[4]=='O')&&(buttvalues[7]=='O'))||
			((buttvalues[2]=='O')&&(buttvalues[5]=='O')&&(buttvalues[8]=='O'))||
			((buttvalues[0]=='O')&&(buttvalues[1]=='O')&&(buttvalues[2]=='O'))||
			((buttvalues[3]=='O')&&(buttvalues[4]=='O')&&(buttvalues[5]=='O'))||
			((buttvalues[6]=='O')&&(buttvalues[7]=='O')&&(buttvalues[8]=='O'))||
			((buttvalues[0]=='O')&&(buttvalues[4]=='O')&&(buttvalues[8]=='O'))||
			((buttvalues[2]=='O')&&(buttvalues[4]=='O')&&(buttvalues[6]=='O'))
		)
	){
		return 1;
	}
	if(strlen(buttvalues)==9){
		printf("\nNo winners on this try. Restart the game!\n");
		return 2;
	}
	return 0;
}
int isin(char*arr, char a){
	int count=0;
	for(int i=0;i<strlen(arr);i++){
		if(arr[i]==a){
			count++;
		}
	}
	if(count) return 1;
	else return 0;
}
void changepl(){	
	
	switch(player){
		case 'X':
			player='O';
			system("Color 1A");
			break;
		case 'O':
			player='X';
			system("Color A1");
			break;
	}
}
char play[8][20];
char playon[8][20]={
	"     |     |     ",
	"  1  |  2  |  3  ",
	"-----|-----|-----",
	"     |     |     ",
	"  4  |  5  |  6  ",
	"-----|-----|-----",
	"     |     |     ",
	"  7  |  8  |  9  "
	};

void printboard(){
	system("cls");
//	printf("Current done value %s and current buttvalues value %s:\n",done, buttvalues);
//	for(int i=0;i<strlen(buttvalues);i++){
//		printf("%c",buttvalues[i]);
//	}
	printf("\n\n");
	printf("----TIC TAC TOE----\n");
	printf("\n\n");
	for (int i=0;i<8;i++){
			printf("%s\n",play[i]);
	}
	printf("\n\n");
}
int access(){
	char butt;
	printf("Enter a position between 1 and 9\n");
	printf("Press 'X' to exit the game\n");
	butt=getch();
	if((butt=='x')||(butt=='X')){
		return 1;
	}
	if(!((butt=='1')||(butt=='2')||(butt=='3')||(butt=='4')||
	(butt=='5')||(butt=='6')||(butt=='7')||(butt=='8')||(butt=='9'))){
		printf("\n*****Invalid input.*****\n");sleep(1);printboard();
		return 0;
	}
	if(isin(done,butt)){
		printf("Position occupied!\n");sleep(1);
		printboard();
		return 0;
	}else{
		done[count]=butt;
		buttvalues[butt-49]=player;
		count++;
	}
	switch (butt){
		case '1':
			play[1][2]=player;changepl();break;
		case '2':
			play[1][8]=player;changepl();break;
		case '3':
			play[1][14]=player;changepl();break;
		case '4':
			play[4][2]=player;changepl();break;
		case '5':
			play[4][8]=player;changepl();break;
		case '6':
			play[4][14]=player;changepl();break;
		case '7':
			play[7][2]=player;changepl();break;
		case '8':
			play[7][8]=player;changepl();break;
		case '9':
			play[7][14]=player;changepl();break;
		default:
			printf("Invalid input.\n");sleep(1);
	}
	printboard();
	if(win()==1){//when a win is recorded
		changepl();
		printf("%c wins the game!\n",player);
		return 2;
	}
	if(win()==2){//when no wins are recorded
		return 3;
	}
	return 0;
} 
int main(){
	system("Color 12");
	char start='y';
	while((start=='y')||(start=='Y')){
		memset(done,0,10);
		memset(buttvalues,0,10);
		player = 'X';
		count=0;
		for(int i=0;i<8;i++){
			strcpy(play[i],playon[i]);
		}
		printboard();
		while(1){
			int a = access();
			if (a==1){//exiting game
				printf("------------GAME OVER------------\n");
				start=restart();
				break;
			}else if(a==2){//when a win is recorded
				start=restart();
				break;
			}else if(a==3){//when no wins are recorded
				start=restart();
				break;
			}
		}
		if(start=='n') break;
	}
	return 0;
}
