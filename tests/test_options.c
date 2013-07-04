//#include "../options/m6_options.h"
#include <stdio.h>

#include "../deps/libcgen/vector.h"
#include "../options/m6_options.h"
#include "../log/log.h"

USE_M6_LOGGER_DEFAULT;
USE_M6_OPTIONS;

struct {
    u64     opt1;
    i64     opt2;
    m6_bool opt3;
    char*   opt4;
    double  opt5;
} options;


int main(int argc, char** argv)
{
    m6_opt_addu(M6_OPTION_OPTIONAL,'a',"first","This is the 1st option", &options.opt1, 43);
    m6_opt_addi(M6_OPTION_OPTIONAL,'b',"second","This is the 2nd option", &options.opt2, -43);
    m6_opt_addb(M6_OPTION_OPTIONAL,'c',"third","This is the 3rd option", &options.opt3, true);
    m6_opt_adds(M6_OPTION_OPTIONAL,'d',"fourth","This is the 4th option", &options.opt4, "ha ha");
    m6_opt_addf(M6_OPTION_OPTIONAL,'e',"fifth","This is the 5th option", &options.opt5, 43.0);
    m6_opt_parse(argc,argv);

    printf("a=%lu, b=%li, c=%i, d=%s, e=%lf\n", options.opt1, options.opt2, options.opt3, options.opt4, options.opt5);


    return 0;
}