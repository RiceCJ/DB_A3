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

RecordIteratorComparator(function <bool ()> comp, MyDB_RecordIteratorAltPtr it1,  MyDB_RecordIteratorAltPtr it2,
                         MyDB_RecordPtr lhs, MyDB_RecordPtr rhs){
    iterator1 = it1;
    iterator2 = it2;
    iterator1->getCurrent(lhs);
    iterator2->getCurrent(rhs);
    comparator = comp;
}

    

    bool operator () (void *lhsPtr, void *rhsPtr) {
        iterator1->getCurrent(lhs);
        iterator2->getCurrent(rhs);
        lhs->fromBinary (lhsPtr);
        rhs->fromBinary (rhsPtr);
        return comparator ();
    }

private:
    function <bool ()> comparator;
    MyDB_RecordIteratorAltPtr iterator1;
    MyDB_RecordIteratorAltPtr iterator2;
    MyDB_RecordPtr lhs;
    MyDB_RecordPtr rhs;
};

#endif //A3_RECORDITERATORCOMPARATOR_H
