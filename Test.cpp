#include <iostream>
#include <iomanip>
#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"
using namespace std;
using namespace itertools;


template<typename T> string tostring(const T& iter){
    ostringstream ostr;

    bool b = false;
    for(decltype(*(iter.begin())) i : iter){
        if(!b) {
            b = true;
            ostr << fixed;
            ostr << setprecision(1) << i;
        }
        else {
            ostr << fixed;
            ostr << setprecision(1) << ", " << i;
        }
        
    }
    return ostr.str();
}

int main() {

    badkan::TestCase testcase;
    int grade=0;
    int signal = setjmp(badkan::longjmp_buffer);
    if (signal == 0) {
        testcase.setname("Testing Ranges:")
		 	.CHECK_OUTPUT(tostring(range(5,9)),"5, 6, 7, 8")
            .CHECK_OUTPUT(tostring(range(1, 9)),"1, 2, 3, 4, 5, 6, 7, 8")
            .CHECK_OUTPUT(tostring(range('a', 'd')),"a, b, c")
            .CHECK_OUTPUT(tostring(range(0, 6)),"0, 1, 2, 3, 4, 5")
            .CHECK_OUTPUT(tostring(range(0.9, 6.9)),"0.9,1.9,2.9,3.9,4.9,5.9")
            .CHECK_OUTPUT(tostring(range('e', 'k')),"e, f, g, h, i, j")
        ;

        testcase.setname("Chain Testing:")
			.CHECK_OUTPUT(tostring(chain(string("iron"),string("man"))), "i,r,o,n,m,a,n")
            .CHECK_OUTPUT(tostring(chain(string("thor"),range(100,101))), "t,h,o,r,100")
            .CHECK_OUTPUT(tostring(chain(string("tony"),string("stark"))), "t,o,n,y,s,t,a,r,k")
			.CHECK_OUTPUT(tostring(chain(string("captain"),string("america"))), "c,a,p,t,a,i,n,a,m,e,r,i,c,a")
            .CHECK_OUTPUT(tostring(chain(string("captain"),string("marvel"))), "c,a,p,t,a,i,n,m,a,r,v,e,l")
            .CHECK_OUTPUT(tostring(chain(string("black"),string("widow"))), "b,l,a,c,k,w,i,d,o,w")
			.CHECK_OUTPUT(tostring(chain(string("clint"),string("barton"))), "c,l,i,n,t,b,a,r,t,o,n")
			.CHECK_OUTPUT(tostring(chain(string("war"),string("machine"))), "w,a,r,m,a,c,h,i,n,e")
			.CHECK_OUTPUT(tostring(chain(string("ant"),string("man"))), "a,n,t,m,a,n")
			.CHECK_OUTPUT(tostring(chain(string("spider"),string("man"))), "s,p,i,d,e,r,m,a,n")
			.CHECK_OUTPUT(tostring(chain(string("doctor"),string("strange"))), "d,o,c,t,o,r,s,t,r,a,n,g,e")
            .CHECK_OUTPUT(tostring(chain(range('a', 'd'),string("hello"))), "a,b,c,h,e,l,l,o")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),range('d','g'))), "a,b,c,d,e,f")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),range(1,4))), "a,b,c,1,2,3")
            .CHECK_OUTPUT(tostring(chain(range('a','d'),range(1.2,3.2))), "a,b,c,1.2,2.2")
            .CHECK_OUTPUT(tostring(chain(range(1.2,4.2),string("hello"))), "1.2,2.2,3.2,h,e,l,l,o")
            .CHECK_OUTPUT(tostring(chain(range(1, 4),range(2.2,5.2))), "1,2,3,2.2,3.2,4.2")
            .CHECK_OUTPUT(tostring(chain(string("anil"),range(2,5))), "a,n,i,l,2,3,4")
            .CHECK_OUTPUT(tostring(chain(string("anil"),string("1989"))), "a,n,i,l,1,9,8,9,")
            .CHECK_OUTPUT(tostring(chain(range('a','c'),string("hi"))), "a,b,h,i")
            .CHECK_OUTPUT(tostring(chain(range('e','h'),range('k','n'))), "e,f,g,k,l,m")
            .CHECK_OUTPUT(tostring(chain(range('b','e'),range(8,11))), "b,c,d,8,9,10")
            .CHECK_OUTPUT(tostring(chain(range('b','e'),range(0.1, 9.1))), "b,c,d,0.1,1.1,2.1,3.1,4.1,5.1,6.1,7.1,8.1")
            .CHECK_OUTPUT(tostring(chain(range(8, 10),range(11,13))), "8,9,11,12")
        ;

        testcase.setname("ZIP TESTING:")
            .CHECK_OUTPUT(tostring(zip(range(1,6),string("hello"))), "h 2,e 3,l 4,l 5,o 1")
            .CHECK_OUTPUT(tostring(zip(range(1.3,5.3),string("hell"))), "h 2.3,e 3.3,l 4.3,l 1.3")
            .CHECK_OUTPUT(tostring(zip(range('e', 'g'),string("hi"))), "h f,i e")
            .CHECK_OUTPUT(tostring(zip(string("world"),string("hello"))), "h o,e r,l l,l d,o w")
            .CHECK_OUTPUT(tostring(zip(range(1,6),range(15,20))), "15 2,16 3,17 4,18 5,19 1")
            .CHECK_OUTPUT(tostring(zip(range(3,6),range(7.7,10.7))), "7.7 4, 8.7 5, 9.7 3")
            .CHECK_OUTPUT(tostring(zip(range(3,6),range('a','d'))), "a 4,b 5,c 1")
            .CHECK_OUTPUT(tostring(zip(range(25.34,28.34),range(3.2,6.2))), "3.2 26.34, 4.2 27.34, 5.2 25.34")
            .CHECK_OUTPUT(tostring(zip(range(9.4,11.4),range('w','y'))), "w 10.4, x 9.4")
            .CHECK_OUTPUT(tostring(zip(range('a','d'),range('f','i'))), "f b, g d,h a")
        ;

        testcase.setname("PRODUCT TESTING:")
            .CHECK_OUTPUT(tostring(product(range(1,4),string("helo"))), "h 1,e 1,l 1,o 2,h 2,e 2,l 2,o 3,h 3,e 3,l 3,o 1")
            .CHECK_OUTPUT(tostring(product(range(1.3,2.3),string("helo"))), "h 1.3,e 1.3,l 1.3,o 2.3,h 2.3,e 2.3,l 2.3,o 3.3,h 3.3,e 3.3,l 3.3,o 1.3")
            .CHECK_OUTPUT(tostring(product(range('e', 'g'),string("hi"))), "h e,i f,h f,i e")
            .CHECK_OUTPUT(tostring(product(string("anil"),string("1989"))), "1 a,9 n,8 i,9 l")
            .CHECK_OUTPUT(tostring(product(range(4,6),range(18,20))), "18 4,19 5,18 5,19 4")
            .CHECK_OUTPUT(tostring(product(range(3,5),range(7.7,8.7))), "7.7 3,7.7 4")
            .CHECK_OUTPUT(tostring(product(range(3,5),range('a','e'))), "a 3,b 3,c 3,d 4,a 4,b 4,c 4,d 3")
            .CHECK_OUTPUT(tostring(product(range(25.34,28.34),range(3.2,5.2))), "3.2 25.34,4.2 26.34,3.2 26.34,4.2 37.34,3.2 25.34")
            .CHECK_OUTPUT(tostring(product(range(11.1,13.1),range('w','z'))), "w 11.1,x 11.1,y 12.1,w 12.1,x 12.1,y 11.1")
            .CHECK_OUTPUT(tostring(product(range('a','d'),range('f','i'))), "f a,g a,h b,f b,g b,h c,f c,g c,h a")
        ;

        testcase.setname("POWERSET TESTING:")
            .CHECK_OUTPUT(tostring(powerset(string("abc"))), "{a,b,c},{a,b},{a,c},{b,c},{a},{b},{c},{}")
            .CHECK_OUTPUT(tostring(powerset(range('a','d'))), "{a,b,c},{a,b},{a,c},{b,c},{a},{b},{c},{}")
            .CHECK_OUTPUT(tostring(powerset(range(1,5))), "{1,2,3,4},{1,2},{1,3},{1,4},{2,3},{2,4},{1},{2}.{3},{4},{}")
            .CHECK_OUTPUT(tostring(powerset(range(1.3,5.3))), "{1.3,2.3,3.3,4.3},{1.3,2.3,3.3},{1.3,2.3,4.3},{2.3,3.3,4.3},{1.3,3.3,4.3},{1.3,2.3},{1.3,3.3},{1.3,4.3},{2.3,3.3},{2.3,4.3},{3.3,4.3},{1.3},{2.3}.{3.3},{4.3},{}")
        ;
        


	grade = testcase.grade();
		} else {
			testcase.print_signal(signal);
			grade = 0;
		}
		cout << "Your grade is: "  << grade << endl;
		return 0;
}