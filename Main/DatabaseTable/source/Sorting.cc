
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

    MyDB_PageReaderWriter curpage = MyDB_PageReaderWriter(*mngr.get());

    bool has1 = false;
    bool has2 = false;
    if(iter1->advance()){
        has1 = true;
        iter1->getCurrent(rec1);
    }
    if(iter2->advance()){
        has2 = true;
        iter2->getCurrent(rec2);
    }
    while(has1 || has2){
        if(has1 && has2){
            // comp() is true if rec1 < rec2
            if(comp()){
                // append rec1
                if(!curpage.append(rec1)){
                    mergedvec.push_back(curpage);
                    curpage = MyDB_PageReaderWriter(*mngr.get());
                    curpage.append(rec1);
                }
                if(iter1->advance()){
                    iter1->getCurrent(rec1);
                }
                else{
                    has1 = false;
                }
            }
            else{
                if(!curpage.append(rec2)){
                    mergedvec.push_back(curpage);
                    curpage = MyDB_PageReaderWriter(*mngr.get());
                    curpage.append(rec2);
                }
                if(iter2->advance()){
                    iter2->getCurrent(rec2);
                }
                else{
                    has2 = false;
                }
            }
        }
        else if(has1){
            // append rec1
            if(!curpage.append(rec1)){
                mergedvec.push_back(curpage);
                curpage = MyDB_PageReaderWriter(*mngr.get());
                curpage.append(rec1);
            }
            if(iter1->advance()){
                iter1->getCurrent(rec1);
            }
            else{
                has1 = false;
            }
        }
        else{
            if(!curpage.append(rec2)){
                mergedvec.push_back(curpage);
                curpage = MyDB_PageReaderWriter(*mngr.get());
                curpage.append(rec2);
            }
            if(iter2->advance()){
                iter2->getCurrent(rec2);
            }
            else{
                has2 = false;
            }
        }
    }

    mergedvec.push_back(curpage);

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
//        itervec.push_back(sortedvec[0].getIteratorAlt());

    }


    // merge phase


}

#endif
