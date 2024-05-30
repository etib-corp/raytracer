/*
** EPITECH PROJECT, 2024
** B-OOP-400-RUN-4-1-raytracer-julien.ferdinand
** File description:
** Vector
*/

#pragma once

#include "raytracer.hpp"
#include "Error.hpp"

/**
 * @brief This file contains the implementation of the Vector class.
 * The Vector class represents a mathematical vector in N-dimensional space.
 * It provides various operations and functionalities for vector manipulation.
 */

namespace Math {
    template<int N>
    class Vector {
        public:
            /**
             * @brief Custom exception class for Vector errors.
             * This class is derived from the Error class and is used to handle errors specific to Vector operations.
             */
            class VectorError : public Error {
                public:
                    /**
                     * @brief Constructs a VectorError object with the given error message.
                     * @param message The error message.
                     */
                    VectorError(const std::string &message) : Error(message) {}
            };

            /**
             * @brief Default constructor.
             * Initializes all elements of the vector to 0.
             */
            Vector()
            {
                for (int i = 0; i < N; i++)
                    this->_values[i] = 0;
            }

            /**
             * @brief Constructor that initializes the vector with the given values.
             * @param values An array of double values representing the vector elements.
             */
            Vector(std::array<double, N> values)
            {
                for (int i = 0; i < N; i++)
                    this->_values[i] = values[i];
            }

            /**
             * @brief Destructor.
             * Default destructor for the Vector class.
             */
            ~Vector() = default;

            /**
             * @brief Get the size of the vector.
             * @return The size of the vector.
             */
            int size() const
            {
                return N;
            }

            /**
             * @brief Calculate the length of the vector.
             * @return The length of the vector.
             */
            double length() const
            {
                return sqrt(this->length_squared());
            }

            /**
             * @brief Calculate the squared length of the vector.
             * @return The squared length of the vector.
             */
            double length_squared() const
            {
                double sum = 0.0F;
                for (int i = 0; i < N; i++)
                    sum += this->_values[i] * this->_values[i];
                return sum;
            }

            /**
             * @brief Calculate the dot product with another vector.
             * @param vec The vector to calculate the dot product with.
             * @return The dot product of the two vectors.
             * @throws VectorError if the vectors have different sizes.
             */
            double dot(const Vector &vec) const
            {
                double sum = 0.0F;

                if (N != vec.size())
                    throw VectorError("Vectors must have the same size to perform dot product");
                for (int i = 0; i < N; i++)
                    sum += this->_values[i] * vec._values[i];
                return sum;
            }

            /**
             * @brief Calculate the cross product with another vector.
             * @param vec The vector to calculate the cross product with.
             * @return The cross product of the two vectors.
             * @throws VectorError if the vectors are not 3-dimensional.
             */
            Vector cross(const Vector &vec) const
            {
                if (N != 3 || vec.size() != 3)
                    throw VectorError("Cross product is only defined for 3D vectors");
                std::array<double, N> values;

                values[0] = this->_values[1] * vec._values[2] - this->_values[2] * vec._values[1];
                values[1] = this->_values[2] * vec._values[0] - this->_values[0] * vec._values[2];
                values[2] = this->_values[0] * vec._values[1] - this->_values[1] * vec._values[0];
                return Vector(values);
            }

            /**
             * @brief Get the unit vector of this vector.
             * @return The unit vector of this vector.
             */
            Vector unit_vector() const
            {
                return this->normalize();
            }

            /**
             * @brief Normalize the vector.
             * @return The normalized vector.
             */
            Vector normalize() const
            {
                double len = this->length();
                std::array<double, N> values;

                for (int i = 0; i < N; i++)
                    values[i] = this->_values[i] / len;
                return Vector(values);
            }

            static Vector random()
            {
                std::array<double, N> values;

                for (int i = 0; i < N; i++)
                    values[i] = random_double();
                return Vector(values);
            }

            static Vector random(double min, double max)
            {
                std::array<double, N> values;

                for (int i = 0; i < N; i++)
                    values[i] = random_double(min, max);
                return Vector(values);
            }

