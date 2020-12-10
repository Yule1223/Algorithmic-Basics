// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
// El coste de la funcion es lineal
void resolver(vector<int>const& datos, const int n, const int t, int& ini, int& fin) {
    int l = 0;//longitud actual
    int lmax = 0;//longitud max
   
    for (int i = 0; i < n; i++) {
        if (datos[i] > t) {
            l++;
            if (i == n - 1 && l > lmax) {
                fin = i;
                ini = i - l + 1;
            }
        }
        else {
            if (l > lmax) {
                fin = i - 1;
                ini = i - l;
                lmax = l;
            }
            l = 0;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de edificios
    int t;//altura de transporte

    cin >> n >> t;

    vector<int>datos(n);

    for (int i = 0; i < n; i++) {
        cin >> datos[i];
    }

    int ini = 0;//comienzo del intervalo
    int fin = 0;//final del intervalo
    resolver(datos, n, t, ini, fin);
    // escribir sol
    cout << ini << " " << fin << endl;

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
