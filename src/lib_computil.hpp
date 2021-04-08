

/*

Copyright (c) 2021 Ajay Biswas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <array>
#include <cmath>
#include <complex>
#include <exception>

namespace computil {

/**
*  @brief A container to calculate the Arithmetic Progression and provides
*  fixed time access of elements.
*
*  @ingroup sequences and series
*
*  @tparam T Type of element.
*
*  An Arithmetic progression (AP) or arithmetic sequence is a sequence of numbers 
*  in which the common difference 'd' of any two consecutive number is constant. This class 
*  provides support of various AP related operations.
*  
*/
template<class T>
class AP {

private:
    T a, d;
    unsigned int n;

public:
    AP(T first_term, T common_diff, T no_of_terms);   
    T get_common_diff();
    T get_first_term();
    T get_nth_term(unsigned int nth);
    T get_nth_term_from_last(unsigned int nth);
    unsigned int get_no_of_terms();
    T sum_n();
    static inline T sum_n(T first_term, T last_term, unsigned int n) {return n*(first_term + last_term)/2.0;}
    void set_common_diff(T common_diff);
    void set_first_term(T first_term);
    void set_no_of_terms(T no_of_terms);
    std::vector<T> get_all_terms();
};

template<class T>
class GP {

private:

public:



};

template<class T>
class Prime {

private:

public:

    static bool is_prime(T num);
    static T nearest_prime(T num);
    static std::vector<T> get_prime_in_range(T lower_limit, T upper_limit);
    static T random_prime(unsigned int no_of_digits);
};

template<class T>
class BooleanAlgebra {

private:

};

template<class T>
class QuadraticEquation {

private:
T a,b,c;

public:
    QuadraticEquation(T coeff_x2, T coeff_x, T constant_term) : a(coeff_x2),b(coeff_x),c(constant_term){}
    std::pair<T,T> get_real_roots();
    std::pair<std::complex<T>,std::complex<T> > get_complex_roots();
    inline T get_discriminant() {return b*b - 4*a*c;}
    inline T get_sum_of_roots() {return (-1 * b)/a;}
    inline T get_product_of_roots() {return c/a;}
};


template<class T>
AP<T>::AP(T first_term, T common_diff, T no_of_terms) {
    a = first_term;
    d = common_diff;
    n = no_of_terms;
}

/**
*  @brief  Returns the common difference 'd' of an AP.
*  @return The common difference of the AP of the type same as the class.
*
*  Returns the common difference 'd' of an AP which was initialized by the user. 
*/
template<class T>
T AP<T>::get_common_diff() {
    return d;
}

/**
*  @brief  Returns the First term of an AP.
*  @return The first term of the AP of the type same as the class.
*
*  Returns the first term 'a' of an AP which was initialized by the user.
*/
template<class T>
T AP<T>::get_first_term() {
    return a;
}

