#pragma once
#include <stdexcept>
#include <string>

class StocInsuficientException : public std::runtime_error {
public:
    explicit StocInsuficientException(const std::string& mesaj) 
        : std::runtime_error(mesaj) {}
};