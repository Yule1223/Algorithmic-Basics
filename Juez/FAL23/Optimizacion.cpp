// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void superarSati(vector<vector<int>>const& sati, vector<int>& sol, int & maxSati) {
    int n = 0;//satifacion actual
    for (int i = 0; i < sol.size(); i++) {
        n += sati[i][sol[i]];
    }
    if (n > maxSati)
        maxSati = n;
}

// funci¨®n que resuelve el problema
void vueltaAtras(vector<int>& sol, vector<vector<int>>const& sati, vector<bool>& juguetes, 
    const int m, const int n, int k, int & maxSati) {
    for (int i = 0; i < m; i++) {
        sol[k] = i;
        if (!juguetes[i]) {//es valida
            //marcar
            juguetes[i] = true;
            if (k == (n - 1))//es solucion
                superarSati(sati, sol, maxSati);
            else
                vueltaAtras(sol, sati, juguetes, m, n, k + 1, maxSati);
            //desmarcar
            juguetes[i] = false;
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
    if (!cin)
        return false;

    //matriz de la satisfacion de cada nino con cada juguete
    vector<vector<int>>sati(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> sati[i][j];
    }

    vector<int>sol(n);//vector de salida
    int maxSati = 0;
    //vector para marcar si se ha asignado cada juguete
    vector<bool>juguetes(m);
    for (int i = 0; i < m; i++) {
        juguetes[i] = false;
    }

    vueltaAtras(sol, sati, juguetes, m, n, 0, maxSati);

    cout << maxSati << endl;

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
