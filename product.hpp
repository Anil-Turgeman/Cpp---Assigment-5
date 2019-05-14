#pragma once

using namespace std;

namespace itertools{
	
	template<typename T,typename S> class product{

		public:

            T start;
            S start2; 

            product(T firstValue, S secondValue) : start(firstValue), start2(secondValue){}
            
            template<typename A,typename B> class iterator {
                private:

                    A value;
                    B value2;

                public:

                    iterator(A firstStart, B secondStart):  value(firstStart),value2(secondStart){}

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
                return (start.begin(), start2.begin());
            }
                
            auto end() const{
                return (start.end(), start2.end());
            }
	};
};
