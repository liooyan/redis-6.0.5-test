//
// Created by 李延 on 2021/7/8.
//
/**
 *
 * 关于字典数据类型的测试用例
 *
 */
#include "dict.h"
#include "../src/server-test.h"
#include "dict_test.h"


#define NULL ((void*)0)
#define run_test() map_rehashing()

int main() {
    run_test();
}

/**
 * 字典数据结构测试
 * 对字典添加一个值，并取出
 *
 */
void map_add_whit_get() {

    dict *map = dictCreate(&clusterNodesDictType, NULL);

    dictAdd(map, "ceshiyix", "wojiapom");
    dictEntry *node = dictFind(map, "ceshiyix");

    printf("%s\n", node->key);
    printf("%s\n", node->val);
}


/**
 * map 刷新测试
 * 在刚创建的数组大小为4个。当超过4个后会扩容
 *
 *
 */
void map_rehashing() {
    dict *map = dictCreate(&clusterNodesDictType, NULL);

    dictAdd(map, "k1", "wojiapom");
    dictAdd(map, "k2", "wojiapom");
    dictAdd(map, "k3", "wojiapom");
    dictAdd(map, "k4", "wojiapom");
    dictAdd(map, "k5", "wojiapom");
    dictAdd(map, "k6", "wojiapom");
    dictAdd(map, "k7", "wojiapom");
    dictAdd(map, "k8", "wojiapom");

}

