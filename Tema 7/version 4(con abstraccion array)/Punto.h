#ifndef _PUNTO_H
#define _PUNTO_H

typedef float Punto[2];

void iniciaPunto(Punto& punto, float x, float y); 

void actualizaPunto(Punto& punto, const Punto& p); 

float coordenadaX(const Punto& punto); 

float coordenadaY(const Punto& punto); 

#endif