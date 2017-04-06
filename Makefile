all:	months today glib2test

months:	months.c
	$(CC) -o months months.c

today:	today.c
	$(CC) -o today today.c

glib2test:	glib2test.c
	$(CC) -o glib2test glib2test.c `pkg-config --cflags --libs glib-2.0`

