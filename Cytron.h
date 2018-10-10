class Cytron
{ 
	public:
	uint8_t dIrpin, pWmpin,lastpWm=0,lastpWm1=0,step=5,interval=10,pWmpin1,dIrpin1;	//
	
	Cytron(int getdIrpin, int getpWmpin){			//constructor function takes direction and pwm pins for cytron
		dIrpin=getdIrpin;
		pWmpin=getpWmpin;
		pinMode(dIrpin,OUTPUT);			//sets direction pin as output
	}
	Cytron(int getdIrpin, int getpWmpin,int gerdIrpin1,int getpWmpin1){     //constructor function takes direction and pwm pins for cytron
    dIrpin=getdIrpin;
    pWmpin=getpWmpin;
    pWmpin1=getpWmpin1;
    dIrpin=gerdIrpin1;
    pinMode(dIrpin,OUTPUT);     //sets direction pin as output
  }
	void direction(int dIrection){
		digitalWrite(dIrpin,dIrection);
	}
	  void direction(int dIrection){
    digitalWrite(dIrpin,dIrection);
  }

	void drive(uint8_t pWm){
		
		if(pWm>lastpWm){		//accelerate

			for(lastpWm=lastpWm;lastpWm<pWm,){		//increase the speed step by step
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

	void drive(uint8_t pWm,uint8_t pWm1){
    
    if(pWm>lastpWm){    //accelerate

      for(lastpWm=lastpWm,lastpWm1=lastpWm1;lastpWm<pWm||lastpWm1<pWm1;){   //increase the sp,eed step by step
        lastpWm+=step;
        lastpWm1+=step;
        analogWrite(pWmpin,constrain(lastpWm,-1,pWm));
        analogWrite(pWmpin1,constrain(lastpWm1,-1,pWm1));
        delay(interval);
            
      }
      Serial.println(constrain(lastpWm,-1,pWm));
      
    }

    else if((pWm<lastpWm)&&(pWm1<lastpWm1)){       //decelerate

      for(lastpWm=lastpWm,lastpWm1=lastpWm1;lastpWm<pWm||lastpWm1<pWm1;){   //decrease the speed step by step
        lastpWm-=step;
        lastpWm1-=step;
        analogWrite(pWmpin,constrain(lastpWm,pWm,255));
         analogWrite(pWmpin1,constrain(lastpWm1,pWm1,255));
        delay(interval);    
    
      }
         Serial.println(constrain(lastpWm,pWm,255)); 
    }
    
    

    else{   //no change
      analogWrite(pWmpin,pWm);
	    analogWrite(pWmpin1,pWm1);
    }
    
  }
};



























