class L298n{
	public:
	uint8_t dIrpin1, dIrpin2, pWmpin,lastpWm=0,step=5,interval=10;	//
	
	Cytron(int getdIrpin1, getdIrpin2, int getpWmpin){			//constructor function takes direction and pwm pins for cytron
		dIrpin1=getdIrpin1;
		dIrpin2=getdIrpin2;
		pWmpin=getpWmpin;
		pinMode(dIrpin1,OUTPUT);			//sets direction pin as output
		pinMode(dIrpin2,OUTPUT);
	}
	
	void direction(bool dIrection){
		digitalWrite(dIrpin1,dIrection);
		digitalWrite(dIrpin2,~dIrection);
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
