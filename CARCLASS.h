/*
* Written by Muhammad Nasir Shamshad(Pakistan)
* Year - 2009
* email: nasir031@gmail.com
*/
//function prtotypes

void carControl(int&, int &, int &, int &, int&);
void makeCar(int&, int&, int&, int&);
void roadStrips(int, int);


//creating a car class


class car {


	private:
		int model;

		int trakLength();//Utilty function

		char name[20];

	public:

		car(); //class constructor

		void carName();
		void start();
		void road();
		int setSpeed();
		int enginePower();
		void refiller();
		void aplSettings();
		void refill();
		void speed();
		void help();
		void enemy(int&,int&);

	struct features {

		  char playerName[25];

		  int highScore;



	};//end of struct


};//end of car class

////////////////////////////////////////////////////////////////////////////
///////////////////////DEFINATION OF CAR NAME FUNCTION//////////////////////
///////////////////////////////////////////////////////////////////////////


car c;  //object of car

car :: features f; //object of feature struct

//initializing the data memebers in car constructor

car :: car() {

	f.highScore = 500;

	model = 1901;

}//end of car constructor;




void car :: carName() {

		cleardevice();


		settextstyle(0, HORIZ_DIR, 5);

		setcolor(4);

		outtextxy(7,50, "BED_FORD");

		outtextxy(7,100,"1901 Model");

		delay(3000);

		cleardevice();

		outtextxy(10,100,"Enter your Name");

		gotoxy(5,5);


//getting the player name from user

		cin >> f.playerName;

}//end of carName function



//**********************************************************************//
/////////////////////////////////HELP FUNCTION//////////////////////////
//**********************************************************************//



void car :: help() {

	setbkcolor(4);

	cleardevice();

	settextstyle(0, HORIZ_DIR, 5);

	setcolor(WHITE);

	outtextxy(100,200,"HELP MENU");

	delay(2000);

	cleardevice();

	settextstyle(1, HORIZ_DIR, 5);

	outtextxy(50,200,"Use Arrow Keys");

	delay(2000);

	cleardevice();

	outtextxy(20,200,"Press h For Horn");

	delay(1000);

	cleardevice();

	outtextxy(20,200,"Press b For break");

	delay(2000);


	cleardevice();


}//end of help function




////////////////////////////////////////////////////////////////////////////
///////////////////////REFILLER FUNCTION///////////////////////////////
///////////////////////////////////////////////////////////////////////////


void car :: refiller() {


//local declarations for refiller

	char string[20];
	float i = 313.80;



	rectangle(180,320,200,150);

	settextstyle(1, HORIZ_DIR,5);

	sprintf(string, "REFILLING..... ", 10);

 /* output the message */

	outtextxy(75, 70, string);


while(i >= 160) {

	circle(190,i,8);

	setcolor(2);

if(i > 180)

	setcolor(4);

	i--; //decrement in the value of i

	delay(10);

  if(i >= 180) {

	delay(40);
	setbkcolor(0);

  }//end of if


	sound(800);

	delay(10);

	nosound();

  }//end of if

	delay(700);


}//end of function

/////////////////////////////////////////////////////////////////////////
/////////********************APPLIYING SETTING*************************//
////////////////////////////////////////////////////////////////////////

void car :: aplSettings() {

	 cleardevice();

	 delay(1000);

	int j = 205; //initializing the loop

	rectangle(200,150,400,160);

	setbkcolor(0);

	outtextxy(20,50,"APPLIYING SETTINGS......");

while(j <= 393) {


	circle(j,155,4);

	setcolor(15);

	j++; //increment in loop value

	delay(10);

  if(j >= 340) {

	delay(50);

   }//end of if

}//end of while

	delay(1000);

	cleardevice();


}//end of aplSettings fun


///////////////////////////////////////////////////////////////////////
////////////////////////SET SPEED FUNCTION////////////////////////////
/////////////////////////////////////////////////////////////////////