            bool nearZero() const
            {
                double s = 1e-8;

                for (int i = 0; i < N; i++)
                    if (fabs(this->_values[i]) > s)
                        return false;
                return true;
            }

            /**
             * @brief Add two vectors.
             * @param vec The vector to add.
             * @return The sum of the two vectors.
             * @throws VectorError if the vectors have different sizes.
             */
            Vector operator+(const Vector &vec) const
            {
                std::array<double, N> values;

                if (N != vec.size())
                    throw VectorError("Vectors must have the same size to perform addition");
                for (int i = 0; i < N; i++)
                    values[i] = this->_values[i] + vec._values[i];
                return Vector(values);
            }

            /**
             * @brief Subtract a vector from this vector.
             * @param vec The vector to subtract.
             * @return The difference between the two vectors.
             * @throws VectorError if the vectors have different sizes.
             */
            Vector operator-(const Vector &vec) const
            {
                std::array<double, N> values;

                if (N != vec.size())
                    throw VectorError("Vectors must have the same size to perform substraction");
                for (int i = 0; i < N; i++)
                    values[i] = this->_values[i] - vec._values[i];
                return Vector(values);
            }

            /**
             * @brief Multiply two vectors element-wise.
             * @param vec The vector to multiply.
             * @return The element-wise product of the two vectors.
             * @throws VectorError if the vectors have different sizes.
             */
            Vector operator*(const Vector &vec) const
            {
                std::array<double, N> values;

                if (N != vec.size())
                    throw VectorError("Vectors must have the same size to perform addition");
                for (int i = 0; i < N; i++)
                    values[i] = this->_values[i] * vec._values[i];
                return Vector(values);
            }

            /**
             * @brief Multiply the vector by a scalar value.
             * @param val The scalar value to multiply.
             * @return The scaled vector.
             */
            Vector operator*(const double &val) const
            {
                std::array<double, N> values;

                for (int i = 0; i < N; i++)
                    values[i] = this->_values[i] * val;
                return Vector(values);
            }

            /**
             * @brief Divide two vectors element-wise.
             * @param vec The vector to divide.
             * @return The element-wise division of the two vectors.
             * @throws VectorError if the vectors have different sizes.
             */
            Vector operator/(const Vector &vec) const
            {
                std::array<double, N> values;

                if (N != vec.size())
                    throw VectorError("Vectors must have the same size to perform addition");
                for (int i = 0; i < N; i++)
                    values[i] = this->_values[i] / vec._values[i];
                return Vector(values);
            }

            /**
             * @brief Divide the vector by a scalar value.
             * @param val The scalar value to divide.
             * @return The scaled vector.
             */
            Vector operator/(const double &val) const
            {
                std::array<double, N> values;

                for (int i = 0; i < N; i++)
                    values[i] = this->_values[i] / val;
                return Vector(values);
            }

            /**
             * @brief Add a vector to this vector.
             * @param vec The vector to add.
             * @throws VectorError if the vectors have different sizes.
             */
            void operator+=(const Vector &vec)
            {
                if (N != vec.size())
                    throw VectorError("Vectors must have the same size to perform addition");
                for (int i = 0; i < N; i++)
                    this->_values[i] += vec._values[i];
            }

            /**
             * @brief Subtract a vector from this vector.
             * @param vec The vector to subtract.
             * @throws VectorError if the vectors have different sizes.
             */
            void operator-=(const Vector &vec)
            {
                if (N != vec.size())
                    throw VectorError("Vectors must have the same size to perform addition");
                for (int i = 0; i < N; i++)
                    this->_values[i] -= vec._values[i];
            }

            /**
             * @brief Multiply this vector by another vector element-wise.
             * @param vec The vector to multiply.
             * @throws VectorError if the vectors have different sizes.
             */
            void operator*=(const Vector &vec)
            {
                if (N != vec.size())
                    throw VectorError("Vectors must have the same size to perform addition");
                for (int i = 0; i < N; i++)
                    this->_values[i] *= vec._values[i];
            }

