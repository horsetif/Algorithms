//
// Created by horsetif on 19-4-20.
//

#ifndef SEARCH_ALGORITHMS_BASE_EXCEPTION_H
#define SEARCH_ALGORITHMS_BASE_EXCEPTION_H

#include <base_include.h>
class NoFindException{
public:
    string msg;
    NoFindException(){}
    NoFindException(string s):msg(s){}
    NoFindException(NoFindException &e){
        this->msg = e.msg;
    }
};

#endif //SEARCH_ALGORITHMS_BASE_EXCEPTION_H
