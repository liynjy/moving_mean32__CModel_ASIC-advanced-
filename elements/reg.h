// -------------------------------------------------------
// Author  : Lin Junyang
// Version : 01
// junyang.lin@cn.innovusion.com
// 
// Copyright (c) 2021 Innovusion, Inc. 
// All rights reserved.
// -------------------------------------------------------


#ifndef _REG_H_
#define _REG_H_


template <class T>
class REG
{
public:
    REG(T init_val): reg_val(init_val), out_val(init_val) {}
    void z1();
    void di(T x);
    void operator=(T x);
private:
    T reg_val;
public:
    T out_val;
};

template <class T>
void REG<T>::z1() {
    out_val = reg_val;
}

template <class T>
void REG<T>::di(T x) {
    reg_val = x;
}

template <class T>
void REG<T>::operator=(T x) {
    reg_val = x;
}


#endif
