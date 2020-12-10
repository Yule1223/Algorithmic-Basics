// Yule Zhang
// E81

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// funci¨®n que resuelve el problema
void vueltaAtras(vector<vector<int>>const& matriz, vector<int>& sol, vector<bool>& marcas, vector<int>const& acum, const int n, 
    int& precioMin, int precioAct, int k){
    for (int i = 1; i < n; i++) {
        sol[k] = i;
        //marcar
        precioAct += matriz[sol[k - 1]][i];
        if (!marcas[i]) {//es valido
            marcas[i] = true;
            if (k == n - 1) {//es solucion
                if (precioAct + matriz[i][0] < precioMin)
                    precioMin = precioAct + matriz[i][0];
            }
            else {
                if (acum[k + 1] + precioAct < precioMin)
                    vueltaAtras(matriz, sol, marcas, acum, n, precioMin, precioAct, k + 1);
            }
            marcas[i] = false;
        }
        //desmarcar
        precioAct -= matriz[sol[k - 1]][i];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci¨®n, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;//numero de ciudades
    cin >> n;
    if (n == 0)
        return false;
    vector<vector<int>>matriz(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    vector<bool>marcas(n);//vector de marcas de ciudades visitadas
    for (int i = 0; i < n; i++) {
        marcas[i] = false;
    }

    //acum
    vector<int>acum(n);
    for (int i = 0; i < n; i++) {
        int min = matriz[i][0];
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] < min)  min = matriz[i][j];
        }
    }

    //vector acum
    for (int i = n - 1; i > 0; i--) {
        acum[i - 1] += acum[i];
    }

    int precioMin = 0;//precio mas barato
    int precioAct = 0;//precio actual
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            precioMin += matriz[i][j];
        }
    }
  
    vector<int>sol(n);
    sol[0] = 0;

    vueltaAtras(matriz, sol, marcas, acum, n, precioMin, precioAct, 1);
    // escribir sol
    cout << precioMin << endl;

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
