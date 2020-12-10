// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct sol {
    int numero;
    int pot;//la potencia de 10
};

// funci¨®n que resuelve el problema
sol resolver(int num) {
    if (num == 0) {
        sol s;
        s.numero = 0;
        s.pot = 1;
        return s;
    }
    else {
        sol s = resolver(num / 10);
        sol p;
        p.numero = s.numero + (num % 10 * s.pot);
        p.pot = s.pot * 10;
        return p;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (num == 0)
        return false;

    auto sol = resolver(num);

    // escribir sol
    cout << sol.numero << endl;

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