int car :: setSpeed() {

	cleardevice();

	int speed; //declaring the speed variable

	setbkcolor(0);

	cout << "\t=========================================\n";

	cout << "\tSET THE HIGEST SPEED FOR YOUR CAR IN KM's\n";

	cout << "\t=========================================\n";


	gotoxy(10,5);


//getting input the speed variable

	cin >> speed;

	cleardevice();

	return speed;



}//end of setSpeed fun



////////////////////////////////////////////////////////////////////
///////////////////ENGINE POWER FUNCTION///////////////////////////
//////////////////////////////////////////////////////////////////


int car :: enginePower() {

	cleardevice();

	setbkcolor(0);

	int ePower;

	gotoxy(10,10);

	cout << "ENTER YOUR CAR's ENGINE POWER\n";

	gotoxy(10,13);

	cout << "DEFAULT POWER = 2000-hp\n\n";

	gotoxy(20,5);


//getting input in engine power


	cin >> ePower;

	cleardevice();

	return ePower;

}//end of ePower function

////////////////////////////////////////////////////////////////////////
////////////////////////START FUNCTION////////////////////////////////
/////////////////////////////////////////////////////////////////////


void car :: start() {

		cleardevice();

		settextstyle(1, HORIZ_DIR, 5);

		outtextxy(100,200, "PRESS SPACE TO START");


		int status;

		status = getch();

/* athentication condition further excution

		on true key */


	if (status == 32)  {

		road();//call to road function

	} else {

		cleardevice();

		outtextxy(80,200,"WRONG KEY...");

		delay(1000);

		cleardevice();

	/* rucurcive call to function itself
		if user press a wrong key */

		start();

	}//end of else


}//end of start function

////////////////////////////////////////////////////////////////////////////
/////////////////////////TRAK LENGTH FUNCTION//////////////////////////////
//////////////////////////////////////////////////////////////////////////

int car :: trakLength() {

	/* Pre: recieve nothing

	*  Post: return a integer value
	*	 used as the game traklength
						*/




	       cleardevice();


//getting the memory for storing the value  of length

	       int length;

	       settextstyle(1, 0, 5);

	       setbkcolor(0);

	       outtextxy(50,100,"Enter Trak Length");

	       setcolor(10);

	       delay(1000);

	       gotoxy(20,5);

	       cin >> length;

	       cleardevice();

	 return length; //returning the length value entered by user

}//end of trakLength function




/////////////////////////////////////////////////////////////////////////
/////////////////////////CAR CONTROL//ROAD//////////////////////////////
///////////////////////////////////////////////////////////////////////




