// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

bool esValida(vector<int>const& sol, const int k) {
    if (k > 0 && sol[k] == sol[k - 1]) return false;
    return true;
}

// funci¨®n que resuelve el problema
void vueltaAtras(vector<int>& sol, vector<vector<int>>const &datos, vector<int>& alumnos, const int n, const int a,
    const int t, int & prefMax, int & prefAct, int k) {
    for (int i = 0; i < a; i++) {
        sol[k] = i;
        //marcar
        alumnos[i]++;
        prefAct += datos[i][k/2];
        if (esValida(sol, k) && alumnos[i] <= t) {//es valida
            if (k == (2 * n - 1)) {//es solucion
                if (prefAct > prefMax)
                    prefMax = prefAct;
            }
            else
                vueltaAtras(sol, datos, alumnos, n, a, t, prefMax, prefAct, k + 1);
        }
        //desmarcar
        alumnos[i]--;
        prefAct -= datos[i][k/2];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de tareas
    int a;//numero de alumnos
    int t;//numero maximo de tareas
    cin >> n;
    if (n == 0)
        return false;
    cin >> a >> t;

    vector<vector<int>>datos(a, vector<int>(n));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < n; j++) {
            cin >> datos[i][j];
        }
    }

    int prefMax = 0;
    int prefAct = 0;
    vector<int>alumnos(a);//vector para guardar numero de puestos que ocupa cada alumno
    for (int i = 0; i < a; i++) {
        alumnos[i] = 0;//inicializar a 0
    }
    vector<int>sol(2 * n);
    vueltaAtras(sol, datos, alumnos, n, a, t, prefMax, prefAct, 0);

    // escribir sol
    cout << prefMax << endl;
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
