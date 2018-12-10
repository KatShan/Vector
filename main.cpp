///////////////////////////////////
//  CS 368, Spring 2018
//  main.cpp to test a Vector class
//  Andy Kuemmel
//
//  This is very similar to the file we will use
//  to test your Vector.hpp
//  
//////////////////////////////////

#include <iostream>
#include "Vector.hpp"

int main()
{
    std::cout << "testing constructor and Push_Back" << std::endl;
    Vector<int> v1;
    v1.Push_Back(9);
    v1.Push_Back(8);
    v1.Push_Back(7);
    std::cout << "v1: " << v1 << std::endl;

    std::cout << "testing copy constructor v2(v1)" << std::endl;
    Vector<int> v2(v1);
    v2.Push_Back(6);
    std::cout << "adding a 6 onto v2" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v1: " << v1 << std::endl << std::endl;

    std::cout << "testing Push_Back with capacity change on v2" << std::endl;
    for (int i=11; i < 17; ++i){
        v2.Push_Back(i);
        std::cout << "size: " << v2.Size() << " capacity: " << v2.Capacity();
        std::cout << " v2: " << v2 << std::endl;
    }
    std::cout << std::endl;

    std::cout << "testing v1[0] = v2[v2.Size()-1]" << std::endl;
    v1[0] = v2[v2.Size()-1] ;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v1: " << v1 <<  std::endl;

    std::cout << "testing copy constructor v4(v2)" << std::endl;
    Vector<int> v4(v2);  // copy constructor
    std::cout << "v4: " << v4 << std::endl;
    std::cout << "v2: " << v2 << std::endl;

    Vector<int>v3;
    v3 = v1;
    std::cout << "testing v3=v1" << std::endl;
    // pop until empty
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4 = v4 causes no problems" << std::endl;
    v4 = v4;
    std::cout << "v4: " << v4 << std::endl; 

    std::cout << "popping v3 until empty" << std::endl;
    while (! v3.Empty() ){
        v3.Pop_Back();
        std::cout << " after Pop_Back,  v3: " << v3 << std::endl;
    }
    std::cout << "popping an empty vector then pushing 1" << std::endl;
    v3.Pop_Back();
    v3.Push_Back(1);
    std::cout << "v3: " << v3 << std::endl;

/*
*********  use this for your own testing....iterator values vary from machine to machine
    for (auto it = v2.Begin(); it != v2.End(); ++it){
        std::cout << "iterator: " << it ;
        std::cout  << " points to : " << *it << std::endl;
    }    
*/
    std::cout << std::endl;
    std::cout <<"testing iterators on v2" << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    auto beginIterator = v2.Begin();
    std::cout << "begin iterator points to : " << *beginIterator << std::endl;
    auto endIterator = v2.End();
    std::cout << "end iterator points to : " << *endIterator << std::endl;

    std::cout << "testing const iterators" << std::endl;
    const Vector<int> v9(v4); // v9 must be accessed with a const iterator
    std::cout << v9 << "\t" << *(v9.Begin()) << "\t" << *(v9.End()) << std::endl;
    std::cout << std::endl;

    std::cout << "testing Size and Clear" << std::endl;
    std::cout << "size of v2 is " << v2.Size() << std::endl;
    std::cout << "Clear just sets the size to 0" << std::endl;
    v2.Clear();
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "size of v2 is " << v2.Size() << std::endl << std::endl;

    std::cout << "testing Erase" << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    auto it = v4.Begin();
    ++it;
    v4.Erase(it);
    std::cout << "erasing the 2nd item in v4" << std::endl; 
    std::cout << "v4: " << v4 << std::endl;
    std::cout <<"erasing the last item in v4" << std::endl;
    it = v4.End();
    --it;
    v4.Erase(it);
    std::cout << "v4: " << v4 << std::endl << std::endl;

    std::cout << "testing At()" << std::endl;
    std::cout << "testing v4.At(3) = 99; v4.At(0) = v4.At(5)" << std::endl;
    v4.At(3) = 99;
    v4.At(0) = v4.At(5);
    std::cout << "v4: " << v4 << std::endl << std::endl;

    std::cout << "trying v4.At(-1)" << std::endl;
    try {
        v4.At(-1) = 100;
    } catch (IndexOutOfBoundsException e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "trying v4.At(v4.Size())" << std::endl;
    try {
        v4.At(v4.Size()) = 12345;
    } catch (IndexOutOfBoundsException e){
        std::cout << e.what() << std::endl;
    }

    std::cout << "trying v4.At()" << std::endl;
    try {
        v4.At(1000) = v4.At(9999);
    } catch (IndexOutOfBoundsException e){
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "testing Vector<double>" << std::endl;
    Vector<double> d1;
    d1.Push_Back(3.14);
    d1.Push_Back(2.71);
    d1.Push_Back(1.62);
    d1.At(1)  = d1.At(2);
    std::cout << "d1 = " << d1 << std::endl << std::endl;

    // two other Vector objects
    { 
        Vector <int> v5(v4);
        Vector <double> d2;
        d2 = d1;
    }
    std::cout << "when variables go out of scope, the Destructor is automatically called" << std::endl;

    return 0;
}


