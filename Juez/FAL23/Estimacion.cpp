// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// funci¨®n que resuelve el problema
void vueltaAtras(vector<vector<int>>const& sati, vector<bool>& juguetes, vector<int>const& acum,
    const int m, const int n, int k, int & satiAct, int & maxSati) {
    for (int i = 0; i < m; i++) {
        satiAct += sati[k][i];
        if (!juguetes[i]) {//es valida
            //marcar
            juguetes[i] = true;
            if (k == (n - 1)) {//es solucion
                if (satiAct > maxSati) 
                    maxSati = satiAct;
            }
            else {
                if(satiAct + acum[k+1] > maxSati)
                    vueltaAtras(sati, juguetes, acum, m, n, k + 1, satiAct, maxSati);
            }
            //desmarcar
            juguetes[i] = false;
        }
        satiAct -= sati[k][i];
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

    //acum
    vector<int> acum(n);
    for (int i = 0; i < n; i++) {
        int maxSati = 0;
        for (int j = 0; j < m; j++)
            if (maxSati < sati[i][j]) maxSati = sati[i][j];
        acum[i] = maxSati;
    }
    // Vector acumulados
    for (int i = n - 1; i > 0; i--) {
        acum[i - 1] += acum[i];
    }

    int maxSati = 0;
    int satiAct = 0;
    //vector para marcar si se ha asignado cada juguete
    vector<bool>juguetes(m);
    for (int i = 0; i < m; i++) {
        juguetes[i] = false;
    }

    vueltaAtras(sati, juguetes, acum, m, n, 0, satiAct, maxSati);

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