void car :: road() {

//local declarations

	int x1 = 280;
	int x2 = 310;
	int y1 = 450;
	int y2 = 420;
	float fuel = 500;

//variable 'k' for getting key

	int k;

//values for car

	int yy1 = -10;
	int yy2 = -210;

//values for enemy cars

	int yExis1 = 20;

	int yExis2 = 40;

//initializing the track length cotroler

	int trakController = 0;

	float race = 0.0;


	int trakLen = trakLength();

	do {


		yy1+=5; //incrementing in road strips

		yy2+=5; //incrementing in road strips

		yExis1+=2; //incrementing in enemy

		yExis2+=2; //incrementing in enemy



		cleardevice();

		rectangle(150, -10, 450, 490);//rectangle for road


		roadStrips(yy1, yy2);//making road strips


		makeCar(x1, y1, x2, y2);//call to makeCar function


//keyboard sensor, sensitive for any touch on keyboard's surface

	       if (kbhit()) {


	      //getting the key's Assci value

			k = getch();


	      carControl(x1, y1, x2, y2, k);//call to car cotrol fun




if(k == 72) {

race++;

//yy1+=20;
//yy2+=10;

}else if(k == 80) {

	race-=0.8;


}else if(k == 75) {

     gotoxy(3,3);

     cout << "LEFT TURNING";


}else if (k == 77) {

	gotoxy(3,3);

	cout << "RIGHT TURNING";



} //accelration if



		}//end of kbhit()'s if



		if (yy1 == 480) {

			yy1 = -210;
			yy2 = -10;

			yExis1 = 20;

			yExis2 = 40;

			//enemy(yExis1,yExis2);
			fuel--;//decrement in fuel

		}//end of yy1 if

		else if(trakController > 50) {

			enemy(yExis1,yExis2);//enemy function call

	       }//end of else if



	       gotoxy(3,5);

	       cout << "SPEED : " << race << endl;

	       gotoxy(3,6);

	       cout << "copleted meters : " << trakController << endl;

	       gotoxy(3,7);

	       cout << "Remaning Fuel :" << fuel << "Ltrs" << endl;


	       gotoxy(3,3);

	       cout << f.playerName;


	       race+=0.04;//increment in speed



	if(trakController == trakLen) {

		setbkcolor(0);

		settextstyle(1,0,5);

		setcolor(4);

		outtextxy(20,100,"Track Finished");

		delay(2000);

		cleardevice();

		outtextxy(20,100,"Terminating Game");

		delay(2000);

		outtextxy(20,150,"WITHIN 5 SECONDS");

		delay(5000);

		cleardevice();

		exit(0);

	}//end of trak controller condition


   if(fuel <= 0) {

		cleardevice();

		setbkcolor(4);

		fuel = 500;

		settextstyle(0,0,3);

		setcolor(2);

		outtextxy(10,100,"oops! Fuel Tank Is Empty");

		delay(3000);

		cleardevice();

		outtextxy(10,100,"I am going to the Petro Pump");

		delay(3000);

		cleardevice();

   //call to refiller function

		refiller();


	}//end of else if


      if(race >= 240.04) {
		gotoxy(40,5);

		cout << "speed limit exceded\n";

		gotoxy(40,7);

		cout << "Engine blowing";

		gotoxy(40,9);

		cout << "Reduce Speed\n";

		gotoxy(40,11);

		cout << "Otherwise Game will Terminate\n";

		if(race >= 300.05) {

			cleardevice();

			outtextxy(50,100,"You Idiot...!!");

			delay(2000);

			exit(0);

		}//race > 300


      }//end of race if

		trakController++;

   } while(yy1 != 481);//end of while

}//end of road function


//********************************************************************//
//////////////////////////////CAR MAKER/////////////////////////
//********************************************************************//


void makeCar(int& x1, int& y1, int& x2, int& y2) {

	rectangle(x1, y1, x2, y2);


//boundry controlar

//car safety switches

	if(x1 == 150 || x1 == 130) {

		x1 = 280;
		x2 = 310;


	}else if(x2 == 490 || x2 == 455) {


		x1 = 280;
		x2 = 310;

	}else if(y1 == 20) {

	       y1 = 450;
	       y2 = 420;


	}else if(y2 == 460) {

	       y1 = 450;
	       y2 = 420;


	}//end of else if

}//end of car maker function

//********************************************************************//
//////////////////////////////ROAD STRIPS MAKER/////////////////////////
//********************************************************************//


void roadStrips(int yy1, int yy2) {

	setlinestyle(SOLID_FILL,1,1);

	rectangle(280, yy1, 300, yy2);

	setlinestyle(0,1,1);

}

//***********************************************************************
///////////////////////////CAR CONTROL FUNCTION//////////////////////////
//**********************************************************************

void carControl(int& x1, int& y1, int& x2, int& y2, int& key) {



	if (key == 0) {

		key = getch();

		if (key == 77) {

			x1+=5;
			x2+=5;

		} else if (key == 75) {

			x1-=5;
			x2-=5;

		} else if (key == 72) {

			y1-=10;
			y2-=10;

		} else if (key == 80) {

			y1+=10;
			y2+=10;

		}//end of up/down/right/left else if

	} else if (key == 27) {

		exit (0);

	} else if (key == 104 || key == 72)  {


			sound(800); //make a sound
			delay(20); //20ms delay
			nosound(); //shut down the sound



	} else if(key == 'b' || key == 'B') {

		outtextxy(40,100,"Chusss...! Break");

		delay(2000);

		c.start();

	}//end of last else if

}//end of car control function



//////////////////////////////////////////////////////////////////////
//****************************ENEMY CARS************************//
//////////////////////////////////////////////////////////////////////



void car :: enemy(int &exis1, int &exis2) {

	rectangle(250,exis1,270,exis2);


}//enemy end
