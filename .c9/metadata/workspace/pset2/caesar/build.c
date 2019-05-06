{"filter":false,"title":"build.c","tooltip":"/pset2/caesar/build.c","undoManager":{"mark":92,"position":92,"stack":[[{"start":{"row":0,"column":0},"end":{"row":101,"column":1},"action":"insert","lines":["#include <stdio.h>","#include <cs50.h>","#include <stdlib.h>","#include <ctype.h>","#include <string.h>","","int main(int argc, string argv[])","{","    //turn key into an integer","","    int key = atoi(argv[1]);","","    // get text to encipher","","    string text = get_string(\"Enter string: \");","","","    // go through text one letter at a time.","","    int limit = strlen(text);","    printf(\"string length is: %i \\n\", limit);","    //string code[limit];","","    for (int i = 0; i < limit; i++)","    {","","        char letter = text[i];","","       if (isupper(letter)== true)","       {","            // 65 is ascii \"A\"","            letter = letter - 64;","","            //subtract","            // add key","            letter = letter + key;","","            //find remainder %26","            letter = letter % 26;","","            //add","","            letter = letter + 64;","       }","       else","       {","           if (islower(letter) == true)","           {","                //97 is asci \"a\"","                //subtract","                // divide","                //add","                            // 65 is ascii \"A\"","            letter = letter - 96;","","            //subtract","            // add key","            letter = letter + key;","","            //find remainder %26","            letter = letter % 26;","","            //add","","            letter = letter + 96;","           }","           else","           { }","","       }","","       //code[i] = letter;","","    }","","","","","","    //reassemble","    //print","","","","    //add key to each letter","","    //int key = atoi(argv[1]);","","    printf(\"Your  string was: %s\\n\", text);","","    printf(\"key= %i\\n argc = %i\", key, argc);","    //printf(\"%s\\n\", code);","","","","","","","","","","}"],"id":2}],[{"start":{"row":8,"column":3},"end":{"row":12,"column":27},"action":"remove","lines":[" //turn key into an integer","","    int key = atoi(argv[1]);","","    // get text to encipher"],"id":3}],[{"start":{"row":10,"column":4},"end":{"row":10,"column":10},"action":"remove","lines":["string"],"id":4}],[{"start":{"row":10,"column":4},"end":{"row":10,"column":5},"action":"insert","lines":["h"],"id":5}],[{"start":{"row":10,"column":4},"end":{"row":10,"column":5},"action":"remove","lines":["h"],"id":6}],[{"start":{"row":10,"column":4},"end":{"row":10,"column":5},"action":"insert","lines":["c"],"id":7},{"start":{"row":10,"column":5},"end":{"row":10,"column":6},"action":"insert","lines":["h"]},{"start":{"row":10,"column":6},"end":{"row":10,"column":7},"action":"insert","lines":["a"]},{"start":{"row":10,"column":7},"end":{"row":10,"column":8},"action":"insert","lines":["r"]}],[{"start":{"row":12,"column":0},"end":{"row":87,"column":27},"action":"remove","lines":["","    // go through text one letter at a time.","","    int limit = strlen(text);","    printf(\"string length is: %i \\n\", limit);","    //string code[limit];","","    for (int i = 0; i < limit; i++)","    {","","        char letter = text[i];","","       if (isupper(letter)== true)","       {","            // 65 is ascii \"A\"","            letter = letter - 64;","","            //subtract","            // add key","            letter = letter + key;","","            //find remainder %26","            letter = letter % 26;","","            //add","","            letter = letter + 64;","       }","       else","       {","           if (islower(letter) == true)","           {","                //97 is asci \"a\"","                //subtract","                // divide","                //add","                            // 65 is ascii \"A\"","            letter = letter - 96;","","            //subtract","            // add key","            letter = letter + key;","","            //find remainder %26","            letter = letter % 26;","","            //add","","            letter = letter + 96;","           }","           else","           { }","","       }","","       //code[i] = letter;","","    }","","","","","","    //reassemble","    //print","","","","    //add key to each letter","","    //int key = atoi(argv[1]);","","    printf(\"Your  string was: %s\\n\", text);","","    printf(\"key= %i\\n argc = %i\", key, argc);","    //printf(\"%s\\n\", code);"],"id":8}],[{"start":{"row":9,"column":0},"end":{"row":10,"column":0},"action":"insert","lines":["",""],"id":9},{"start":{"row":10,"column":0},"end":{"row":11,"column":0},"action":"insert","lines":["",""]}],[{"start":{"row":8,"column":0},"end":{"row":9,"column":0},"action":"insert","lines":["",""],"id":10}],[{"start":{"row":9,"column":0},"end":{"row":9,"column":1},"action":"insert","lines":["s"],"id":11},{"start":{"row":9,"column":1},"end":{"row":9,"column":2},"action":"insert","lines":["t"]},{"start":{"row":9,"column":2},"end":{"row":9,"column":3},"action":"insert","lines":["r"]},{"start":{"row":9,"column":3},"end":{"row":9,"column":4},"action":"insert","lines":["i"]},{"start":{"row":9,"column":4},"end":{"row":9,"column":5},"action":"insert","lines":["n"]},{"start":{"row":9,"column":5},"end":{"row":9,"column":6},"action":"insert","lines":["g"]}],[{"start":{"row":9,"column":6},"end":{"row":9,"column":7},"action":"insert","lines":[" "],"id":12},{"start":{"row":9,"column":7},"end":{"row":9,"column":8},"action":"insert","lines":["a"]},{"start":{"row":9,"column":8},"end":{"row":9,"column":9},"action":"insert","lines":["n"]},{"start":{"row":9,"column":9},"end":{"row":9,"column":10},"action":"insert","lines":["s"]},{"start":{"row":9,"column":10},"end":{"row":9,"column":11},"action":"insert","lines":["w"]},{"start":{"row":9,"column":11},"end":{"row":9,"column":12},"action":"insert","lines":["e"]},{"start":{"row":9,"column":12},"end":{"row":9,"column":13},"action":"insert","lines":["r"]}],[{"start":{"row":9,"column":13},"end":{"row":9,"column":14},"action":"insert","lines":["="],"id":13}],[{"start":{"row":9,"column":14},"end":{"row":9,"column":15},"action":"insert","lines":[" "],"id":14}],[{"start":{"row":9,"column":14},"end":{"row":9,"column":15},"action":"remove","lines":[" "],"id":15},{"start":{"row":9,"column":13},"end":{"row":9,"column":14},"action":"remove","lines":["="]}],[{"start":{"row":9,"column":13},"end":{"row":9,"column":14},"action":"insert","lines":[";"],"id":16}],[{"start":{"row":9,"column":14},"end":{"row":9,"column":17},"action":"remove","lines":["   "],"id":17},{"start":{"row":9,"column":14},"end":{"row":10,"column":0},"action":"insert","lines":["",""]},{"start":{"row":10,"column":0},"end":{"row":11,"column":0},"action":"insert","lines":["",""]}],[{"start":{"row":11,"column":0},"end":{"row":11,"column":1},"action":"insert","lines":["f"],"id":18},{"start":{"row":11,"column":1},"end":{"row":11,"column":2},"action":"insert","lines":["o"]},{"start":{"row":11,"column":2},"end":{"row":11,"column":3},"action":"insert","lines":["r"]}],[{"start":{"row":11,"column":3},"end":{"row":11,"column":4},"action":"insert","lines":[" "],"id":19},{"start":{"row":11,"column":4},"end":{"row":11,"column":5},"action":"insert","lines":["i"]}],[{"start":{"row":11,"column":5},"end":{"row":11,"column":6},"action":"insert","lines":[" "],"id":20},{"start":{"row":11,"column":6},"end":{"row":11,"column":7},"action":"insert","lines":["="]}],[{"start":{"row":11,"column":7},"end":{"row":11,"column":8},"action":"insert","lines":[" "],"id":21}],[{"start":{"row":11,"column":8},"end":{"row":11,"column":9},"action":"insert","lines":["0"],"id":22},{"start":{"row":11,"column":9},"end":{"row":11,"column":10},"action":"insert","lines":[";"]}],[{"start":{"row":11,"column":4},"end":{"row":11,"column":5},"action":"insert","lines":["("],"id":23}],[{"start":{"row":11,"column":11},"end":{"row":11,"column":12},"action":"insert","lines":[" "],"id":24},{"start":{"row":11,"column":12},"end":{"row":11,"column":13},"action":"insert","lines":["i"]}],[{"start":{"row":11,"column":13},"end":{"row":11,"column":14},"action":"insert","lines":[" "],"id":25},{"start":{"row":11,"column":14},"end":{"row":11,"column":15},"action":"insert","lines":["<"]}],[{"start":{"row":11,"column":15},"end":{"row":11,"column":16},"action":"insert","lines":[" "],"id":26},{"start":{"row":11,"column":16},"end":{"row":11,"column":17},"action":"insert","lines":["1"]},{"start":{"row":11,"column":17},"end":{"row":11,"column":18},"action":"insert","lines":["0"]},{"start":{"row":11,"column":18},"end":{"row":11,"column":19},"action":"insert","lines":[";"]}],[{"start":{"row":11,"column":19},"end":{"row":11,"column":20},"action":"insert","lines":[" "],"id":27},{"start":{"row":11,"column":20},"end":{"row":11,"column":21},"action":"insert","lines":["i"]}],[{"start":{"row":11,"column":21},"end":{"row":11,"column":22},"action":"insert","lines":[" "],"id":28},{"start":{"row":11,"column":22},"end":{"row":11,"column":23},"action":"insert","lines":["+"]},{"start":{"row":11,"column":23},"end":{"row":11,"column":24},"action":"insert","lines":["+"]}],[{"start":{"row":11,"column":23},"end":{"row":11,"column":24},"action":"remove","lines":["+"],"id":29},{"start":{"row":11,"column":22},"end":{"row":11,"column":23},"action":"remove","lines":["+"]},{"start":{"row":11,"column":21},"end":{"row":11,"column":22},"action":"remove","lines":[" "]}],[{"start":{"row":11,"column":21},"end":{"row":11,"column":22},"action":"insert","lines":["+"],"id":30},{"start":{"row":11,"column":22},"end":{"row":11,"column":23},"action":"insert","lines":["+"]},{"start":{"row":11,"column":23},"end":{"row":11,"column":24},"action":"insert","lines":[")"]}],[{"start":{"row":11,"column":24},"end":{"row":12,"column":0},"action":"insert","lines":["",""],"id":31},{"start":{"row":12,"column":0},"end":{"row":12,"column":1},"action":"insert","lines":["{"]}],[{"start":{"row":18,"column":0},"end":{"row":18,"column":1},"action":"insert","lines":["}"],"id":32}],[{"start":{"row":18,"column":1},"end":{"row":19,"column":0},"action":"insert","lines":["",""],"id":33}],[{"start":{"row":13,"column":0},"end":{"row":14,"column":0},"action":"remove","lines":["",""],"id":34}],[{"start":{"row":13,"column":0},"end":{"row":14,"column":0},"action":"remove","lines":["",""],"id":35},{"start":{"row":13,"column":0},"end":{"row":14,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":14,"column":0},"end":{"row":15,"column":0},"action":"insert","lines":["",""],"id":36},{"start":{"row":15,"column":0},"end":{"row":16,"column":0},"action":"insert","lines":["",""]}],[{"start":{"row":14,"column":0},"end":{"row":15,"column":0},"action":"insert","lines":["",""],"id":37}],[{"start":{"row":15,"column":0},"end":{"row":15,"column":4},"action":"insert","lines":["    "],"id":38}],[{"start":{"row":15,"column":4},"end":{"row":15,"column":5},"action":"insert","lines":["a"],"id":39},{"start":{"row":15,"column":5},"end":{"row":15,"column":6},"action":"insert","lines":["n"]},{"start":{"row":15,"column":6},"end":{"row":15,"column":7},"action":"insert","lines":["s"]},{"start":{"row":15,"column":7},"end":{"row":15,"column":8},"action":"insert","lines":["w"]},{"start":{"row":15,"column":8},"end":{"row":15,"column":9},"action":"insert","lines":["e"]},{"start":{"row":15,"column":9},"end":{"row":15,"column":10},"action":"insert","lines":["r"]}],[{"start":{"row":15,"column":10},"end":{"row":15,"column":12},"action":"insert","lines":["[]"],"id":40}],[{"start":{"row":15,"column":11},"end":{"row":15,"column":12},"action":"insert","lines":["i"],"id":41}],[{"start":{"row":15,"column":13},"end":{"row":15,"column":14},"action":"insert","lines":[" "],"id":42},{"start":{"row":15,"column":14},"end":{"row":15,"column":15},"action":"insert","lines":["="]}],[{"start":{"row":15,"column":15},"end":{"row":15,"column":16},"action":"insert","lines":[" "],"id":43},{"start":{"row":15,"column":16},"end":{"row":15,"column":17},"action":"insert","lines":["t"]},{"start":{"row":15,"column":17},"end":{"row":15,"column":18},"action":"insert","lines":["e"]},{"start":{"row":15,"column":18},"end":{"row":15,"column":19},"action":"insert","lines":["x"]},{"start":{"row":15,"column":19},"end":{"row":15,"column":20},"action":"insert","lines":["t"]}],[{"start":{"row":18,"column":1},"end":{"row":19,"column":0},"action":"insert","lines":["",""],"id":44},{"start":{"row":19,"column":0},"end":{"row":20,"column":0},"action":"insert","lines":["",""]},{"start":{"row":20,"column":0},"end":{"row":20,"column":1},"action":"insert","lines":["p"]},{"start":{"row":20,"column":1},"end":{"row":20,"column":2},"action":"insert","lines":["r"]},{"start":{"row":20,"column":2},"end":{"row":20,"column":3},"action":"insert","lines":["i"]},{"start":{"row":20,"column":3},"end":{"row":20,"column":4},"action":"insert","lines":["n"]},{"start":{"row":20,"column":4},"end":{"row":20,"column":5},"action":"insert","lines":["t"]},{"start":{"row":20,"column":5},"end":{"row":20,"column":6},"action":"insert","lines":["f"]}],[{"start":{"row":20,"column":6},"end":{"row":20,"column":8},"action":"insert","lines":["()"],"id":45}],[{"start":{"row":20,"column":7},"end":{"row":20,"column":8},"action":"insert","lines":["%"],"id":46},{"start":{"row":20,"column":8},"end":{"row":20,"column":9},"action":"insert","lines":["s"]}],[{"start":{"row":20,"column":8},"end":{"row":20,"column":9},"action":"remove","lines":["s"],"id":47},{"start":{"row":20,"column":7},"end":{"row":20,"column":8},"action":"remove","lines":["%"]}],[{"start":{"row":20,"column":7},"end":{"row":20,"column":9},"action":"insert","lines":["\"\""],"id":48}],[{"start":{"row":20,"column":8},"end":{"row":20,"column":9},"action":"insert","lines":["%"],"id":49},{"start":{"row":20,"column":9},"end":{"row":20,"column":10},"action":"insert","lines":["s"]}],[{"start":{"row":20,"column":10},"end":{"row":20,"column":11},"action":"remove","lines":["\""],"id":50}],[{"start":{"row":20,"column":10},"end":{"row":20,"column":11},"action":"insert","lines":["\\"],"id":51},{"start":{"row":20,"column":11},"end":{"row":20,"column":12},"action":"insert","lines":["n"]},{"start":{"row":20,"column":12},"end":{"row":20,"column":13},"action":"insert","lines":["\""]}],[{"start":{"row":20,"column":13},"end":{"row":20,"column":14},"action":"insert","lines":[","],"id":52}],[{"start":{"row":20,"column":14},"end":{"row":20,"column":15},"action":"insert","lines":[" "],"id":53},{"start":{"row":20,"column":15},"end":{"row":20,"column":16},"action":"insert","lines":["a"]},{"start":{"row":20,"column":16},"end":{"row":20,"column":17},"action":"insert","lines":["n"]},{"start":{"row":20,"column":17},"end":{"row":20,"column":18},"action":"insert","lines":["s"]},{"start":{"row":20,"column":18},"end":{"row":20,"column":19},"action":"insert","lines":["w"]},{"start":{"row":20,"column":19},"end":{"row":20,"column":20},"action":"insert","lines":["e"]},{"start":{"row":20,"column":20},"end":{"row":20,"column":21},"action":"insert","lines":["r"]}],[{"start":{"row":15,"column":20},"end":{"row":15,"column":21},"action":"insert","lines":[";"],"id":54}],[{"start":{"row":20,"column":22},"end":{"row":20,"column":23},"action":"insert","lines":[";"],"id":55}],[{"start":{"row":11,"column":5},"end":{"row":11,"column":6},"action":"insert","lines":["i"],"id":56},{"start":{"row":11,"column":6},"end":{"row":11,"column":7},"action":"insert","lines":["n"]},{"start":{"row":11,"column":7},"end":{"row":11,"column":8},"action":"insert","lines":["t"]}],[{"start":{"row":11,"column":8},"end":{"row":11,"column":9},"action":"insert","lines":[" "],"id":57}],[{"start":{"row":15,"column":4},"end":{"row":15,"column":5},"action":"insert","lines":["s"],"id":58},{"start":{"row":15,"column":5},"end":{"row":15,"column":6},"action":"insert","lines":["t"]},{"start":{"row":15,"column":6},"end":{"row":15,"column":7},"action":"insert","lines":["r"]},{"start":{"row":15,"column":7},"end":{"row":15,"column":8},"action":"insert","lines":["i"]},{"start":{"row":15,"column":8},"end":{"row":15,"column":9},"action":"insert","lines":["n"]},{"start":{"row":15,"column":9},"end":{"row":15,"column":10},"action":"insert","lines":["g"]}],[{"start":{"row":15,"column":10},"end":{"row":15,"column":11},"action":"insert","lines":[" "],"id":59}],[{"start":{"row":9,"column":13},"end":{"row":9,"column":14},"action":"remove","lines":[";"],"id":60}],[{"start":{"row":9,"column":7},"end":{"row":9,"column":13},"action":"remove","lines":["answer"],"id":61}],[{"start":{"row":9,"column":6},"end":{"row":9,"column":7},"action":"remove","lines":[" "],"id":62}],[{"start":{"row":9,"column":0},"end":{"row":9,"column":6},"action":"remove","lines":["string"],"id":63}],[{"start":{"row":8,"column":0},"end":{"row":9,"column":0},"action":"remove","lines":["",""],"id":64}],[{"start":{"row":12,"column":16},"end":{"row":12,"column":26},"action":"remove","lines":["get_string"],"id":65}],[{"start":{"row":12,"column":16},"end":{"row":12,"column":17},"action":"insert","lines":["g"],"id":66},{"start":{"row":12,"column":17},"end":{"row":12,"column":18},"action":"insert","lines":["e"]},{"start":{"row":12,"column":18},"end":{"row":12,"column":19},"action":"insert","lines":["t"]},{"start":{"row":12,"column":19},"end":{"row":12,"column":20},"action":"insert","lines":["_"]},{"start":{"row":12,"column":20},"end":{"row":12,"column":21},"action":"insert","lines":["c"]},{"start":{"row":12,"column":21},"end":{"row":12,"column":22},"action":"insert","lines":["a"]},{"start":{"row":12,"column":22},"end":{"row":12,"column":23},"action":"insert","lines":["h"]}],[{"start":{"row":12,"column":22},"end":{"row":12,"column":23},"action":"remove","lines":["h"],"id":67},{"start":{"row":12,"column":21},"end":{"row":12,"column":22},"action":"remove","lines":["a"]}],[{"start":{"row":12,"column":21},"end":{"row":12,"column":22},"action":"insert","lines":["h"],"id":68},{"start":{"row":12,"column":22},"end":{"row":12,"column":23},"action":"insert","lines":["a"]},{"start":{"row":12,"column":23},"end":{"row":12,"column":24},"action":"insert","lines":["r"]}],[{"start":{"row":12,"column":37},"end":{"row":12,"column":38},"action":"remove","lines":["g"],"id":69},{"start":{"row":12,"column":36},"end":{"row":12,"column":37},"action":"remove","lines":["n"]},{"start":{"row":12,"column":35},"end":{"row":12,"column":36},"action":"remove","lines":["i"]},{"start":{"row":12,"column":34},"end":{"row":12,"column":35},"action":"remove","lines":["r"]},{"start":{"row":12,"column":33},"end":{"row":12,"column":34},"action":"remove","lines":["t"]},{"start":{"row":12,"column":32},"end":{"row":12,"column":33},"action":"remove","lines":["s"]}],[{"start":{"row":12,"column":32},"end":{"row":12,"column":33},"action":"insert","lines":["c"],"id":70},{"start":{"row":12,"column":33},"end":{"row":12,"column":34},"action":"insert","lines":["h"]},{"start":{"row":12,"column":34},"end":{"row":12,"column":35},"action":"insert","lines":["a"]},{"start":{"row":12,"column":35},"end":{"row":12,"column":36},"action":"insert","lines":["r"]},{"start":{"row":12,"column":36},"end":{"row":12,"column":37},"action":"insert","lines":["a"]},{"start":{"row":12,"column":37},"end":{"row":12,"column":38},"action":"insert","lines":["c"]},{"start":{"row":12,"column":38},"end":{"row":12,"column":39},"action":"insert","lines":["t"]},{"start":{"row":12,"column":39},"end":{"row":12,"column":40},"action":"insert","lines":["e"]},{"start":{"row":12,"column":40},"end":{"row":12,"column":41},"action":"insert","lines":["r"]}],[{"start":{"row":6,"column":30},"end":{"row":6,"column":32},"action":"remove","lines":["[]"],"id":71}],[{"start":{"row":6,"column":26},"end":{"row":6,"column":30},"action":"remove","lines":["argv"],"id":72}],[{"start":{"row":6,"column":25},"end":{"row":6,"column":26},"action":"remove","lines":[" "],"id":73}],[{"start":{"row":6,"column":19},"end":{"row":6,"column":25},"action":"remove","lines":["string"],"id":74}],[{"start":{"row":6,"column":18},"end":{"row":6,"column":19},"action":"remove","lines":[" "],"id":75}],[{"start":{"row":6,"column":17},"end":{"row":6,"column":18},"action":"remove","lines":[","],"id":76}],[{"start":{"row":6,"column":13},"end":{"row":6,"column":17},"action":"remove","lines":["argc"],"id":77}],[{"start":{"row":6,"column":12},"end":{"row":6,"column":13},"action":"remove","lines":[" "],"id":78}],[{"start":{"row":6,"column":9},"end":{"row":6,"column":12},"action":"remove","lines":["int"],"id":79}],[{"start":{"row":14,"column":17},"end":{"row":14,"column":18},"action":"insert","lines":[";"],"id":80}],[{"start":{"row":14,"column":18},"end":{"row":15,"column":0},"action":"insert","lines":["",""],"id":81},{"start":{"row":15,"column":0},"end":{"row":15,"column":4},"action":"insert","lines":["    "]},{"start":{"row":15,"column":4},"end":{"row":15,"column":5},"action":"insert","lines":["a"]},{"start":{"row":15,"column":5},"end":{"row":15,"column":6},"action":"insert","lines":["n"]},{"start":{"row":15,"column":6},"end":{"row":15,"column":7},"action":"insert","lines":["s"]},{"start":{"row":15,"column":7},"end":{"row":15,"column":8},"action":"insert","lines":["w"]},{"start":{"row":15,"column":8},"end":{"row":15,"column":9},"action":"insert","lines":["e"]},{"start":{"row":15,"column":9},"end":{"row":15,"column":10},"action":"insert","lines":["r"]}],[{"start":{"row":5,"column":0},"end":{"row":6,"column":0},"action":"insert","lines":["",""],"id":82},{"start":{"row":6,"column":0},"end":{"row":7,"column":0},"action":"insert","lines":["",""]}],[{"start":{"row":6,"column":0},"end":{"row":6,"column":1},"action":"insert","lines":["s"],"id":83},{"start":{"row":6,"column":1},"end":{"row":6,"column":2},"action":"insert","lines":["t"]},{"start":{"row":6,"column":2},"end":{"row":6,"column":3},"action":"insert","lines":["r"]},{"start":{"row":6,"column":3},"end":{"row":6,"column":4},"action":"insert","lines":["i"]},{"start":{"row":6,"column":4},"end":{"row":6,"column":5},"action":"insert","lines":["n"]},{"start":{"row":6,"column":5},"end":{"row":6,"column":6},"action":"insert","lines":["g"]}],[{"start":{"row":6,"column":6},"end":{"row":6,"column":7},"action":"insert","lines":[" "],"id":84},{"start":{"row":6,"column":7},"end":{"row":6,"column":8},"action":"insert","lines":["a"]},{"start":{"row":6,"column":8},"end":{"row":6,"column":9},"action":"insert","lines":["n"]},{"start":{"row":6,"column":9},"end":{"row":6,"column":10},"action":"insert","lines":["s"]},{"start":{"row":6,"column":10},"end":{"row":6,"column":11},"action":"insert","lines":["w"]},{"start":{"row":6,"column":11},"end":{"row":6,"column":12},"action":"insert","lines":["e"]},{"start":{"row":6,"column":12},"end":{"row":6,"column":13},"action":"insert","lines":["r"]}],[{"start":{"row":6,"column":13},"end":{"row":6,"column":14},"action":"insert","lines":[";"],"id":85}],[{"start":{"row":16,"column":17},"end":{"row":16,"column":18},"action":"remove","lines":[";"],"id":86}],[{"start":{"row":16,"column":11},"end":{"row":16,"column":17},"action":"remove","lines":["answer"],"id":87}],[{"start":{"row":16,"column":10},"end":{"row":16,"column":11},"action":"remove","lines":[" "],"id":88}],[{"start":{"row":16,"column":4},"end":{"row":16,"column":10},"action":"remove","lines":["string"],"id":89}],[{"start":{"row":16,"column":0},"end":{"row":16,"column":4},"action":"remove","lines":["    "],"id":90},{"start":{"row":15,"column":0},"end":{"row":16,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":25,"column":0},"end":{"row":26,"column":0},"action":"remove","lines":["",""],"id":91},{"start":{"row":24,"column":0},"end":{"row":25,"column":0},"action":"remove","lines":["",""]},{"start":{"row":23,"column":0},"end":{"row":24,"column":0},"action":"remove","lines":["",""]},{"start":{"row":22,"column":0},"end":{"row":23,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":22,"column":0},"end":{"row":23,"column":0},"action":"remove","lines":["",""],"id":92},{"start":{"row":22,"column":0},"end":{"row":23,"column":0},"action":"remove","lines":["",""]},{"start":{"row":22,"column":0},"end":{"row":23,"column":0},"action":"remove","lines":["",""]},{"start":{"row":22,"column":0},"end":{"row":23,"column":0},"action":"remove","lines":["",""]},{"start":{"row":22,"column":0},"end":{"row":23,"column":0},"action":"remove","lines":["",""]}],[{"start":{"row":6,"column":13},"end":{"row":6,"column":15},"action":"insert","lines":["[]"],"id":93}],[{"start":{"row":6,"column":14},"end":{"row":6,"column":15},"action":"insert","lines":["1"],"id":94},{"start":{"row":6,"column":15},"end":{"row":6,"column":16},"action":"insert","lines":["0"]}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":9,"column":1},"end":{"row":9,"column":1},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1523556748729,"hash":"daa8e33cee98fcb69eccf2382000caed212e7c1b"}