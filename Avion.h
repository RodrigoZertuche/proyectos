#ifndef Avion_h
#define Avion_h

class Avion {
private:
  string id;
  int capacidad;
  string aerolinea;
public:
  Avion();
  Avion(string id, int capacidad, string aerolinea);
  void setId(string id);
  void setCapacidad(int capacidad);
  void setAerolinea(string aerolinea);
  string getId();
  int getCapacidad();
  string getAerolinea();
};

Avion::Avion() {
  id = "1";
  capacidad = 100;
  aerolinea = "Aeromexico";
}

Avion::Avion(string id, int capacidad, string aerolinea) {
  this->id = id;
  this->capacidad = capacidad;
  this->aerolinea = aerolinea;
}

void Avion::setId(string id) {
  this->id = id;
}

void Avion::setCapacidad(int capacidad) {
  this->capacidad = capacidad;
}

void Avion::setAerolinea(string aerolinea) {
  this->aerolinea = aerolinea;
}

string Avion::getId() {
  return id;
}

int Avion::getCapacidad() {
  return capacidad;
}

string Avion::getAerolinea() {
  return aerolinea;
}

#endif
