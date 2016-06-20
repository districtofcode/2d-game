#include "C_block.h"

void c_block::init(){
	x1=3800;
	y1=571;
	x2=3800;
	y2=-429;
	angle=0;
	active1=true;
	active2=true;
}



void c_block::draw(){
	
	if (active1)CGL_DrawSprite (x1-(scrollx),y1-(scrolly),spr_player[1]);	
	if (active2)CGL_DrawSprite (x2-(scrollx),y2-(scrolly),spr_player[2]);	
}



