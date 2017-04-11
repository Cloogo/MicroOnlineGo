#  High level

***

##  Use Case

![usecase](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/usecase.jpg )

***

## Critical Bussiness

    Due to the limitation of development cycle and developers' skill,in the next thirty days,
    we will try to finish the following bussiness:
    * login/regist/logout
    * select room
    * select desk
    * view players information
    * SmartGo Pro

***

## Logic Design

    Description:
    Use C/S model to develop a LAN online game for Go,
    neglecting loading balance and security.

        __________________________________________________________________________________________________________________
       /server:c++                                                                                                        \
       |                _ _ _ _ _ _ _ _ _        _____________           _ _ _ _ _ _ _       _ _ _ _ _ _ _                 |
       |               /**Business Layer**\     /**Msg agent**\         /  **Json**   \     /**Http Layer**\               |
       |   _ _ _       |-------------------|    |-------------|         |--------------|    |--------------|               |
       | /**DB**\      |  Login/Register   |-- >|   generate  |-------->|  Encode      |    |  Accept      |<---+          |
       | |-------|     |-------------------|    |             |         |              |--->|--------------|    |          |
       | |       |--- >|   Room Manager    |    |-------------|         |--------------|    |  Send        |--+ |          |
       | | Mysql |     |-------------------|< --|   dispatch  |<--------|              |    |--------------|  | |          |
       | \ _ _ _ /< ---|    Chat           |    |             |         |  Decode      |<---|  Recv        |<-|-|-+        |
       |               |-------------------|    |             |         \ _ _ _ _ _ _ _/    \_ _ _ _ _ _ _ /  | | |        |
       |               |    SmartGo Pro    |    |             |                                               | | |        |
       |               \ _ _ _ _ _ _ _ _ _ /    \_____________/                                               | | |        |
        \_____________________________________________________________________________________________________|_|_|________/
                                                                                                              | | |
                                                                                                        TCP/IP| | |
                                                                                     Connection:**Keep_alive**| | |
        ______________________________________________________________________________________________________|_|_|_________
       / client:java                                                                                          | | |        \
       |                                                                                                      | | |        |
       |                 _ _ _ _ _ _ _           _____________           _ _ _ _ _ _     _ _ _ _ _ _ _ _      | | |        |
       |                /  **GUI**    \         /**Msg agent**\         / **Json**  \   /**Http Layer**  \    | | |        | 
       |               |--------------|         |-------------|        |------------|  |-----------------|    | | |        |
       |               |Login/Register|<--------|   dispatch  |<-------| Decode     |  |   Connect       |------+ |        |
       |               |--------------|         |             |        |            |  |-----------------|    |   |        |
       |               | Game Lobby   |         |-------------|        |            |<-| Recv Thread     |<---+   |        |
       |               |--------------|         |             |        |------------|  |-----------------|        |        |
       |               | Chat room    |-------->|   generate  |------->| Encode     |->| Send Thread     |--------+        |
       |   _ _ _ _     |              |         |             |        \ _ _ _ _ _ _/  |-----------------|                 |
       |  /**DB** \ -->| SmartGo Pro  |         |             |                        |   Close         |                 |
       |  |-------|<---|--------------|         |             |                        \  _ _ _ _ _ _ _ _/                 |
       |  |SQLite |    |   Logout     |         \_____________/                                                            |
       |  |_ _ _ _|    \_ _ _ _ _ _ _ /                                                                                    |
       \___________________________________________________________________________________________________________________/


*** 

## GUI switch(Provided by Alinshans)

![guiswitch](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/guiswitch.jpg )

***

## Screen Navigation

###     Entrance

        Description:
        After successfully establishing connection to the server,
        the application will display the following window:

![entrance](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/entrance.jpg )

###     Game Lobby

        Description:
        After successfully doing the operation "login"/"regist" in Entrance,
        the application will display the following window:

![gamelobby](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/lobby.jpg )

###     SmartGo Pro

        Description:
        After successfully doing the operation "sitdown" in Game Lobby,
        the application will display the following window:

![gopro](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/gopro.jpg )


###     Chess Manual List
     
        Description:
        After successfully doing the operation "chess manual" in Game Lobby,
        the application will display the following window:

![chessmanuallist](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/chessmanuallist.jpg)

###     Chess Manual
       
        Description:
        After successfully doing the operation "view" in Chess Manual List,
        the application will display the following window:

![chessmanual](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/chessmanual.jpg)
        
###     Rank List

        Description:
        After successfully doing the operation "rank list" in Game Lobby,
        the application will display the following window:

![ranklist](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/ranklist.jpg)

***

## Module(Provided by Alinshans)

![module1](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/module1.jpg)
