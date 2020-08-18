//
// Created by 郑楚彬 on 2020/6/28.
//
#include <stdlib.h>

// 加法操作
#define IDENT 0     // 1 乘法操作
#define OP +        // * 乘法操作

typedef int data_t; // long、float、double
typedef struct{
    long int len;   // 数组长度
    data_t *data;   // 数据数组
} vec_rec, *vec_ptr;

// 创建特定长度的向量
vec_ptr new_vec(long int len) {
    vec_ptr result = (vec_ptr)malloc(sizeof(vec_rec));
    if(!result)
        return NULL;    //Could not allocate storage
    result->len = len;

    //Allocate array
    if(len > 0){
        data_t *data = (data_t *)calloc(len, sizeof(data_t));
        if(!data){
            free((void *)result);
            return NULL;    //could not allocate storage
        }
        result->data = data;
    }else{
        result->data = NULL;
    }
    return result;
}

// 索引向量元素并存储在*dest，成功返回1，失败(越界)返回0
int get_vec_element(vec_ptr v, long int index, data_t *dest) {
    if(index < 0 || index >= v->len)
        return 0;
    *dest = v->data[index];
    return 1;
}

// 返回向量长度
long int vec_length(vec_ptr v) { return v->len; }

// Implementation with maximum use of data abstraction
void combine1(vec_ptr v, data_t *dest) {
    long int i;
    *dest = IDENT;
    for(i = 0; i < vec_length(v); i++){
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OP val;
    }
}

// 消除循环的低效率
void combine2(vec_ptr v, data_t *dest) {
    long int i;
    long length = vec_length(v);

    *dest = IDENT;
    for(i = 0; i < length; i++){
        data_t val;
        get_vec_element(v, i, &val);
        *dest = *dest OP val;
    }
}


data_t *get_vec_start(vec_ptr v){
    return v->data;
}

void combine3(vec_ptr v, data_t *dest) {
    long int i;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);

    *dest = IDENT;
    for(i = 0; i < length; i++){
        *dest = *dest OP data[i];
    }
}

void combine4(vec_ptr v, data_t *dest) {
    long int i;
    long length = vec_length(v);
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    for(i = 0; i < length; i++){
        acc = acc OP data[i];
    }
    *dest = acc;
}

void combine5(vec_ptr v, data_t *dest) {
    long int i;
    long length = vec_length(v);
    long limit = length-1;
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    for(i = 0; i < limit; i+=2){
        acc = (acc OP data[i]) OP data[i+1];
    }

    for(; i<length; i++){
        acc = acc OP data[i];
    }
    *dest = acc;
}

void combine6(vec_ptr v, data_t *dest) {
    long int i;
    long length = vec_length(v);
    long limit = length-1;
    data_t *data = get_vec_start(v);
    data_t acc0 = IDENT;
    data_t acc1 = IDENT;

    for(i = 0; i < limit; i+=2){
        acc0 = acc0 OP data[i];
        acc1 = acc1 OP data[i];
    }

    for(; i<length; i++){
        acc0 = acc0 OP data[i];
    }
    *dest = acc0 OP acc1;
}

void combine7(vec_ptr v, data_t *dest) {
    long int i;
    long length = vec_length(v);
    long limit = length-1;
    data_t *data = get_vec_start(v);
    data_t acc = IDENT;

    for (i = 0; i < limit; i+=2) {
        acc = acc OP (data[i] OP data[i+1]);
    }
    for (; i < length; i++) {
        acc = acc OP data[i];
    }
    *dest = acc;
}


int main(){

}
