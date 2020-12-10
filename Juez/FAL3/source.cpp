//Yule Zhang
//E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// En el caso peor el coste sera O(n) --> n siendo numero de elementos del vector

bool resolver(vector<int> const& v, int ini, int fin, int & min, int & max) {

    if (ini + 1 == fin) return true; // Si hay solo un elemento

    // Comprobar cuando solo hay dos elementos, es decir, vamos avanzando en la recursi車n
    // y cuando llegamos a dividir uno de los lados hasta que solo quedan dos elementos
    // se comprueba la condici車n impuesta en el ejercicio y guardamos el maximo y minimo
    // parcialmente:
    else if (ini + 2 == fin) {
        if (v[ini] <= v[fin-1]) {
            min = v[ini];
            max = v[fin-1];
            return true;
        }
        else return false;
    }

    else {
        int m = (ini + fin) / 2; // Sacamos la mitad
        int maxI, minI, maxD, minD;
        // Consegimos el maximo y minimo del lado izquierdo:
        bool ladoIzq = resolver(v, ini, m, minI, maxI);
        // Consegimos el maximo y minimo del lado derecho:
        bool ladoDer = resolver(v, m, fin, minD, maxD);

        if (ladoIzq && ladoDer && maxI <= maxD && minI <= minD) {
            // Vamos actualizando el maximo y minimo en cada llamada recursiva si
            // cumple la condici車n pedida:
            max = maxD;
            min = minI;
            return true;
        }
        else return false;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci車n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (num == 0) 
        return false;

    vector<int> v;

    while (num != 0) {
        v.push_back(num);
        cin >> num;
    }

    int min, max;
    bool sol = resolver(v, 0, v.size(), min, max);

    // escribir sol
    if (sol) 
        cout << "SI";
    else 
        cout << "NO";
    cout << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    //save old buf and redirect std::cin to datos.txt:
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

