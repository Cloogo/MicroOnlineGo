AUTOMAKE_OPTIONS=foreign subdir-objects
noinst_LIBRARIES=libmuduo_net.a
INCLUDE=$(top_srcdir)/include/muduo/net
AM_CPPFLAGS=-I$(top_srcdir)/include/
libmuduo_net_a_SOURCES=Acceptor.cc\
					  Buffer.cc\
					  Channel.cc\
					  Connector.cc\
					  EventLoop.cc\
					  EventLoopThread.cc\
					  EventLoopThreadPool.cc\
					  InetAddress.cc\
					  Poller.cc\
					  poller/DefaultPoller.cc\
					  poller/EPollPoller.cc\
					  poller/PollPoller.cc\
					  Socket.cc\
					  SocketsOps.cc\
					  TcpClient.cc\
					  TcpConnection.cc\
					  TcpServer.cc\
					  Timer.cc\
					  TimerQueue.cc\
					$(INCLUDE)/Acceptor.h\
					$(INCLUDE)/boilerplate.h\
					$(INCLUDE)/Buffer.h\
					$(INCLUDE)/Callbacks.h\
					$(INCLUDE)/Channel.h\
					$(INCLUDE)/Connector.h\
					$(INCLUDE)/Endian.h\
					$(INCLUDE)/EventLoop.h\
					$(INCLUDE)/EventLoopThread.h\
					$(INCLUDE)/EventLoopThreadPool.h\
					$(INCLUDE)/InetAddress.h\
					$(INCLUDE)/Poller.h\
					$(INCLUDE)/Socket.h\
					$(INCLUDE)/SocketsOps.h\
					$(INCLUDE)/TcpClient.h\
					$(INCLUDE)/TcpConnection.h\
					$(INCLUDE)/TcpServer.h\
					$(INCLUDE)/Timer.h\
					$(INCLUDE)/TimerId.h\
					$(INCLUDE)/TimerQueue.h\
					$(INCLUDE)/ZlibStream.h\
					$(INCLUDE)/poller/EPollPoller.h\
					$(INCLUDE)/poller/PollPoller.h
