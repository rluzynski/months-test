/**
 * This program demonstrates and tests how the today's date is formatted
 * with different functions from strftime() family, with both %B and %OB
 * format specifiers.  Please test it with different locales.
 */

#include <stdio.h>
#include <langinfo.h>
#include <locale.h>
#include <time.h>

#define __USE_GNU
#include <wchar.h>

extern typeof (strftime_l) __strftime_l;
extern typeof (wcsftime_l) __wcsftime_l;

void main()
{
    time_t t;
    locale_t loc;
    struct tm tm;
    char buf[100];
    wchar_t wbuf[100];

    setlocale (LC_ALL, "");
    loc = newlocale (LC_ALL, "", (locale_t) 0);
    if (!loc) {
        perror("newlocale");
        fprintf(stderr, "Switching to default \"C\" locale\n");
        loc = newlocale (LC_ALL, "C", (locale_t) 0);
        if (!loc)
            perror("newlocale");
    }

    time (&t);
    localtime_r (&t, &tm);

    strftime (buf, 100, "%d %B %Y", &tm);
    printf ("Today (%%B): %s\n", buf);
    strftime (buf, 100, "%d %OB %Y", &tm);
    printf ("Today (%%OB): %s\n", buf);
    strftime (buf, 100, "%d %b %Y", &tm);
    printf ("Today (%%b): %s\n", buf);
    strftime (buf, 100, "%d %Ob %Y", &tm);
    printf ("Today (%%Ob): %s\n\n", buf);

    wcsftime (wbuf, 100, L"%d %B %Y", &tm);
    printf ("Today (wide char, %%B): %ls\n", wbuf);
    wcsftime (wbuf, 100, L"%d %OB %Y", &tm);
    printf ("Today (wide char, %%OB): %ls\n", wbuf);
    wcsftime (wbuf, 100, L"%d %b %Y", &tm);
    printf ("Today (wide char, %%b): %ls\n", wbuf);
    wcsftime (wbuf, 100, L"%d %Ob %Y", &tm);
    printf ("Today (wide char, %%Ob): %ls\n\n", wbuf);

    __strftime_l (buf, 100, "%d %B %Y", &tm, loc);
    printf ("Today (__strftime_l, %%B): %s\n", buf);
    __strftime_l (buf, 100, "%d %OB %Y", &tm, loc);
    printf ("Today (__strftime_l, %%OB): %s\n", buf);
    __strftime_l (buf, 100, "%d %b %Y", &tm, loc);
    printf ("Today (__strftime_l, %%b): %s\n", buf);
    __strftime_l (buf, 100, "%d %Ob %Y", &tm, loc);
    printf ("Today (__strftime_l, %%Ob): %s\n\n", buf);

    __wcsftime_l (wbuf, 100, L"%d %B %Y", &tm, loc);
    printf ("Today (__wcsftime_l, wide char, %%B): %ls\n", wbuf);
    __wcsftime_l (wbuf, 100, L"%d %OB %Y", &tm, loc);
    printf ("Today (__wcsftime_l, wide char, %%OB): %ls\n", wbuf);
    __wcsftime_l (wbuf, 100, L"%d %b %Y", &tm, loc);
    printf ("Today (__wcsftime_l, wide char, %%b): %ls\n", wbuf);
    __wcsftime_l (wbuf, 100, L"%d %Ob %Y", &tm, loc);
    printf ("Today (__wcsftime_l, wide char, %%Ob): %ls\n", wbuf);

}
