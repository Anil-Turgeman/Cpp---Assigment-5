#pragma once

using namespace std;

namespace itertools{
	
	template<typename T> class range{

		private:

            T _begin;
            T _end; 

        public:    

            range(T first, T last) : _begin(first), _end(last){}

            class iterator {
                
                private:
                
                    T it;
                
                public:

                    iterator(T start):  it(start){}

                    iterator* operator++() {
                        ++it;
                        return this;
                    }

                    const iterator operator++(int) {
                        iterator t = *this;
                        it++;
                        return t; 		
                    }

                    T operator*() const {
                        return it;
                    }

                    bool operator==(const iterator& other) const {
                        return it == (other.it);
                    }

                    bool operator!=(const iterator& other) const {
                        return it != (other.it);
                    }
            };

            iterator begin() const{
                return iterator{_begin};
            }
            
            iterator end() const{
                return iterator{_end};
            }
	};
};
