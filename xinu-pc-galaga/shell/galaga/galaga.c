#include <xinu.h>
#include "titlescreen.h"
#include "playerImage.h"
#include "enemy.h"
#include "boss.h"
#include "gameover.h"
#include "shoot.h"

extern unsigned char tecla_actual;
typedef unsigned short u16;
#define RGB(r, g, b) (r | (g << 5) | (b << 10))
// #define REG_DISPCNT *(u16 *)0x4000000
#define extern videoBuffer
#define MODE3 3
#define BG2_ENABLE (1 << 10)
#define WHITE RGB(31, 31, 31)
#define BLACK RGB(0, 0, 0)

#define BUTTON_A	0x24
#define BUTTON_B	0x25 
#define BUTTON_SELECT	0x03
#define BUTTON_START	0x2c
#define BUTTON_RIGHT	0x1f
#define BUTTON_LEFT	0x1e	
#define BUTTON_UP	'w'
#define BUTTON_DOWN 	's'	
#define BUTTON_R	'1'
#define BUTTON_L	'2'
#define KEY_DOWN_NOW(key)  (tecla_actual == key)

//variable definitions
#define playerspeed 2
#define enemyspeed 1
#define fastXSpeed 3
#define fastYSpeed 2


void setPixel(int x, int y, u16 color); 
void drawRect(int x, int y, int width, int height, u16 color);
void drawHollowRect(int x, int y, int width, int height, u16 color);
void drawImage3(int x, int y, int width, int height, const u16* image);
void delay_galaga();
void waitForVBlank();

//helpers
void initialize();
void drawEnemies();
void endGame();
int collision(u16 enemyX, u16 enemyY, u16 enemyWidth, u16 enemyHeight, u16 playerX, u16 playerY);

//objects
struct Players {
	volatile u16 playerX;
	volatile u16 playerY;
};
struct Enemy {
	volatile u16 enemyX;
	volatile u16 enemyY;
};
struct FastEnemy {
	volatile u16 fastX;
	volatile u16 fastY;
};

