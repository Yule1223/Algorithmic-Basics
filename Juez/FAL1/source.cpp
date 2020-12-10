// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

//T(n) = C1 (Si n == 1);
//T(n) = 2T(n/2) + C2 (Si n > 1);
//Se obtiene un coste O(n) siendo n el numero de elementos del vector.

// Funcion que resuelve el problema
// v.size() es potencia de dos
bool sufDisperso(vector<int> const& v, int ini, int fin, int K) {
    if (ini + 1 == fin)// Un elemento 
        return true;
    else { // Vector de 2 o mas elementos
        int m = (ini + fin) / 2;
        bool sIz = sufDisperso(v, ini, m, K);
        bool sDr = sufDisperso(v, m, fin, K);
        return sIz && sDr && K <= abs(v[ini] - v[fin - 1]);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la 
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
    int num;
    cin >> num;
    if (!cin) 
        return false;
    int K;
    cin >> K;
    vector<int> v(num);
    for (int& n : v) 
        cin >> n;
    if (sufDisperso(v, 0, v.size(), K))
        cout << "SI" << endl; 
    else
        cout << "NO" <<endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
