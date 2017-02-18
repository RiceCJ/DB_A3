//
// Created by Liu Fang on 2/18/17.
//

#ifndef A3_RECORDITERATORCOMPARATOR_H
#define A3_RECORDITERATORCOMPARATOR_H
#include <iostream>
#include "MyDB_RecordIteratorAlt.h"

using namespace std;

class RecordIteratorComparator {

public:

RecordIteratorComparator(function <bool ()> comp, MyDB_RecordPtr lhs, MyDB_RecordPtr rhs){

    comparator = comp;
    this->lhs = lhs;
    this->rhs = rhs;

}

    

    bool operator () (MyDB_RecordIteratorAltPtr iter1, MyDB_RecordIteratorAltPtr iter2) {
        iter1->getCurrent(lhs);
        iter2->getCurrent(rhs);
        return comparator ();
    }

private:
    function <bool ()> comparator;
    MyDB_RecordPtr lhs;
    MyDB_RecordPtr rhs;
};

#endif //A3_RECORDITERATORCOMPARATOR_H
