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

bool superarSati(const int minSati, vector<vector<int>>const& sati, vector<int>& sol, const int n) {
    bool ok = true;
    int i = 0;
    while (i < (2* n -1) && ok) {
        int n = sati[i / 2][sol[i]] + sati[i / 2][sol[i + 1]];
        ok = (n >= minSati);
        i += 2;
    }
    return ok;
}

// funci¨®n que resuelve el problema
void vueltaAtras(vector<int>& sol, vector<string>const& juguetes, const int minSati, vector<int>const & disponibles, 
    vector<int>&contJ, vector<vector<int>>const & sati, const int m, const int n, int k, bool& exito) {
    for (int i = 0; i < m; i++) {
        sol[k] = i;
        //marcar
        contJ[i]++;
        if (esValida(sol, juguetes, k) && contJ[i] <= disponibles[i]) {
            if (k == (2 * n - 1)) {//es solucion
                if (superarSati(minSati, sati, sol, n)) {
                    escribirSol(sol);
                    exito = true;
                }
            }
            else
                vueltaAtras(sol, juguetes, minSati, disponibles, contJ, sati, m, n, k+1, exito);
        }
        //desmarcar
        contJ[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m;//numero de juguetes
    int n;//numero de ninos
    int minSati;//la minima satisfacion
    cin >> m;
    if (!cin)
        return false;
    cin >> n >> minSati;

    //vector de unidades disponibles de cada juguete
    vector<int>disponibles(m);
    for (int j = 0; j < m; j++) {
        cin >> disponibles[j];
    }

    //vector del tipo de cada juguete
    vector<string>juguetes(m);
    for (int i = 0; i < m; i++) {
        cin >> juguetes[i];
    }

    //matriz de la satisfacion de cada nino con cada juguete
    vector<vector<int>>sati(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> sati[i][j];
    }

    vector<int>sol(2 * n);//vector de salida
    bool exito = false;

    //vector para guardar el numero actual de cada juguete
    vector<int>contJ(m);

    vueltaAtras(sol, juguetes, minSati, disponibles, contJ, sati, m, n, 0, exito);

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
