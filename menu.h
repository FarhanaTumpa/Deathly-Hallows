
#define MENU_H_INCLUDED

int mode=4;
int mposx,  mposy;

void drawMenuBox(int x_co , int y_co , int box_len , int box_wid)
{
	if(mposx >= x_co && mposx <= x_co + box_len && mposy >= y_co && mposy <= y_co + box_wid)
	iSetColor(60,160,100);
	else
	iSetColor(60,200,100);
	iFilledRectangle(x_co , y_co , box_len , box_wid);
}
 void menu(){

 if(mode == 4)
	{
		iClear();
		iSetColor(255 , 255 , 255);
		iFilledRectangle(0 , 0 , 900, 600);
		iShowBMP(0 , 0,"images\\1b.bmp");

		iSetColor(255,0,0);
		iText(500,600, "Deathly Halllows",GLUT_BITMAP_TIMES_ROMAN_24 );

		drawMenuBox(675, 200, 200, 50);
		iSetColor(0,0,0);
		iText(715, 215 , "New Game ",GLUT_BITMAP_HELVETICA_18);

		drawMenuBox(675, 140, 200, 50);
		iSetColor(0,0,0);
		iText(715, 155 , "Instructions ",GLUT_BITMAP_HELVETICA_18);

		drawMenuBox(675, 80, 200, 50);
		iSetColor(0,0,0);
		iText(715, 95 , "High Score ",GLUT_BITMAP_HELVETICA_18);

		drawMenuBox(675, 20, 200, 50);
		iSetColor(0,0,0);
		iText(750, 35 , "Exit ",GLUT_BITMAP_HELVETICA_18);

		
	}
 }
