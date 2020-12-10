//Yule Zhang
//E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// T(n) = C0 (n=1)
// T(n) = C1 (n=2)
// T(n) = 2T(n/2) + C2(n>=4)
// El coste es del orden lineal, O(n)
// Siendo n es el numero de elementos

bool resolver(vector<int> const& v, int ini, int fin, int& cont) {
    if (ini + 1 == fin) { //Si solo hay un elemento
        cont = 0;
        return true;
    }
    else if (ini + 2 == fin) { //Si hay dos elementos
        if ((v[ini] % 2 == 0) && (v[fin - 1] % 2 == 0)) cont = 2; //Si los dos son pares
        else if ((v[ini] % 2 == 0) || (v[fin - 1] % 2 == 0)) cont = 1; //Si solo uno es par
        else cont = 0; //Si ninguno es par
        return true;
    }
    else {
        int m = (ini + fin) / 2;
        int contIz, contDe;
        bool okIz, okDe;
        okIz = resolver(v, ini, m, contIz);//Lado izqierdo
        okDe = resolver(v, m, fin, contDe);//Lado derecho
        if (okIz && okDe && (abs(contIz - contDe) <= 2)) {
            cont = contIz + contDe;
            return true;
        }
        else return false;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    if (num == 0) return false;

    vector<int> v(num);

    for (int i = 0; i < num; ++i)
        cin >> v[i];

    // escribir sol
    int cont = 0;

    if (resolver(v, 0, num, cont)) cout << "SI" << "\n";
    else cout << "NO" << "\n";

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
