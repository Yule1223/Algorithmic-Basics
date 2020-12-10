// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
//El coste es T(n) = T(n/2) + C; O(log(n))

// funci¨®n que resuelve el problema
bool resolver(vector<int>const & v, vector<int>const& w, int ini, int fin, int & pos) {
     if (ini >= fin) {//si solo hay un elemento
         if (v[ini] < w[ini]) { 
             if (ini != (int)(v.size() - 1)) {
                 if (v[ini + 1] > w[ini + 1]) {
                     pos = ini;
                     return false;
                 }
                 else {
                     pos = ini + 1;
                     return v[ini + 1] == w[ini + 1];
                 }
             }
             else {
                 pos = ini;
                 return false;
             }
         }
         else if (v[ini] == w[ini]) { 
             pos = ini;
             return true; 
         }
         else { 
             pos = ini - 1;
             return false; 
         }
     }
     else {
         int m = (ini + fin) / 2;
         if (v[m] == w[m]) { 
             pos = m; 
             return true; 
         }
         else if (v[m] < w[m]) {
             return resolver(v, w, m + 1, fin, pos);
         }
         else {
             return resolver(v, w, ini, m, pos);
         }
     }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nElems;
    cin >> nElems;

    if (nElems == 0)
        return false;

    //crear los dos vectores
    vector<int>v(nElems);
    for (int i = 0; i < nElems; i++) {
        cin >> v[i];
    }

    vector<int>w(nElems);
    for (int j = 0; j < nElems; j++) {
        cin >> w[j];
    }
    int pos = -1;
    auto sol = resolver(v, w, 0, nElems-1, pos);

    // escribir sol
    if (sol)
        cout << "SI " << pos << endl;
    else
        cout << "NO " << pos <<" "<< pos + 1 << endl;

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
