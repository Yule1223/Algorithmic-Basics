// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct tPersonas {
    string nombre;
    int numC;
};

// funci¨®n que resuelve el problema
tPersonas resolver(vector<tPersonas>const& v, int ini, int fin) {
    tPersonas ganadorIz, ganadorDe;
    /*
    if(ini + 1 == fin)//Si solo hay un chico
        return{v[ini].nombre,v[ini].numC};
    */
    if (ini + 2 == fin) {//Si solo hay dos chicos
        if (v[ini].numC >= v[fin - 1].numC)
            return{ v[ini].nombre,v[ini].numC + v[fin - 1].numC / 2 };
        else
            return{ v[fin - 1].nombre,v[fin - 1].numC + v[ini].numC / 2 };
    }

    else {//Si hay mas de dos chicos
        int m = (ini + fin) / 2;

        ganadorIz = resolver(v, ini, m);//LADO IZQUIERDO
        ganadorDe = resolver(v, m, fin);//LADO DERECHO

        if (ganadorIz.numC >= ganadorDe.numC)
            return{ ganadorIz.nombre, ganadorIz.numC + ganadorDe.numC / 2 };
        else
            return{ ganadorDe.nombre, ganadorDe.numC + ganadorIz.numC / 2 };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    cin >> num;
    if (!cin)
        return false;

    vector<tPersonas>v(num);

    for (int i = 0; i < v.size(); i++) {
        cin >> v[i].nombre;
        cin >> v[i].numC;
    }

    tPersonas gana = resolver(v, 0, num);

    // escribir sol
    cout << gana.nombre << " " << gana.numC << "\n";

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