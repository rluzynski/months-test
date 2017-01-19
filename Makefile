all:	months today

months:	months.c
	$(CC) -o months months.c

today:	today.c
	$(CC) -o today today.c

