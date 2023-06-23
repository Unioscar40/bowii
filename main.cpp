#include "vectorii.h"
#include <iostream> 
#include <stdlib.h>
#include <vector>

int main() {
    std::vector<float> vector1{1.0, 2.0, 3.0, 4.0}; 
    std::vector<float> vector2{1.0, 2.0, 3.0, 4.0}; 

    float result;

    for(unsigned int i = 0 ; i < vector1.size() ; i++) {
        result += vector1[i] * vector2[i];
    }

    size_t tam = 4;
    std::cout << "Resultado esperado: " << result << std::endl;
    std::cout << "Resultado obtenido: " <<  bowii::vector::dotProductSSE(vector1.data(), vector2.data(), tam) << std::endl;

}