#pragma once

using namespace std;

namespace itertools{
	
	template<typename T, typename S> class product{

		private:

            T start;
            S start2; 
            
            template<typename A, typename B> class iterator {

                private:

                    A value;
                    B value2;

                public:
                    B temp = value2;

                    iterator(A firstStart, B secondStart):  value(firstStart), value2(secondStart){}

                    std::pair<decltype(*value), decltype(*value2)> operator*() const {
				        return std::pair<decltype(*value), decltype(*value2)> (*value, *value2);
			        }
 
                    product::iterator<A,B> &operator++() {
				        ++value2;;
				        return *this;
			        }

                    bool operator!=(const iterator& other) const {
                        if (value2 == other.value2){
                            value2 = temp;
                            value++;
                        }
                        return value != other.value && value2 != other.value2;
                    }
                };

        public:

            product(T firstValue, S secondValue) : start(firstValue), start2(secondValue){}

            auto begin() const{
                return product::iterator<decltype(start.begin()), decltype(start2.begin())> (start.begin(), start2.begin());
            }
                
            auto end() const{
                return product::iterator<decltype(start.end()), decltype(start2.end())> (start.end(), iterastart2bel2.end());
            }
	};
};
