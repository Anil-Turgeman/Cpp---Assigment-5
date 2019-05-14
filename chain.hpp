#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace itertools{
    template<typename T, typename U> class chain{

        private:
            T _item1;
            U _item2;

        public:

            chain(const T item1 , const U item2): _item1(item1), _item2(item2) {}
            class iterator{
                
                private:

                    typename T::iterator _it1;
                    typename T::iterator _it1End;
                    typename U::iterator _it2;

                public:

                    iterator(typename T::iterator item1, typename T::iterator item1End, typename U::iterator item2)
                    : _it1(item1), _it1End(item1End), _it2(item2) {}

		            auto operator*()  {
                        if(_it1 != _it1End){
                            return *(_it1);
                        }
			            return *(_it2);
		            }

		            auto operator->() const {
                        if(_it1 != _it1End){
                            return &(_it1);
                        }
			            return &(_it2);
		            }

		            /* Prefix operator ++ implementation.(++i)  */
		            iterator& operator++() {
                        if(_it1 != _it1End){
                            (_it1)++;
			                return *this;
                        }
                        (_it2)++;
			            return *this;
		            }

		            /* Postfix operator ++ implementation.(i++)  */ 
		            const iterator operator++(int) {
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

            typename chain::iterator begin() {
		        return chain::iterator(_item1.begin(),_item1.end() ,_item2.begin());
	        }

	        typename chain::iterator end() {
		        return chain::iterator(_item1.end(), _item1.end(), _item2.end());
            }

    };
}