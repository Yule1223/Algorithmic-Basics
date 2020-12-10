// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//El coste es del O(n), siendo n el nemro de digitos que tiene el numero
//Recursion simpre por cada cifra del numero
int inverso(int num, int pot) {
    if (pot == 0 && num < 10) return 9 - num;
    else if (num == 0) return pot;
    else return inverso(num / 10, pot * 10 + (9 - (num % 10)));
}

// funci¨®n que resuelve el problema
int complementario(int num) {
    if (num / 10 == 0)   return 9 - num;
    else return complementario(num / 10) * 10 + (9 - (num % 10));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;

    auto sol = complementario(num);
    auto insol = inverso(num, 0);
    // escribir sol
    cout << sol << " " << insol << endl;

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
