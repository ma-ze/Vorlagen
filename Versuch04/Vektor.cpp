//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 * @return void
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Function to calculate the length of the vector
 * @return The length of the vector
 */
double Vektor::laenge() const
{
    return sqrt(x*x + y*y + z*z);
}

/**
 * @brief Function to subtract another vector from this vector
 * @param input The vector to be subtracted
 * @return The resulting vector after subtraction
 */
Vektor Vektor::sub(const Vektor& input) const
{
    double resX = x - input.x;
    double resY = y - input.y;
    double resZ = z - input.z;

    return Vektor(resX, resY, resZ);
}
/**
 * @brief Function to calculate the scalar product of two vectors
 * @param input The other vector for scalar product calculation
 * @return The scalar product of the two vectors
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return x * input.x + y * input.y + z * input.z;
}

/**
 * @brief Function to calculate the angle between two vectors in degrees
 * @param input The other vector to calculate the angle with
 * @return The angle between the two vectors in degrees
 */
double Vektor::winkel(const Vektor& input) const
{
    // Calculate the angle in radians
    double angleRad = acos(skalarProd(input) / (laenge() * input.laenge()));

    // Convert the angle from radians to degrees
    return angleRad * 180.0 / M_PI;
}

/**
 * @brief Function to rotate the vector around the z-axis by a specified angle in radians
 * @param rad The angle in radians by which to rotate the vector
 */
void Vektor::rotiereUmZ(const double rad)
{
    //apply the transformatin matrix
    double newX = x * cos(rad) - y * sin(rad);
    double newY = x * sin(rad) + y * cos(rad);

    x = newX;
    y = newY;
}