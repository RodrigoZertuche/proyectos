#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

#include"Avion.h"
#include"Vuelo.h"
#include"Fecha.h"

int reng = 0;

Fecha FechaHora(string fecha_str, string hora_str) {
  int ano,mes,dia,hora,minuto;
  ano = stoi(fecha_str.substr(0,4));
  mes = stoi(fecha_str.substr(5,7));
  dia = stoi(fecha_str.substr(8,10));
  hora = stoi(hora_str.substr(0,2));
  minuto = stoi(hora_str.substr(3,5));
  Fecha f(ano,mes,dia,hora,minuto);
  return f;
}

int CuentaFechas(Vuelo vuelos[]){
  Fecha fecha1;
  int cuenta = 0;
  for (int i = 0; i < reng; i++){
    if(!(vuelos[i].getFecha().getAnio() == fecha1.getAnio() && vuelos[i].getFecha().getMes() == fecha1.getMes() && vuelos[i].getFecha().getDia() == fecha1.getDia())){
      fecha1 = vuelos[i].getFecha();
      cuenta++;
    }
  }
  return cuenta;
}

void FechasTotales(Vuelo vuelos[],Fecha fechas[]){
  Fecha fecha1;
  int dia = 0;
  for (int i = 0; i < reng; i++){
    if(!(vuelos[i].getFecha().getAnio() == fecha1.getAnio() && vuelos[i].getFecha().getMes() == fecha1.getMes() && vuelos[i].getFecha().getDia() == fecha1.getDia())){
      fecha1 = vuelos[i].getFecha();
      fechas[dia] = fecha1;
      dia++;
    }
  }
}

int HoraSaturada(Fecha v, Vuelo vuelos[]) {
  int anio = v.getAnio();
  int mes = v.getMes();
  int dia = v.getDia();


  int horas[24];
  for(int i = 0; i < 24; i++) {
    horas[i] = 0;
  }

  int i = 0;

  while(!(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia)) {
    i++;
  }

  while(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia) {
    horas[vuelos[i].getFecha().getHora()] += 1;
    i++;
  }

  int mayor = 0;
  int iMayor = 0;
  for(int i = 0; i < 24; i++) {
    if(mayor < horas[i]) {
      mayor = horas[i];
      iMayor = i;
    }
  }
  return iMayor;
}

int CuentaEntrasale(string entrasale, Vuelo vuelos[]){
  int cuenta = 0;
  for (int i = 0; i < reng; i++) {
    if(vuelos[i].getEntrasale() == entrasale) {
      cuenta++;
    }
  }
  return cuenta;
}

void EntrasaleTotales(string entrasale, Vuelo vuelos[], Vuelo vuelosEntrasale[]){
  int cuenta = 0;
  for (int i = 0; i < reng; i++){
    if(vuelos[i].getEntrasale() == entrasale) {
      vuelosEntrasale[cuenta] = vuelos[i];
      cuenta++;
    }
  }
}

void PromedioPorHora(int total, int fechas, Vuelo vuelos[], float horas[]) {
  for(int i = 0; i < 24; i++) {
    horas[i] = 0;
  }

  for(int i = 0; i < total; i++) {
    horas[vuelos[i].getFecha().getHora()] += 1;
  }

  for(int i = 0; i < 24; i++) {
    horas[i] = horas[i]/fechas;
  }
}

void ContarAerolineas(vector<string> &aerolineas, Vuelo vuelos[]) {
  bool check;
  for(int i = 0; i < reng; i++)
  {
    check = false;
    for(int j = 0; j < aerolineas.size(); j++) {
      if(aerolineas[j] == vuelos[i].getAvion().getAerolinea()) {
        check = true;
      }
    }
    if(!check) {
      aerolineas.push_back(vuelos[i].getAvion().getAerolinea());
    }
  }
}

int CuentaPasajeros(Fecha v, Vuelo vuelos[]) {
  int suma = 0;
  int anio = v.getAnio();
  int mes = v.getMes();
  int dia = v.getDia();

  int i = 0;
  while(!(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia)) {
    i++;
  }

  while(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia) {
    suma += vuelos[i].getPasajeros();
    i++;
  }
  return suma;
}

float PorcentajeCapacidadUtilizada(Fecha v, Vuelo vuelos[]) {
  float sumaPasa = 0;
  float sumaCapa = 0;
  float total = 0;
  int anio = v.getAnio();
  int mes = v.getMes();
  int dia = v.getDia();

  int i = 0;
  while(!(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia)) {
    i++;
  }

  while(vuelos[i].getFecha().getAnio() == anio && vuelos[i].getFecha().getMes() == mes && vuelos[i].getFecha().getDia() == dia) {
    sumaPasa += vuelos[i].getPasajeros();
    sumaCapa += vuelos[i].getAvion().getCapacidad();
    //cout << vuelos[i].getPasajeros() << "/" << vuelos[i].getAvion().getCapacidad() << endl;
    i++;
  }
  total = sumaPasa/sumaCapa;
  return total*100;
}

