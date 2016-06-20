#include "C_player.h"
#include <iostream>

void c_player::init(){
	x =150;
	y=600;
	lives=10;
	state=0;
	angle=0;
	jumpcount=0;
	checkpoint =0;
	CGL_LoadSprite("player1.tga",&spr_player[0]);
	CGL_LoadSprite("player2.tga",&spr_player[1]);
	CGL_LoadSprite("player3.tga",&spr_player[2]);
	
}



void c_player::draw(){
	
	if (state==0)	CGL_DrawRotatedSprite (x-(scrollx),y-(scrolly),spr_player[0],angle);
	if (state==1)	CGL_DrawRotatedSprite (x-(scrollx),y-(scrolly),spr_player[1],angle);	
	if (state==2)	CGL_DrawRotatedSprite (x-(scrollx),y-(scrolly),spr_player[2],angle);	
}


void c_player::handle(){
	
//inputcontrolling


	int key,keytrig;
	
	CGL_GetKeys(&key,&keytrig);
	
	if (key& CGL_INPUT_KEY_RIGHT)xmomentum=10;
	if (key& CGL_INPUT_KEY_LEFT)xmomentum=-10;
	if (key& CGL_INPUT_KEY_UP)jump();
    // ghravity 
	ymomentum++;
	
//bitmapcontrolling
	int kleurbottom,kleurtop,kleurrechts,kleurlinks;
	
	kleurbottom=CGL_GetPixel(x+25,y+1378,bgmask);
	kleurtop=CGL_GetPixel(x+25,y+1328,bgmask);
	kleurrechts=CGL_GetPixel(x+50,y+1353,bgmask);
	kleurlinks=CGL_GetPixel(x,y+1353,bgmask);
	

	
	if (kleurbottom==ground){
	ymomentum=-1;
	jumpcount=0;
	}
	
	if (kleurtop==ground){
	ymomentum=1;
	jumpcount=-1;
	}
	
	if (kleurrechts==ground){
	xmomentum=-1;
	jumpcount=0;
	}
	
	if (kleurlinks==ground){
	xmomentum=+1;
	jumpcount=0;
	}
	
	if (kleurbottom==spikes||y>720){
	x = oldx;
	y=oldy;
	lives--;
		
	}
	
	if (kleurbottom==yellowblock){
		if(state==2){
			ymomentum=-1;
			jumpcount=0;
		}
	}
	
	if (kleurtop==yellowblock){
		if(state==2){
			ymomentum=1;
			jumpcount=-1;
		}
	}
		
			
	if (kleurrechts==yellowblock){
		if(state==2){
			xmomentum=-1;
			jumpcount=0;
		}
	}
	
		
	if (kleurlinks==yellowblock){
		if(state==2){
			xmomentum=1;
			jumpcount=0;
		}
	}
	
	if (kleurlinks==nonjumpwall)xmomentum=1;
	if (kleurrechts==nonjumpwall)xmomentum=-1;
	if (kleurtop==nonjumpwall)ymomentum=1;
	if (kleurbottom==nonjumpwall)ymomentum=-1;
	
	if (kleurrechts==finish)gameactive =0;
	
	//physics simulation
	
	x+=xmomentum;
	y+=ymomentum;
	
	if (ymomentum>6)ymomentum--;
	if (ymomentum<0)ymomentum++;
	if (xmomentum>0)xmomentum--;
	if (xmomentum<0)xmomentum++;
	
	
	//bounds player
	if (x<0)x=0;
	if (x>4096)x=4096;
	if (y>1328)y=1328;
	
	
}

void c_player::jump(){


	if (state==0||state==2){
	

		if(jumpcount==0 || jumpcount==3){
			oldx=x;
			oldy=y;	
			jumpcount=1;
		}
	
	if (jumpcount==1){
			if (y>=oldy-200)ymomentum=-20;
			}
		
		if (y<oldy-200)jumpcount=2;
		
		
	}
	
	
	if (state==1) {
		
	
		if(jumpcount==0 || jumpcount==3){
			oldx=x;
			oldy=y;	
			jumpcount=1;
		}
	
		if (jumpcount==4){}	
	
		if (jumpcount==1){
			if (y>=oldy-200)ymomentum=-20;
			if (y<oldy-200)jumpcount=2;
		}
		
		if (jumpcount==2){
			if (y>=oldy-400)ymomentum=-20;
			if (y<oldy-400)jumpcount=4;
			}
	
	}
	
}	
	
	
	

