ifeq ($(OS),Windows_NT)
OSDIR			= _windows
STATIC_BUILD	= $(OSDIR)/lib/libMLV.a
DLL_BUILD		= $(OSDIR)/bin/SSGE.dll
IMPLIB_BUILD	= $(OSDIR)/lib/libMLV.dll.a
else
OSDIR			= _linux
STATIC_BUILD	= $(OSDIR)/lib/libMLV.all
DLL_BUILD		= $(OSDIR)/bin/libMLV.so
IMPLIB_BUILD	= $(OSDIR)/lib/libMLV.so
endif

SRC 	= $(wildcard MLV/*.c)
OBJ 	= $(subst MLV,$(OSDIR)/build,$(patsubst %.c,%.o,$(SRC)))

INCLUDE = -I ./include -I ./include/SDL -I ./include/glib  -I ./include/libxml
LIB 	= -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lglib-2.0 -lxml2
CCARGS	= -Wall -Werror -O2 -fPIC
EXTRA	= -D_GNU_SOURCE

all: createDirs $(OBJ)
	@echo Building dynamic library...
ifeq ($(OS),Windows_NT)
	@gcc -shared -o $(DLL_BUILD) $(OBJ) $(LIB) -Wl,--out-implib=$(IMPLIB_BUILD)
else
	@gcc -shared -fPIC -o $(DLL_BUILD) $(OBJ) $(LIB)
	@cp $(DLL_BUILD) $(IMPLIB_BUILD)
endif

createDirs:
	@echo Creating build dirs...
	@mkdir -p $(OSDIR)/bin $(OSDIR)/build $(OSDIR)/lib

clean:
	rm -f $(OSDIR)/build/*

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

