# Server for play go online.

# Required

 * linux environment
 * g++4.8 or later
 
# How to install:

 * git clone or downloads this repository and decompress the `tar.gz` file

```
tar -xvf MicroOnlineGo-1.0.tar.gz
cd MicroOnlineGo-1.0
```

 * install libzdb

```
    cd server/lib/zdb
    ./configure
    make
    make install
```

 * build and run go server

 ```
    cd server/
    ./configure
    make
    cd src
    service mysql start
    mysql < sql/sql/init.sql
    LD_LIBRARY_PATH=/usr/local/lib/ ./MicroOnlineGo
```

