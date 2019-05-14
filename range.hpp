#pragma once

using namespace std;

namespace itertools{
	
	template<typename T> class range{

		public:

            T _begin;
            T _end; 

            range(T first, T last) : _begin(first), _end(last){}

            class iterator {
                
                private:
                
                    T it;
                
                public:

                    iterator(T rangeStartElement):  it(rangeStartElement){}

                    T operator*() const {
                        return it;
                    }

                    T* operator->() const {
                        return &it;
                    }
        
                    iterator* operator++() {
                        it++;
                        return this;
                    }

                    const iterator operator++(int) {
                        iterator tmp = *this;
                        it++;
                        return tmp; 		
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
