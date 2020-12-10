// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// T(n) = C0 (n=1)
// T(n) = T(n/2) + C1 (n>1)
// El coste de esta funci¨®n es O(log(n))--> siendo n el numero de elementos del vector.

int resolver(vector<int> const& v, vector<int> const& w, int ini, int fin) {

    if (ini >= fin) return v[ini];

    else if (ini + 1 == fin) {
        if (w[ini] == v[ini]) return v[fin];
        else return v[ini];
    }

    else {
        int m = (ini + fin) / 2;

        //Descartamos la mitad del vector (con esto conseguimos
        //un coste logaritmico):
        if (v[m] != w[m]) return resolver(v, w, ini, m);
        else return resolver(v, w, m + 1, fin);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    vector<int> v(num);
    vector<int> w(num - 1);

    for (int i = 0; i < num; ++i)
        cin >> v[i];

    for (int j = 0; j < num - 1; ++j)
        cin >> w[j];

    int sol = resolver(v, w, 0, num - 1);

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
