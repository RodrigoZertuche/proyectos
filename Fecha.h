#ifndef Fecha_h
#define Fecha_h

class Fecha {
private:
  int anio;
  int mes;
  int dia;
  int hora;
  int minutos;
public:
  Fecha();
  Fecha(int anio, int mes, int dia, int hora, int minutos);
  void setAnio(int anio);
  void setMes(int mes);
  void setDia(int dia);
  void setHora(int hora);
  void setMinutos(int minutos);
  int getAnio();
  int getMes();
  int getDia();
  int getHora();
  int getMinutos();
};

Fecha::Fecha() {
  anio = 2000;
  mes = 12;
  dia = 1;
  hora = 00;
  minutos = 00;
}

Fecha::Fecha(int anio, int mes, int dia, int hora, int minutos) {
  this->anio = anio;
  this->mes = mes;
  this->dia = dia;
  this->hora = hora;
  this->minutos = minutos;
}

void Fecha::setAnio(int anio) {
  this->anio = anio;
}

void Fecha::setMes(int mes) {
  this->mes = mes;
}

void Fecha::setDia(int dia) {
  this->dia = dia;
}

void Fecha::setHora(int hora) {
  this->hora = hora;
}

void Fecha::setMinutos(int minutos) {
  this->minutos = minutos;
}

int Fecha::getAnio() {
  return anio;
}

int Fecha::getMes() {
  return mes;
}

int Fecha::getDia() {
  return dia;
}

int Fecha::getHora() {
  return hora;
}

int Fecha::getMinutos() {
  return minutos;
}

#endif
