/**
 * This program demonstrates and tests how monts are reported by different
 * functions from nl_langinfo() family, referred to as by MON_x and ALTMON_x.
 * Please test it with different locales.
 */

#include <stdio.h>
#include <langinfo.h>
#include <locale.h>
#include <wchar.h>

extern typeof (nl_langinfo_l) __nl_langinfo_l;

/* Print a number and a string.  */
static void print_char(int n, char *str) {
    if (str == NULL)
        str = "NULL";
    else if (!*str)
        str = "(empty string)";
    printf("[%d] %s\n", n, str);
}

/* Print a number and a string as if it was a wchar_t string.
   Results returned from nl_langinfo() are of type char* even if
   they actually contain wchar_t characters.  */
static void print_wchar(int n, char *str) {
    if (str == NULL)
        str = (char*) L"NULL";
    else if (!*str)
        str = (char*) L"(empty string)";
    printf("[%d] %ls\n", n, (wchar_t*) str);
}

/* Retrieves from nl_langinfo() and prints an array of 12 char strings
   starting at base.  */
void array_char(nl_item base) {
    int i;
    char *result;

    for (i = 0; i < 12; ++i)
        print_char(i + 1, nl_langinfo (i + base));
}

/* Retrieves from nl_langinfo() and prints an array of 12 wchar_t strings
   starting at base.  */
void array_wchar(nl_item base) {
    int i;
    char *result;

    for (i = 0; i < 12; ++i)
        print_wchar(i + 1, nl_langinfo (i + base));
}

void main()
{
    locale_t loc;
    char *m;
    setlocale (LC_ALL, "");
    loc = newlocale (LC_ALL, "", (locale_t) 0);
    if (!loc) {
        perror("newlocale");
        fprintf(stderr, "Switching to default \"C\" locale\n");
        loc = newlocale (LC_ALL, "C", (locale_t) 0);
        if (!loc)
            perror("newlocale");
    }

    printf("Months (regular)\n");
    array_char(MON_1);
    printf("\nMonths (alternative)\n");
    array_char(_NL_TIME_CODESET + 1);   /* ALTMON_1 */
    printf("\nMonths (abbreviated)\n");
    array_char(ABMON_1);
    printf("\nMonths (abbreviated alternative)\n");
    array_char(_NL_TIME_CODESET + 25);   /* _NL_ABALTMON_1 */

    printf("\nMonths (wide char)\n");
    array_wchar(_NL_WMON_1);
    printf("\nMonths (wide alternative)\n");
    array_wchar(_NL_TIME_CODESET + 13);   /* _NL_WALTMON_1 */
    printf("\nMonths (wide abbreviated)\n");
    array_wchar(_NL_WABMON_1);
    printf("\nMonths (wide abbreviated alternative)\n");
    array_wchar(_NL_TIME_CODESET + 37);   /* _NL_WABALTMON_1 */

    printf("\nAlso compare __nl_langinfo_l():\n");
    print_char(1, __nl_langinfo_l(MON_1, loc));
    print_char(2, __nl_langinfo_l(MON_2, loc));
    print_char(3, __nl_langinfo_l(MON_3, loc));
    print_char(4, __nl_langinfo_l(MON_4, loc));
    printf("\nAlso compare __nl_langinfo_l() (alternative):\n");
    print_char(1, __nl_langinfo_l(_NL_TIME_CODESET + 1, loc));
    print_char(2, __nl_langinfo_l(_NL_TIME_CODESET + 2, loc));
    print_char(3, __nl_langinfo_l(_NL_TIME_CODESET + 3, loc));
    print_char(4, __nl_langinfo_l(_NL_TIME_CODESET + 4, loc));
    printf("\nAlso compare __nl_langinfo_l() (abbreviated):\n");
    print_char(1, __nl_langinfo_l(ABMON_1, loc));
    print_char(2, __nl_langinfo_l(ABMON_2, loc));
    print_char(3, __nl_langinfo_l(ABMON_3, loc));
    print_char(4, __nl_langinfo_l(ABMON_4, loc));
    print_char(5, __nl_langinfo_l(ABMON_5, loc));
    printf("\nAlso compare __nl_langinfo_l() (abbreviated alternative):\n");
    print_char(1, __nl_langinfo_l(_NL_TIME_CODESET + 25, loc));
    print_char(2, __nl_langinfo_l(_NL_TIME_CODESET + 26, loc));
    print_char(3, __nl_langinfo_l(_NL_TIME_CODESET + 27, loc));
    print_char(4, __nl_langinfo_l(_NL_TIME_CODESET + 28, loc));
    print_char(5, __nl_langinfo_l(_NL_TIME_CODESET + 29, loc));
}
