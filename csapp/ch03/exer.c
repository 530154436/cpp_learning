//
// Created by Edward on 2020/6/13.
//

/*向量的数据结构定义 */
typedef struct{
    int len;     //向量长度，即元素的个数 float *data; //向量元素的存储地址
    float *data; //向量元素的存储地址
} vec;

/*获取向量长度*/
int vec_length(vec *v){return v->len;}

/* 获取向量中指定下标的元素值，保存在指针参数 val 中*/
float get_vec_element(vec* v, int idx){
    if (idx >= v->len)
        return 0;
    float *val;
    *val = v->data[idx];
    return *val;
}

/*计算向量内积*/
void inner0(vec *v, vec *u,float *sum){
    long int i;
    *sum = 0;//初始化为 0
    for (i = 0; i < vec_length(v); i++) {
        *sum = *sum + get_vec_element(v,i )*get_vec_element(u, i);
    }
}