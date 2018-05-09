/*! 
   \file Vector3D.hpp
   \brief Fichero de definición de la clase Vector3D: vector libre de tres dimensiones
   \author   Carlos Luque Córdoba
   \date     2018-2-28
   \version  1.0
*/

#ifndef _VECTOR3D_HPP_
#define _VECTOR3D_HPP_

// Entrada y salida 
#include <iostream>

// Para usar abs
#include <cmath>

// Para controlar las pre y post condiciones mediante asertos
#include <cassert>

// COMPLETAR, SI ES PRECISO


// Para la sobrecarga de los operadores de flujo: << y >>
using std::istream;
using std::ostream;

#define COTA_ERROR 1.0e-6 //!< Cota de error para la comparación números reales


// Se incluye la clase Vector3D dentro del espacio de nombre de la asigantura: ed
namespace ed{

//!  Definición de la clase Vector3D:  \f$ \vec{v} = (v_1, v_2, v_3) = v_1 \vec{i} + v_2 \vec{j} + v_3 \vec{k} \f$ 
class Vector3D{
  //! \name Atributos privados de la clase Vector3D
   private: 

	double _vec[3]; //!< Vector[1]: _x, Vector[2]:_y, Vector[3]:_z

   //! \name Funciones o métodos públicos de la clase Vector3D
   public:

	//! \name Constructores de la clase Vector3D
		/*! 
				\brief     Constructor que crea un Vector3D nulo (0, 0, 0)
				\attention Constructor sobrecargado sin argumentos       
				\note      Función inline
			 	\warning   Los parámetros tienen valores por defecto
				\pre       Ninguna
				\post      (get1()==0) and (get2()==0) and (get3()==0)
				\sa        set1(), set2(), set3(), get1(), get2(), get3()
		*/
		inline Vector3D(){
			this->set1(0.0);
			this->set2(0.0);
			this->set3(0.0);
			#ifndef NDEBUG //Se comprueba la post condición
				assert((get1()==0.0) and (get2()==0.0) and (get3()==0.0));
			#endif
		}
		
		/*! 
				\brief     Constructor que crea un Vector3D a partir de las coordenadas v1, v2 y v3
				\attention Constructor sobrecargado con argumentos      
				\note      Función inline
				\param     v1: Coordenada x del plano de abscisas del Vector3D; 
				\param     v2: Coordenada y del plano de ordenadas del Vector3D; 
				\param	   v3: Coordenada z del plano de cotas del Vector3D; 
				\n \f$     \vec{v} = v_1 \ast \vec{i} + v_2 \ast \vec{j} + v_3 \ast \vec{k} = (v_1 v_2 v_3 )\f$
				\pre       Ninguna
				\post      (get1()==v1) and (get2()==v2) and (get3()==v3)
				\sa        set1(), set2(), set3(), get1(), get2(), get3()
		*/	
		inline Vector3D(double v1, double v2, double v3){
			set1(v1);
			set2(v2);
			set3(v3);

			#ifndef NDEBUG
				assert((std::abs(get1()-v1)<COTA_ERROR) and (std::abs(get2()-v2)<COTA_ERROR) and (std::abs(get3()-v3))<COTA_ERROR);
			#endif
		}

		/*! 
				\brief     Constructor que crea un Vector3D a partir de otro Vector3D
				\attention Constructor sobrecargado con otro Vector3D       
				\note      Función inline
				\param     v: Objeto de tipo Vector3D pasado como referencia constante 
				\pre       Ninguna
				\post      (get1()==v.get1()) and (get2()==v.get2()) and (get3()==v.get3())
				\sa        set1(), set2(), set3()
		*/
		inline Vector3D(Vector3D const &v){
			set1(v.get1());
			set2(v.get2());
			set3(v.get3());
			#ifndef NDEBUG
				assert(std::abs(get1()-v.get1())<COTA_ERROR and std::abs((get2()-v.get2()))<COTA_ERROR and std::abs((get3()-v.get3()))<COTA_ERROR);
			#endif
		}
			//! \name Observadores: funciones de consulta de Vector3D

