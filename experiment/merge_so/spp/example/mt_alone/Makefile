MT_INCL = ../../include/sync_incl
BIN_DIR := $(shell echo `ls ../.. | grep bin`)

ifeq ($(BIN_DIR), bin)
	MT_LIB = ../../bin/lib
else
	MT_LIB = ../../../bin/lib
endif

CXX = g++
CFLAGS += -g -Wall -Wno-write-strings -Werror
INC += -I$(MT_INCL)
LIB += -L$(MT_LIB) -lmt -ldl -Wl,-rpath,$(MT_LIB)
INSTALL_DIR = ../bin

ifeq ($(ARCH),32)
	CFLAGS += -m32 -march=pentium4
endif

TARGET = mt_alone
OBJ = mt_alone.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) $(LIB) -o $@ $^
	install $(TARGET) $(INSTALL_DIR)

clean:
	@echo -e Clean ...
	@-rm *.o
	@-rm $(TARGET)

%.o: %.cpp
	@echo -e Compiling $< ...
	$(CXX) $(CFLAGS) -c -o $@ $< $(INC)