int shoots[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int curr_shot = 0;
#define N_SHOOTS 10

//procesos 1 y 2
int proceso1(pid32 proc2);
int proceso2(pid32 proc3);


int proceso1(pid32 proc2){
    /*se encarga del juego en si*/
    //easy enemy wave set setup
	struct Enemy easyEnemies[9];
	for (int a = 0; a < 9; a++) {
		easyEnemies[a].enemyX = (28*a);
		easyEnemies[a].enemyY = 0;
	} 
	easyEnemies[1].enemyX = 240;
	easyEnemies[4].enemyX = 240;
	easyEnemies[8].enemyX = 240;
	//difficult enemies setup
	struct Enemy hardEnemies[9];
	for (int a = 0; a < 9; a++) {
		hardEnemies[a].enemyX = (28*a);
		hardEnemies[a].enemyY = 160;
	} 
	hardEnemies[3].enemyX = 240;
	hardEnemies[6].enemyX = 240;
	//player setup
	struct Players player;
	player.playerX = 120;
	player.playerY = 136;
	//fast enemy "boss" setup
	struct FastEnemy fast;
	fast.fastX = 0;
	fast.fastY = 30;
	// REG_DISPCNT = MODE3 | BG2_ENABLE;
	//initalize title screen
	print_text_on_vga(10, 20, "GALAGA ");
	drawImage3(0, 0, 240, 160, titlescreen);
	while(1) {
		if (KEY_DOWN_NOW(BUTTON_START)) {
			break;
		}
	}	
	//start black screen for drawing
	for (int i = 0; i < 240; i++) {
		for (int j = 0; j < 160; j++) {
			setPixel(i, j, BLACK);
		}
	}	
	while(1) {
		//go back to title screen if select button is pressed
		if (KEY_DOWN_NOW(BUTTON_SELECT)) {
			//initialize();
			galaga();
		}
		//player shots 
		if (KEY_DOWN_NOW(BUTTON_A)) {
			if (shoots[curr_shot] == 0) {
				shoots[curr_shot] = 136*240 + player.playerX+9; /* 24 widht player */
				curr_shot++;
				if (curr_shot >= N_SHOOTS)
					curr_shot = 0;
			};
		}
		//player movement input
		if (KEY_DOWN_NOW(BUTTON_LEFT) && (player.playerX > 0)) {
			player.playerX -= playerspeed;
		}
		if (KEY_DOWN_NOW(BUTTON_RIGHT) && (player.playerX <= 216)) {
			player.playerX += playerspeed;
		}
		if (KEY_DOWN_NOW(BUTTON_UP) && (player.playerY > 25)) {
			player.playerY -= playerspeed;
		}
		if (KEY_DOWN_NOW(BUTTON_DOWN) && (player.playerY <= 136)) {
			player.playerY += playerspeed;
		}
		waitForVBlank();
		sleepms(50);
		//draw player
		drawImage3(player.playerX, player.playerY, 24, 24, playerImage);
		drawHollowRect(player.playerX - 1, player.playerY - 1, 26, 26, BLACK);
		drawHollowRect(player.playerX - 2, player.playerY - 2, 28, 28, BLACK);
		//draw easy enemies with downward movement
		for (int a = 0; a < 9; a++) {
			easyEnemies[a].enemyY += enemyspeed;
			drawImage3(easyEnemies[a].enemyX, easyEnemies[a].enemyY, 20, 20, enemy);
			if (collision(easyEnemies[a].enemyX, easyEnemies[a].enemyY, 20, 20, player.playerX, player.playerY)) {
 				//ENVIA MENSAJE A 2
                send(proc2, 0); 
				drawRect(easyEnemies[a].enemyX, easyEnemies[a].enemyY,  20, 20, BLACK);
				easyEnemies[a].enemyY = 0;
			}	
			if (easyEnemies[a].enemyY >= 160) {
				easyEnemies[a].enemyY = 0;
			}		
		}
		//draw hard enemies
		for (int a = 0; a < 9; a++) {
			hardEnemies[a].enemyY += enemyspeed;
			drawImage3(hardEnemies[a].enemyX, hardEnemies[a].enemyY, 20, 20, enemy);
			if (collision(hardEnemies[a].enemyX, hardEnemies[a].enemyY, 20, 20, player.playerX, player.playerY)) {
			//ENVIAR MENSAJE A 2
				send(proc2, 0); 
				drawRect(hardEnemies[a].enemyX, hardEnemies[a].enemyY,  20, 20, BLACK);
				hardEnemies[a].enemyY = 0;
			}	
			if (hardEnemies[a].enemyY >= 228) {
				hardEnemies[a].enemyY = 0;
			}
			if ((hardEnemies[a].enemyY >= 200) && (easyEnemies[a].enemyY <=45)) {
				hardEnemies[a].enemyY = 160;
			}	
			//space enemies apart
			if ((hardEnemies[a].enemyY >= 200) && (easyEnemies[a].enemyY <=45)) {
				hardEnemies[a].enemyY = 160;
			}		
			if ((easyEnemies[a].enemyY >= 120) && (hardEnemies[a].enemyY >=170)) {
				hardEnemies[a].enemyY = 160;
			}							
		}	
		//draw fast enemy
		drawImage3(fast.fastX, fast.fastY, 15, 15, boss);
		drawHollowRect(fast.fastX - 1, fast.fastY - 1, 17, 17, BLACK);
		drawHollowRect(fast.fastX - 2, fast.fastY - 2, 19, 19, BLACK);
		if(collision(fast.fastX, fast.fastY, 15, 15, player.playerX, player.playerY)) {
		//ENVIAR MENSAJE A 2
			send(proc2, 0); 
			drawRect(fast.fastX, fast.fastY,  20, 20, BLACK);
			fast.fastY = 0;
		}		
		fast.fastX += fastXSpeed;
		fast.fastY += fastYSpeed;
		if (fast.fastX >= 240) {
			fast.fastX = 0;
		}
		if (fast.fastY >= 200) {
			fast.fastY = player.playerY - 20;
		}
	
	//draw shots
	for (int i = 0; i < N_SHOOTS; i++) {
		if (shoots[i] != 0) {
			drawRect((shoots[i] % 240), (shoots[i] / 240)+4, 5, 5, BLACK);
			drawImage3((shoots[i] % 240), (shoots[i] / 240), 5, 5, shoot);
			shoots[i] = shoots[i]-240*4;
			if (shoots[i] <=0)   shoots[i]=0;
		
		// check hits of shoots for easy enemys 
		for (int j = 0; j < 9; j++) {
			if (collision(easyEnemies[j].enemyX, easyEnemies[j].enemyY, 15, 15, shoots[i] % 240, shoots[i] / 240)) {
				//ENVIAR MENSAJE A 2
				send(proc2, 1);
				drawRect(easyEnemies[j].enemyX, easyEnemies[j].enemyY,  20, 20, BLACK);
				drawRect((shoots[i] % 240), (shoots[i] / 240)+4, 5, 5, BLACK);
				easyEnemies[j].enemyY = 0;
				shoots[i] = 0;
			}
			if (collision(hardEnemies[j].enemyX, hardEnemies[j].enemyY, 15, 15, shoots[i] % 240, shoots[i] / 240)) {
				//ENVIAR MENSAJE A 2
				send(proc2, 10);
				drawRect(hardEnemies[j].enemyX, hardEnemies[j].enemyY,  20, 20, BLACK);
				drawRect((shoots[i] % 240), (shoots[i] / 240)+4, 5, 5, BLACK);
				hardEnemies[j].enemyY = 0;
				shoots[i] = 0;
			}
		}
		if(collision(fast.fastX, fast.fastY, 15, 15, shoots[i] % 240, shoots[i] / 240)){
			//ENVIAR MENSAJE A 2
			send(proc2, 100);
				drawRect(fast.fastX, fast.fastY,  20, 20, BLACK);
				drawRect((shoots[i] % 240), (shoots[i] / 240)+4, 5, 5, BLACK);
				fast.fastY = 0;
				shoots[i] = 0;
		}
		}
	}
}
	return 0;
}

int collision(u16 enemyX, u16 enemyY, u16 enemyWidth, u16 enemyHeight, u16 playerX, u16 playerY) {
	//check if bottom right corner of enemy is within player
	if (((enemyX + enemyWidth) > playerX) && ( (enemyY + enemyHeight) 
		> playerY ) &&  ((enemyX + enemyWidth) < (playerX + 24)) 
		&& ((enemyY + enemyWidth) < (playerY + 24))) {
		return 1;
	} 
	//check bottom left corner of enemy
	if ( (enemyX < (playerX + 24)) 
		&& (enemyX > playerX)
		&& ((enemyY + enemyHeight) > playerY)
		&& ((enemyY + enemyHeight) < (playerY + 24))
		) {
		return 1;
	}
	//check top left corner
	if ( (enemyX < (playerX + 24)) 
		&& (enemyX > playerX)
		&& (enemyY > playerY)
		&& (enemyY < (playerY + 24))
		) {
		return 1;
	}	
	//check top right corner
	if ( ((enemyX + enemyWidth) < (playerX + 24)) 
		&& ((enemyX + enemyWidth) > playerX)
		&& (enemyY > playerY)
		&& (enemyY < (playerY + 24))
		) {
		return 1;
	}	
	return 0;
}

int proceso2(pid32 proc3){
    /*se encarga de las vidas y el puntaje*/
    int vidas = 5, puntaje = 0; 
    int mensaje; 
    char cartel[50];


    while(1){

		sprintf(cartel, "vidas: %d, puntaje: %d", vidas, puntaje);
        print_text_on_vga(100, 650, cartel);
        mensaje = receive(); 
        if(mensaje > 1){ //el mensaje trae la cantidad de puntos o pierde vidas
            puntaje = puntaje + mensaje; 
        } else {
            vidas = vidas -1; 
            if(vidas <= 0 ){
                send(proc3, 1); 
            }
        }
    }
}

//proceso3
int galaga (){
    /*se encarga del cotrol de los otros procesos, los crea y se queda esperando el mensaje de fin del juego*/
    int mensaje; 
    pid32 proc2 = create(proceso2, 2048, 20, "puntajeYvidas", 1,getpid());
    pid32 proc1 = create(proceso1, 2048, 20, "juego",1 ,proc2);
    resume(proc1);
    resume(proc2);
    receive();
    kill(proc2);
    kill(proc1);
    endGame();
}

void endGame() {
	//start Game Over State
	drawImage3(0, 0, 240, 160, gameover);
	drawHollowRect(0, 0, 240, 160, WHITE);
	while(1) {
		if (KEY_DOWN_NOW(BUTTON_SELECT)) {
			galaga();
		}
		if (KEY_DOWN_NOW(BUTTON_START))	{
			galaga();
		}
	}
}