// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
void resolver(vector<int>const& datos, const int n, int& suma, int& dia, int& l) {
    int sumaAux = 0;
    int diaAux = 0;
    int lAux = 0;
    for (int i = 0; i < n; i++) {
        sumaAux += datos[i];
        if (sumaAux > 0) {//es bueno
            lAux++;
            if (sumaAux > suma || (sumaAux == suma && lAux < l)) {
                suma = sumaAux;
                dia = diaAux;
                l = lAux;
            }
        }
        else {
            sumaAux = 0;
            if (i < n)
                diaAux = i + 1;
            else
                diaAux = i;
            lAux = 0;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de elementos
    cin >> n;
    if (!cin)
        return false;

    vector<int>datos(n);
    for (int i = 0; i < n; i++) {
        cin >> datos[i];
    }
    int suma = 0;//la suma de subsecuencia
    int dia = 0;//dia que comienza la subsecuencia
    int l = 0;//longitud de la subsecuencia

    resolver(datos, n, suma, dia, l);

    // escribir sol
    cout << suma << " " << dia << " " << l << endl;

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
