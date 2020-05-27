#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>
#include <iterator>



// Este es el método principal que debe contener los 4 Comportamientos_Jugador
// que se piden en la práctica. Tiene como entrada la información de los
// sensores y devuelve la acción a realizar.
Action ComportamientoJugador::think(Sensores sensores) {
	Action accion = actIDLE;
	// Estoy en el nivel 1

		actual.fila        = sensores.posF;
		actual.columna     = sensores.posC;
		actual.orientacion = sensores.sentido;
		actual.bikini 		 = false;
		actual.zapas 			 = false;

		cout << "Fila: " << actual.fila << endl;
		cout << "Col : " << actual.columna << endl;
		cout << "Ori : " << actual.orientacion << endl;

		destino.fila       = sensores.destinoF;
		destino.columna    = sensores.destinoC;

		if (sensores.nivel != 4){
			bool hay_plan = pathFinding (sensores.nivel, actual, destino, plan);
		}
		else {
			// Estoy en el nivel 2
			cout << "No implementado" << endl;
				exit(0);
			}

  return accion;
}


// Llama al algoritmo de busqueda que se usará en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador::pathFinding (int level, const estado &origen, const estado &destino, list<Action> &plan){
	switch (level){
		case 1: cout << "Busqueda en profundidad\n";
			      return pathFinding_Profundidad(origen,destino,plan);
						break;
		case 2: cout << "Busqueda en Anchura\n";
			      return pathFinding_Anchura(origen,destino,plan);
						break;
		case 3: cout << "Busqueda en Costo Uniforme\n";
						return pathFinding_Uniforme(origen,destino,plan);
						break;
		case 4: cout << "Busqueda para el reto\n";
						// Incluir aqui la llamada al algoritmo de búsqueda usado en el nivel 2
						break;
	}
	cout << "Comportamiento sin implementar\n";
	return false;
}


//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Dado el código en carácter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo(unsigned char casilla){
	if (casilla=='P' or casilla=='M')
		return true;
	else
	  return false;
}


// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador::HayObstaculoDelante(estado &st){
	int fil=st.fila, col=st.columna;

  // calculo cual es la casilla de delante del agente
	switch (st.orientacion) {
		case 0: fil--; break;
		case 1: col++; break;
		case 2: fil++; break;
		case 3: col--; break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil<0 or fil>=mapaResultado.size()) return true;
	if (col<0 or col>=mapaResultado[0].size()) return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col])){
		// No hay obstaculo, actualizo el parámetro st poniendo la casilla de delante.
    st.fila = fil;
		st.columna = col;
		return false;
	}
	else{
	  return true;
	}
}



struct nodo{
	estado st;
	list<Action> secuencia;
	int coste;
};

struct ComparaEstados{
	bool operator()(const estado &a, const estado &n) const{
		if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
	      (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion))
			return true;
		else
			return false;
	}
};

struct ComparaNodos{
	bool operator()(const nodo &a, const nodo &n) const{
		if (a.coste < n.coste)
			return true;
		else
			return false;
	}
};

multiset<nodo,ComparaNodos>::const_iterator Encontrado(multiset<nodo,ComparaNodos> &abiertos, nodo &nodo){
	for(auto it = abiertos.begin(); it != abiertos.end(); ++it){
		if(it->st.fila == nodo.st.fila && it->st.columna == nodo.st.columna && it->st.orientacion == nodo.st.orientacion){
			return it;
		}
	}
	return abiertos.end();
}

