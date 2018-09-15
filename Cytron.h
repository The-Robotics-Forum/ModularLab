class Cytron
{ 
	public:
	uint8_t dIrpin, pWmpin,lastpWm=0,step=5,interval=10;	//
	
	Cytron(int getdIrpin, int getpWmpin){			//constructor function takes direction and pwm pins for cytron
		dIrpin=getdIrpin;
		pWmpin=getpWmpin;
		pinMode(dIrpin,OUTPUT);			//sets direction pin as output
	}
	
	void direction(int dIrection){
		digitalWrite(dIrpin,dIrection);
	}

	void drive(uint8_t pWm){
		
		if(pWm>lastpWm){		//accelerate

			for(lastpWm=lastpWm;lastpWm<pWm,lastpWm+=step){		//increase the speed step by step
				
				analogWrite(pWmpin,constraint(lastpWm,0,pWm));
				delay(interval);		
			}
			
		}

		else if(pWm<lastpWm){				//decelerate

			for(lastpWm=lastpWm;lastpWm>pWm,lastpWm-=step){		//decrease the speed step by step
				
				analogWrite(pWmpin,constraint(lastpWm,pWm,255));
				delay(interval);		
			}
		}

		else{		//no change
			analogWrite(pWmpin,pWm);
		}
		
	}
}
