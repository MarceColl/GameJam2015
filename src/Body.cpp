#include "Body.h"

Body::Body(const rapidjson::GenericValue<rapidjson::UTF8<> >* d) 
: Object (d) {
	desaparegut = false;
	eCos = NORMAL;
}

bool Body::doesKillMatter() {
	
	if((int)eInicial == (int)eFinal || desaparegut){
		return false;
	}
	
	if(eFinal == FS_INTOXICAT){
		if(eInicial == IS_ASFIXIA || eInicial == IS_ACONTUNDENT){
			return false;
		}else{
			return true;
		}
	}
	
	if(eFinal == FS_ACONTUNDENT){
		if(eInicial == IS_ASFIXIA || eInicial == IS_ACONTUNDENT){
			return false;
		}else{
			return true;
		}
	}
	
	if(eFinal == FS_AFOC){
		if(eInicial == IS_AFOC || eInicial == IS_ASFIXIA || eInicial == IS_ACONTUNDENT){
			return false;
		}else{
			return true;
		}
	}
	
	if(eFinal == FS_ABLANCA){
		if(eInicial == IS_ABLANCA || eInicial == IS_ACONTUNDENT || eInicial == IS_ASFIXIA){
			return false;
		}else{
			return true;
		}
	}
	
	if(eFinal == FS_ASFIXIA){
		if(eInicial == IS_ASFIXIA){
			return false;
		}else{
			return true;
		}
	}
	
	
	return true;
}

bool Body::doesBodyMatter() {

	if(!doesKillMatter()){
		if(eCos == APUNYALAT_DISPARAT){
			return true;
		}
	
		if(eFinal == FS_INTOXICAT){
			return (eCos != NORMAL || eCos != COLPEJAT);
		}
		
		if(eFinal == FS_ACONTUNDENT){
			return eCos != COLPEJAT;
		}
		
		if(eFinal == FS_AFOC){
			return eCos != DISPARAT;
		}
		
		if(eFinal == FS_ABLANCA){
			return eCos != APUNYALAT;
		}
		
		if(eFinal == FS_ASFIXIA){
			return eCos != NORMAL;
		}
	}
	
	return !desaparegut;

}

void Body::assignarFinalState() {
	std::string estat = initStates[0];

	if(estat == "normal") {
		eFinal = FS_ASFIXIA;
	} else if(estat == "chopped") {
		eFinal = FS_ABLANCA;
	} else if(estat == "stabbed") {
		eFinal = FS_ABLANCA;
	} else if(estat == "shot") {
		eFinal = FS_AFOC;
	} else if(estat == "stabbed-shot") {
		if(eInicial == IS_ABLANCA) {
			eFinal = FS_ABLANCA;
		} else {
			eFinal = FS_AFOC;
		}
	} else if(estat == "hit") {
		eFinal = FS_ACONTUNDENT;
	} else if(estat == "poison") {
		eFinal = FS_INTOXICAT;
	}
}

