#pragma once

using namespace std;

namespace itertools{
	
	template<typename T,typename S> class chain{

		public:

            T item1;
            S item2; 

            chain(T firstValue, S secondValue) : item1(firstValue), item2(secondValue){}
            
            template<typename A,typename B> class iterator {
                
                private:

                    A value;
                    B value2;

                public:

                    iterator(A firstStart, B secondStart):  value(firstStart), value2(secondStart){}

                    T operator*() const {
                        return value;
                    }

                    iterator* operator++() {
                        value++;
                        return this;
                    }

                    bool operator!=(const iterator& other) const {
                        return value != (other.value);
                    }
            };

            auto begin() const{
                return (item1.begin(), item2.begin());
            }
            
            auto end() const{
                return (item1.end(), item2.end());
            }
	};
};
