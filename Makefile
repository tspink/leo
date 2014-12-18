export leodir := $(CURDIR)
-include build/Makefile.defs

out := leo.o
lds := leo.ld
obj :=

-include $(srcdir)/build
obj := $(patsubst %,$(srcdir)/%,$(obj-y))
dep := $(patsubst %.o,%.d,$(obj))

-include build/Makefile.build

all: $(out) $(test)

clean:
	rm -f $(out)
	rm -f $(obj)
	rm -f $(dep)

$(out): $(lds) $(obj)
	@echo "  LD    $(notdir $@)"
	$(q)$(ld) -r -o $@ $(obj)
	
-include $(dep)