		/*! 
				\fn        inline double get1() const
				\brief     Función que devuelve la coordenada x del Vector3D
				\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\note      Función inline
				\return    Componente x del Vector3D
				\pre       Ninguna
				\post	   Ninguna
				\sa        get1()
		*/
		inline double get1() const {return _vec[0];}

		/*! 
				\fn        inline double get2() const
				\brief     Función que devuelve la coordenada y del Vector3D
				\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\note      Función inline
				\return    Componente y del Vector3D
				\pre       Ninguna
				\post	   Ninguna
				\sa        get2()
		*/
		inline double get2() const {return _vec[1];}

		/*! 
				\fn        inline double get3() const
				\brief     Función que devuelve la coordenada z del Vector3D
				\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\note      Función inline
				\return    Componente z del Vector3D
				\pre       Ninguna
				\post	   Ninguna
				\sa        get3()
		*/
		inline double get3() const {return _vec[2];}

		/*! 
				\fn        double modulo() const
				\brief     Función que calcula el modulo del Vector3D       
				\note      Función double
				\n \f$     modulo(\vec{v}) = \Vert \vec{v} \Vert = \sqrt{v_1 \ast v_1 + v_2 \ast v_2 + v_3 \ast v_3}\f$
			 	\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\pre       Ninguna
		     	\post      moduloDev == sqrt (get1()*get1() + get2()*get2() + get3()*get3())				\sa        set1(), set2(), set3(), get1(), get2(), get3()
				\sa 	   get1(), get2(), get3()
		*/
		double modulo() const ;


		/*! 
				\fn        double angulo(Vector3D const &v) const
				\brief     Función que calcula el angulo del Vector3D     
				\note      Función double
				\param     v: Objeto de tipo Vector3D pasado como referencia constante 
				\n \f$     Ángulo(\vec{u}, \vec{v}) = \arccos(\frac{\vec{u} \ast \vec{v}}{\Vert \vec{u} \Vert \ast \Vert \vec{v} \Vert}) \f$
				\return    Angulo del Vector3D
			 	\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\pre       ((modulo()*v.modulo())>0)
				\post      anguloDev == acos( dotProduct(v) / (modulo() * v.modulo()) )
				\sa        modulo(), dotProduct()
		*/
		double angulo(Vector3D const &v) const ;

		/*! 
				\fn        double alfa() const
				\brief     Función que calcula el angulo del Vector3D con el eje x      
				\note      Función double
				\return    Angulo de la componente x del Vector3D
			 	\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\pre       (modulo()>0)
				\post      anguloDev == angulo(Vector3D(1,0,0))
				\sa        modulo(), set1(), set2(), set3(), angulo()
		*/	
		double alfa() const ;

		/*! 
				\fn        double beta() const
				\brief     Función que calcula el angulo del Vector3D con el eje y    
				\note      Función double
				\return    Angulo de la componente y del Vector3D
			 	\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\pre       (modulo()>0)
				\post      anguloDev == angulo(Vector3D(0,1,0))
				\sa        modulo(), set1(), set2(), set3(), angulo()
		*/		
		double beta() const ;

		/*! 
				\fn        double gamma() const
				\brief     Función que calcula el angulo del Vector3D con el eje z     
				\note      Función double
				\return    Angulo de la componente z del Vector3D
			 	\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\pre       (modulo()>0)
				\post      anguloDev == angulo(Vector3D(0,0,1))
				\sa        modulo(), set1(), set2(), set3(), angulo()
		*/	
		double gamma() const ;

