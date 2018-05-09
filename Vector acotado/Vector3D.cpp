/*! 
   \file Vector3D.cpp
   \brief Fichero que contiene el código de las funciones de la clase Vector3D
   \author   Carlos Luque Córdoba
   \date     2018-2-28
   \version  1.0
*/


// Ficheros de cabecera
#include <iostream>

// Para usar sqrt, acos
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

#include "Vector3D.hpp"

#define COTA_ERROR 1.0e-6 //!< Cota de error para la comparación números reales

// OBSERVADORES

double ed::Vector3D::modulo() const {
		double moduloDev;
		moduloDev=sqrt((get1()*get1())+(get2()*get2())+(get3()*get3()));
	#ifndef NDEBUG
		assert(std::abs(moduloDev-sqrt((get1()*get1())+(get2()*get2())+(get3()*get3())))<COTA_ERROR);
	#endif //NDEBUG
	return moduloDev;
}

double ed::Vector3D::angulo(ed::Vector3D const &v) const {
	#ifndef NDEBUG
		assert((modulo()*v.modulo())>0);
	#endif //NDEBUG

	double anguloDev;
	anguloDev=acos((dotProduct(v))/(modulo()*v.modulo()));
	
	#ifndef NDEBUG
		assert(std::abs(anguloDev-acos(((dotProduct(v))/(modulo()*v.modulo()))))<COTA_ERROR);
	#endif //NDEBUG
	return anguloDev;
}

double ed::Vector3D::alfa() const {
	#ifndef NDEBUG
		assert(modulo()>0);
	#endif //NDEBUG
	
	Vector3D v;
	v.set1(1);
	v.set2(0);
	v.set3(0);

	double anguloDev=angulo(v);
	#ifndef NDEBUG
		assert(std::abs(anguloDev-angulo(v))<COTA_ERROR);
	#endif //NDEBUG
	return anguloDev;
}

double ed::Vector3D::beta() const {
	#ifndef NDEBUG
		assert(modulo()>0);
	#endif //NDEBUG
	
	Vector3D v;
	v.set1(0);
	v.set2(1);
	v.set3(0);
	double anguloDev=angulo(v);
	
	#ifndef NDEBUG
		assert(std::abs(anguloDev-angulo(v))<COTA_ERROR);
	#endif //NDEBUG
	
	return anguloDev;	
}

double ed::Vector3D::gamma() const {
	#ifndef NDEBUG
		assert(modulo()>0);
	#endif //NDEBUG
	
	Vector3D v;
	v.set1(0);
	v.set2(0);
	v.set3(1);
	double anguloDev=angulo(v);
	#ifndef NDEBUG
		assert(std::abs(anguloDev-angulo(v))<COTA_ERROR);
	#endif //NDEBUG
	return anguloDev;
}

double ed::Vector3D::dotProduct(ed::Vector3D const &v) const {
	double productoDev;
	productoDev=((get1()*v.get1())+(get2()*v.get2())+(get3()*v.get3()));
	
	#ifndef NDEBUG
		assert(std::abs(productoDev-((get1()*v.get1())+(get2()*v.get2())+(get3()*v.get3())))<COTA_ERROR);
	#endif
	
	return productoDev;
}

ed::Vector3D ed::Vector3D::crossProduct(ed::Vector3D const &v) const {

	#ifndef NDEBUG
		assert(angulo(v)>0);
		assert(modulo()>0);
		assert(v.modulo()>0);
	#endif //NDEBUG

	double v1=v.get1();
	double v2=v.get2();
	double v3=v.get3();

	double u1=get1();
	double u2=get2();
	double u3=get3();

	ed::Vector3D productoDev;
	productoDev.set1((u2*v3)-(u3*v2));
	productoDev.set2(-(u1*v3)+(u3*v1));
	productoDev.set3((u1*v2)-(u2*v1));

	#ifndef NDEBUG
		assert(dotProduct(productoDev)==0);
		assert(v.dotProduct(productoDev)==0);
		assert(std::abs(productoDev.modulo()-modulo()*v.modulo()*sin(angulo(v)))<COTA_ERROR);
	#endif //NDEBUG
	
	return productoDev;

	
}

double ed::Vector3D::productoMixto(ed::Vector3D const &v, ed::Vector3D const &w) const {
	double prodMixDev=(dotProduct(v.crossProduct(w)));
	
	#ifndef NDEBUG
		assert(std::abs(prodMixDev-(dotProduct(v.crossProduct(w))))<COTA_ERROR);
	#endif //NDEBUG

	return prodMixDev;
}

////////////////////////////////////////////////////////////////

// MODIFICADORES

void ed::Vector3D::sumConst(double const k){
	double x=get1();
	double y=get2();
	double z=get3();

	set1(x+k);
	set2(y+k);
	set3(z+k);

	#ifndef NDEBUG
		assert(std::abs((get1()-(x+k)))<COTA_ERROR and std::abs((get2()-(y+k)))<COTA_ERROR and std::abs((get3()-(z+k)))<COTA_ERROR);
	#endif //NDEBUG
}

