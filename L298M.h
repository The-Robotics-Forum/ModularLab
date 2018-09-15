

#include <avr/io.h>
#include <utildelay.h>
class l2n8
{ public:
	void init(int z ,int h)
	{
		DDRB=(1<<h)|(1<<(h-1));

		if(z==0)
		{
		PORTB=(1<<h)|(1<<(h-2));
		}
		if (z==1)
		{
			PORTB=(1<<(h-1))|(1<<(h-3));
		}
	}
	void drive(int y ,int g)
	{	analogWrite(y,g);
	}
}
