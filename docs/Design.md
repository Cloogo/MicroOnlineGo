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

    Description:Use C/S model to develop an instant online game for Go,neglecting loading
    balance and security.

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
                                                                                                              | | |TCP/IP
                                                                                                              | | |Connection:**Keep_alive**
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

***

### entrance

![entrance](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/entrance.jpg )

### game lobby

![gamelobby](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/lobby.jpg )

### SmartGo Pro

![gopro](https://github.com/Cloogo/MicroOnlineGo/blob/master/docs/gopro.jpg )
