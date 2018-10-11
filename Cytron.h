class Cytron
{ 
	public:
	uint8_t dIrpin, pWmpin, lastpWm=0, step=5, interval=10;	//variables for first motor
	uint8_t dIrpin1, pWmpin1, lastpWm1=0, step1=5, interval1=10; //variables for second motor
	uint8_t dIrpin2, pWmpin2, lastpWm2=0, step2=5, interval2=10; //variables for third motor

	Cytron(uint8_t getdIrpin, uint8_t getpWmpin){			//constructor function takes direction and pwm pins for cytron
		dIrpin=getdIrpin;
		pWmpin=getpWmpin;
		pinMode(dIrpin,OUTPUT);			//sets direction pin as output
	}
	Cytron(uint8_t getdIrpin, uint8_t getpWmpin, uint8_t gerdIrpin1, uint8_t getpWmpin1){     //constructor function takes direction and pwm pins for cytron
    	dIrpin=getdIrpin;
	    pWmpin=getpWmpin;
	    pWmpin1=getpWmpin1;
	    dIrpin1=getdIrpin1;
	    pinMode(dIrpin,OUTPUT);     //sets direction pin as output
	    pinMode(dIrpin1,OUTPUT);
  }
  	Cytron(uint8_t getdIrpin, uint8_t getpWmpin, uint8_t getdIrpin1, uint8_t getpWmpin1, uint8_t getdIrpin2, uint8_t getpWmpin2){     //constructor function takes direction and pwm pins for cytron
	    pWmpin=getpWmpin;
	    dIrpin=getdIrpin;
	    pWmpin1=getpWmpin1;
	    dIrpin1=getdIrpin1;
	    pWmpin2=getpWmpin2;
	    dIrpin2=getdIrpin2;
	    pinMode(dIrpin,OUTPUT);     //sets direction pin as output
	    pinMode(dIrpin1,OUTPUT);
	    pinMode(dIrpin2,OUTPUT);
  }
  	void direction(uint8_t dIrection){
		digitalWrite(dIrpin,dIrection);
	}
	
	void direction(uint8_t dIrection, uint8_t dIrection1){
		digitalWrite(dIrpin,dIrection);
		digitalWrite(dIrpin1,dIrection1);
	}

	void direction(uint8_t dIrection, uint8_t dIrection1, uint8_t dIrection2){
		digitalWrite(dIrpin,dIrection);
		digitalWrite(dIrpin1,dIrection1);
		digitalWrite(dIrpin2,dIrection2);
	}

	void drive(uint8_t pWm){
		
		if(pWm>lastpWm){		//accelerate

			for(lastpWm=lastpWm;lastpWm<pWm;){		//increase the speed step by step
				lastpWm+=step;
				analogWrite(pWmpin,constraint(lastpWm,0,pWm));
				delay(interval);		
			}
			
		}

		else if(pWm<lastpWm){				//decelerate

			for(lastpWm=lastpWm;lastpWm>pWm;){		//decrease the speed step by step
				lastpWm-=step;
				analogWrite(pWmpin,constraint(lastpWm,pWm,255));
				delay(interval);		
			}
		}

		else{		//no change
			analogWrite(pWmpin,pWm);
		}	
	}

	//TWO MOTORS
	void drive(uint8_t pWm, uint8_t pWm1){
		
		if(pWm>lastpWm||pWm1>lastpWm1){		//accelerate

			for(lastpWm=lastpWm,lastpWm1=lastpWm1;lastpWm<pWm||lastpWm1<pWm1;){		//increase the speed step by step
				if (pWm>lastpWm){
					lastpWm+=step;
					analogWrite(pWmpin,constraint(lastpWm,0,pWm));
				}
				if (pWm1>lastpWm1){
					lastpWm1+=step1;
					analogWrite(pWmpin1,constraint(lastpWm1,0,pWm1));
				}	
				delay(interval);		
			}
			
		}

		else if(pWm<lastpWm||pWm1<lastpWm1){				//decelerate

			for(lastpWm=lastpWm,lastpWm1=lastpWm1;lastpWm>pWm||lastpWm1>pWm1;){		//decrease the speed step by step
				if (pWm<lastpWm){
					lastpWm-=step;
					analogWrite(pWmpin,constraint(lastpWm,pWm,255));
				}
				if (pWm1<lastpWm1){
					lastpWm1-=step1;
					analogWrite(pWmpin1,constraint(lastpWm1,pWm1,255));
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
	void drive(uint8_t pWm, uint8_t pWm1, uint8_t pWm2){
		
		if(pWm>lastpWm||pWm1>lastpWm1||pWm2>lastpWm2){		//accelerate

			for(lastpWm=lastpWm,lastpWm1=lastpWm1,lastpWm2=lastpWm2;lastpWm<pWm||lastpWm1<pWm1||lastpWm2<pWm2;){		//increase the speed step by step
				if (pWm>lastpWm){
					lastpWm+=step;
					analogWrite(pWmpin,constraint(lastpWm,0,pWm));
				}
				if (pWm1>lastpWm1){
					lastpWm1+=step1;
					analogWrite(pWmpin1,constraint(lastpWm1,0,pWm1));
				}
				if (pWm2>lastpWm2){
					lastpWm2+=step2;
					analogWrite(pWmpin2,constraint(lastpWm2,0,pWm2));
				}	
				delay(interval);		
			}
			
		}

		else if(pWm<lastpWm||pWm1<lastpWm1){				//decelerate

			for(lastpWm=lastpWm,lastpWm1=lastpWm1;lastpWm>pWm||lastpWm1>pWm1;){		//decrease the speed step by step
				if (pWm<lastpWm){
					lastpWm-=step;
					analogWrite(pWmpin,constraint(lastpWm,pWm,255));
				}
				if (pWm1<lastpWm1){
					lastpWm1-=step1;
					analogWrite(pWmpin1,constraint(lastpWm1,pWm1,255));
				}
				if (pWm2<lastpWm2){
					lastpWm2-=step2;
					analogWrite(pWmpin2,constraint(lastpWm2,pWm2,255));
				}
				delay(interval);		
			}
		}

		else{		//no change
			analogWrite(pWmpin,pWm);
			analogWrite(pWmpin1,pWm1);
			analogWrite(pWmpin1,pWm2);
		}	
	}	
};