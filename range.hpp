#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace itertools{
   template<typename T> class range { 
        
        private:

            T _begin;
            T _end;
        
        public:
            range(const T begin, const T end): _begin (begin), _end(end) {}
            class iterator{
                     
                     T _iterator;

                public:
                    iterator(T item): _iterator(item){}

		            T& operator*() {    return _iterator; }

		            T* operator->() const { return &(_iterator);  }

		            iterator& operator++() {
                        _iterator += 1;
			            return *this;
		            }

		            const iterator operator++(int) {
                        iterator it = *this; 
                         ++*this; 
                        return it; 
		            }
                    
                    bool operator==(const iterator& rhs) const {
			            return _iterator == rhs._iterator;
		            }

		            bool operator!=(const iterator& rhs) const {
			            return _iterator != rhs._iterator;
                    }
            };

            iterator begin() {  return iterator(_begin);    }

	        iterator end() {    return iterator(_end);  }   
    };
}