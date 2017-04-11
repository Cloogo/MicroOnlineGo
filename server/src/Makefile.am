AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS=MicroOnlineGo
AM_CPPFLAGS=-I$(top_srcdir)/include -std=c++11
AM_LDFLAGS=-pthread -lrt
MicroOnlineGo_SOURCES=main.cc\
					  GoServer.cc GoServer.h\
					  RoomManager.cc RoomManager.h\
					  PacketParser.cc PacketParser.h
MicroOnlineGo_LDADD=../lib/muduo/libmuduo_net.a\
		   ../lib/muduo/libmuduo_base.a\
		   ../lib/redbud/parser/libjson.a

bin_PROGRAMS=json_test
AM_CPPFLAGS=-I$(top_srcdir)/include -std=c++11
json_test_SOURCES=json_test.cc
json_test_LDADD=../lib/redbud/parser/libjson.a
