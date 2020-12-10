//Yule Zhang
//E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// T(n) = C0 (n=1)
// T(n) = T(n/2) + C1 (n>1)
// Coste es del O(log(n)), siendo n es el numero de casos

bool resolver(vector<int> const& v, int ini, int fin, int num, int& n) {

    if (ini > fin) return false;
    else {
        int m = (ini + fin) / 2;

        if (v[m] == m + num) {
            n = v[m];
            return true;
        }
        else {
            if (v[m] > m + num) return resolver(v, ini, m - 1, num, n);
            else return resolver(v, m + 1, fin, num, n);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, num;
    cin >> tam >> num;
    vector<int> v(tam);

    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }

    int n;
    bool sol = resolver(v, 0, tam - 1, num, n);

    // escribir sol
    if (!sol) cout << "NO" << "\n";
    else cout << n << "\n";
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
