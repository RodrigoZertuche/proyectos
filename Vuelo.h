#ifndef Vuelo_h
#define Vuelo_h

#include "Avion.h"
#include "Fecha.h"

class Vuelo {
private:
  string numero;
  int pasajeros;
  Avion avion;
  string entrasale;
  Fecha fecha;
public:
  Vuelo();
  Vuelo(string numero, int pasajeros, Avion avion, string entrasale, Fecha fecha);
  void setNumero(string numero);
  void setPasajeros(int pasajeros);
  void setAvion(Avion avion);
  void setEntrasale(string entrasale);
  void setFecha(Fecha fecha);
  string getNumero();
  int getPasajeros();
  Avion getAvion();
  string getEntrasale();
  Fecha getFecha();
};

Vuelo::Vuelo() {
  numero = "0";
  pasajeros = 0;
  avion = Avion();
  entrasale = "a";
  fecha = Fecha();
}

Vuelo::Vuelo(string numero, int pasajeros, Avion avion, string entrasale, Fecha fecha) {
  this->numero = numero;
  this->pasajeros = pasajeros;
  this->avion = avion;
  this->entrasale = entrasale;
  this->fecha = fecha;
}

void Vuelo::setNumero(string numero) {
  this->numero = numero;
}

void Vuelo::setPasajeros(int pasajeros) {
  this->pasajeros = pasajeros;
}

void Vuelo::setAvion(Avion avion) {
  this->avion = avion;
}

void Vuelo::setEntrasale(string entrasale) {
  this->entrasale = entrasale;
}

void Vuelo::setFecha(Fecha fecha) {
  this->fecha = fecha;
}

string Vuelo::getNumero() {
  return numero;
}

int Vuelo::getPasajeros() {
  return pasajeros;
}

Avion Vuelo::getAvion() {
  return avion;
}

string Vuelo::getEntrasale() {
  return entrasale;
}

Fecha Vuelo::getFecha() {
  return fecha;
}

#endif
