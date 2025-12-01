ifeq ($(OS),Windows_NT)
OSDIR			= _windows
STATIC_BUILD	= $(OSDIR)/lib/libMLV.a
DLL_BUILD		= $(OSDIR)/bin/libMLV.dll
IMPLIB_BUILD	= $(OSDIR)/lib/libMLV.dll.a
else
OSDIR			= _linux
STATIC_BUILD	= $(OSDIR)/lib/libMLV.all
DLL_BUILD		= $(OSDIR)/bin/libMLV.so
IMPLIB_BUILD	= $(OSDIR)/lib/libMLV.so
endif

SRC 	= $(wildcard MLV/*.c)
OBJ 	= $(subst MLV,$(OSDIR)/build,$(patsubst %.c,%.o,$(SRC)))

INCLUDE = -I ./include -I ./include/MLV -I ./include/SDL -I ./include/glib  -I ./include/libxml
LIB 	= -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lxml2
CCARGS	= -Wall -Wextra -Werror -O2 -fPIC -std=c17 -flto=auto

EXTRA	= -D_GNU_SOURCE -DMLV_BUILD

all: createDirs $(OBJ)
	@printf "Building dynamic library... "
ifeq ($(OS),Windows_NT)
	@gcc -shared -o $(DLL_BUILD) $(OBJ) $(LIB) $(CCARGS) -Wl,--out-implib=$(IMPLIB_BUILD)
else
	@gcc -shared -fPIC -o $(DLL_BUILD) $(OBJ) $(LIB) $(CCARGS)
	@cp $(DLL_BUILD) $(IMPLIB_BUILD)
endif
	@printf "Done\n"

remake: clean all


createDirs:
	@printf "Creating build dirs... "
	@mkdir -p $(OSDIR)/bin $(OSDIR)/build $(OSDIR)/lib
	@printf "Done\n"

clean:
	@printf "Cleaning build dir... "
	@rm -f $(OSDIR)/build/*
	@printf "Done\n"

$(OSDIR)/build/%.o: MLV/%.c
	@echo Compiling $*.c
	@gcc -c MLV/$*.c -o $(OSDIR)/build/$*.o $(INCLUDE) $(LIB) $(CCARGS) $(EXTRA)

release:
	mkdir -p MLV-release/
	cp -r bin MLV-release/bin
	cp -r data MLV-release/bin/data
	cp -r include/MLV MLV-release/MLV
	zip -r MLV.zip MLV-release
	rm -rf MLV-release/