		/*! 
				\fn        double dotProduct(Vector3D const &v) const ;
				\brief     Función que calcula el producto escalar de 2 vectores     
				\note      Función double
				\param     v: Objeto de tipo Vector3D pasado como referencia constante 
				\n \f$     \vec{u} \ast \vec{v} = u_1 \ast v_1 + u_2 \ast v_2 +u_3 \ast v_3 \f$
				\return    Producto escalar de 2 vectores
			 	\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\pre       Ninguna
				\post      anguloDev == get1()*v.get1() + get2()*v.get2() + get3()*v.get3()
				\sa        get1(), get2(), get3()
		*/	
		double dotProduct(Vector3D const &v) const ;

		/*! 
				\fn        Vector3D crossProduct(Vector3D const &v) const
				\brief     Función que calcula el producto vectorial de 2 vectores guardandolo en otro vector   
				\note      Función Vector3D
				\param     v: Objeto de tipo Vector3D pasado como referencia constante 	
				\n \f$     \vec{u} \wedge \vec{v} = \vec{w} =w_1*\vec{i} + w_2*\vec{j} + w_3*\vec{k} \f$
				<ul>
						   <li>\f$     w_1 = u_2 \ast v_3 - u_3 \ast v_2 \f$
						   <li>\f$     w_2 = - u_1 \ast v_3 + u_3 \ast v_1 \f$
						   <li>\f$     w_3 = u_1 \ast v_2 - u_2 \ast v_1 \f$
				</ul>
				\return    Producto vectorial de 2 vectores
			 	\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\pre       (angulo(v)>0) and (modulo()>0) and (v.modulo()>0)
				\post      (dotProduct(productoDev)==0) and (v.dotProduct(productoDev)==0) and (productoDev.modulo()==(modulo()*v.modulo()*sin(angulo(v)))
				\sa        modulo(), set1(), set2(), set3(), get1(), get2(), get3(), angulo(), dotProduct()
		*/	
		Vector3D crossProduct(Vector3D const &v) const ;

		/*! 
				\fn        double productoMixto(Vector3D const &v, Vector3D const &w) const
				\brief     Función que calcula el producto mixto de 3 vectores   
				\note      Función double
				\param     v: Objeto de tipo Vector3D pasado como referencia constante 
				\param     w: Objeto de tipo Vector3D pasado como referencia constante 
				\n \f$     productoMixto(\vec{u}, \vec{v}, \vec{w}) = \vec{u} \ast (\vec{v} \wedge \vec{w}) \f$
				\return    Producto mixto de 3 vectores
			 	\warning   Se usa const en la definición para poder usar el operador de asignación "="      
				\pre       Ninguna
				\post      (prodMixDev==(dotProduct(v.crossProduct(vectorW))))<COTA_ERROR)
				\sa        set1(), set2(), set3(), dotProduct(), crossProduct()
		*/	
		double productoMixto(Vector3D const &v, Vector3D const &w) const ;


			//! \name Modificadores: funciones de modificación de Vector3D

		/*! 
				\fn        inline void set1(double v)
				\brief     Función que iguala una variable real a la primera componente del Vector3D 
				\note      Función void
				\param     v: Objeto de tipo doble 
				\pre       Ninguna
				\post      (get1()==v)
				\sa        get1()
		*/
		inline void set1(double v){
			_vec[0]=v;

			#ifndef NDEBUG
				assert(std::abs(get1()-v)<COTA_ERROR);
			#endif //NDEBUG
		}

		/*! 
				\fn        inline void set2(double v)
				\brief     Función que iguala una variable real a la segunda componente del Vector3D 
				\note      Función void
				\param     v: Objeto de tipo doble 
				\pre       Ninguna
				\post      (get2()==v)
				\sa        get2()
		*/
		inline void set2(double v){
			_vec[1]=v;

			#ifndef NDEBUG
				assert(std::abs(get2()-v)<COTA_ERROR);
			#endif //NDEBUG
		}

