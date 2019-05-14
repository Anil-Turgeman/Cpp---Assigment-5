#pragma once

namespace itertools{
    template<typename T> class powerset{
         private:
            T _item;

        public:
            powerset(const T item): _item(item) {}

            class iterator{

                private:
                    typename T::iterator _it;
                
                public:
                    iterator(typename T::iterator it): _it(it) {}

		            auto operator*()  {
                        std::string s = "{}";
                        return s;
		            }

		            iterator& operator++() {
                        _it++;
			            return *this;
		            }

		            const iterator operator++(int) {
                        iterator it = *this; 
                         ++*this; 
                        return it; 
		            }

                    bool operator==(const iterator& rhs) const {
			            return (_it == rhs._it);
		            }

		            bool operator!=(const iterator& rhs) const {
			            return (_it != rhs._it);
                    }
            };

            typename powerset::iterator begin() {
		        return powerset::iterator(_item.begin());
	        }

	        typename powerset::iterator end() {
		        return powerset::iterator(_item.end());
            }
    };
}