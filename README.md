# Linux-XMC-Development
GNU toolchain for XMC software development



# Automake Initialization of new Project

Most of the following explanations how to create a new automake project is perfectly explained on
http://mij.oltrelinux.com/devel/autoconf-automake/

## Initialization
To create a new automake project, only two files and the src directory are necessary:
- configure.ac
- Makefile.am
- src/

## Command line tool sequence
Please execute the following commands in order to use automake to create a makefile

```{r, engine='bash', count_lines}
aclocal
autoconf
automake --add-missing
configure.ac:10: installing './compile'
configure.ac:7: installing './install-sh'
configure.ac:7: installing './missing'
Makefile.am: installing './INSTALL'
Makefile.am: error: required file './NEWS' not found
Makefile.am: error: required file './README' not found
Makefile.am: error: required file './AUTHORS' not found
Makefile.am: error: required file './ChangeLog' not found
Makefile.am: installing './COPYING' using GNU General Public License v3 file
Makefile.am:     Consider adding the COPYING file to the version control system 
Makefile.am:     for your code, to avoid questions about which license your project uses
Makefile.am: installing './depcomp' 
Makefile.am:12: warning: 'CFLAGS' is a user variable, you should not override it; 
Makefile.am:12: use 'AM_CFLAGS' instead
```

To mitigate the four error messages, add a NEWS, README, AUTHORS and ChangeLog file to the project.
```{r, engine='bash', count_lines}
echo "" > NEWS
echo "" > README
echo "" > AUTHORS
echo "" > ChangeLog
```

Executing automake --add-missing should work now.





## Compile and Link

The following command must be executed only to reconfigure the Makefile after the source directory structure has changed.
```{r, engine='bash', count_lines}
./configure
```

If there are only changes to the source files, it's sufficient to execute
```{r, engine='bash', count_lines}
make
```
















