#include "Judge.h"

Judge::Judge(Body b){
	puntsHomicidiJo=0;
	puntsHomicidiIncrim=0;
	puntsSuicidi=0;
	puntsAccident=0;
	puntsFuga=0;
	puntsIncriminar=0;
	body=b;
}

void Judge::evaluarCrim(){

	std::list<Object*> objects;
	
	Body* body;
	
	bool onBody;
	bool onCharacter;
	
	int puntsHomicidi=0;
	
	for (std::list<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
		
		Objecte* item=it*;
		
		//evaluar objecte
		if(it->objectName!="body"){
			
			
			
		
		//onBody=GJ2015.isObjectOnBody(object*)
		//onCharacter=GJ2015.isObjectOnCharacter(object*)
		
		
		
			int punts [6] = item->evaluarObjecte(onBody,onCharacter);//HOMICIDI SUICIDI ACCIDENT FUGA INCRIMINAR
			
			puntsHomicidiJo=puntsHomicidiJo+punts[0];
			puntsHomicidiIncrim=puntsHomicidiIncrim+punts[0];
			if(puntsHomicidiIncrim<puntsHomicidiJo){
				puntsHomicidi=puntsHomicidiJo;
				incriminat=false;
			}else{
				incriminat=true;			
			}
			puntsSuicidi=puntsSuicidi+punts[2];
			puntsAccident=puntsAccident+punts[3];
			puntsFuga=puntsFuga+punts[4];
			
			puntsIncriminar=puntsIncriminar+punts[5];
		
		
		}
		
	}
	
	//Un cop aplicats els punts d'objecte veredicte
	
	if(desaparegut>0){
        if(puntsFuga>0){

            cout<<"DESAPAREGUT"<<endl;

		}else{
            if(incriminat){
            cout<<"HAS INCRIMINAT"<<endl;
            }else{
            cout<<"CULPABLE"<<endl;
            }
		}
	}else{
        if((puntsAccident+puntsSuicidi)>puntsHomicidi){
            if(puntsAccident>puntsSuicidi){
                cout<<"ACCIDENT"<<endl;
            }else{
                cout<<"SUICIDI"<<endl;
            }
        }else{
            if(incrimina>0){
            cout<<"HAS INCRIMINAT"<<endl;
            }else{
            cout<<"CULPABLE"<<endl;
            }
        }
	}
	
	

}

