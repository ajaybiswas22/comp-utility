

/**

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
#include <vector>
#include <map>
#include <array>
#include <cmath>

namespace computil {

    template<class T>
    class AP {

    private:
        T a, d;
        unsigned int n;
        bool status;

    public:
        AP();
        AP(T first_term, T common_diff, T no_of_terms);   
        bool isEmpty();
        T getCommonDiff();
        T getFirstTerm();
        T getNthTerm(unsigned int nth);
        T getNthTermFromLast(unsigned int nth);
        unsigned int getNoOfTerms();
        T sumN();
        static inline T sumN(T first_term, T last_term) {return (first_term + last_term)/2;}
        void setCommonDiff(T common_diff);
        void setFirstTerm(T first_term);
        void setNoOfTerms(T no_of_terms);
        std::vector<T> getAllTerms();
    };

    template<class T>
    AP<T>::AP() {
        status = true;
        a = 0;
        d = 0;
        n = 0;
    } 

    template<class T>
    AP<T>::AP(T first_term, T common_diff, T no_of_terms) {
        status = false;
        a = first_term;
        d = common_diff;
        n = no_of_terms;
    }

    template<class T>
    bool AP<T>::isEmpty() {
        return status;
    }

    template<class T>
    T AP<T>::getCommonDiff() {
        return d;
    }

    template<class T>
    T AP<T>::getFirstTerm() {
        return a;
    }

    template<class T>
    T AP<T>::getNthTerm(unsigned int nth) {
        return a + (nth-1)*d;
    }

    template<class T>
    T AP<T>::getNthTermFromLast(unsigned int nth) {
        return getNthTerm(n) - (nth-1)*d;
    }

    template<class T>
    unsigned int AP<T>::getNoOfTerms() {
        return n;
    }

    template<class T>
    T AP<T>::sumN() {
        
        return (n/2)*(2*a + (n-1)*d);
    }

    template<class T>
    void AP<T>::setCommonDiff(T common_diff) {
        d = common_diff;
    }

    template<class T>
    void AP<T>::setFirstTerm(T first_term) {
        a = first_term;
    }

    template<class T>
    void AP<T>::setNoOfTerms(T no_of_terms) {
        n = no_of_terms;
    }

    template<class T>
    std::vector<T> AP<T>::getAllTerms() {
        
        std::vector<T> v;

        for(unsigned int i = 1; i<=n; i++) {
            v.push_back(getNthTerm(i));
        }
    }

}