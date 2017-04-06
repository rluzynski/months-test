#include <stdio.h>
#include <locale.h>
#include <glib.h>

static void do_one_test(const char *format, GDateTime *date)
{
    gchar *formatted;
    formatted = g_date_time_format (date, format);
    printf ("%s\n", formatted);
    g_free (formatted);
}

static void do_test(const char *format, GDateTime *date1,
    GDateTime *date2, GDateTime *date3)
{
    do_one_test (format, date1);
    do_one_test (format, date2);
    do_one_test (format, date3);
}

void main()
{
    locale_t loc;
    GDateTime *today, *in_april, *in_may;
    int year_today;

    setlocale (LC_ALL, "");
    loc = newlocale (LC_ALL, "", (locale_t) 0);
    if (!loc) {
        perror("newlocale");
        fprintf(stderr, "Switching to default \"C\" locale\n");
        loc = newlocale (LC_ALL, "C", (locale_t) 0);
        if (!loc)
            perror("newlocale");
    }

    today = g_date_time_new_now_local ();
    year_today = g_date_time_get_year (today);
    in_april = g_date_time_new_local (year_today, 4, 24, 0, 0, 0);
    in_may = g_date_time_new_local (year_today, 5, 25, 0, 0, 0);

    printf("Testing %%B (long month name)\n");
    do_test ("%d %B %Y", today, in_april, in_may);
    printf("\nTesting %%OB (long month name, standalone)\n");
    do_test ("%d %OB %Y", today, in_april, in_may);
    printf("\nTesting %%b (abbreviated month name)\n");
    do_test ("%d %b %Y", today, in_april, in_may);
    printf("\nTesting %%Ob (abbreviated month name, standalone)\n");
    do_test ("%d %Ob %Y", today, in_april, in_may);
}

