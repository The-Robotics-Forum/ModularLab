//TODO: Add a stop() function
class Cytron
{
	public:
	uint8_t dIrpin, pWmpin, lAstpwm, step1, interval;	//variables for first motor
	uint8_t dIrpin1, pWmpin1, lAstpwm1, step2; //variables for second motor
	uint8_t dIrpin2, pWmpin2, lAstpwm2, step3; //variables for third motor
	uint8_t dIrpin3, pWmpin3, lAstpwm3, step4; //variables for third motor

	Cytron(uint8_t getdIrpin, uint8_t getpWmpin){			//constructor function takes direction and pwm pins for cytron
		dIrpin=getdIrpin;
		pWmpin=getpWmpin;
					//sets direction pin as output
		lAstpwm=0;
		step1=5;
		interval=10;
	}
	Cytron(uint8_t getdIrpin, uint8_t getpWmpin, uint8_t getdIrpin1, uint8_t getpWmpin1){     //constructor function takes direction and pwm pins for cytron
    	dIrpin=getdIrpin;
	    pWmpin=getpWmpin;
	    pWmpin1=getpWmpin1;
	    dIrpin1=getdIrpin1;
	    lAstpwm=0;
		lAstpwm1=0;
		step1=5;
		step2=5;
		interval=10;

  	}
  	Cytron(uint8_t getdIrpin, uint8_t getpWmpin, uint8_t getdIrpin1, uint8_t getpWmpin1, uint8_t getdIrpin2, uint8_t getpWmpin2){     //constructor function takes direction and pwm pins for cytron
	    pWmpin=getpWmpin;
	    dIrpin=getdIrpin;
	    pWmpin1=getpWmpin1;
	    dIrpin1=getdIrpin1;
	    pWmpin2=getpWmpin2;
	    dIrpin2=getdIrpin2;
	    lAstpwm=0;
		lAstpwm1=0;
		lAstpwm2=0;
		step1=5;
		step2=5;
		step3=5;
		interval=10;
  	}
  	Cytron(uint8_t getdIrpin, uint8_t getpWmpin, uint8_t getdIrpin1, uint8_t getpWmpin1, uint8_t getdIrpin2, uint8_t getpWmpin2, uint8_t getdIrpin3, uint8_t getpWmpin3){     //constructor function takes direction and pwm pins for cytron
	    pWmpin=getpWmpin;
	    dIrpin=getdIrpin;
	    pWmpin1=getpWmpin1;
	    dIrpin1=getdIrpin1;
	    pWmpin2=getpWmpin2;
	    dIrpin2=getdIrpin2;
	    pWmpin3=getpWmpin3;
	    dIrpin3=getdIrpin3;
	    lAstpwm=0;
		lAstpwm1=0;
		lAstpwm2=0;
		lAstpwm3=0;
		step1=5;
		step2=5;
		step3=5;
		step4=5;
		interval=10;
  	}

  	void direction(uint8_t dIrection){
  		pinMode(dIrpin,OUTPUT);
		digitalWrite(dIrpin,dIrection);
	}

	void direction(uint8_t dIrection, uint8_t dIrection1){
		pinMode(dIrpin,OUTPUT);     //sets direction pin as output
	    pinMode(dIrpin1,OUTPUT);
		digitalWrite(dIrpin,dIrection);
		digitalWrite(dIrpin1,dIrection1);
	}

	void direction(uint8_t dIrection, uint8_t dIrection1, uint8_t dIrection2){
		pinMode(dIrpin,OUTPUT);     //sets direction pin as output
	    pinMode(dIrpin1,OUTPUT);
	    pinMode(dIrpin2,OUTPUT);
		digitalWrite(dIrpin,dIrection);
		digitalWrite(dIrpin1,dIrection1);
		digitalWrite(dIrpin2,dIrection2);
	}