// Implementación de la búsqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; // Lista de Cerrados
	stack<nodo> pila;											// Lista de Abiertos

  nodo current;
	current.st = origen;
	current.secuencia.empty();

	pila.push(current);

  while (!pila.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		pila.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			pila.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			pila.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				pila.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la pila
		if (!pila.empty()){
			current = pila.top();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}


// Implementación de la búsqueda en anchura
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados;
	queue<nodo> cola;

  nodo current;
	current.st = origen;
	current.secuencia.empty();

	cola.push(current);

  while (!cola.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		cola.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			cola.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			cola.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				cola.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la cola
		if (!cola.empty()){
			current = cola.front();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}

// Implementación de la búsqueda en coste uniforme
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Uniforme(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();

	multiset<nodo,ComparaNodos> nodos_abiertos;	  		// Lista de Abiertos
	set<estado,ComparaEstados> generados;				  		// Lista de Cerrados

  nodo current;
	current.st = origen;
	current.secuencia.empty();
	current.coste = 0;					//Hemos añadido al struct nodos el atributo coste

	nodos_abiertos.insert(current);

  while (!nodos_abiertos.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		nodos_abiertos.erase(nodos_abiertos.begin());
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;

		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.coste += getCosteMovimiento(current.st, hijoTurnR.st);

			multiset<nodo,ComparaNodos>::iterator it;
			it = Encontrado(nodos_abiertos, hijoTurnR);

			if(it != nodos_abiertos.end()){
				if(hijoTurnR.coste <= it->coste){
					nodos_abiertos.erase(it);
					hijoTurnR.secuencia.push_back(actTURN_R);
					nodos_abiertos.insert(hijoTurnR);
				}
			} else{
				hijoTurnR.secuencia.push_back(actTURN_R);
				nodos_abiertos.insert(hijoTurnR);
				}
			}


			// Generar descendiente de girar a la derecha
			nodo hijoTurnL = current;
			hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;

			if (generados.find(hijoTurnL.st) == generados.end()){
				hijoTurnL.coste += getCosteMovimiento(current.st, hijoTurnL.st);

				multiset<nodo,ComparaNodos>::iterator it;
				it = Encontrado(nodos_abiertos, hijoTurnL);

				if(it != nodos_abiertos.end()){
					if(hijoTurnL.coste <= it->coste){
						nodos_abiertos.erase(it);
						hijoTurnL.secuencia.push_back(actTURN_L);
						nodos_abiertos.insert(hijoTurnL);
					}
				} else{
					hijoTurnL.secuencia.push_back(actTURN_L);
					nodos_abiertos.insert(hijoTurnL);
				}
			}

		// Generar descendiente de avanzar
	 	nodo hijoForward = current;

		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.coste += getCosteMovimiento(current.st, hijoForward.st);

				multiset<nodo,ComparaNodos>::iterator it;
				it = Encontrado(nodos_abiertos, hijoForward);

				if(it != nodos_abiertos.end()){
					if(hijoForward.coste <= it->coste){
						nodos_abiertos.erase(it);
						hijoForward.secuencia.push_back(actFORWARD);
						nodos_abiertos.insert(hijoForward);
					}
				} else{
					hijoForward.secuencia.push_back(actFORWARD);
					nodos_abiertos.insert(hijoForward);
				}
			}
		}

		// Tomo el siguiente valor de la cola
		if (!nodos_abiertos.empty()){
			current = *nodos_abiertos.begin();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}

//Contabilizar el coste de pasar de una casilla a otra,
//contando con las casillas especiales A, B, T y cambiar el estado si se
//obtienen las zapatillas o el bikini
int ComportamientoJugador::getCosteMovimiento(estado &origen, estado &sig){
	char next_casilla = mapaResultado[sig.fila][sig.columna];
	int  coste = 0;

	if(origen.orientacion != sig.orientacion){
		coste++;
	}

	if(next_casilla == 'A' || next_casilla == 'B' || next_casilla == 'T'){
			switch(next_casilla){
				case 'A': coste = origen.bikini? 10 : 100; break;
				case 'B':	coste =  origen.zapas? 5  : 50;  break;
				case 'T': coste =  2;  break;
			}
		} else if (next_casilla == 'K' || next_casilla == 'D'){
			switch(next_casilla){
				case 'K': sig.bikini = true; coste++; break;
				case 'D': sig.zapas  = true; coste++; break;
		}
	} else coste++;

	return coste;
}


// Sacar por la términal la secuencia del plan obtenido
void ComportamientoJugador::PintaPlan(list<Action> plan) {
	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			cout << "A ";
		}
		else if (*it == actTURN_R){
			cout << "D ";
		}
		else if (*it == actTURN_L){
			cout << "I ";
		}
		else {
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}



void AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
}


// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			switch (cst.orientacion) {
				case 0: cst.fila--; break;
				case 1: cst.columna++; break;
				case 2: cst.fila++; break;
				case 3: cst.columna--; break;
			}
			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R){
			cst.orientacion = (cst.orientacion+1)%4;
		}
		else {
			cst.orientacion = (cst.orientacion+3)%4;
		}
		it++;
	}
}



int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
