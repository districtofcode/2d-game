#include <cgl/cgl.h>
#define yellowblock 0xfffff5cc
#define spikes      0xffff0000
#define ground      0xff373737
#define finish      0xff00ff00
#define nonjumpwall 0xff000000

extern s_sprite spr_player[3];
extern int scrollx,scrolly;
extern s_bitmap bgmask;
extern int gameactive;

class c_player {
	public :
		float x,y,xmomentum,ymomentum,oldx,oldy;
		int state;
		int checkpoint;
		int angle;
		int jumpcount;
		int lives;
		
		void init();
		void draw();
		void jump();
		void handle();
		
	
};	


