#pragma once

#define HEADER_MATH_MACRO(TYPE, OTHERTYPE) \
TYPE operator+(OTHERTYPE const& other); \
TYPE operator-(OTHERTYPE const& other); \
TYPE operator*(OTHERTYPE const& other); \
TYPE operator/(OTHERTYPE const& other); \
TYPE& operator+=(OTHERTYPE const& other); \
TYPE& operator-=(OTHERTYPE const& other); \
TYPE& operator*=(OTHERTYPE const& other); \
TYPE& operator/=(OTHERTYPE const& other); \

#define SOURCE_OPERATOREQUALS_MACRO(MACRONAME, TYPE, OTHERTYPE, OPERATOR) \
TYPE& TYPE::operator OPERATOR##=(OTHERTYPE const& other) MACRONAME(OPERATOR)

#define SOURCE_OPERATOR_MACRO(MACRONAME, TYPE, OTHERTYPE, OPERATOR) \
SOURCE_OPERATOREQUALS_MACRO(MACRONAME,TYPE,OTHERTYPE,OPERATOR) \
TYPE TYPE::operator OPERATOR(OTHERTYPE const& other) { \
    return TYPE(*this) OPERATOR##= other;\
} \

#define SOURCE_MATH_MACRO(MACRONAME, TYPE, OTHERTYPE) \
SOURCE_OPERATOR_MACRO(MACRONAME,TYPE,OTHERTYPE,+) \
SOURCE_OPERATOR_MACRO(MACRONAME,TYPE,OTHERTYPE,-) \
SOURCE_OPERATOR_MACRO(MACRONAME,TYPE,OTHERTYPE,*) \
SOURCE_OPERATOR_MACRO(MACRONAME,TYPE,OTHERTYPE,/) \

/*
Vector3& Vector3::operator+=(Vector3 const& vec){
    x+=vec.x; \
    y+=vec.y; \
    z+=vec.z; \
    return *this; \
}

Vector3 Vector3::operator+(Vector3 const& vec){
    return Vector3(*this) += vec;
}*/