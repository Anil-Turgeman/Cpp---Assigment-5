#pragma once
#include <iostream>

namespace itertools{
    template<typename T, typename U> 
    class zip{
         private:
            T _item1;
            U _item2;

        public:

            zip(const T item1 , const U item2): _item1(item1), _item2(item2) {}
            class iterator{

                private:
                    typename T::iterator _it1;
                    typename T::iterator _it1End;
                    typename U::iterator _it2;

                public:
                    iterator(typename T::iterator item1,typename T::iterator item1End , typename U::iterator item2)
                    : _it1(item1), _it1End(item1End), _it2(item2) {}

		            auto operator*()  {
                        return pair(*(_it1),*(_it2));
		            }

		            auto operator->() const {
                       return pair(&(_it1),&(_it2));
		            }
                    
		            iterator& operator++() {/* Prefix operator ++ implementation.(++i)  */
                        _it1++;
                        _it2++;
			            return *this;
		            }

		            const iterator operator++(int) {/* Postfix operator ++ implementation.(i++)  */
                        iterator it = *this; 
                         ++*this; 
                        return it; 
		            }

                    bool operator==(const iterator& rhs) const {/* Operator == implementation. Return true iff _it == rhs._it */
			            return (_it1 == rhs._it1) && (_it2 == rhs._it2);
		            }

		            bool operator!=(const iterator& rhs) const {/* Operator != implementation. Return true iff _it != rhs._it */
			            return (_it1 != rhs._it1) && (_it2 != rhs._it2);
                    }

            };

            typename zip::iterator begin() {
		        return zip::iterator(_item1.begin(),_item1.end() ,_item2.begin());
	        }

	        typename zip::iterator end() {
		        return zip::iterator(_item1.end(), _item1.end(), _item2.end());
            }

    };

    template <typename T, typename U> class pair {
        private:

            T _first;
            U _second;

        public:

            pair(T first, U second): _first(first), _second(second) {}

            template <typename T1, typename T2>
            friend std::ostream& operator <<(std::ostream& os, const pair<T1,T2> thepair);

            
    };
}


template <typename T1, typename T2> 
            ostream& operator<< (ostream& out, 
            const pair<T1,T2>& thepair) {
                out << thepair.first << "," << thepair.second;
                return out;
            }