/**
*  @brief  Returns the nth term of an AP.
*  @param  nth  An unsigned integer denoting the n.
*  @return The nth term of the AP of the type same as the class.
*  @throws std::out_of_range if the nth no. is an invalid term.
*          std::domain_error if the nth no. is zero or negative.
*
*  Uses the first term a, common difference d and the user input nth
*  to calculate the nth term. 
*/
template<class T>
T AP<T>::get_nth_term(unsigned int nth) {
    try{
        if(nth > n) {
            throw std::out_of_range("Not enough terms in AP");
        }
        if(nth <= 0) {
            throw std::domain_error("Terms cannot be zero or negative");
        }
        return a + (nth-1)*d;
    } 
    catch(std::exception& e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    
}

/**
*  @brief  Returns the nth term of an AP from the last.
*  @param  nth  An unsigned integer denoting the n.
*  @return The nth term of the AP from the last of the type same as the class.
*  @throws std::out_of_range if the nth no. is an invalid term.
*          std::domain_error if the nth no. is zero or negative.
*
*  Uses the getNthTerm(), common difference d and the user input nth
*  to calculate the nth term from the last.  
*/
template<class T>
T AP<T>::get_nth_term_from_last(unsigned int nth) {

    try{
        if(nth > n) {
            throw std::out_of_range("Not enough terms in AP");
        }
        if(nth <= 0) {
            throw std::domain_error("Terms cannot be zero or negative");
        }
        return get_nth_term(n) - (nth-1)*d;
    } 
    catch(std::exception& e)
    {
        std::cerr<<e.what()<<std::endl;
    }
}

/**
*  @brief  Returns the total no. of terms of the AP.
*  @return The total no. of terms 'n' of the AP of the type same as the class.
*
*  Returns the total no. of terms 'n' of an AP that was initialized by the user.
*/
template<class T>
unsigned int AP<T>::get_no_of_terms() {
    return n;
}

template<class T>
T AP<T>::sum_n() {  
    return (n/2.0)*(2*a + (n-1)*d);
}

template<class T>
void AP<T>::set_common_diff(T common_diff) {
    d = common_diff;
}

template<class T>
void AP<T>::set_first_term(T first_term) {
    a = first_term;
}

template<class T>
void AP<T>::set_no_of_terms(T no_of_terms) {
    n = no_of_terms;
}

/**
*  @brief  Get all terms of the AP
*  @return a std::vector that Returns n no. of terms of the AP
*
*  Return a list of terms of an Arithmetic Progrssion.
*/
template<class T>
std::vector<T> AP<T>::get_all_terms() {

    std::vector<T> v;

    for(unsigned int i = 0; i<n; i++) {
        v.push_back(a+ i*d);
    }

    return v;
}

template<class T>
bool Prime<T>::is_prime(T num) {
    
    try {

        if(num <= 1)
            return false;

        long double v = num - floor(num);
        if(v > 0.0)
            return false;

        unsigned long long int val = num;
        
        for(unsigned long long int i=2; i<=sqrt(val); i++)
        {
            if(val%i == 0)
            {
                return false;
            }
        }
        return true;
    }
    catch(std::exception& e) {
        std::cerr<<"Number not valid for checking"<<std::endl;
    }
}

template<class T>
std::vector<T> Prime<T>::get_prime_in_range(T lower_limit, T upper_limit) {
    
    std::vector<T> primes(upper_limit+1, 1);
    std::vector<T> B;

    try {

        if(lower_limit < 0 || upper_limit < 0)
            throw std::out_of_range("Range cannot be negative");

        unsigned long long int val1 = ceil(lower_limit);
        unsigned long long int val2 = floor(upper_limit);

        if(upper_limit < lower_limit)
            throw std::out_of_range("Wrong range provided");

        primes[0] = 0;
        primes[1] = 0;
        
        for(unsigned long long int i=2; i<=sqrt(val2); i++)
        {
            if(primes[i] == 1)
            {
                for(unsigned long long int j=2;(i*j)<=val2;j++)
                    primes[i*j] = 0;
            }
        }
        
        for(unsigned long long int i=val1;i<=val2;i++)
        {
            if(primes[i] == 1)
            {
                B.push_back(i);
            }
        }
        return B;

    }
    catch(std::exception& e)
    {
        std::cerr<<e.what()<<std::endl;
    }
}

template<class T>
T Prime<T>::nearest_prime(T num) {
    try {
        num = floor(num);
        if(num < 2)
            return 2;
        else {
            
            while(num >= 2) {
                bool st = is_prime(num);
                if(st == true)
                    return num;
                num--;
            }
        }
    } catch(std::exception& e) {
        std::cerr<<e.what()<<std::endl;
    }
}

template<class T>
std::pair<T,T> QuadraticEquation<T>::get_real_roots() {

    std::pair<T,T> soln;
    soln.first = ((-1*b) + sqrt(b*b - 4*a*c) ) / (2*a);
    soln.second = ((-1*b) - sqrt(b*b - 4*a*c) ) / (2*a);
    return soln;
}

template<class T>
std::pair<std::complex<T>,std::complex<T> > QuadraticEquation<T>::get_complex_roots() {

    std::pair<std::complex<T>,std::complex<T> > soln;
    std::complex<T> v1 ((-1*b)/(2*a) , sqrt(abs(b*b - 4*a*c))/(2*a) );
    std::complex<T> v2 ((-1*b)/(2*a) , -1 * ( sqrt(abs(b*b - 4*a*c))/(2*a) ) );
    soln.first = v1;
    soln.second = v2;
    return soln;
}


}   // namespace ends