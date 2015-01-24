#include "Judge.h"

Judge::Judge(Body b){
	puntsHomicidiJo=0;
	puntsHomicidiIncrim=0;
	puntsSuicidi=0;
	puntsAccident=0;
	puntsFuga=0;
	body=b;
}

void Judge::evaluarCrim(){

	std::list<Object*> objects;
	
	Body* body;
	
	bool onCorpse;
	bool onCharacter;
	
	int puntsHomicidi=0;
	
	for (std::list<Object*>::iterator it = objects.begin(); it != objects.end(); ++it){
		
		Objecte* item=it*;
		
		//evaluar objecte
		
		//onCorpse=GJ2015.isObjectOnBody(object*)
		//onCharacter=GJ2015.isObjectOnCharacter(object*)
		
		if(it->objectName=="body"){
			desaparegut=onCharacter;
		}
		
		GameEvaler punts = item->evaluarObjecte(onCorpse,onCharacter);//HOMICIDI SUICIDI ACCIDENT FUGA INCRIMINAR
		
		puntsHomicidiJo=puntsHomicidiJo+punts.puntsHomicidiJo;
		puntsHomicidiIncrim=puntsHomicidiIncrim+punts.puntsHomicidiIncrim;
		if(puntsHomicidiIncrim<puntsHomicidiJo){
			puntsHomicidi=puntsHomicidiJo;
			incriminat=false;
		}else{
			puntsHomicidi=puntsHomicidiIncrim;
			incriminat=true;			
		}
		puntsSuicidi=puntsSuicidi+punts.puntsSuicidi;
		puntsAccident=puntsAccident+punts.puntsAccident;
		puntsFuga=puntsFuga+punts.puntsFuga;
		
		puntsIncriminar=puntsIncriminar+punts.puntsIncriminar;
		
	}
	
	//Un cop aplicats els punts d'objecte veredicte
	
	if(desaparegut>0){
        if(puntsFuga>0){
			veredicte=Veredicte.DESAPAREGUT
            cout<<"DESAPAREGUT"<<endl;

		}else{
            if(incriminat){
				veredicte=Veredicte.INCRIMINA_HOMICIDI;
                cout<<"INCRIMINA_HOMICIDI"<<endl;
            }else{
				veredicte=Veredicte.JUGADOR_HOMICIDI;
                cout<<"JUGADOR_HOMICIDI"<<endl;
            }
		}
	}else{
        if((puntsAccident+puntsSuicidi)>puntsHomicidi){
            if(puntsAccident>puntsSuicidi){
				veredicte=Veredicte.ACCIDENT;
                cout<<"ACCIDENT"<<endl;
            }else{
				veredicte=Veredicte.SUICIDI;
                cout<<"SUICIDI"<<endl;
            }
        }else{
            if(incrimina>0){
				veredicte=Veredicte.INCRIMINA_HOMICIDI;
				cout<<"INCRIMINA_HOMICIDI"<<endl;
            }else{
				veredicte=Veredicte.JUGADOR_HOMICIDI;
				cout<<"JUGADOR_HOMICIDI"<<endl;
            }
        }
	}
	
	

}

