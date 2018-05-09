
/*!
  \file   funcionesAuxiliares.hpp
  \brief  Funciones auxiliares para el programa principal de la práctica 1
  \author 
  \date  
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "Vector3D.hpp"


namespace ed
{
	/*! 
		\brief   Muestra el menú del programa principal 
		\return  Devuelve el número de opción elegido
	*/
	int menu();

	//! \name Funciones Auxiliares

	/*!		\fn 	   void leerVectores(Vector3D &u, Vector3D &v, Vector3D &w) 
			\brief     Función que pide las componentes de los vectores u, v y w      
			\note      Función void
			\param     u: Objeto de tipo Vector3D pasado como referencia  
			\param     v: Objeto de tipo Vector3D pasado como referencia 
			\param	   w: Objeto de tipo Vector3D pasado como referencia  
			\pre       Ninguna
			\post      Ninguna
			\sa        leerVector3D()
	*/	
	void leerVectores(ed::Vector3D &u, ed::Vector3D &v, ed::Vector3D &w);

	/*!		\fn 	   void escribirVectores(Vector3D const &u, Vector3D const &v, Vector3D const &w) 
			\brief     Función que imprime por pantalla las componentes de los vectores u, v y w      
			\note      Función void
			\param     u: Objeto de tipo Vector3D pasado como referencia constante 
			\param     v: Objeto de tipo Vector3D pasado como referencia constante 
			\param	   w: Objeto de tipo Vector3D pasado como referencia constante  
			\pre       Ninguna
			\post      Ninguna
			\sa        escribirVector3D()
	*/	
	void escribirVectores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*!		\fn 	   void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v)
			\brief     Función que imprime por pantalla las componentes de los vectores pasados por referencia, sus modulos, el angulo entre ellos, y los angulos de cada componente de los vectores
			\note      Función void
			\param     u: Objeto de tipo Vector3D pasado como referencia constante 
			\param     v: Objeto de tipo Vector3D pasado como referencia constante 
			\pre       Ninguna
			\post      Ninguna
			\sa        escribirVector3D(), modulo(), angulo(), get1(), get2(), get3(), alfa(), beta(), gamma(), operator=()
	*/	
	void observadoresDeVectores(ed::Vector3D const &u, ed::Vector3D const &v);

	/*!		\fn 	   void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k)
			\brief     Función que modifica el primer vector pasado por argumento con la suma/multiplicación de una constante real o la suma/multiplicación de otro Vector3D     
			\note      Función void
			\param     u: Objeto de tipo Vector3D pasado como referencia constante 
			\param     v: Objeto de tipo Vector3D pasado como referencia constante 
			\param     k: Constante de tipo doble pasa por referencia 
			\pre       Ninguna
			\post      Ninguna
			\sa        sumConst(), multConst(), sumVect(), multVect(), operator=()
	*/	
	void modificarVector(ed::Vector3D &u, ed::Vector3D const &v, double k);

	/*!		\fn 	   void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v) 
			\brief     Función que muestra el producto escalar de dos vectores pasados por referencia constante
			\note      Función void
			\param     u: Objeto de tipo Vector3D pasado como referencia constante 
			\param     v: Objeto de tipo Vector3D pasado como referencia constante 
			\pre       Ninguna
			\post      Ninguna
			\sa        dotProduct(), operator*()
	*/	
	void mostrarProductoEscalar(ed::Vector3D const &u, ed::Vector3D const &v); 

	/*!		\fn 	   void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v)
			\brief     Función que muestra el producto vectorial de dos vectores pasados por referencia constante 
			\note      Función void
			\param     u: Objeto de tipo Vector3D pasado como referencia constante 
			\param     v: Objeto de tipo Vector3D pasado como referencia constante 
			\pre       Ninguna
			\post      Ninguna
			\sa        crossProduct(), modulo(), angulo(), operator^()
	*/	
	void mostrarProductoVectorial(ed::Vector3D const &u, ed::Vector3D const &v);

	/*!		\fn 	   void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w)
			\brief     Función que muestra el producto mixto de tres vectores pasados por referencia constante  
			\note      Función void
			\param     u: Objeto de tipo Vector3D pasado como referencia constante 
			\param     v: Objeto de tipo Vector3D pasado como referencia constante 
			\param	   w: Objeto de tipo Vector3D pasado como referencia constante  
			\pre       Ninguna
			\post      Ninguna
			\sa        modulo(), angulo(), productoMixto(), operator^()
	*/	
	void mostrarProductoMixto(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

	/*!		\fn 	   void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);
			\brief     Función que muestra los operadores    
			\note      Función void
			\param     u: Objeto de tipo Vector3D pasado como referencia constante 
			\param     v: Objeto de tipo Vector3D pasado como referencia constante 
			\param	   w: Objeto de tipo Vector3D pasado como referencia constante  
			\param     k: Constante de tipo doble pasa por referencia 
			\pre       Ninguna
			\post      Ninguna
			\sa        operator==(), operator=(), operator+(), operator-(),operator*()
	*/	
	void mostrarOperadores(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);

	/*!		\fn 	   void operacionesAdicionales(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D &w,  double k);
			\brief     Función que realiza el baricentro de 3 vectores, la propiedad asociativa, conmutativa y comprueba si los 3 vectores están alineados
			\note      Función void
			\param     u: Objeto de tipo Vector3D pasado como referencia constante 
			\param     v: Objeto de tipo Vector3D pasado como referencia constante 
			\param	   w: Objeto de tipo Vector3D pasado como referencia constante  
			\pre       Ninguna
			\post      Ninguna
			\sa        operator==(),, operator+(), operator-()
	*/	
	void operacionesAdicionales(ed::Vector3D const &u, ed::Vector3D const &v, ed::Vector3D const &w);

} // Fin del espacio de nombre de la asignatura: ed

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

