// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci車n que resuelve el problema
// T(n) = C0 (n = 0)
// T(n) = C1 (n = 1)
// T(n) = 2T(n/2) + C2 (n > 1)
// El coste es del O(n) --> n siendo numero de elementos

bool resolver(vector<int> const& v, int ini, int fin, int& suma) {

    if (ini + 1 == fin) return true; //Si hay un solo elemento;

    else if (ini + 2 == fin) { //Si hay solo 2 elementos;
        suma = v[ini] + v[fin-1];
        //Comprobamos la condici車n del degradado para dos elementos:
        if (v[ini] < v[fin-1]) return true;
        else return false;
    }

    else { //Si hay m芍s de 2 elementos;
        int m = (ini + fin) / 2;
        int acIz = 0, acDr = 0;

        bool ladoIzq = resolver(v, ini, m, acIz);
        bool ladoDer = resolver(v, m, fin, acDr);

        //Comprobamos la condici車n y actualizamos el acumulado tras
        //cada nivel de profundidad de la recursi車n:
        if (ladoIzq && ladoDer && acIz < acDr) {
            suma = acIz + acDr;
            return true;
        }
        else return false;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci車n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numFila;
    cin >> numFila;

    if (!cin)
        return false;

    int numCol;
    cin >> numCol;

    if (!cin)
        return false;

    //Creamos la matriz:
    vector<vector<int>>v(numFila, vector<int>(numCol));

    //Rellenamos la matriz:
    for (int i = 0; i < numFila; i++) {
        for (int j = 0; j < numCol; j++) {
            cin >> v[i][j];
        }
    }
    bool sol = true;
    for (int i = 0; sol && (i < numFila); ++i) {
        int acumulado = 0;
        sol = resolver(v[i], 0, numCol, acumulado);
    }
    // escribir sol
    if (sol) cout << "SI" << "\n";
    else cout << "NO" << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
