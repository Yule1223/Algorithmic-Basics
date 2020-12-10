// E81
// Yule Zhang

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//funcion para calcular el numero de ceros de una columna
//coste lineal O(n) siendo n = columna.size()
int calcularCeros(vector<int>const& columna) {
    int ceros = 0;
    for (int i = 0; i < columna.size(); i++) {
        if (columna[i] == 0)
            ceros++;
    }
    return ceros;
}

//si la columna contiene mas de x ceros
//coste lineal por la funcion calcularCeros, y la comparacion es del coste constante
//por lo tanto, esta funcion es del coste lineal
bool columnaValida(vector<int>const& columna, const int x) {
    return calcularCeros(columna) >= x;
}

//funcion para sacar la columna que queremos desde la matriz
//coste lineal O(n) siendo n es el numero de filas de la matriz
vector<int> sacaColumna(vector<vector<int>>const& matriz, int j) {
    vector<int>columna(matriz.size());
    for (int i = 0; i < matriz.size(); i++) {
        columna[i] = matriz[i][j];
    }
    return columna;
}

// funcion que resuelve el problema
int resolver(vector<vector<int>>const& matriz, const int k, const int y, const int x) {
    int sol = 0;
    int yAux = 0;
    for (int l = k; l <= matriz[0].size(); l++) {
        for (int j = 0; j < k; j++) {
            auto columna = sacaColumna(matriz, l-k+j);//O(n)
            if (columnaValida(columna, x)) {
                yAux++;
            }
        }
        if (yAux >= y) {
            sol++;
        }
        yAux = 0;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//filas
    int m;//columnas
    int k;//ancho
    int y;//sub-ancho
    int x;//ceros

    cin >> n;
    if (!cin)
        return false;
    cin >> m >> k >> y >> x;
    //crear la matriz
    vector<vector<int>>matriz(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matriz[i][j];
        }
    }
    
    int sol = resolver(matriz, k, y, x);

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
