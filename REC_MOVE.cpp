#include <stdio.h>
#include<conio.h>
#include <constream.h>
#include <stdlib.h>
#include <graphics.hpp>
#include <dos.h>
#include<alloc.h>
#include "carclassheader.h"


void main() {

	car c;

	int a = DETECT, b;
	initgraph (&a, &b, "C:\\TC\\BGI");


	c.carName();

	c.enginePower();

	c.setSpeed();

	c.refiller();

	c.help();

	c.aplSettings();


	c.start();

	c.road();

	getch();

}//end of main body
