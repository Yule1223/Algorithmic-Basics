// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const int NUMERO_COLORES = 3;
const int AZUL = 0;
const int ROJO = 1;
const int VERDE = 2;

void escribirSol(vector<int>const & sol) {
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i] == AZUL)
            cout << "azul ";
        else if (sol[i] == ROJO)
            cout << "rojo ";
        else
            cout << "verde ";
    }
    cout << endl;
}

bool esValida(vector<int>const& sol, vector<int>const& colores, const int a, const int r, const int v, int k) {
    if (colores[0] > a || colores[1] > r || colores[2] > v) return false;
    //no hay dos verdes consecutivos
    if (k > 0 && (sol[k] == VERDE && sol[k - 1] == VERDE))   return false;
    //verde no supera a azul
    if (colores[2] > colores[0]) return false;
    //primera pieza es roja
    if (k == 0 && sol[k] != ROJO) return false;
    return true;
}

// funci¨®n que resuelve el problema
void vueltaAtras(vector<int>& sol, int altura, const int a, const int r, const int v, vector<int>& colores, int k, bool& exito) {
    for (int i = 0; i < NUMERO_COLORES; i++) {
        sol[k] = i;
        //marcar
        colores[i]++;
        if (esValida(sol, colores, a, r, v, k)) {
            if (k == altura - 1) {//es solucion
                if (colores[1] > (colores[2] + colores[0])) {//piezas de rojo mayor que verde y azul
                    escribirSol(sol);
                    exito = true;
                }
            }
            else
                vueltaAtras(sol, altura, a, r, v, colores, k + 1, exito);
        }
        //desmarcar
        colores[i]--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int altura, a, r, v;
    vector<int>colores(3);//vector para guardar el numero de tubos de los colores
    //v[0] -> azul
    //v[1] -> rojo
    //v[2] -> verde
    cin >> altura >> a >> r>> v;
    
    if (altura ==0 && a == 0 && r == 0 && v == 0)
        return false;
    for (int i = 0; i < colores.size(); i++) {
        colores[i] = 0;//inicializar a -1
    }

    vector<int>sol(altura);
    bool exito = false;
    vueltaAtras(sol, altura, a, r, v, colores, 0, exito);
    if (!exito)
        cout << "SIN SOLUCION" << endl;
    cout << endl;
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
