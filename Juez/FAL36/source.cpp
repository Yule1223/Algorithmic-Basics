// E81
// Yule Zhang

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct edificio {
    string nombre;//nombre del dificio
    int altura;//altura del edificio
    int pisoAlto;//el piso mas alto que se alquila del edificio
};

bool tieneVistas(vector<edificio>const& datos, int i, int maxi) {
    
    bool ok = true;
    if (datos[i].pisoAlto < 0) {
        return false;
    }
    else {
        ok = datos[i].pisoAlto > maxi;
    }
    return ok;
}

// funcion que resuelve el problema
void resolver(vector<edificio>const& datos, const int n, vector<string>& sol) {
    //empezamos desde la costa del mar
    int maxi = datos[n-1].altura;
    for (int i = n - 1; i >= 0; i--) {
        if (i == datos.size() - 1 && datos[i].pisoAlto != -1){//el edificio mas cerca al mar
            sol.push_back(datos[i].nombre);
        }
        else if(tieneVistas(datos, i, maxi)) {
            sol.push_back(datos[i].nombre);
        }
        if (datos[i].altura > maxi)
            maxi = datos[i].altura;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de edificios
    cin >> n;
    if (n == 0)
        return false;

    vector<edificio>datos(n);
    for (int i = 0; i < n; i++) {
        cin >> datos[i].nombre >> datos[i].altura >> datos[i].pisoAlto;
    }

    vector<string>sol;
    resolver(datos, n, sol);

    // escribir sol
    if (sol.size() == 0)
        cout << "Ninguno" << endl;
    else {
        cout << sol.size() << endl;
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << " ";
        }
        cout << endl;
    }
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
