q := @
topdir := $(CURDIR)
srcdir := $(topdir)/src
incdir := $(topdir)/inc
testdir := $(topdir)/test

test := $(testdir)/led-test
out := leo.o
lds := leo.ld
obj :=

-include $(srcdir)/build
obj := $(patsubst %,$(srcdir)/%,$(obj-y))

pfx := arm-unknown-linux-gnueabi-
-include $(topdir)/config

cc  := $(pfx)gcc
cxx := $(pfx)g++
as  := $(pfx)as
ar  := $(pfx)ar
ld  := $(pfx)ld

common-flags := -I$(incdir) -march=armv7-m -mthumb
common-cflags := -Wall -nostdlib -O0 -pedantic

asflags  := $(common-flags)
cflags   := $(common-flags) $(common-cflags) -std=gnu99
cxxflags := $(common-flags) $(common-cflags) -fno-exceptions -std=gnu++98

all: $(out) $(test)

clean:
	rm -f $(out)
	rm -f $(obj)
	rm -f $(test) $(testdir)/led-test.o

$(out): $(lds) $(obj)
	@echo "  LD    $(notdir $@)"
	$(q)$(ld) -r -o $@ $(obj)
	
$(test): $(out) $(testdir)/led-test.o
	$(ld) -o $@ -T $(lds) $^

%.o: %.c
	@echo "  CC    $(notdir $@)"
	$(q)$(cc) -c -o $@ $(cflags) $<

%.o: %.cpp
	@echo "  C++   $(notdir $@)"
	$(q)$(cxx) -c -o $@ $(cxxflags) $<

%.o: %.S
	@echo "  AS    $(notdir $@)"
	$(q)$(as) -o $@ $(asflags) $<
