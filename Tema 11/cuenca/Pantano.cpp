#include "Pantano.h"

Pantano::Pantano(float cmax, float vol) : _cmax(cmax), _vol(vol) {}
float Pantano::cmax() const { return _cmax; }
float Pantano::vol() const { return _vol; }
void Pantano::pon_vol(float vol) { _vol = vol; }
