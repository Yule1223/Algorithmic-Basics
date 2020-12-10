// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
int combinatorio(int a, int b, vector<vector<int>>& matriz) {
    if (b == 0 || a == b) { 
        matriz[a][b] = 1;
        return 1; 
    }
    else if (b == 1) {
        matriz[a][b] = a;
        return a;
    }
    else {
        if (matriz[a - 1][b - 1] == -1)
            matriz[a - 1][b - 1] = combinatorio(a - 1, b - 1, matriz);
        if (matriz[a - 1][b] == -1)
            matriz[a - 1][b] = combinatorio(a - 1, b, matriz);
        return
            matriz[a - 1][b - 1] + matriz[a - 1][b];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a, b;
    cin >> a >> b;
    if (!cin)
        return false;
    //crear la matriz inicializada a -1
    vector<vector<int>> matriz(a + 1, vector<int>(b + 1));
    for (int i = 0; i < a + 1; i++) {
        for (int j = 0; j < b + 1; j++) {
            matriz[i][j] = -1;
        }
    }

    auto sol = combinatorio(a, b, matriz);

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
