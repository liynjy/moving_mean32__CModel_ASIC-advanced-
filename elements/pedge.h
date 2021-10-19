// -------------------------------------------------------
// Author  : Lin Junyang
// Version : 01
// junyang.lin@cn.innovusion.com
// 
// Copyright (c) 2021 Innovusion, Inc. 
// All rights reserved.
// -------------------------------------------------------


#ifndef _PEDGE_H_
#define _PEDGE_H_


template <class T>
class PEDGE{
public:
    void di(T x);
    void operator=(T x);
    T val;
private:
    T xd1 = (T)0; // Last cycle input value: x_d1
};

template <class T>
void PEDGE<T>::di(T x){
    val= (xd1==0)&&(x==1);
    xd1=x;
}

template <class T>
void PEDGE<T>::operator=(T x){
    val= (xd1==0)&&(x==1);
    xd1=x;
}


#endif