            /**
             * @brief Multiply this vector by a scalar value.
             * @param val The scalar value to multiply.
             */
            void operator*=(const double &val)
            {
                for (int i = 0; i < N; i++)
                    this->_values[i] *= val;
            }

            /**
             * @brief Divide this vector by another vector element-wise.
             * @param vec The vector to divide.
             * @throws VectorError if the vectors have different sizes.
             */
            void operator/=(const Vector &vec)
            {
                if (N != vec.size())
                    throw VectorError("Vectors must have the same size to perform addition");
                for (int i = 0; i < N; i++)
                    this->_values[i] /= vec._values[i];
            }

            /**
             * @brief Divide this vector by a scalar value.
             * @param val The scalar value to divide.
             */
            void operator/=(const double &val)
            {
                for (int i = 0; i < N; i++)
                    this->_values[i] /= val;
            }

            /**
             * @brief Get the reference to the element at the specified index.
             * @param index The index of the element.
             * @return The reference to the element at the specified index.
             * @throws VectorError if the index is out of bounds.
             */
            double& operator[](int index)
            {
                if (index < 0 || index >= N)
                    throw VectorError("Index out of bounds");
                return this->_values[index];
            }

            /**
             * @brief Get the const reference to the element at the specified index.
             * @param index The index of the element.
             * @return The const reference to the element at the specified index.
             * @throws VectorError if the index is out of bounds.
             */
            const double& operator[](int index) const
            {
                if (index < 0 || index >= N)
                    throw VectorError("Index out of bounds");
                return this->_values[index];
            }

            /**
             * @brief Output stream operator overload for Vector class.
             * @param os The output stream.
             * @param vec The Vector object to output.
             * @return The output stream.
             */
            friend std::ostream &operator<<(std::ostream &os, const Math::Vector<N> &vec)
            {
                os << "(";
                for (int i = 0; i < N; i++) {
                    os << vec._values[i];
                    if (i < N - 1)
                        os << ", ";
                }
                os << ")";
                return os;
            }

            std::array<double, N> _values; /**< The array of double values representing the vector elements. */
    };
}

/**
 * Generates a random vector within a unit sphere.
 *
 * @return A random vector within a unit sphere.
 */
inline Math::Vector<3> randomInUnitSphere()
{
    while (true) {
        Math::Vector<3> v = Math::Vector<3>::random(-1.0, 1.0);
        if (v.length_squared() < 1)
            return v;
    }
}

/**
 * Generates a random unit vector in 3D space.
 *
 * @return A random unit vector.
 */
inline Math::Vector<3> randomUnitVector()
{
    return randomInUnitSphere().unit_vector();
}

/**
 * Calculates the reflection of a vector `v` against a surface with normal vector `n`.
 *
 * @param v The incident vector.
 * @param n The surface normal vector.
 * @return The reflected vector.
 */
inline Math::Vector<3> reflect(const Math::Vector<3> &v, const Math::Vector<3> &n)
{
    return v - n * 2 * v.dot(n);
}

/**
 * Calculates the refraction of a ray given the incident direction, surface normal, and the ratio of indices of refraction.
 *
 * @param uv The incident direction of the ray.
 * @param n The surface normal.
 * @param etai_over_etat The ratio of indices of refraction.
 * @return The refracted ray direction.
 */
inline Math::Vector<3> refract(const Math::Vector<3> &uv, const Math::Vector<3> &n, double etai_over_etat)
{
    double cos_theta = fmin((uv * -1.0).dot(n), 1.0);
    Math::Vector<3> r_out_perp = (uv + n * cos_theta) * etai_over_etat;
    Math::Vector<3> r_out_parallel = n * -sqrt(fabs(1.0 - r_out_perp.length_squared()));
    return r_out_perp + r_out_parallel;
}

/**
 * Generates a random vector in a unit disk.
 *
 * @return A random vector in a unit disk.
 */
inline Math::Vector<3> randomInUnitDisk()
{
    while (true) {
        Math::Vector<3> p = Math::Vector<3>({random_double(-1, 1), random_double(-1, 1), 0.0});
        if (p.length_squared() < 1)
            return p;
    }
}

