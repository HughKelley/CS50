{"filter":false,"title":"Long.c","tooltip":"/pset1/credit/Long.c","undoManager":{"mark":2,"position":2,"stack":[[{"start":{"row":0,"column":0},"end":{"row":19,"column":1},"action":"insert","lines":["long long subtract_long_longs(void)","{","    // read long long from stdin","    long long i = get_long_long(\"Enter a long long: \");","","    // make sure we read one successfully","    if (i == LLONG_MAX)","    {","        return LLONG_MAX;","    }","","    long long j = get_long_long(\"What do you want to subtract from %lld? \", i);","","    if (j == LLONG_MAX)","    {","        return LLONG_MAX;","    }","","    return i - j;","}"],"id":1}],[{"start":{"row":0,"column":0},"end":{"row":1,"column":0},"action":"insert","lines":["",""],"id":2},{"start":{"row":1,"column":0},"end":{"row":2,"column":0},"action":"insert","lines":["",""]}],[{"start":{"row":0,"column":0},"end":{"row":0,"column":17},"action":"insert","lines":["#include <cs50.h>"],"id":3}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":16,"column":5},"end":{"row":16,"column":5},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1523298467235,"hash":"3228164e0e6b8aec3675ab7327bcf0f570efdf01"}