		/*! 
				\fn        inline void set3(double v)
				\brief     Función que iguala una variable real a la tercera componente del Vector3D 
				\note      Función void
				\param     v: Objeto de tipo doble 
				\pre       Ninguna
				\post      (get3()==v)
				\sa        get3()
		*/
		inline void set3(double v){
			_vec[2]=v;
			
			#ifndef NDEBUG
				assert(std::abs(get3()-v)<COTA_ERROR);
			#endif //NDEBUG
		} 

		/*! 
				\fn        void sumConst(double k)
				\brief     Función que suma una constante real a un vector
				\note      Función void
			 	\param     k: Constante de tipo doble pasa por referencia constante 
			 	\warning   "old" representa el vector original antes de ser modificado     
				\pre       Ninguna
				\post      (get1() == old.get1() + k) and (get2() == old.get2() + k) and (get3() == old.get3() + k)
				\sa        set1(), set2(), set3(), get1(), get2(), get3()
		*/	
		void sumConst(double k);

		/*! 
				\fn        void sumVect(Vector3D const &v)
				\brief     Función que suma un vector de tipo Vector3D a otro Vector3D
				\note      Función void
			 	\param     v: Objeto de tipo Vector3D pasado como referencia constante
			 	\warning   "old" representa el vector original antes de ser modificado     
				\pre       Ninguna
				\post      (get1() == old.get1() + v.get1()) and (get2() == old.get2() + v.get2()) and (get3() == old.get3() + v.get3())
				\sa        set1(), set2(), set3(), get1(), get2(), get3()
		*/	
		void sumVect(Vector3D const &v);

		/*! 
				\fn        void multConst(double k)
				\brief     Función que multiplica una constante real a un vector
				\note      Función void
				\param     k: Constante de tipo doble pasa por referencia constante 
			 	\warning   "old" representa el vector original antes de ser modificado     
				\pre       Ninguna
				\post      (get1() == old.get1() * k) and (get2() == old.get2() * k) and (get3() == old.get3() * k)
				\sa        set1(), set2(), set3(), get1(), get2(), get3()
		*/	
		void multConst(double k);

		/*! 
				\fn        void multVect(Vector3D const &v)
				\brief     Función que multplica un vector de tipo Vector3D a otro Vector3D
				\note      Función void
			 	\param     v: Objeto de tipo Vector3D pasado como referencia constante
			 	\warning   "old" representa el vector original antes de ser modificado     
				\pre       Ninguna
				\post      (get1() == old.get1() * v.get1()) and (get2() == old.get2() * v.get2()) and (get3() == old.get3() * v.get3())
				\sa        set1(), set2(), set3(), get1(), get2(), get3()
		*/		
		void multVect(Vector3D const &v);


	    //! \name Operadores de la clase
		   
		/*! 
				\fn        bool operator == (Vector3D const &objeto) const
				\brief     Función que identifica si dos vectores son iguales o no
				\note      Función booleana
				\param     objeto: Objeto de tipo Vector3D pasado como referencia constante
				\n \f$     \vec{u} == \vec{v} \f$
			 	\warning   Se usa const en la definición para poder usar en otras funciones el operador "=="
				\return    Devuelve true si los vectores son iguales dentro de la cota de error, si no, devuelve falso
				\pre       Ninguna
				\post      (get1() == old.get1() * v.get1()) and (get2() == old.get2() * v.get2()) and (get3() == old.get3() * v.get3())
				\sa        get1(), get2(), get3()
		*/	
		bool operator == (Vector3D const &objeto) const;

		/*! 
				\fn        Vector3D operator = (Vector3D const &objeto) 
				\brief     Función que iguala un vector a otro
				\note      Función Vector3D
				\param     v: Objeto de tipo Vector3D pasado como referencia constante
				\n \f$     \vec{u} = \vec{v} \f$
				\return    Devuelve el puntero a this
				\pre       
				\post      (get1() == v.get1()) and (get2() == v.get2()) and (get3() == v.get3())
				\sa        get1(), get2(), get3()
		*/	
		Vector3D operator=(Vector3D const &v);

