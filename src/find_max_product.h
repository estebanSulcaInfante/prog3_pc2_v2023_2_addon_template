//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_PC2_V2023_2_ADDON_FIND_MAX_PRODUCT_H
#define PROG3_PC2_V2023_2_ADDON_FIND_MAX_PRODUCT_H

#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <algorithm>
#include <numeric>
#include <thread>
#include <type_traits>
#include <iostream>


template <typename Container>
auto find_max_product(const Container& c) -> typename Container::value_type {
    using ValueType = typename Container::value_type;

    // Caso especial: Contenedor vacío
    if (c.empty()) return 0;

    // Caso especial: Contenedor con un solo elemento
    if (c.size() == 1) return *c.begin();

    // Caso especial: std::list o std::forward_list, o menos de 10,000 elementos
    if (std::is_same<Container, std::list<ValueType>>::value ||
        std::is_same<Container, std::forward_list<ValueType>>::value ||
        c.size() < 10000) {

        // Inicializamos los valores máximos y mínimos
        ValueType max1 = std::numeric_limits<ValueType>::min();
        ValueType max2 = max1;
        ValueType min1 = std::numeric_limits<ValueType>::max();
        ValueType min2 = min1;

        // Recorremos el contenedor para encontrar los dos valores más grandes y los dos más pequeños
        for (const auto& value : c) {
            if (value > max1) {
                max2 = max1;
                max1 = value;
            } else if (value > max2) {
                max2 = value;
            }

            if (value < min1) {
                min2 = min1;
                min1 = value;
            } else if (value < min2) {
                min2 = value;
            }
        }

        // Comparamos los productos de los dos mayores y los dos menores
        return std::max(max1 * max2, min1 * min2);



    }

    // caso concurrente

    // Retorna un valor ficticio, reemplazar con la lógica de procesamiento concurrente
    return ValueType{};
}

#endif //PROG3_PC2_V2023_2_ADDON_FIND_MAX_PRODUCT_H
