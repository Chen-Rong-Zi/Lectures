#include "SmartPointer.h"

SmartPointer::SmartPointer(const SmartPointer &sptr)
{
    if ( sptr.pointer == NULL ) {
        this->pointer = NULL;
        this->ref_cnt = NULL;
        return;
    }

    this->pointer = sptr.pointer;
    this->ref_cnt = new int;
    (*(sptr.ref_cnt))++;
    *(this->ref_cnt) = *(sptr.ref_cnt);
}

void SmartPointer::assign(const SmartPointer &sptr)
{
    if ( this->pointer != NULL ) {
        (*(this->ref_cnt))--;
        if ( *(this->ref_cnt) == 0 ) {
            delete this->ref_cnt;
            delete this->pointer;
        }
    }

    if ( sptr.pointer != NULL ) {
        this->pointer = sptr.pointer;
        this->ref_cnt = new int;
        (*(sptr.ref_cnt))++;
        *(this->ref_cnt) = *(sptr.ref_cnt);
    }
    else if ( sptr.pointer == NULL ) {
        this->pointer = NULL;
        this->ref_cnt = NULL;
    }
}

SmartPointer::~SmartPointer()
{
    if ( (this->ref_cnt) == NULL )
        return;

    if ( *(this->ref_cnt) == 1 ) {
            delete this->pointer;
            delete this->ref_cnt;
    }
    else {
        (*(this->ref_cnt))--;
    }
}