		/*! 
				\fn        Vector3D operator +(Vector3D const &objeto) const
				\brief     Función que devuelve otro vector que es la suma del vector actual y el vector pasado como parámetro
				\attention Función operador + sobrecargada con argumentos
				\note      Función Vector3D
				\param     v: Objeto de tipo Vector3D pasado como referencia constante
				\n \f$     \vec{u} + \vec{v} = (u_1 + v_1, u_2 + v_2, u_3 + v_3) \f$
			 	\warning   Se usa const en la definición para poder usar en otras funciones el operador "+" 
				\return    Devuelve el nuevo vector en el que se ha guardado la suma de componentes de los vectores
				\pre       Ninguna
				\post      (valorDevuelto.get1() == get1() + v.get1()) and (valorDevuelto.get2() == get2() + v.get2()) and (valorDevuelto.get3() == get3() + v.get3())
				\sa        get1(), get2(), get3(), set1(), set2(), set3()
		*/	
		Vector3D operator+(Vector3D const &v) const;

		/*! 
				\fn        Vector3D operator +() const
				\brief     Función que devuelve otro vector que es una copia al vector actual
				\attention Función operador + sobrecargada sin argumentos
				\note      Función Vector3D
				\n \f$     + \vec{v} = (v_1, v_2, v_3) \f$
			 	\warning   Se usa const en la definición para poder usar en otras funciones el operador "-"
				\return    Devuelve la copia del vector actual
				\pre       Ninguna
				\post      (valorDevuelto.get1() == get1()) and (valorDevuelto.get2() == get2()) and (valorDevuelto.get3() == get3()))
				\sa        get1(), get2(), get3(), set1(), set2(), set3()
		*/	
		Vector3D operator+() const;

		/*! 
				\fn        Vector3D operator -(Vector3D const &v) const
				\brief     Función que devuelve otro vector que es la diferencia entre el vector actual y el vector pasado como parámetro
				\attention Función operador - sobrecargada sin argumentos
				\note      Función Vector3D
				\param     v: Objeto de tipo Vector3D pasado como referencia constante
				\n \f$     \vec{u} - \vec{v} = (u_1 - v_1, u_2 - v_2, u_3 - v_3) \f$
			 	\warning   Se usa const en la definición para poder usar en otras operaciones el operador "-"
				\return    Devuelve el nuevo vector en el que se ha guardado la suma de componentes de los vectores
				\pre       Ninguna
				\post      (valorDevuelto.get1() == get1()) and (valorDevuelto.get2() == get2()) and (valorDevuelto.get3() == get3()))
				\sa        get1(), get2(), get3(), set1(), set2(), set3()
		*/	
		Vector3D operator-(Vector3D const &v) const;

		/*! 
				\fn        Vector3D operator -() const
				\brief     Función que devuelve otro vector que es el opuesto al vector actual
				\attention Función operador - sobrecargada sin argumentos
				\note      Función Vector3D
				\n \f$     - \vec{v} = (-v_1, -v_2, -v_3) \f$
			 	\warning   Se usa const en la definición para poder usar en otras funciones el operador "-"
				\return    Devuelve el opuesto del vector actual
				\pre       Ninguna
				\post      (valorDevuelto.get1() == -get1()) and (valorDevuelto.get2() == -get2()) and (valorDevuelto.get3() == -get3())
				\sa        get1(), get2(), get3(), set1(), set2(), set3()
		*/	
		Vector3D operator-() const;	

		/*! 
				\fn        Vector3D operator *(double k) const
				\brief     Función que devuelve otro vector cuyas componentes se obtienen multiplicando por “k” las componentes del vector actual
				\attention Función operador * de tipo Vector3D de la clase Vector3D sobrecargada con argumentos
				\note      Función Vector3D
				\param     k: Constante de tipo double pasado como referencia constante
				\n \f$     \vec{v} \ast k = (k \ast v_1, k \ast v_2, k \ast v_3) \f$
			 	\warning   Se usa const en la definición para poder usar en otras operaciones el operador "*"
				\return    Devuelve otro vector cuyas componentes se obtienen multiplicando por “k” las componentes del vector actual
				\pre       Ninguna
				\post      (valorDevuelto.get1() == get1() * k) and (valorDevuelto.get2() == get2() * k) and (valorDevuelto.get3() == get3() * k)
				\sa        get1(), get2(), get3(), set1(), set2(), set3()
		*/	
		Vector3D operator* (double k) const;
		  
