class mdrive
{ public:
	void CytronmotorDrive(int z ,int y ,int g,int h)
	{
		DDRB=(1<<h)|(1<<(h-1));
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
