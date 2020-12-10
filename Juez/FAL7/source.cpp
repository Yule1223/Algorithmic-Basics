//Yule Zhang
//E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


int resolver(vector<int> const& v, int ini, int fin) {

    if (ini == fin) return v[ini];
    else {
        int m = (fin + ini) / 2;

        if (v[ini] < v[fin]) {
            if (v[m] < v[m + 1]) return v[m];
            else if (v[m] > v[ini]) return resolver(v, ini, m);
            else return resolver(v, m + 1, fin);
        }
        else return v[fin];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    cin >> tam;

    if (!cin)return false;
    vector<int> v(tam);

    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];

    int sol = resolver(v, 0, tam - 1);

    // escribir sol
    cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
