// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
bool resolver(vector<int>const& datos, int numElem, int pos) {
    if (pos == numElem - 1)
        return true;

    int maxi, mini;
    maxi = datos[0];
    mini = datos[pos + 1];
    for (int i = 0; i <= pos; i++) {
        if (maxi < datos[i])
            maxi = datos[i];
    }
    for (int j = pos + 1; j < numElem; j++) {
        if (mini > datos[j])
            mini = datos[j];
    }
    return maxi < mini;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElem, pos;
    cin >> numElem >> pos;

    vector<int>datos(numElem);

    for (int i = 0; i < numElem; i++) {
        cin >> datos[i];
    }

    bool sol = resolver(datos, numElem, pos);
    // escribir sol
    if (sol)
        cout << "SI";
    else
        cout << "NO";
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
