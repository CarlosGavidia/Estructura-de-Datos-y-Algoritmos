#ifndef ___PANTANO_H
#define ___PANTANO_H

class Pantano {
public:
	/** 
	Crea un pantano con una capacidad maxima y un vol�men 
	embalsado inicial.
	@param cmax Capacidad m�xima del pantano
	@param vol Volumen inicial embalsado
	*/
	Pantano(float cmax, float vol); 
	/**
	  Permite consultar la capacidad m�xima del pantano
	  @return capacidad m�xima del pantano
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
	float _cmax; // Capacidad m�xima
	float _vol;  // Volumen embalsado
};

#endif // !__PANTANO_H