	void direction(uint8_t dIrection, uint8_t dIrection1, uint8_t dIrection2, uint8_t dIrection3){
		pinMode(dIrpin,OUTPUT);     //sets direction pin as output
	    pinMode(dIrpin1,OUTPUT);
	    pinMode(dIrpin2,OUTPUT);
	    pinMode(dIrpin3,OUTPUT);
		digitalWrite(dIrpin,dIrection);
		digitalWrite(dIrpin1,dIrection1);
		digitalWrite(dIrpin2,dIrection2);
		digitalWrite(dIrpin3,dIrection3);
	}

	void drive(uint8_t pWm){

		if(pWm>lAstpwm){		//accelerate

			for(lAstpwm=lAstpwm;lAstpwm<pWm;){		//increase the speed step by step
				lAstpwm+=step1;
				analogWrite(pWmpin,constrain(lAstpwm,0,pWm));
				delay(interval);
			}

		}

		else if(pWm<lAstpwm){				//decelerate

			for(lAstpwm=lAstpwm;lAstpwm>pWm;){		//decrease the speed step by step
				lAstpwm-=step1;
				analogWrite(pWmpin,constrain(lAstpwm,pWm,255));
				delay(interval);
			}
		}

		else{		//no change
			analogWrite(pWmpin,pWm);
		}
	}

	//TWO MOTORS
	void drive(uint8_t pWm, uint8_t pWm1){
		if(pWm>lAstpwm&&pWm1>lAstpwm1){		//accelerate

			for(lAstpwm=lAstpwm,lAstpwm1=lAstpwm1;lAstpwm<pWm&&lAstpwm1<pWm1;){		//increase the speed step by step
				if (pWm>lAstpwm){
					lAstpwm+=step1;
					analogWrite(pWmpin,constrain(lAstpwm,0,pWm));
				}
				if (pWm1>lAstpwm1){
					lAstpwm1+=step2;
					analogWrite(pWmpin1,constrain(lAstpwm1,0,pWm1));
				}
				delay(interval);
			}

		}

		else if(pWm<lAstpwm&&pWm1<lAstpwm1){				//decelerate

			for(lAstpwm=lAstpwm,lAstpwm1=lAstpwm1;lAstpwm>pWm&&lAstpwm1>pWm1;){		//decrease the speed step by step
				if (pWm<lAstpwm){
					lAstpwm-=step1;
					analogWrite(pWmpin,constrain(lAstpwm,pWm,255));
				}
				if (pWm1<lAstpwm1){
					lAstpwm1-=step2;
					analogWrite(pWmpin1,constrain(lAstpwm1,pWm1,255));
				}
				delay(interval);
			}
		}

		else{		//no change
			analogWrite(pWmpin,pWm);
			analogWrite(pWmpin1,pWm1);
		}
	}

	//THREE MOTORS
	void drive(uint8_t pWm, uint8_t pWm1, uint8_t pWm2)
	{
		while(pWm==lAstpwm&&pWm1==lAstpwm1&&pWm2=lAstpwm2)
		{
			
			if(pWm>lAstpwm)
			{lAstpwm+=step1;
	constrain(lAstpwm,0,pWm);
			}
			else if(pWm<lAstpwm)
	         {lAstpwm-=step1;
			constrain(lAstpwm,pWm,255);
			}
				if(pWm1>lAstpwm1)
				{lAstpwm1+=step2;
	constrain(lAstpwm,0,pWm);
					}
					else if(pWm1<lAstpwm1)
					{lAstpwm1-=step2;
			constrain(lAstpwm,pWm,255);
						}
						if(pWm2>lAstpwm2)
				{lAstpwm2+=step3;
	constrain(lAstpwm,0,pWm);
					}
					else if(pWm2<lAstpwm1)
					{lAstpwm2-=step3;
			constrain(lAstpwm,pWm,255);
						}				 
		analogWrite(pWmpin,lastpWm);
		analogWrite(pWmpin1,lastpWm1);
		analogWrite(pWmpin2,lastpWm2);
				delay(interval);
		}
		}		


