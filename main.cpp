// =============================================================================
#include <cgl/cgl.h>
#include "C_player.h"
#include <core/corefile.h>
#include <cgl/core.h>
#include <stdlib.h>
#include "C_block.h"


s_bitmap bmp_background;
s_sprite spr_BackGround;
s_bitmap bgmask;
s_sprite spr_speler;
s_font fntgame;
s_sprite spr_player[3];
s_sprite spr_lives[10];


int gameactive;
int time=0;
int scrollx,scrolly;
c_player player;
c_block block;


void scrollcontroller(){

	scrollx=player.x-640;
	scrolly=player.y-360;
	if (scrollx<0)scrollx=0;
	if (scrollx>2816)scrollx=2816;
	if (scrolly<-1328)scrolly=-1328;
	if (scrolly>0)scrolly=0;
	
	
	
	

}

void BackGroundController () {
	
	CGL_DrawSprite (0-scrollx,0-(scrolly+1328),spr_BackGround);
}


void checkcollision() {
	
	if(CGL_CheckBoxCollision(block.x1-scrollx,block.y1-scrolly,50,50,player.x-scrollx,player.y-scrolly,50,50)){

		player.state=1;
		block.active1=false;

	}
	
	if(CGL_CheckBoxCollision(block.x2-scrollx,block.y2-scrolly,50,50,player.x-scrollx,player.y-scrolly,50,50)){

		player.state=2;
		block.active2=false;

	}
}

void drawhud(){
	
	for (int t =0;t<player.lives;t++){
		CGL_DrawSprite(515+(t*25),0,spr_lives[t]);
		printf("%d",t);
		
	}
	
	time++;
	CGL_DrawText(10,10,fntgame,"seconds : %d",time/60);
}


void LoadGraphics()

{
	
	CGL_LoadBitmap("bgmask.tga",&bgmask);
	for (int t =0;t<10;t++){
		CGL_LoadSprite("heart.tga",&spr_lives[t]);
		
	}
	CGL_LoadSprite("bg-layer1.tga",&spr_BackGround);
	CGL_InitFont("font_heat.tga",&fntgame);


}

// ===================== Main - Program entry =================
void coremain()
        
{
	// Init Video & Resources
	corefile_mountimage("res",MOUNT_DIR);
    CGL_InitVideo(1280,720,CGL_VIDEO_NONE);
	CGL_SetTitle("untitled_1");
	int id =CGL_InitFramebuffer(1280,720);
	CGL_SetFramebuffer(id);
	

	LoadGraphics();
	player.init();
	block.init();
	// update loop
    gameactive=1;
    do {
      CGL_WaitRefresh();
      BackGroundController();
      scrollcontroller();
      
      block.draw();
      player.draw();
      player.handle();
      checkcollision();
      drawhud();
      CGL_SwapBuffers();                               
    } while(gameactive);  
    CGL_CloseVideo();
}
   
        
