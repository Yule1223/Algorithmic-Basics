//Yule Zhang
//E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct tJugador {
    bool presentado;
    int numJuegos; // Cuantas veces ha jugado el jugador
};

// Funci¨®n que resuelve el problema
// T(n) = C0 (n = 1)
// T(n) = 2T(n/2) + C1 (n>1)
// El coste es del orden n, siendo n el numero de elementos

tJugador resolver(vector<string> const& v, int ini, int fin, int numRonda, int& rondaActual) {
    if (ini + 2 == fin) { //Si solo hay dos jugadores
        rondaActual = 1;
        if ((v[ini] != "NP") && (v[fin - 1] != "NP")) return { true, 1 };
        else if ((v[ini] != "NP") || (v[fin - 1] != "NP")) return { true, 0 };
        else return { false, 0 };
    }
    else { //Si hay mas de 2 jugadores
        int m = (ini + fin) / 2;
        tJugador iz = resolver(v, ini, m, numRonda, rondaActual);
        tJugador de = resolver(v, m, fin, numRonda, rondaActual);

        if ((rondaActual < numRonda) && iz.presentado && de.presentado) {
            rondaActual++;
            return { true,iz.numJuegos + de.numJuegos + 1 };
        }

        else if (iz.presentado || de.presentado) {
            rondaActual++;
            return { true,iz.numJuegos + de.numJuegos };
        }

        else {
            rondaActual++;
            return { false, (iz.numJuegos + de.numJuegos) };
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    int num;
    cin >> num;
    if (!cin) return false;

    int numRonda;
    cin >> numRonda;

    vector<string> v(num);

    for (int i = 0; i < num; i++)
        std::cin >> v[i];

    int rondaActual = 0;
    tJugador sol = resolver(v, 0, num, numRonda, rondaActual);

    // Escribir sol:
    cout << sol.numJuegos << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    //save old buf and redirect std::cin to datos.txt
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
