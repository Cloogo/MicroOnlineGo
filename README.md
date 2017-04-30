Introduction:

server for Play Go Online.

How to install:

tar -xvf MicroOnlineGo-1.0.tar.gz
cd MicroOnlineGo-1.0

1.install libzdb

cd server/lib/zdb
./configure
make
make install

2.build and run go server
cd server/
./configure
make
cd src
service mysql start
LD_LIBRARY_PATH=/usr/local/lib/ ./MicroOnlineGo

