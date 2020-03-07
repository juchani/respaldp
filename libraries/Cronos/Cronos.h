/*
  Cronos.h - Libreria para ejecutar codigo pasado x tiempo sin detener el flujo de ejecucion.
  Created by Roberto Perez Parro, 11 Diciembre 2013.
  Released into the public domain.
*/

#ifndef Cronos_h
#define Cronos_h
#include "Arduino.h"
class Cronos{

public:
	Cronos(unsigned int tiempo);
	boolean Estado();
	void Reset();
	void Version();

private:
	unsigned long _Crono=0;
	unsigned int _Tiemp=0;
	int NVer=1;
	int NRev=1;

};

#endif