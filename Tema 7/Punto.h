#ifndef _PUNTO_H
#define _PUNTO_H

class Punto {
public:
	Punto();
	Punto(float x, float y);
	float coordenadaX() const;
	float coordenadaY() const;
	bool operator==(const Punto& p) const;
private:
	float _x;
	float _y;
};

#endif