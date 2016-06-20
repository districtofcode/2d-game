#include <cgl/cgl.h>

extern s_sprite spr_player[3];
extern int scrollx,scrolly;
extern int state;



class c_block {

	public :
		float x1,y1,x2,y2;
		int angle;
		bool active1,active2;
		void init();
		void draw();
		
	
};	


