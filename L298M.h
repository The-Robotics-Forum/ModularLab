

#include <avr/io.h>
#include <utildelay.h>
int y,g,SPEd,prt;

#include "io.h"
class mdrive
{ public:
	void l298nmotorDrive(int z ,int y ,int g,int h)
	{
		DDRB=(1<<h)|(1<<(h-1))|(1<<(h-2))|(1<<(h-3));
		analogWrite(y,g);
		if(z==0)
		{
		PORTB=(1<<h)|(1<<(h-2));
		}
		if (z==1)
		{
			PORTB=(1<<(h-1))|(1<<(h-3));
		}
		y=SPEd;
		g=prt;
	}
