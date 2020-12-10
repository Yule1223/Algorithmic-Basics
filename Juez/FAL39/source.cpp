// E81
// Yule Zhang

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//coste lineal O(n) siendo n = fin - ini
bool consecutivos(vector<int>const& datos, int ini, int fin) {
    bool ok = true;
    for (int i = ini; i < fin && ok; i++) {
        if (datos[i + 1] - datos[i] != 1)
            ok = false;
    }
    return ok;
}

//coste lineal O(n-1) siendo n es el numero de elementos de la secuencia
bool secuenciaMax(vector<int>const& datos, int l) {
    int lAux = 1;
    int lMax = 1;
    for (int i = 0; i < datos.size()-1; i++) {
        if (consecutivos(datos, i, i + 1)) {
            lAux++;
        }
        else {
            if (lAux > lMax)
                lMax = lAux;
            lAux = 0;
        }
    }
    return lMax == l;
}

// funcion que resuelve el problema
void resolver(vector<int>const& datos, int& pos, int& l) {
    int posAux = 0;
    int lAux = 1;
    for (int i = 0; i <datos.size() - 1; i++) {
        if (consecutivos(datos, i, i + 1)) {
            lAux++;
            if (i == datos.size() - 2) {
                if (lAux > l) {
                    l = lAux;
                    pos = posAux;
                }
            }
        }
        else {
            if (lAux > l) {
                l = lAux;
                pos = posAux;
            }
            posAux = i + 1;
            lAux = 1;
        }       
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de datos
    cin >> n;
    if (n == 0)
        return false;

    vector<int>datos(n);
    for (int i = 0; i < n; i++) {
        cin >> datos[i];
    }

    int pos = 0;//posicion del comienzo
    int l = 1;//longitud
    resolver(datos, pos, l);

    // escribir sol
    cout << pos << " " << l << endl;
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
