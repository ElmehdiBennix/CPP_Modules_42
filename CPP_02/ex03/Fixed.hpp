/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:58:41 by ebennix           #+#    #+#             */
/*   Updated: 2024/01/09 01:57:21 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        // constractor
        Fixed(void);
        Fixed(const int int_to_fixed);
        Fixed(const float float_to_fixed);
        Fixed(const Fixed &source); // copy constractor
        
        // copy assig operator
        Fixed& operator=(const Fixed &source);
        
        //comparison operators
        bool operator>(const Fixed &source) const {
            return (this->Fixed_point > source.Fixed_point)? true : false;
        };
        bool operator<(const Fixed &source) const {
            return (this->Fixed_point < source.Fixed_point)? true : false;
        };
        bool operator>=(const Fixed &source) const {
            return (this->Fixed_point >= source.Fixed_point)? true : false;
        };
        bool operator<=(const Fixed &source) const {
            return (this->Fixed_point <= source.Fixed_point)? true : false;

        };
        bool operator==(const Fixed &source) const {
            return (this->Fixed_point == source.Fixed_point)? true : false;
        };
        bool operator!=(const Fixed &source) const {
            return (this->Fixed_point != source.Fixed_point)? true : false;
        };
        //arithmetic operators
        Fixed operator+(const Fixed &source){
            Fixed tmp;
            tmp.Fixed_point = this->Fixed_point + source.Fixed_point;
            return tmp;
        };
        Fixed operator-(const Fixed &source){
            Fixed tmp;
            tmp.Fixed_point = this->Fixed_point - source.Fixed_point;
            return tmp;
        };
        Fixed operator*(const Fixed &source){
            Fixed tmp;
            tmp.Fixed_point = (this->Fixed_point * source.Fixed_point) >> this->Fractional_bits;
            return tmp;
        };
        Fixed operator/(const Fixed &source){
            Fixed tmp;
            tmp.Fixed_point = (this->Fixed_point << this->Fractional_bits) / source.Fixed_point;
            return tmp;
        };

        //increment / decrement operators  \\ prefix and postfix 
        Fixed  operator++(int){
            Fixed tmp = *this;
            ++this->Fixed_point;
            return tmp;
        };
        Fixed& operator++(void){
            ++this->Fixed_point;
            return *this;
        };
        Fixed  operator--(int){
            Fixed tmp = *this;
            --this->Fixed_point;
            return tmp;
        };
        Fixed& operator--(void){
            --this->Fixed_point;
            return *this;
        };

        // memeber functions
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        static Fixed& min(Fixed& F_p_A, Fixed& F_p_B) {
            return (F_p_A.Fixed_point > F_p_B.Fixed_point)? F_p_B : F_p_A;
        };
        static const Fixed& min(const Fixed& F_p_A, const Fixed& F_p_B) {
            return (F_p_A.Fixed_point > F_p_B.Fixed_point)? F_p_B : F_p_A;
        };
        static Fixed& max(Fixed& F_p_A, Fixed& F_p_B) {
            return (F_p_A.Fixed_point > F_p_B.Fixed_point)? F_p_A : F_p_B;
        };
        static const Fixed& max(const Fixed& F_p_A, const Fixed& F_p_B) {
            return (F_p_A.Fixed_point > F_p_B.Fixed_point)? F_p_A : F_p_B;
        };

        //destructor
        ~Fixed(void);

    private:
        // mutable int *nb, * nb; can be modified even if its inside a const method
        int Fixed_point;
        static const int Fractional_bits = 8;
};

// overlaod for the << operator;
std::ostream &operator<<(std::ostream& os, const Fixed& obj); 

//static functions 

#endif