#include "Body.h"

Body::Body(const rapidjson::GenericValue<rapidjson::UTF8<> >**){
	
	InitialState init;
	desaparegut=false;
	
	
	
	//falta parsejar i actualitzar
	
	eCos=init;
	objectName="body";
	locationInObject="";

}

bool doesKillMatter(){
	
	if(eInicial==eFinal||desaparegut){
		return false;
	}
	
	if(eFinal==FinalState.FS_INTOXICAT){
		if(eInicial==InitialState.IS_ASFIXIA ||eInicial==InitialState.IS_ACONTUNDENT){
			return false;
		}else{
			return true;
		}
	}
	
	if(eFinal==FinalState.FS_ACONTUNDENT){
		if(eInicial==InitialState.IS_ASFIXIA ||eInicial==InitialState.IS_ACONTUNDENT){
			return false;
		}else{
			return true;
		}
	}
	
	if(eFinal==FinalState.FS_AFOC){
		if(eInicial==InitialState.IS_AFOC ||eInicial==InitialState.IS_ASFIXIA||eInicial==InitialState.IS_ACONTUNDENT){
			return false;
		}else{
			return true;
		}
	}
	
	if(eFinal==FinalState.FS_ABLANCA){
		if(eInicial==InitialState.IS_ABLANCA ||eInicial==InitialState.IS_ACONTUNDENT||eInicial==InitialState.IS_ASFIXIA){
			return false;
		}else{
			return true;
		}
	}
	
	if(eFinal==FinalState.FS_ASFIXIA){
		if(eInicial==InitialState.IS_ASFIXIA){
			return false;
		}else{
			return true;
		}
	}
	
	
	return true;
}

void doesBodyMatter(){

	if(!doesKillMatter()){
	
		if(eCos==BodyState.APUNYALAT_DISPARAT){
			return true;
		}
	
		if(eFinal==FinalState.FS_INTOXICAT){
			return (eCos!=BodyState.NORMAL||eCos!=BodyState.COLPEJAT);
		}
		
		if(eFinal==FinalState.FS_ACONTUNDENT){
			return eCos!=BodyState.COLPEJAT;
		}
		
		if(eFinal==FinalState.FS_AFOC){
			return eCos!=BodyState.DISPARAT;
		}
		
		if(eFinal==FinalState.FS_ABLANCA){
			return eCos!=BodyState.APUNYALAT;
		}
		
		if(eFinal==FinalState.FS_ASFIXIA){
			return eCos!=BodyState.NORMAL;
		}
	
	}
	
	return !desaparegut;

}

void assignarFinalState(){
	std::string estat=initstates.front();
	if(estat="normal"){
		eFinal=FinalState.FS_ASFIXIA;
	}else if(estat="chopped"){
		eFinal=FinalState.FS_ABLANCA;
	}else if(estat="stabbed"){
		eFinal=FinalState.FS_ABLANCA;
	}else if(estat="shot"){
		eFinal=FinalState.FS_AFOC;
	}else if(estat="stabbed-shot"){
		if(eInicial==FinalState.IS_ABLANCA){
			eFinal=FinalState.FS_ABLANCA;
		}else {
			eFinal=FinalState.FS_AFOC;
		}
	}else if(estat="hit"){
		eFinal=FinalState.FS_ACONTUNDENT;
	}else if(estat="poison"){
		eFinal=FinalState.FS_INTOXICAT;
	}
}