		/*! 
				\fn        double operator *(Vector3D const &v) const
				\brief     Función que devuelve el producto escalar de dos vectores
				\attention Función operador * de tipo Vector3D de la clase Vector3D sobrecargada con argumentos
				\note      Función Vector3D
				\param     v: Objeto de tipo Vector3D pasado como referencia constante
				\n \f$     \vec{u} \ast \vec{v} = (u_1 \ast v_1, u_2 \ast v_2, u_3 \ast v_3) \f$
			 	\warning   Se usa const en la definición para poder usar en otras operaciones el operador "*"
				\return    Devuelve el producto escalar de dos vectores
				\pre       Ninguna
				\post      valorDevuelto == get1()*v.get1() + get2()*v.get2() + get3()*v.get3()
				\sa        dotProduct()
		*/	    
		double operator*(Vector3D const &v) const ;

		/*! 
				\fn        Vector3D operator ^(Vector3D const &v) const
				\brief     Función que devuelve un Vector3D que es el resultado del producto vectorial de dos vectores
 				\note      Función Vector3D
				\param     v: Objeto de tipo Vector3D pasado como referencia constante
				\n \f$     \vec{u} \wedge \vec{v} = \vec{w} = w_1 \ast \vec{i} + w_2 \ast \vec{j} + w_3 \ast \vec{k}\f$
			 	<ul>
						   <li>\f$     w_1 = u_2 \ast v_3 - u_3 \ast v_2 \f$
						   <li>\f$     w_2 = - u_1 \ast v_3 + u_3 \ast v_1 \f$
						   <li>\f$     w_3 = u_1 \ast v_2 - u_2 \ast v_1 \f$
				</ul>
			 	\warning   Se usa const en la definición para poder usar en otras operaciones el operador "^"
				\return    Devuelve un Vector3D que es el resultado del producto vectorial de dos vectores
				\pre       (angulo(v)>0.0) and (módulo>0.0) (v.módulo>0.0)
				\post      (dotProduct(valorDevuelto)==0) and (v.dotProduct(valorDevuelto)==0) and (valorDevuelto.modulo()==(modulo()*v.modulo()*sin(angulo(v)))
				\sa        get1(), get2(), get3(), set1(), set2(), set3()
		*/
		Vector3D operator^(Vector3D const &v) const ;

			//! \name Funciones lectura y escritura de la clase Vector3D

		/*! 
				\fn        void leerVector3D()
				\brief     Función que lee desde el teclado las componentes del vector
				\note      Función void
				\pre       Ninguna
				\post      Ninguna
				\sa        set1(), set2(), set3()
		*/
		void leerVector3D();

		/*! 
				\fn        void escribirVector3D() const
				\brief     Función que lee desde el teclado las componentes del vector
				\note      Función void
				\n \f$     (v_1  v_2  v_3) \f$
				\warning   Se usa const para poder usar los operadores "<<" y ">>" ya que no se modifica ningún valor, solo se imprime por pantalla
				\pre       Ninguna
				\post      Ninguna
				\sa        get1(), get2(), get3()
		*/
		void escribirVector3D() const ;