void ed::Vector3D::sumVect(ed::Vector3D const &v){
	double vx=v.get1();
	double vy=v.get2();
	double vz=v.get3();

	double ux=get1();
	double uy=get2();
	double uz=get3();

	set1(ux+vx);
	set2(uy+vy);
	set3(uz+vz);

	#ifndef NDEBUG
			assert(std::abs((get1()-(ux+vx)))<COTA_ERROR and std::abs((get2()-(uy+vy)))<COTA_ERROR and std::abs((get3()-(uz+vz)))<COTA_ERROR);
	#endif //NDEBUG
}

void ed::Vector3D::multConst(double const k){
	double x=get1();
	double y=get2();
	double z=get3();

	set1(x*k);
	set2(y*k);
	set3(z*k);

	#ifndef NDEBUG
		assert(std::abs((get1()-(x*k)))<COTA_ERROR and std::abs((get2()-(y*k)))<COTA_ERROR and std::abs((get3()-(z*k)))<COTA_ERROR);
	#endif //NDEBUG
}

void ed::Vector3D::multVect(ed::Vector3D const &v){
	double vx=v.get1();
	double vy=v.get2();
	double vz=v.get3();

	double ux=get1();
	double uy=get2();
	double uz=get3();

	set1(ux*vx);
	set2(uy*vy);
	set3(uz*vz);

	#ifndef NDEBUG
		assert(std::abs((get1()-(ux*vx)))<COTA_ERROR and std::abs((get2()-(uy*vy)))<COTA_ERROR and std::abs((get3()-(uz*vz)))<COTA_ERROR);
	#endif //NDEBUG
}


////////////////////////////////////////////////////////////////////////////////

// OPERADORES

bool ed::Vector3D:: operator == (Vector3D const &objeto) const{
	if(std::abs(get1()-objeto.get1())<COTA_ERROR && std::abs(get2()-objeto.get2())<COTA_ERROR && std::abs(get3()-objeto.get3())<COTA_ERROR){
		#ifndef NDEBUG
			assert(std::abs(get1()-objeto.get1())<COTA_ERROR && std::abs(get2()-objeto.get2())<COTA_ERROR && std::abs(get3()-objeto.get3())<COTA_ERROR);
		#endif
		
		return true;
	
	}else{
		#ifndef NDEBUG
			assert(std::abs(get1()-objeto.get1())>=COTA_ERROR || std::abs(get2()-objeto.get2())>=COTA_ERROR || std::abs(get3()-objeto.get3())>=COTA_ERROR);
		#endif //Postcondicion
	
		return false;
	}
}

ed::Vector3D ed::Vector3D::operator=(ed::Vector3D const &v){
	#ifndef NDEBUG
		assert(std::abs(get1()-v.get1())>=COTA_ERROR and std::abs(get2()-v.get2())>=COTA_ERROR and std::abs(get3()-v.get3())>=COTA_ERROR);
	#endif //NDEBUG

	set1(v.get1());
	set2(v.get2());
	set3(v.get3());
	
	#ifndef NDEBUG
		assert(std::abs(get1()-v.get1())<COTA_ERROR and std::abs(get2()-v.get2())<COTA_ERROR and std::abs(get3()-v.get3())<COTA_ERROR);
	#endif //NDEBUG
	
	return *this;
}

	
ed::Vector3D ed::Vector3D::operator+(ed::Vector3D const &v) const {
	ed::Vector3D vectorW;
	vectorW.set1(get1()+v.get1());
	vectorW.set2(get2()+v.get2());
	vectorW.set3(get3()+v.get3());

	#ifndef NDEBUG
		assert(std::abs(vectorW.get1()-(get1()+v.get1()))<COTA_ERROR and std::abs(vectorW.get2()-(get2()+v.get2()))<COTA_ERROR and std::abs(vectorW.get3()-(get3()+v.get3()))<COTA_ERROR);
	#endif

	return vectorW;
}

ed::Vector3D ed::Vector3D::operator+() const {
	ed::Vector3D vectorW;
	vectorW.set1(get1());
	vectorW.set2(get2());
	vectorW.set3(get3());

	#ifndef NDEBUG
			assert(std::abs(vectorW.get1()-get1())<COTA_ERROR and std::abs(vectorW.get2()-get2())<COTA_ERROR and std::abs(vectorW.get3()-get3())<COTA_ERROR);
	#endif

	return vectorW;
}

ed::Vector3D ed::Vector3D::operator-(ed::Vector3D const &v) const {
	ed::Vector3D vectorW;
	vectorW.set1(get1()-v.get1());
	vectorW.set2(get2()-v.get2());
	vectorW.set3(get3()-v.get3());

	#ifndef NDEBUG
		assert(std::abs(vectorW.get1()-(get1()-v.get1()))<COTA_ERROR and std::abs(vectorW.get2()-(get2()-v.get2()))<COTA_ERROR and std::abs(vectorW.get3()-(get3()-v.get3()))<COTA_ERROR);
	#endif

	return vectorW;
}

