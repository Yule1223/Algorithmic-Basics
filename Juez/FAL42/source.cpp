// E81
// Yule Zhang

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// funcion que resuelve el problema
// coste lineal O(n) siendo n es el numero de elementos del array datos
// porque recorremos una vez cada elemento del array
bool resolver(vector<int>const& datos, const int l, int& pos) {
    int maxCeros = 0;
    //cogemos los l numeros primeros
    for (int i = 0; i < l; i++) {
        if (datos[i] == 0)
            maxCeros++;
    }
    //vamos comparando...
    int cerosAct = maxCeros;
    for (int i = l; i < datos.size(); i++) {
        if (datos[i] == 0 && datos[i-l] != 0) {
            cerosAct++;
        }
        else if (datos[i] != 0 && datos[i - l] == 0) {
            cerosAct--;
        }
        if (cerosAct >= maxCeros) {
            maxCeros = cerosAct;
            pos = i - l + 1;
        }
    }
    return maxCeros != 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int m;//metros de la valla
    int l;//longitud metalica
    cin >> m;
    if (m == 0)
        return false;
    cin >> l;
    
    vector<int>datos(m);
    for (int i = 0; i < datos.size(); i++) {
        cin >> datos[i];
    }
    //0 -> danado
    //1 -> buen estado
    int pos = 0;
    bool sol = resolver(datos, l, pos);
    if (sol)
        cout << pos << endl;
    else
        cout << "No hace falta" << endl;

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
