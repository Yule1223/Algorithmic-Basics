//Yule Zhang
//E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tDatos {
    vector<int> tiposAbrigos;
    vector<int> probPrecipitacion;
};

// funci¨®n que resuelve el problema
bool esValida(int k, int i, tDatos const& datos, vector<int> const& sol, vector<int> const& marcas) {
    // El abrigo soporta la cantidad de lluvia que va a caer
    if (datos.tiposAbrigos[i] < datos.probPrecipitacion[k]) return false;

    // No llevo dos dias seguidos el mismo abrigo
    if (k > 0 && sol[k] == sol[k - 1]) return false;

    // No me pongo un abrigo muchos mas dias que otro
    if (marcas[i] > k / 3 + 2) return false;

    return true;
}

// datos - datos entrada. probabilidad precipitacion y lluvia que aguanta cada abrigo.
// k - etapa
// sol - abrigo que me pondre cada dia.
// marcas: dias que me he puesto cada abrigo.

int abrigos(tDatos const& datos, int k, vector<int>& sol, vector<int>& marcas) {
    int numSoluciones = 0; // numero de soluciones diferentes encontradas
    for (int i = 0; i < datos.tiposAbrigos.size(); ++i) {
        sol[k] = i;
        // marcar
        ++marcas[i];
        if (esValida(k, i, datos, sol, marcas)) { // es valida
            if (k == datos.probPrecipitacion.size() - 1) { // es solucion
                if (sol[0] != sol[k])// El primer abrigo no coincide con el ultimo
                    ++numSoluciones;
            }
            else {
                numSoluciones += abrigos(datos, k + 1, sol, marcas);
            }
        }
        // desmarcar
        --marcas[i];
    }
    return numSoluciones;
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int d, a;
    cin >> d>> a;
    if (d == 0 && a == 0) return false;

    tDatos datos;
    for (int i = 0; i < d; i++) {
        cin >> datos.probPrecipitacion[i];
    }
    for (int j = 0; j < a; j++) {
        cin >> datos.tiposAbrigos[j];
    }

    int k = 0;
    vector<int> sol(d);
    vector<int> marcas(a);
    int numSoluciones = abrigos(datos, k, sol, marcas);

    // Escribir resultado
    if (numSoluciones == 0)
        cout << "Lo puedes comprar" << endl;
    else 
        cout << numSoluciones << endl;
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
