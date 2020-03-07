/*
  Cronos.h - Libreria para ejecutar codigo pasado x tiempo sin detener el flujo de ejecucion.
  Created by Roberto Perez Parro, 11 Diciembre 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "Cronos.h"

	Cronos::Cronos(unsigned int tiempo){
		 _Tiemp= tiempo;
	}

	boolean Cronos::Estado(){
		if (( _Crono+_Tiemp)<millis()) {
			_Crono=millis();
			return true;
	  	}
		else{
			return false;
		}
	}

	void Cronos::Reset(){
		_Crono=0;
	}
	
	void Cronos::Version(){
		Serial.print("Versión: ");
		Serial.print(NVer);
		Serial.print(".");
		Serial.println(NRev);
	}
