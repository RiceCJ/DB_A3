
#ifndef SORT_C
#define SORT_C

#include "MyDB_PageReaderWriter.h"
#include "MyDB_TableRecIterator.h"
#include "MyDB_TableRecIteratorAlt.h"
#include "MyDB_TableReaderWriter.h"
#include "Sorting.h"

using namespace std;

/**
 * used for merge pahse
 * tbl: merge into this table
 * itervec: vector of record iterators
 * comp: comparator function
 * rec1 & rec2, used to compare
 */
void mergeIntoFile (MyDB_TableReaderWriter &tbl, vector <MyDB_RecordIteratorAltPtr> &itervec,
					function <bool ()> comp, MyDB_RecordPtr rec1, MyDB_RecordPtr rec2) {




}

/**
 * used for sort pahse
 * mngr: the buffer manager
 * iter1:
 * iter2:
 * comp: comparator function
 * rec1 & rec2, used to compare
 */
vector <MyDB_PageReaderWriter> mergeIntoList (MyDB_BufferManagerPtr mngr,
											  MyDB_RecordIteratorAltPtr iter1,
											  MyDB_RecordIteratorAltPtr iter2,
											  function <bool ()> comp,
											  MyDB_RecordPtr rec1,
											  MyDB_RecordPtr rec2) {
	vector <MyDB_PageReaderWriter> mergedvec;



	return mergedvec;

}

/**
 * TPMMS algorithm
 * r: run size
 * tblread: table to be sorted
 * tbwrite: table sorted
 * comp: comparator function
 * rec1 & rec2, used to compare
 */
void sort (int r, MyDB_TableReaderWriter &tblread, MyDB_TableReaderWriter &tblwrite,
		   function <bool ()> comp, MyDB_RecordPtr rec1, MyDB_RecordPtr rec2) {






}

#endif
