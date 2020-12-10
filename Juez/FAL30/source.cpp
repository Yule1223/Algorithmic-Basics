// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
void resolver(vector<int>& datos, int numElem, int& puntero) {
    for (int i = 0; i < numElem; i++) {
        if (datos[i] % 2 == 0) {
            datos[puntero] = datos[i];
            puntero++;
        }
    }
    datos.resize(puntero);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElem;
    cin >> numElem;
    vector<int>datos(numElem);

    for (int i = 0; i < numElem; i++) {
        cin >> datos[i];
    }

    int puntero = 0;
    resolver(datos, numElem, puntero);
    // escribir sol
    for (int i = 0; i < puntero; i++) {
        cout << datos[i] << " ";
    }
    cout << "\n";

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
