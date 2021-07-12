//
// Created by 李延 on 2021/7/10.
//

#include "skip_test.h"
/**
 *
 * 跳跃表的测试用例
 * @return
 */

#define NULL ((void*)0)
#define run_test() map_delete_whit_get()
#define run_test() creat_set_value()

/**
 * 创建并添加值,
 *
 */
void creat_set_value(){
    zskiplist *zsk =  zslCreate();
    zslInsert(zsk,0.4,"4");
    zslInsert(zsk,0.3,"3");
    zslInsert(zsk,0.5,"5");
    zslInsert(zsk,23,"230");

    zskiplistNode *zskiplistNode1 =  zslGetElementByRank(zsk,4);

}



int main() {
    run_test();
}


