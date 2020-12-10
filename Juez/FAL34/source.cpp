// E81
// Yule Zhang

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
void resolver(vector<int>const& datos, const int n, int& l, int& v, int& f) {
    int laux = 0;//longitud actual
    bool enc = false;
    for (int i = 0; i < n; i++) {
        if (datos[i] > 0) {
            enc = true;
            laux++;
            if (i == n - 1) {
                if (laux > l) {
                    l = laux;
                    v = 1;
                    f = 0;
                }
                else if (laux == l) {
                    v++;
                    f = 0;
                }
            }
        }
        else {
            if (laux > l) {
                f = n - i;
                l = laux;
                v = 1;
            }
            else if (laux == l && l != 0) {
                v++;
                f = n - i;
            }
            laux = 0;
        }
    }
    if (!enc)
        f = n;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de partidos
    cin >> n;
    if (!cin)
        return false;

    vector<int>datos(n);
    for (int i = 0; i < n; i++) {
        cin >> datos[i];
    }

    int l = 0, v = 0, f = 0;
    //l -> numero maximo de partidos seguidos ganados
    //v -> numero de veces que se ha ganado l
    //f -> numero de partidos jugados desde que finalizo la ultima racha ganadora
    resolver(datos, n, l, v, f);

    // escribir sol
    cout << l << " " << v << " " << f << endl;
   
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
