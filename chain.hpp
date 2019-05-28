#pragma once

using namespace std;

namespace itertools{
	
	template<typename T,typename S> class chain{

		private:

            T item;
            S item2; 
            
            template<typename A,typename B> class iterator {
                
                private:

                    A value;
                    B value2;

                public:

                    bool isFirstEnd = false;
                    iterator(A firstStart, B secondStart):  value(firstStart), value2(secondStart){}

                    T operator*() const {
                        if(isFirstEnd) return *value2;
				        return *value;
                    }

                    chain::iterator<A,B> &operator++() {
				        if(!isFirstEnd) value++;
				        else value2++;
				        return *this;
			        }
                    
                    iterator operator++(int) {
                        iterator tmp = *this;
                        if(!isFirstEnd) value++;
                        else value2++;
                        return tmp;
			        }

                    bool operator ==(chain::iterator<A,B> const &other){
				        return (*value==*other.value) && (*value2==*other.value2);
			        }
			
			        bool operator!=(chain::iterator<A,B> const &other){
                        if(!isFirstEnd && value == other.value) isFirstEnd = true;
                        if(isFirstEnd) return value2 != other.value2;
                        return value != other.value;
			        }
            };

        public:
            chain(T firstValue, S secondValue): item(firstValue), item2(secondValue){}

            auto begin() const{
                return chain::iterator<decltype(item.begin()), decltype(item2.begin())> (item.begin(), item2.begin());
            }
            
            auto end() const{
                return chain::iterator<decltype(item.end()), decltype(item2.end())> (item.end(), item2.end());
            }
	};
};
