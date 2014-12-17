topdir := $(CURDIR)
srcdir := $(topdir)/src
incdir := $(topdir)/inc

out := leo.a
obj :=

-include $(srcdir)/build

obj := $(patsubst %,$(srcdir)/%,$(obj-y))

pfx := arm-none-eabi-
cc  := $(pfx)gcc
cxx := $(pfx)g++
as  := $(pfx)as
ar  := $(pfx)ar

common-flags := -nostdlib -Wall -I$(incdir)

asflags  := $(common-flags)
cflags   := $(common-flags)
cxxflags := $(common-flags)

all: $(out)

clean:
	rm -f $(out)
	rm -f $(obj)

$(out): $(obj)
	$(ar) t $@ $(obj)

%.o: %.c
	$(cc) -c -o $@ $(cflags) $<

%.o: %.cpp
	$(cxx) -c -o $@ $(cxxflags) $<

%.o: %.S
	$(as) -c -o $@ $(asflags) $<