ed::Vector3D ed::Vector3D::operator-() const {

	ed::Vector3D vectorW;
	vectorW.set1(-get1());
	vectorW.set2(-get2());
	vectorW.set3(-get3());

	#ifndef NDEBUG
		assert(std::abs(vectorW.get1()-(-get1()))<COTA_ERROR and std::abs(vectorW.get2()-(-get2()))<COTA_ERROR and std::abs(vectorW.get3()-(-get3()))<COTA_ERROR);
	#endif

	return vectorW;
}

ed::Vector3D ed::Vector3D::operator*(const double k) const
{
	ed::Vector3D vectorResultado;

	vectorResultado.set1(get1()*k);
	vectorResultado.set2(get2()*k);
	vectorResultado.set3(get3()*k);
	
	#ifndef NDEBUG
		assert(std::abs((vectorResultado.get1())-(get1() * k))<COTA_ERROR and std::abs((vectorResultado.get2())-(get2() * k))<COTA_ERROR and std::abs((vectorResultado.get3())-(get3() * k))<COTA_ERROR);
	#endif

	return vectorResultado;
}

double ed::Vector3D::operator*(ed::Vector3D const &v) const {
	double result;
	result=dotProduct(v);
	
	#ifndef NDEBUG
		assert(std::abs(result-dotProduct(v))<COTA_ERROR);
	#endif
	
	return result;
}

ed::Vector3D ed::Vector3D::operator^(ed::Vector3D const &v) const {
	#ifndef NDEBUG
		assert(angulo(v)>0);
		assert(modulo()>0);
		assert(v.modulo()>0);
	#endif //NDEBUG

	ed::Vector3D result;
	result=crossProduct(v);
	
	#ifndef NDEBUG
		assert(dotProduct(result)==0);
		assert(v.dotProduct(result)==0);
		assert(std::abs(result.modulo()-modulo()*v.modulo()*sin(angulo(v)))<COTA_ERROR);
	#endif //NDEBUG

	return result;

}

ed::Vector3D ed::Vector3D::baricentro(Vector3D const &v, Vector3D const &w) const{
	double centerX=((get1()+v.get1()+w.get1())/3);
	double centerY=((get2()+v.get2()+w.get2())/3);
	double centerZ=((get3()+v.get3()+w.get3())/3);

	ed::Vector3D baricentroReal;
	baricentroReal.set1(centerX);
	baricentroReal.set2(centerY);
	baricentroReal.set3(centerZ);
	
	return baricentroReal;
}

//Funcion Puntos Alineados
bool ed::Vector3D::puntosAlineados(ed::Vector3D const &v, ed::Vector3D const &w) const {
double izquierda=((v.get1()-get1())/(w.get1()-v.get1()));
double centro=((v.get2()-get2())/(w.get2()-v.get2()));
double derecha=((v.get3()-get3())/(w.get3()-v.get3()));

	if(izquierda == centro && centro == derecha && izquierda == derecha)
		return true;
	else
		return false;
}

////////////////////////////////////////////////////////////////////////////////

// FUNCIONES DE LECTURA Y ESCRITURA

void ed::Vector3D::leerVector3D(){
	double x, y, z;
	
	std::cout<<"Introduzca la componente x del vector: ";
	std::cin>>x;
	set1(x);
	
	std::cout<<"\nIntroduzca la componente y del vector: ";
	std::cin>>y;
	set2(y);
	
	std::cout<<"\nIntroduzca la componente z del vector: ";
	std::cin>>z;
	set3(z);
}


void ed::Vector3D::escribirVector3D() const {
	std::cout<<"("<<get1()<<","<<get2()<<","<<get3()<<")"<<std::endl;
}
////////////////////////////////////////////////////////////////////////////////


// Se incluyen los operadores sobrecargados dentro del espacio de nombres de ed

namespace ed{


// Producto "por un" escalar (prefijo): k * v
ed::Vector3D &operator*(double k, ed::Vector3D const &objeto)
{
	ed::Vector3D *vectorResultado = new ed::Vector3D();

	vectorResultado->set1(k*objeto.get1());
	vectorResultado->set2(k*objeto.get2());
	vectorResultado->set3(k*objeto.get3());
	
	#ifndef NDEBUG
		assert(std::abs(vectorResultado->get1()-(objeto.get1() * k))<COTA_ERROR and std::abs(vectorResultado->get2()-(objeto.get2() * k))<COTA_ERROR and std::abs(vectorResultado->get3()-(objeto.get3() * k))<COTA_ERROR);
	#endif

	return *vectorResultado;
}


// Sobrecarga del operador de salida
// Se escriben por pantalla las coordenadas del vector 3D  de la forma (v1, v2, v3)
ostream &operator<<(ostream &stream, ed::Vector3D const &objeto)
{
	std::cout << "(";
 	stream << objeto.get1();
	stream << ", ";
	stream << objeto.get2();
	std::cout << ",";
	stream << objeto.get3();
	std::cout << ")";

	return stream;
}

// Sobrecarga del operador de entrada
istream &operator>>(istream &stream, ed::Vector3D &objeto)
{
	double numero;

	stream >> numero;
	objeto.set1(numero);

	stream >> numero;
	objeto.set2(numero);

	stream >> numero;
	objeto.set3(numero);

	return stream;
} 

} // Fin del espacio de nombres ed
