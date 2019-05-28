#pragma once

using namespace std;

namespace itertools{
	
	template<typename T,typename S> class zip{

		public:

            zip(T firstValue, S secondValue) : start(firstValue), start2(secondValue){}

            auto begin() const{
                return zip::iterator < decltype(start.begin()), decltype(start2.begin()) > (start.begin(), start2.begin());
            }
            
            auto end() const{
                return zip::iterator < decltype(start.end()), decltype(start2.end()) > (start.end(), start2.end());
            }

        private:

            T start;
            S start2;    
            
            template<typename A,typename B> class iterator {

                private:

                    A value;
                    B value2;

                public:

                    iterator(A firstStart, B secondStart):  value(firstStart),value2(secondStart){}

                    std::pair<decltype(*value),decltype(*value2) > operator*() const {
				        return std::pair < decltype(*value), decltype(*value2) > (*value, *value2);
			        }   

                    iterator* operator++() {
                        ++value;
                        ++value2;
                        return this;
                    }
                    
                    bool operator!=(zip::iterator<A,B> const &other){
					    return (value != other.value) && (value2 != other.value2);
			        }
            };
	};
};
