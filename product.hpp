#pragma once
#include <iostream>
#include "zip.hpp"

namespace itertools{
    template<typename T, typename U> class product{
         private:

            T _item1;
            U _item2;

        public:

            product(const T item1 , const U item2): _item1(item1), _item2(item2) {}

            class iterator{

                private:
                    typename T::iterator _it1;
                    typename T::iterator _it1End;
                    typename U::iterator _it2;
                    typename U::iterator _it2End;

                public:
                    iterator(typename T::iterator item1,typename T::iterator item1End, 
                    typename U::iterator item2 ,typename U::iterator item2End )
                    : _it1(item1), _it1End(item1End), _it2(item2), _it2End(item2End) {}

		            auto operator*()  {
                        return std::pair(*(_it1),*(_it2));
		            }

		            auto operator->() const {
                       return std::pair(&(_it1),&(_it2));
		            }
                    
                    
		            iterator& operator++() {/* Prefix operator ++ implementation.(++i)  */
                        if(_it1 != _it1End && _it2 != _it2End){
                            _it1++;
                            _it2++;
                        }
                       
			            return *this;
		            }

                     
		            const iterator operator++(int) {/* Postfix operator ++ implementation.(i++)  */
                        iterator it = *this; 
                         ++*this; 
                        return it; 
		            }

                    bool operator==(const iterator& rhs) const {
			            return (_it1 == rhs._it1) && (_it2 == rhs._it2);
		            }

		            bool operator!=(const iterator& rhs) const {
			            return (_it1 != rhs._it1) && (_it2 != rhs._it2);
                    }
            };
       
            typename product::iterator begin() {
		        return product::iterator(_item1.begin(),_item1.end() ,_item2.begin(),_item2.end());
	        }

	        typename product::iterator end() {
		        return product::iterator(_item1.end(), _item1.end(), _item2.end(),_item2.end());
            }
    };
}