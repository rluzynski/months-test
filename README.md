Months
======

These programs are to test how months are displayed on different versions
of Linux with different locales.  Also it's worth noting that its behaviour
may depend on the glibc version installed.  I'm currently working on
providing some new features to nl_langinfo() and strftime() families.
These features will work on the newest (patched) systems only but binaries
built for older systems should work on newer systems without any change.
For more details and patches see:
https://sourceware.org/bugzilla/show_bug.cgi?id=10871

Building
========

Just type:

```
    make
```

Due to differences between system I encourage you to build on multiple
systems and then copy binaries to another system.  If you haven't got
multiple computers then you can set up a virtual machine.  If you can't
set up a virtual machine then you can build and run under mock configured
to simulate some older version of Linux.  You can also use any other
chroot or LD_LIBRARY_PATH techniques to simulate running under a different
version of Linux.

Running
=======

```
    ./months
```

will display all month names

```
    ./today
```

will display today's date.  Note if the date is displayed correctly, if
the month name is correct according to your language rules.

Then test under different locales:

```
    LANG=<language>_<territory>.<encoding> ./months
    LANG=<language>_<territory>.<encoding> ./today
```

Examples are: ```LANG=pl_PL.utf8```, ```LANG=cs_CZ.utf8```,
```LANG=uk_UA.utf8```, ```LANG=ca_ES.utf8```, and so on. If ```LANG```
does not work try ```LC_ALL```. If ```utf8``` does not work try ```UTF-8```.

