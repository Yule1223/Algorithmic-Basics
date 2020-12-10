// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void escribirSol(vector<int>const& sol) {
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
}

bool esValida(vector<int>const& sol, vector<string>const& juguetes, int k) {
    if (k > 0 && k % 2 ==1 && (juguetes[sol[k]] <= juguetes[sol[k - 1]]))     return false;
    return true;
}

// funci¨®n que resuelve el problema
void vueltaAtras(vector<int>& sol, vector<string>const& juguetes, const int m, const int n, int k, bool& exito) {
    for (int i = 0; i < m; i++) {
        sol[k] = i;
        if (esValida(sol, juguetes, k)) {
            if (k == (2 * n - 1)) {//es solucion
                escribirSol(sol);
                exito = true;
            }
            else
                vueltaAtras(sol, juguetes, m, n, k+1, exito);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m;//numero de juguetes
    int n;//numero de ninos

    cin >> m >> n;
    if (!std::cin)
        return false;
    vector<string>juguetes(m);
    for (int i = 0; i < m; i++) {
        cin >> juguetes[i];
    }

    vector<int>sol(2 * n);//vector de salida
    bool exito = false;
    vueltaAtras(sol, juguetes, m, n, 0, exito);

    if (!exito)
        cout << "SIN SOLUCION" << endl;
    cout << endl;

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
