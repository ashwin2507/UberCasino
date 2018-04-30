

OSPL_LIBS = -lpthread -lddskernel -ldcpssacpp
LIBS=-L${OSPL_HOME}/lib ${OSPL_LIBS} -lboost_system -lboost_thread

CFLAGS = -DDEBUG_PRINT -DDEBUG_STATES -Wall -O0 -g -I. -I./include -I${OSPL_HOME}/include/dcps/C++/SACPP -I${OSPL_HOME}/include/sys
CXXFLAGS = -std=c++11
LDFLAGS  = $(shell fltk-config --use-gl --use-images --ldflags --compile)
INCLUDE =  -I/usr/local/include/ -I/usr/local/lib/

all: PitBoss Dealer Player


IDL_GENERATED_H= \
                 ccpp_UberCasino.h \
                 UberCasinoDcps.h \
                 UberCasinoDcps_impl.h \
                 UberCasino.h \
                 UberCasinoSplDcps.h 

IDL_GENERATED_CPP=\
                 UberCasino.cpp \
                 UberCasinoDcps.cpp \
                 UberCasinoDcps_impl.cpp \
                 UberCasinoSplDcps.cpp

IDL_GENERATED=${IDL_GENERATED_H} ${IDL_GENERATED_CPP}

${IDL_GENERATED}: idl/UberCasino.idl
	${OSPL_HOME}/bin/idlpp -l cpp idl/UberCasino.idl

COMMON_CPP= src/CheckStatus.cpp src/DDSEntityManager.cpp 

COMMON_H= src/io.h src/CheckStatus.h src/DDSEntityManager.h 

DEALER_FILES = src/dealer.cpp src/deck.cpp
DEALER_H_FILES = src/dealer.h src/deck.h src/start_window.h src/mainwindow.h

PLAYER_FILES = src/player.cpp
PLAYER_H_FILES = src/player.h

PitBoss: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} src/PitBoss.cpp
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LDFLAGS} ${LIBS} ${INCLUDE}

Dealer: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} src/Dealer.cpp ${DEALER_FILES} ${DEALER_H_FILES}  ${COMMON_H} ${COMMON_CPP}
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LDFLAGS} ${LIBS} ${INCLUDE}

Player: ${IDL_GENERATED_H} ${IDL_GENERATED_CPP} src/Player.cpp ${PLAYER_FILES} ${PLAYER_H_FILES} ${COMMON_H} ${COMMON_CPP}
	g++ -o $@ ${CFLAGS} ${CXXFLAGS} $^ ${LDFLAGS} ${LIBS} ${INCLUDE}

clean:
	-rm -f PitBoss Player Dealer
	-rm -f ${IDL_GENERATED_H} ${IDL_GENERATED_CPP}
	-rm -f ospl-error.log ospl-info.log
