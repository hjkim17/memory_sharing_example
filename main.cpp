#include "memory_sharing.h"

#include <memory>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class A {
public:
    int i;
    A(int i) {
        this->i = i;
    }
    std::size_t hash() {
        return std::hash<int>()(i);
    }
    bool operator==(const A& other) {
        i == other.i;
    }
};

int main() {

    std::shared_ptr<A> x = std::make_shared<A>(2);
    memshare::try_share(x);
    std::cout<<x.use_count()<<"\n";

    std::shared_ptr<A> z = std::make_shared<A>(2);
    memshare::try_share(z);
    std::cout<<z.use_count()<<"\n";
    z = memshare::lookup(z);
    std::cout<<z.use_count()<<"\n";


    boost::shared_ptr<A> bx = boost::make_shared<A>(2);
    memshare::try_share(bx);
    std::cout<<bx.use_count()<<"\n";

    boost::shared_ptr<A> bz = boost::make_shared<A>(2);
    memshare::try_share(bz);
    std::cout<<bz.use_count()<<"\n";
    bz = memshare::lookup(bz);
    std::cout<<bz.use_count()<<"\n";


    return 0;
}
