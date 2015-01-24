#ifndef BODY_H
#define BODY_H
//#include "utils.hpp"
#include "Object.h"
#include <vector>
#include <map>

enum InitialState {IS_ASFIXIA,IS_ABLANCA,IS_AFOC,IS_ACONTUNDENT};

enum FinalState {FS_ASFIXIA,FS_ABLANCA,FS_AFOC,FS_ACONTUNDENT,FS_INTOXICAT,FS_DESAPAREGUT};

enum BodyState {NORMAL,APUNYALAT,DISPARAT,COLPEJAT,APUNYALAT_DISPARAT,ESQUARTERAT}

class Boddy : Object {

	InitialState eInicial;
	
	FinalState eFinal;
	
	BodyState eCos;
	
	Body(InitialState init);
	
	bool doesKillMatter();
	
	bool doesBodyMatter();

}
#endif