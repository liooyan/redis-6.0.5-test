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
#define run_test() map_delete_whit_get()


/**
 * 字典数据结构测试
 * 对字典添加一个值，并取出
 * 其中dictAdd只有添加功能
 *
 */
void map_add_whit_get() {

    dict *map = dictCreate(&shaScriptObjectDictType, NULL);

    dictAdd(map, "ceshiyix", "wojiapom");
    dictAdd(map, "ceshiyix", "wojiapom1");
    dictEntry *node = dictFind(map, "ceshiyix");

    printf("%s\n", node->key);
    printf("%s\n", node->val);
}


void map_delete_whit_get() {

    dict *map = dictCreate(&shaScriptObjectDictType, NULL);
    dictAdd(map, "ceshiyix", "wojiapom");
    dictDelete(map, "ceshiyix");
    dictEntry *node = dictFind(map, "ceshiyix");

    printf("%s\n", node->key);
    printf("%s\n", node->val);
}


void map_dictReplace_whit_get() {

    dict *map = dictCreate(&shaScriptObjectDictType, NULL);

    dictReplace(map, "ceshiyix", "wojiapom");
    dictReplace(map, "ceshiyix", "wojiapom1");
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
    dict *map = dictCreate(&shaScriptObjectDictType, NULL);

    dictAdd(map, "k1", "wojiapom");
    dictAdd(map, "k2", "wojiapom");
    dictAdd(map, "k3", "wojiapom");
    dictAdd(map, "k4", "wojiapom");
    dictAdd(map, "k5", "wojiapom");
    dictAdd(map, "k6", "wojiapom");
    dictAdd(map, "k7", "wojiapom");
    dictAdd(map, "k8", "wojiapom");

    dictEntry *node1 = dictFind(map, "k1");
    dictEntry *node2 = dictFind(map, "k2");

    printf("%s\n", node1->key);
    printf("%s\n", node1->val);

    printf("%s\n", node2->key);
    printf("%s\n", node2->val);

}


int main() {
    run_test();
}