	//FOUR MOTORS
	void drive(uint8_t pWm, uint8_t pWm1, uint8_t pWm2, uint8_t pWm3){

		if(pWm>lAstpwm&&pWm1>lAstpwm1&&pWm2>lAstpwm2&&pWm3>lAstpwm3){		//accelerate

			for(lAstpwm=lAstpwm,lAstpwm1=lAstpwm1,lAstpwm2=lAstpwm2,lAstpwm3=lAstpwm3;lAstpwm<pWm&&lAstpwm1<pWm1&&lAstpwm2<pWm2&&lAstpwm3<pWm3;){		//increase the speed step by step
				if (pWm>lAstpwm){
					lAstpwm+=step1;
					analogWrite(pWmpin,constrain(lAstpwm,0,pWm));
				}
				if (pWm1>lAstpwm1){
					lAstpwm1+=step2;
					analogWrite(pWmpin1,constrain(lAstpwm1,0,pWm1));
				}
				if (pWm2>lAstpwm2){
					lAstpwm2+=step3;
					analogWrite(pWmpin2,constrain(lAstpwm2,0,pWm2));
				}
				if (pWm3>lAstpwm3){
					lAstpwm3+=step4;
					analogWrite(pWmpin3,constrain(lAstpwm3,0,pWm3));
				}
				delay(interval);
			}

		}

		else if(pWm<lAstpwm&&pWm1<lAstpwm1&&pWm2<lAstpwm2&&pWm3<lAstpwm3){				//decelerate

			for(lAstpwm=lAstpwm,lAstpwm1=lAstpwm1,lAstpwm2=lAstpwm2,lAstpwm3=lAstpwm3;lAstpwm>pWm&&lAstpwm1>pWm1&&lAstpwm2>pWm2&&lAstpwm3>pWm3;){		//decrease the speed step by step
				if (pWm<lAstpwm){
					lAstpwm-=step1;
					analogWrite(pWmpin,constrain(lAstpwm,pWm,255));
				}
				if (pWm1<lAstpwm1){
					lAstpwm1-=step2;
					analogWrite(pWmpin1,constrain(lAstpwm1,pWm1,255));
				}
				if (pWm2<lAstpwm2){
					lAstpwm2-=step3;
					analogWrite(pWmpin2,constrain(lAstpwm2,pWm2,255));
				}
				if (pWm3<lAstpwm3){
					lAstpwm3-=step4;
					analogWrite(pWmpin3,constrain(lAstpwm3,pWm3,255));
				}
				delay(interval);
			}
		}

		else{		//no change
			analogWrite(pWmpin,pWm);
			analogWrite(pWmpin1,pWm1);
			analogWrite(pWmpin2,pWm2);
			analogWrite(pWmpin3,pWm3);
		}
	}

	void stop(int s)
	{
		switch(s)
		{
			case 1:
				analogWrite(pWmpin,0);
		    break;

		    case 2:
				analogWrite(pWmpin1,0);
		    break;

			case 3:
				analogWrite(pWmpin2,0);
		    break;
		}
	}


	void stop(short int s,short int a)
	{
		switch(s)
		{
			case 1:
					analogWrite(pWmpin,0);
		                   switch(a)
					   {case 2:
					    analogWrite(pWmpin1,0);
				       break;
				     case 3:
			         	analogWrite(pWmpin2,0);
				       break;
					    }
			              break;
			case 2:
					 analogWrite(pWmpin1,0);
					  switch(a)
					   {case 1:
					    analogWrite(pWmpin,0);
				       break;
				     case 3:
			         	analogWrite(pWmpin2,0);
				       break;
					    }
			              break;
			case 3:
		           analogWrite(pWmpin2,0);
				   switch(a)
				   {
				   	case 1:
				    	analogWrite(pWmpin,0);
			       	break;

			     	case 2:
		         		analogWrite(pWmpin1,0);
			       	break;
				    }
		 }
	}
};
