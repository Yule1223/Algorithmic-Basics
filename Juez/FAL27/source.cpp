// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct objeto {
    int coste;
    int superficie;
};

bool comparador(objeto o1, objeto o2) {
     return (((float)o1.superficie/o1.coste) > ((float)o2.superficie/o2.coste));
}

int inicializarSuperficie(vector<objeto>const& datos, int presupuesto) {
    int i = 0; int sumaSuperficie = 0; int sumaCoste = 0;
    while (i < datos.size() && sumaCoste + datos[i].coste <= presupuesto) {
        sumaSuperficie += datos[i].superficie;
        sumaCoste += datos[i].coste;
        ++i;
    }
    return sumaSuperficie;
}

// funci¨®n que resuelve el problema
void vueltaAtras(vector<objeto>const& datos, vector<bool>& marcas, const int n, const int presupuesto, int actPre,
    int & maxSup, int actSup, int k) {
    for (int i = 0; i < n; i++) {
        //marcar
        actPre += datos[i].coste;
        actSup += datos[i].superficie;
        if (!marcas[i] && actPre <= presupuesto) {//es valido -> el objeto no se ha usado
            //marcar
            marcas[i] = true;
            if (actSup > maxSup)
                maxSup = actSup;
            if(k < n - 1) {
                vueltaAtras(datos, marcas, n, presupuesto, actPre, maxSup, actSup, k + 1);
            }
            //desmarcar
            marcas[i] = false;
        }
        //desmarcar
        actPre -= datos[i].coste;
        actSup -= datos[i].superficie;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de objetos
    int presupuesto;
    cin >> n;
    if (!cin)
        return false;
    cin >> presupuesto;

    vector<objeto>datos(n);
    for (int i = 0; i < n; i++) {
        cin >> datos[i].coste >> datos[i].superficie;
    }

    // ordena los datos por superficie por unidad de coste
    sort(datos.begin(), datos.end(), comparador);
    int maxSup = inicializarSuperficie(datos, presupuesto);

    int actSup = 0;//la superficie actual
    int actPre = 0;//el presupuesto actual
    vector<bool>marcas(n);
    for (int i = 0; i < n; i++) {
        marcas[i] = false;
    }

    vueltaAtras(datos, marcas, n, presupuesto, actPre, maxSup, actSup, 0);

    // escribir sol
    cout << maxSup << endl;

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
