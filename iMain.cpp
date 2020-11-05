/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/




# include "iGraphics.h"
# include "bitmap_loader.h"
# include "level2.h"



//mode_6(); is for high score
//mode_5(); is for instruction
//mode_1(); is for starting game
//mode_4(); is for menubar

/*
	function iDraw() is called again and again by the system.
*/


/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
/*void drawMenuBox(int x_co , int y_co , int box_len , int box_wid)
{
	if(mposx >= x_co && mposx <= x_co + box_len && mposy >= y_co && mposy <= y_co + box_wid)
	iSetColor(60,160,100);
	else
	iSetColor(60,200,100);
	iFilledRectangle(x_co , y_co , box_len , box_wid);
}*/

void highScore()
{
	iShowBMP(0,0, "images\\hScore.bmp");

}

void prevMenu_1()
{
	iSetColor(255,255,255);
	iText(900,35,"Press b to go back", GLUT_BITMAP_HELVETICA_18);

}


void mode_1()
{
	if(mode==1)
	{
	   drawing();
	   prevMenu_1();
	}
	
}

void mode_3()
{
	printf("%d\n", mode);
	if(mode==3)draw2();
}
void mode_4()
{
	if(mode==4)menu();
}
void mode_5()
{
	if(mode==5)
	{
		iClear();
		iShowBMP(0,0,"images\\instruction.bmp");
		prevMenu_1();
	}
}
//void mode_2()
//{
	//if(mode==2){
	//iSetColor(0,123,174);
	//iShowBMP(0,700, "images\\sand.bmp");}
//}

void mode_6()
{
	if(mode == 6)
	{
		iClear();
		highScore();
		prevMenu_1();
	}
	
}

void inGame()
{
	mode_1();
	mode_2();
	mode_3();
	mode_5();
	mode_4();
	mode_6();
	

}

void iDraw()
{
	//place your drawing codes here
	
	inGame();

}
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if(mx >= 675 && mx <= 875 && my >= 200 && my <= 250 && mode == 4)
		{
			mode = 1;
		}

		if(mx >= 675 && mx <= 875 && my >= 140 && my <= 190 && mode == 4)
		{
			mode = 5;
		}

		if(mx >= 675 && mx <= 875 && my >= 20 && my <= 70 && mode == 4)
		{
			exit(0);
		}

		if(mx >= 675 && mx <= 875 && my >= 80 && my <= 130 && mode == 4)
		{
			mode = 6 ;
		}

		
	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'b')
	{
		mode=4;//do something with 'q'
	}
	if(key=='2'){
		mode=2;
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}

	if(key == GLUT_KEY_RIGHT  && mode==1)
	{
		i+=10;
		//printf("%d",i+39);
		if(39+i>679)
	{
		i-=10;
	}
		RightxRestricted();
	}

	
	if(key == GLUT_KEY_LEFT  && mode==1)
	{
		i-=10;
		//printf("%d",39+i);
		//printf("%d %d ", 39+i, 35+j);
		//printf("%d\n",key);
		if(39+i>=400 && 39+i<=430 && 35+j>=300 && 35+j<=330 && (39+i)>=400 && (39+i)<=430 && (35+j)>=300 && (35+j)<=330)flagCloak=1;
			
		if((39+i)<19)
		{
			i+=10;
		}
		LeftxRestricted();

	}
	if(key == GLUT_KEY_UP && mode==1)
	{
		if(35+j<=670)j+=10;
		//printf("%d",j+35);
		/*if((35+j)>680)
	{
		j-=10;
	}*/

		UpyRestricted();
	}
	if(key == GLUT_KEY_DOWN && mode==1)
	{
		j-=10;
		//printf("%d",35+j);
		if((35+j)<20)
	{
		j+=10;
	}
		
		DownyRestricted();
	}

	if(key == GLUT_KEY_RIGHT  && mode==3)
	{
		if(shipX<=790)shipX+=10;
	}

	
	if(key == GLUT_KEY_LEFT  && mode==3)
	{
		if(shipX>=10)shipX-=10;
	}
	//place your codes for other keys here
}
//
int main()
{
	//place your own initialization codes here.
	i=0;
	j=0;
	flagCloak=0;
	iSetTimer(200,ghmove);
	dghx = 20;

	iInitialize(1100, 700, "Deathly Hallows");
	iStart();
	return 0;
}
