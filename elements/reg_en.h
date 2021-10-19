// -------------------------------------------------------
// Author  : Lin Junyang
// Version : 01
// junyang.lin@cn.innovusion.com
// 
// Copyright (c) 2021 Innovusion, Inc. 
// All rights reserved.
// -------------------------------------------------------


#ifndef _REG_EN_H_
#define _REG_EN_H_


template <class T, class T2>
class REG_EN
{
public:
    REG_EN(T init_val): reg_val(init_val), out_val(init_val) {}
    void z1();
    void di(T x, T2 en);
    void assign(T x, T2 en);
private:
    T reg_val;
public:
    T out_val;
};

template <class T, class T2>
void REG_EN<T, T2>::z1() {
    out_val = reg_val;
}

template <class T, class T2>
void REG_EN<T, T2>::di(T x, T2 en) {
    if(en>0)
        reg_val = x;
}

template <class T, class T2>
void REG_EN<T, T2>::assign(T x, T2 en) {
    if(en>0)
        reg_val = x;
}


#endif
