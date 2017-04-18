#ifndef _PROTO_H
#define _PROTO_H
enum class REQUEST_TYPE{
    ACCOUNT_CHECK=0,
    FETCH_PLAYER_INFO,
    FETCH_PLAYERS_INFO,
    REGIST,
    LOGIN,
    LOGOUT=5,
    FETCH_LOBBY_INFO,
    FETCH_ROOM_INFO,
    SITDOWN,
    LEAVE,
    READGO=10,
    GIVEUP,
    PLACECHESS,
    GAMEOVER_WINNER,
    GAMEOVER_LOSER,
    SEND_MSG=15,
    GROUP_CHAT
};

enum class RESPONSE_TYPE{
    FETCH_PLAYER_INFO_SUCCESS=0,
    FETCH_PLAYER_INFO_FAILED,
    FETCH_PLAYERS_INFO_SUCCESS,
    FETCH_PLAYERS_INFO_FAILED,
    REGIST_SUCCESS,
    REGIST_FAILED=5,
    LOGIN_SUCCESS,
    LOGIN_FAILED,
    LOGOUT_SUCCESS,
    LOGOUT_FAILED,
    FETCH_LOBBY_INFO_SUCCESS=10,
    FETCH_LOBBY_INFO_FAILED,
    FETCH_ROOM_INFO_SUCCESS,
    FETCH_ROOM_INFO_FAILED,
    BROADCAST_SITDOWN,
    SITDOWN_FAILED=15,
    BROADCAST_LEAVE,
    LEAVE_FAILED,
    SINGLECAST_READYGO,
    READYGO_FAILED,
    GIVEUP_SUCCESS=20,
    GIVEUP_FAILED,
    PLACECHESS_SUCCESS,
    PLACECHESS_FAILED,
    SINGLECAST_PLACECHESS,
    GAMEOVER=25,
    GAMEOVER_FAILED,
    SEND_MSG_SUCCESS,
    SEND_MSG_FAILED,
    BROADCAST_SOMEONE_UP,
    BROADCAST_SOMEONE_DOWN=30,
    GROUP_CHAT_MSG,
    GROUP_CHAT_SUCCESS,
    GROUP_CHAT_FAILED
};
#endif