int main() {
  string datos[9];
  ifstream archivo;

  archivo.open("datos_vuelos.txt");

  while( archivo >> datos[0] >> datos[1] >> datos[2] >> datos[3] >> datos[4] >> datos[5] >> datos[6] >> datos[7] >> datos[8] ) {
    reng++;
  }

  archivo.close();


  Vuelo vuelos[reng];
  int i = 0;
  archivo.open("datos_vuelos.txt");

  while ( archivo >> datos[0] >> datos[1] >> datos[2] >> datos[3] >> datos[4] >> datos[5] >> datos[6] >> datos[7] >> datos[8] ) {
    Fecha fecha_temp;
    fecha_temp = FechaHora(datos[0], datos[1]);
    vuelos[i] = Vuelo(datos[2], stoi(datos[7]), Avion(datos[6], stoi(datos[8]), datos[4]), datos[3], fecha_temp);
    i++;
  }

  archivo.close();

  //Pregunta 1
  Fecha fechas[CuentaFechas(vuelos)];
  FechasTotales(vuelos, fechas);
  for(int i = 0; i < CuentaFechas(vuelos); i++) {
    cout << "Hora con la mayor cantidad de vuelos en " << fechas[i].getDia() << "/" << fechas[i].getMes() << "/"  << fechas[i].getAnio() << " es " << HoraSaturada(fechas[i], vuelos) << endl;
  }

  cout << endl;
  //Pregunta 2 y 3
  int entra, sale;
  entra = CuentaEntrasale("A", vuelos);
  sale = CuentaEntrasale("S", vuelos);

  Vuelo vuelosEntra[entra];
  EntrasaleTotales("A", vuelos, vuelosEntra);
  float horasEntra[24];
  PromedioPorHora(entra, CuentaFechas(vuelos), vuelosEntra, horasEntra);

  Vuelo vuelosSale[sale];
  EntrasaleTotales("S", vuelos, vuelosSale);
  float horasSale[24];
  PromedioPorHora(sale, CuentaFechas(vuelos), vuelosSale, horasSale);

  for(int i = 0; i < 24; i++) {
    cout << "Hora " << i << " - " << horasEntra[i] << " llegadas y " << horasSale[i] << " salidas promedio." << endl;
  }

  cout << endl;
  //Pregunta 4
  vector<string> aerolineas;
  ContarAerolineas(aerolineas, vuelos);
  sort(aerolineas.begin(), aerolineas.end());
  int cantidadAeroEntra[aerolineas.size()];
  for(int i = 0; i < aerolineas.size(); i++) {
    cantidadAeroEntra[i] = 0;
  }

  int cantidadAeroSale[aerolineas.size()];
  for(int i = 0; i < aerolineas.size(); i++) {
    cantidadAeroSale[i] = 0;
  }

  for(int i = 0; i < aerolineas.size(); i++) {
    for(int j = 0; j < entra; j++) {
      if(aerolineas[i] == vuelosEntra[j].getAvion().getAerolinea()) {
        cantidadAeroEntra[i] += 1;
      }
    }
  }

  for(int i = 0; i < aerolineas.size(); i++) {
    for(int j = 0; j < sale; j++) {
      if(aerolineas[i] == vuelosSale[j].getAvion().getAerolinea()) {
        cantidadAeroSale[i] += 1;
      }
    }
  }

  for(int j = 0; j < aerolineas.size(); j++) {
    cout << "Aerolinea " << aerolineas[j] << " - " << cantidadAeroEntra[j] << " llegadas y " << cantidadAeroSale[j] << " salidas." << endl;
  }

  cout << endl;
  //Pregunta 5
  for(int i = 0; i < CuentaFechas(vuelos); i++) {
    cout << "El numero de pasajeros atendidos en " << fechas[i].getDia() << "/" << fechas[i].getMes() << "/"  << fechas[i].getAnio() << " es " << CuentaPasajeros(fechas[i], vuelos) << endl;
  }

  cout << endl;
  //Pregunta 6
  for(int i = 0; i < CuentaFechas(vuelos); i++) {
    cout << "El porcentaje promedio de capacidad utilizada en " << fechas[i].getDia() << "/" << fechas[i].getMes() << "/"  << fechas[i].getAnio() << " es " << PorcentajeCapacidadUtilizada(fechas[i], vuelos) << "%" << endl;
  }

  return 0;
}
