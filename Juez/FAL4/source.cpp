//Yule Zhang
//E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
// la funcion es del orden O(n)
char resolver(vector<char> const& presos, int ini, int fin, char prim, char ulti) {

    if (ini >= (int)presos.size()) return ulti;//Si solo hay un elemento
    int medio = (ini + fin) / 2;
    if (ini > fin) return presos[ini] - 1;
    else {
        if (presos[medio] - prim == medio) return resolver(presos, medio + 1, fin, prim, ulti);
        else return resolver(presos, ini, medio - 1, prim, ulti);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char prim, ulti;
    cin >> prim >> ulti;
    vector<char> presos;
    presos.reserve(ulti - prim);//Para inicializar la longitud del vector

    char aux;
    for (int i = 0; i < presos.capacity(); ++i) {
        cin >> aux;
        presos.push_back(aux);
    }

    char sol = resolver(presos, 0, presos.size() - 1, prim, ulti);
    // escribir sol
    cout << sol << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
