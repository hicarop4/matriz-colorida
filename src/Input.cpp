//
// Created by Eu on 10/07/2024.
//

#include "Input.h"

int Input::sanitizeInputPontosPretos(const std::string &input) {
        int qtd = std::stoi(input.substr(1));
        return qtd;
}
