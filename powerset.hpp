#pragma once

using namespace std;

namespace itertools{
	
	template<typename T> class powerset{

		private:

            T start;

        public:

            powerset(T firstValue) : start(firstValue){}

            class iterator {

                private:

                    T value;
                
                public:

                    iterator(T rangeStartElement):  value(rangeStartElement){}

                    auto operator*() const {
                        return *value;
                    }
                    
                    iterator* operator++() {
                        value++;
                        return *this;
                    }

                    bool operator!=(const iterator& other) const {
                        return value != (other.value);
                    }
            };

            auto begin() const {
                return (start.begin());
            }

            auto end() const {
                return (start.end());
            }
	};
};
