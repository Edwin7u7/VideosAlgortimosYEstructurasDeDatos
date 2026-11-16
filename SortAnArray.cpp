//A00842140 Edwin Arturo Salgado Santana
//12/10/2026
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> auxiliar(nums.size()); // Arreglo auxiliar, se crea una sola vez

        mergeSplit(nums, auxiliar, 0, nums.size() - 1);

        return nums;
    }

private:
    // Copia el resultado ordenado del auxiliar de regreso al arreglo original
    void copyArray(vector<int> &arreglo, vector<int> &auxiliar, int inicio, int fin) {
        for (int posicion = inicio; posicion <= fin; posicion++) {
            arreglo[posicion] = auxiliar[posicion];
        }
    }

    // Mezcla en orden las dos mitades ya ordenadas: [inicio, mitad] y [mitad + 1, fin]
    void mergeArray(vector<int> &arreglo, vector<int> &auxiliar, int inicio, int mitad, int fin) {
        int indiceIzquierda = inicio;     // Recorre la mitad izquierda
        int indiceDerecha = mitad + 1;    // Recorre la mitad derecha
        int indiceAuxiliar = inicio;      // Siguiente posicion libre en el auxiliar

        while (indiceIzquierda <= mitad && indiceDerecha <= fin) {
            if (arreglo[indiceIzquierda] <= arreglo[indiceDerecha]) {
                auxiliar[indiceAuxiliar] = arreglo[indiceIzquierda];
                indiceIzquierda++;
            } else {
                auxiliar[indiceAuxiliar] = arreglo[indiceDerecha];
                indiceDerecha++;
            }
            indiceAuxiliar++;
        }

        // Copiar lo que sobre de la mitad izquierda
        while (indiceIzquierda <= mitad) {
            auxiliar[indiceAuxiliar] = arreglo[indiceIzquierda];
            indiceIzquierda++;
            indiceAuxiliar++;
        }

        // Copiar lo que sobre de la mitad derecha
        while (indiceDerecha <= fin) {
            auxiliar[indiceAuxiliar] = arreglo[indiceDerecha];
            indiceDerecha++;
            indiceAuxiliar++;
        }

        copyArray(arreglo, auxiliar, inicio, fin);
    }

    // Divide el arreglo recursivamente y luego mezcla
    void mergeSplit(vector<int> &arreglo, vector<int> &auxiliar, int inicio, int fin) {
        if (inicio < fin) {
            int mitad = inicio + (fin - inicio) / 2;

            // Ordenar la mitad izquierda del arreglo
            mergeSplit(arreglo, auxiliar, inicio, mitad);

            // Ordenar la mitad derecha del arreglo
            mergeSplit(arreglo, auxiliar, mitad + 1, fin);

            // Mezclar en orden ambas mitades que ya están ordenadas
            mergeArray(arreglo, auxiliar, inicio, mitad, fin);
        }
    }
};
