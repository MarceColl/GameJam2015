#ifndef JUDGE_H
#define JUDGE_H
#include "Object.h"
#include "Body.h"
#include "Jutge.h"


enum Veredicte[JUGADOR_HOMICIDI,INCRIMINA_HOMICIDI,SUICIDI,ACCIDENT,DESAPAREGUT];

class GJ2015;
class Judge{

public:

	Judge();
	
	int puntsHomicidiJo;
	int puntsHomicidiIncrim;
	int puntsSuicidi;
	int puntsAccident;
	int puntsFuga;
	
	bool incriminat;
	
	Veredicte veredicte;
	
	void evaluarCrim();
	

}

#endif