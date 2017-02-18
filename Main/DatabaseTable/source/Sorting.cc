
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
 * tblwrite: merge into this table
 * itervec: vector of record iterators
 * comp: comparator function
 * rec1 & rec2, used to compare
 */
void mergeIntoFile (MyDB_TableReaderWriter &tblwrite, vector <MyDB_RecordIteratorAltPtr> &itervec,
					function <bool ()> comp, MyDB_RecordPtr rec1, MyDB_RecordPtr rec2) {

    // using priority queue


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

    // get manager
    MyDB_BufferManagerPtr readmngrptr = tblread.getBufferMgr();

    // get num of pages in tblread
    int pagenum = tblread.getNumPages();

    // vector used in merge pahse
    vector <MyDB_RecordIteratorAltPtr> itervec;

    // sort phase
    for(int i = 0; i < pagenum; i += r){

        // load r pages per run

        vector <MyDB_PageReaderWriter> pagevec;
        vector <MyDB_PageReaderWriter> sortedvec;
        int numr = 0;

        while(i + numr < pagenum && numr < r){
            pagevec.push_back(tblread[i+numr]);
            numr++;
        }

        // sort each page
        vector <MyDB_PageReaderWriter>::iterator pageiter;
        for(pageiter = pagevec.begin(); pageiter != pagevec.end(); pageiter++){
            /**
             * rec1 & rec2 need to be rebuild?
             * * get?
             */
            sortedvec.push_back(*pageiter->sort(comp, rec1, rec2).get());
        }

        // call mergeIntoList
        


        // push iterator to itervec
        itervec.push_back(sortedvec[0].getIteratorAlt());

    }


    // merge phase


}

#endif
