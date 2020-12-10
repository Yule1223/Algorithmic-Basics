// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
// El coste de la funcion es lineal
void resolver(vector<int>const& datos, const int n, const int m, int& pos, int& ganancia) {
    int g, j, k;
    for (int i = 0; i < (n - m + 1); i++) {
        g = 0;//ganancia actual
        j = i;
        k = j + m;
        while (j < k) {
            g += datos[j];
            j++;
        }
        if (g >= ganancia) {
            pos = i;
            ganancia = g;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de vagones del tren
    int m;//numero de vagones a asaltar

    cin >> n >> m;

    vector<int>datos(n);

    for (int i = 0; i < n; i++) {
        cin >> datos[i];
    }

    int pos = 0;//numero del vagon en el que debemos empezar el asalto
    int ganancia = 0;
    resolver(datos, n, m, pos, ganancia);
    // escribir sol
    cout << pos << " " << ganancia << endl;

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
