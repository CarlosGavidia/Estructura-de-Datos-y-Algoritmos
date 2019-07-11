#ifndef _PUNTO_H
#define _PUNTO_H

typedef struct {
	float x;
	float y;
} Punto;

void iniciaPunto(Punto& punto, float x, float y); 

void actualizaPunto(Punto& punto, const Punto& p); 

float coordenadaX(const Punto& punto); 

float coordenadaY(const Punto& punto); 

#endif