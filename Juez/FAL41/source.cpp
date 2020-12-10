// E81
// Yule Zhang

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// funcion que resuelve el problema
// El coste es (n-p+1)*(n-p+1)*p*p = n^2
int resolver(vector<vector<int>>const& matriz, const int p) {
    int solMax = 0;
    for (int m = p; m <= matriz.size(); m++) {
        for (int n = p; n <= matriz[0].size(); n++) {
            int sol = 0;
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    sol += matriz[m-p+i][n-p+j];
                }
            }
            if (sol > solMax)
                solMax = sol;
        }
    }
    return solMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int p;
    cin >> n;
    if (!cin)
        return false;
    cin >> p;
    //crear la matriz
    vector<vector<int>>matriz(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    int sol = resolver(matriz, p);

    // escribir sol
    cout << sol << endl;
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
