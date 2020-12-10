// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
void vueltaAtras(vector<pair<int, int>>const& canciones, vector<bool>& marcas, const int n, const int t1, const int t2, 
    int tAct1, int tAct2, int satiAct, int & satiMax, int k, bool& exito) {
    for (int i = 0; i < n; i++) {
        bool elige = false;
        //marcar
        satiAct += canciones[i].second;
        if (tAct1 < t1) { tAct1 += canciones[i].first; elige = true; }
        else tAct2 += canciones[i].first;
        if (tAct1 <= t1 && tAct2 <= t2 && !marcas[i]) {//es valido
            marcas[i] = true;
            if (tAct1 == t1 && tAct2 == t2) {//es solucion
                if (satiAct > satiMax)
                    satiMax = satiAct;
                exito = true;
            }
            else
                vueltaAtras(canciones, marcas, n, t1, t2, tAct1, tAct2, satiAct, satiMax, k + 1, exito);
            marcas[i] = false;
        }
        //desmarcar
        satiAct -= canciones[i].second;
        if(elige)   tAct1 -= canciones[i].first;
        else tAct2 -= canciones[i].first;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de canciones
    int t1;//tiempo que dura el viaje de ida
    int t2;//tiempo que dura el viaje de vuelta
    cin >> n;
    if (n == 0)
        return false;
    cin >> t1 >> t2;

    vector<pair<int, int>>canciones(n);
    for (int i = 0; i < n; i++) {
        cin >> canciones[i].first >> canciones[i].second;
        /*
        int duracion, satisfaccion;
        cin >> duracion >> satisfaccion;
        canciones.push_back(make_pair(duracion,satisfaccion));
        */
    }

    vector<bool>marcas(n);//marca de canciones escuchadas
    for (int i = 0; i < n; i++) {
        marcas[i] = false;
    }

    bool exito = false;//si se ha encontrado la solucion
    int satiAct = 0;//satifaccion actual
    int satiMax = 0;//satifaccion maxima
    int tAct1 = 0;//tiempo actual de ida
    int tAct2 = 0;//tiempo actual de vuelta

    vueltaAtras(canciones, marcas, n, t1, t2, tAct1, tAct2, satiAct, satiMax, 0, exito);

    // escribir sol
    if (exito)
        cout << satiMax << endl;
    else
        cout << "Imposible" << endl;

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
