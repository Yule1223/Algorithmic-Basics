// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// funci¨®n que resuelve el problema
void vueltaAtras(vector<vector<int>>const &datos, vector<bool>& trabajos, const int n, int & act, int & min, int k) {
    for (int i = 0; i < n; i++) {
        //marcar
        act += datos[k][i];
        if (!trabajos[i]) {//es valida
            trabajos[i] = true;
            if (k == n - 1) {//es solucion
                if (act < min || min == -1)
                    min = act;
            }
            else
                vueltaAtras(datos, trabajos, n, act, min, k + 1);
            trabajos[i] = false;
        }
        //desmarcar
        act -= datos[k][i];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de funcionarios y trabajos
    cin >> n;
    if (n == 0)
        return false;
    
    vector<vector<int>>datos(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> datos[i][j];
        }
    }

    //marca para los trabajos
    vector<bool>trabajos(n);
    for (int i = 0; i < n; i++) {
        trabajos[i] = false;
    }

    int min = -1;//tiempo minimo
    int act = 0;//tiempo actual
    vueltaAtras(datos, trabajos, n, act, min, 0);

    // escribir sol
    cout << min << endl;

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