		//! \name Baricentro
		/*! 
				\fn        Vector3D baricentro(Vector3D const &v, Vector3D const &w) const
				\brief     Función que calcula el baricentro de 3 vectores
				\note      Función Vector3D
				\n \f$     G(\frac {u_1 + u_2 + u_3} {3} , \frac {v_1 + v_2 + v_3} {3} \frac {z_1 + z_2 + z_3} {3} \f$
				\warning   Se usa const para poder usar los operadores "=" y "+"
				\pre       Ninguna
				\post      Ninguna
				\sa        get1(), get2(), get3(), set1(), set2(), set3()
		*/
		Vector3D baricentro(Vector3D const &v, Vector3D const &w) const;
	
		//! \name Puntos aliineados
		/*! 
				\fn        bool puntosAlineados(Vector3D const &v, Vector3D const &w) const
				\brief     Función que calcula si 3 puntos están alineados
				\note      Función bool
				\n \f$     G(\frac {v_1 - u_1} {z_1 - v_1} , \frac {v_2 - u_2} {z_2 - v_2} \frac {v_3 - u_3} {z_3 - v_3} \f$
				\warning   Se usa const para poder usar los operadores "=" y "-"
				\pre       Ninguna
				\post      Ninguna
				\sa        get1(), get2(), get3()
		*/
		bool puntosAlineados(Vector3D const &v, Vector3D const &w) const;


		}; // \brief Fin de la definición de la clase Vector3D


		//////////////////////////////////////////////////////////////////////////////////////

		//! \name Funciones que utilizan un objetos de la clase Vector3D, pero que no pertenecen a la clase Vector3D

			/*! 
					\fn        Vector3D &operator* (double k, Vector3D const &objeto)
					\brief     Función que devuelve otro vector cuyas componentes se obtienen multiplicando por “k” las componentes del vector “objeto” pasado como parámetro
					\attention Función operador * de tipo Vector3D no siendo de la clase Vector3D sobrecargada con argumentos
					\note      Función Vector3D
					\param     k: Constante de tipo double pasado como referencia constante
					\param	   objeto: Objeto de tipo Vector3D pasado como referencia constante
					\n \f$     k \ast \vec{v}  = (k \ast v_1 \vec{i}, k \ast v_2 \vec{j}, k \ast v_3) \vec{k} \f$
				 	\warning   Para crear un vector de tipo Vector3D, habrá que reservar memoria y igualarlo a un vector new de tipo Vector3D "Vector3D *vectorResultado = new Vector3D()"
					\return    Devuelve otro vector cuyas componentes se obtienen multiplicando por “k” las componentes del vector “objeto” pasado como parámetro
					\pre       Ninguna
					\post      (valorDevuelto.get1() == objeto.get1() * k) and (valorDevuelto.get2() == objeto.get2() * k) and (valorDevuelto.get3() == objeto.get3() * k)
					\sa        get1(), get2(), get3(), set1(), set2(), set3()
			*/	
			Vector3D &operator* (double k, Vector3D const &objeto);

			/*! 
					\fn        istream &operator>> (istream &stream, Vector3D const &objeto)
					\brief     Función que lee desde el flujo de entrada las componentes del vector “v” separadas por espacios
					\note      Función istream
					\param	   stream: Flujo de datos pasado por referencia
					\param     objeto: Objeto de tipo Vector3D pasado como referencia constante
					\pre       Ninguna
					\post      Ninguna
					\sa        set1(), set2(), set3()
			*/
		    istream &operator>>(istream &stream, Vector3D &objeto);

		    /*! 
					\fn        ostream &operator>> (ostream &stream, Vector3D const &objeto)
					\brief     Función que escribe desde el flujo de entrada las componentes del vector “v” separadas por espacios
					\note      Función ostream
					\param	   stream: Flujo de datos pasado por referencia
					\param     objeto: Objeto de tipo Vector3D pasado como referencia constante
					\n \f$     (v_1  v_2  v_3) \f$
					\pre       Ninguna
					\post      Ninguna
					\sa        get1(), get2(), get3()
			*/
			ostream &operator<<(ostream &stream, Vector3D const &objeto);


		} // \brief Fin de namespace ed.

		//  _VECTOR3D_HPP_
		#endif 
