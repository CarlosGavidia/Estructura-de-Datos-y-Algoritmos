#ifndef ___PANTANO_H
#define ___PANTANO_H

class Pantano {
public:
	/** 
	Crea un pantano con una capacidad maxima y un volúmen 
	embalsado inicial.
	@param cmax Capacidad máxima del pantano
	@param vol Volumen inicial embalsado
	*/
	Pantano(float cmax, float vol); 
	/**
	  Permite consultar la capacidad máxima del pantano
	  @return capacidad máxima del pantano
	*/
	float cmax() const; 
	/**
	  Permite consultar el volumen embalsado en el pantano
	  @return volumen embalsado
	*/
	float vol() const; 
	/**
	Actualiza el volumen embalsado en el pantano
	@param vol Nuevo volumen embalsado
	*/
	void pon_vol(float vol); 
private:
	float _cmax; // Capacidad máxima
	float _vol;  // Volumen embalsado
};

#endif // !__PANTANO_H


