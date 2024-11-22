#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//#include "command/start.h"
//#include "command/load.h"
//#include "command/login.h"
//#include "command/logout.h"
//#include "command/register.h"
//#include "command/work.h"
//#include "command/workchallenge.h"
#include "command/store.h"
//include "command/help.h"
//#include "command/save.h"
//#include "command/quit.h"

int main() {
    ArrayBarang q = CreateArrayBarang();
    QueueBarang r; CreateQueueBarang(&r);
    Barang b1 = createBarang("Platypus Laser", 1000);
    Barang b2 = createBarang("Shrink", 2000);
    Barang b3 = createBarang("Mickel Ray", 1000);
    addBarang(&q, b1);
    addBarang(&q, b2);
    enqueue(&r, b3);
    StoreList(&q);
    StoreSupply(&q, &r);
    StoreList(&q);
}
