
VERSION=1.0.0

CC  ?= gcc
CCC ?= g++
DST ?= $(shell uname -m )
PACK ?= makepkg -l y -c n 

INSTALL ?= install

BUILDDIR= $(shell uname -m ) 
PACKAGE= keepconf
SOURCES= keepconf.o intern.o xml.o json.o support.o
OBJECTS= $(SOURCES:%.c=$(BUILDDIR)/%.o)
DEPENDS= $(OBJECTS:%.o=%.d) 

DEPS= keepconf.h parse.h

LIB=lib${PACKAGE}-$(VERSION).a
PKG=/var/cache/packages/${DST}/extra/${PACKAGE}-${VERSION}-${DST}-0.txz

CFLAGS= -g -fPIC -dPIC

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cc $(DEPS)
	$(CCC) -c  -o $@ $< $(CFLAGS)

$(LIB): $(SOURCES)
	$(AR) rcs  $@ $(SOURCES) 

all: ${LIB} 

slack: $(LIB) 
	$(INSTALL) -d ${DST}/usr/local/lib/ ${DST}/usr/local/include/
	$(INSTALL) -t ${DST}/usr/local/lib/  ${LIB}
	$(INSTALL) -t ${DST}/usr/local/include/   ${DEPS}
	cd ${DST}/usr/local/lib/; ln -sf $(LIB) lib${PACKAGE}.a
	cd ${DST}; $(PACK) ${PKG}

install: $(LIB) 
	$(INSTALL) -d /usr/local/lib/ /usr/local/include/
	$(INSTALL) -t /usr/local/lib/       ${LIB}
	$(INSTALL) -t /usr/local/include/   ${DEPS}
	cd /usr/local/lib/; ln -sf $(LIB) lib${PACKAGE}.a


