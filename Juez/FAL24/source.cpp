// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(vector<int>const& sol, const int k, vector<int>const&colores, const int lucesTotal, const int i, const int n) {
    //si hay dos bombillas consecutivas que tengan el mismo color
    if (k > 1 && sol[k] == sol[k - 1] && sol[k - 1] == sol[k - 2] )   return false;
    //la suma de un color no supera en mas de una unidad la suma de las luces de los demas
    if (colores[i] > lucesTotal - colores[i] + 1)   return false;
    return true;
}

// funci¨®n que resuelve el problema
void vueltaAtras(vector<int>& sol, vector<int>const &bombillas, vector<int>&colores, int & lucesTotal,
    const int l, const int n, const int c, int& act, int & nSol, int k) {
    for (int i = 0; i < n; i++) {
        sol[k] = i;
        //marcar
        act += bombillas[i];//suma el consumo al actual
        colores[i]++;
        lucesTotal++;
        if (esValida(sol, k, colores, lucesTotal, i, n) && act <= c) {
            if (k == l - 1) {//es solucion
                nSol++;
            }
            else
                vueltaAtras(sol, bombillas, colores, lucesTotal, l, n, c, act, nSol, k+1);
        }
        //desmarcar
        act -= bombillas[i];
        colores[i]--;
        lucesTotal--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int l;//longitud de la linea de luces
    int n;//numero de colores
    int c;//consumo maximo
    cin >> l;
    if (l == 0)
        return false;
    cin >> n >> c;

    //vector del consumo de cada tipo de bombilla
    vector<int>bombillas(n);
    for (int i = 0; i < n; i++) {
        cin >> bombillas[i];
    }

    int nSol = 0;
    int act = 0;//consumo actual
    int lucesTotal = 0;
    vector<int>sol(l);
    vector<int>colores(n);//vector para guardar el numero de bombillas de cada color
    for (int i = 0; i < n; i++) {
        colores[i] = 0;//iniciar a 0
    }

    vueltaAtras(sol, bombillas, colores, lucesTotal, l, n, c, act, nSol, 0);

    // escribir sol
    cout << nSol << endl;

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
