AUTOMAKE_OPTIONS=foreign
bin_PROGRAMS=MicroOnlineGo
AM_CPPFLAGS=-g -I$(top_srcdir)/include -I$(top_srcdir)/include/zdb -std=c++11
AM_LDFLAGS=-pthread -lrt `mysql_config --libs`
MicroOnlineGo_SOURCES=SqlManager.cc SqlManager.h\
					  SqlStm.h\
					  Proto.h\
					  RoomManager.cc RoomManager.h\
					  PairManager.cc PairManager.h\
					  PacketParser.cc PacketParser.h\
					  Account.cc Account.h\
					  Nickname.cc Nickname.h\
					  Login.cc Login.h\
					  Logout.cc Logout.h\
					  Regist.cc Regist.h\
					  PlayerInfo.cc PlayerInfo.h\
					  PlayersInfo.cc PlayersInfo.h\
					  NewRoom.cc NewRoom.h\
					  NewRival.cc NewRival.h\
					  Handshake.cc Handshake.h\
					  RoomInfo.cc RoomInfo.h\
					  LobbyInfo.cc LobbyInfo.h\
					  GroupChat.cc GroupChat.h\
					  ChessInfo.cc ChessInfo.h\
					  SinglecastMsg.cc SinglecastMsg.h\
					  GameResult.cc GameResult.h\
					  GoServer.cc GoServer.h\
					  main.cc
MicroOnlineGo_LDADD=../lib/muduo/libmuduo_net.a\
		   ../lib/muduo/libmuduo_base.a\
		   ../lib/redbud/parser/libjson.a\
		   ../lib/zdb/libzdb.a

#bin_PROGRAMS=json_test
#json_test_SOURCES=json_test.cc
#json_test_LDADD=../lib/redbud/parser/libjson.a
