// Aplicacion TDA de una estructura big integer

#include <string>
#include <vector>

class BigInteger {
public:
    // Constructor
    BigInteger(std::string digits);

    // Copy
    BigInteger(const BigInteger& other);

    // Addition overload
    BigInteger operator+(const BigInteger& other);

    // Subtraction overload
    BigInteger operator-(const BigInteger& other);

    // Multiplication overload
    BigInteger operator*(const BigInteger& other);

    // Division overload
    BigInteger operator/(const BigInteger& other);

    // Modulo oerload
    BigInteger operator%(const BigInteger& other);

    // Exponentiation overload
    BigInteger operator^(const int& exponent);

    // Equality overload
    bool operator==(const BigInteger& other);

    // Less than overload
    bool operator<(const BigInteger& other);

    // Less than or equal to overload
    bool operator<=(const BigInteger& other);

    // Addition function overload
    static BigInteger sumarListaValores(const std::vector<BigInteger>& values);

    // Multiplication function
    static BigInteger multiplicarListaValores(const std::vector<BigInteger>& values);

    // String representation of the BigInteger
    std::string toString() const;

private:
    // Internal representation of the BigInteger as a vector
    std::vector<int> digits;

    // Helper function for division and modulo operations
    std::pair<BigInteger, BigInteger> divideAndRemainder(const BigInteger& divisor) const;
};
