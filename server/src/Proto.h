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
    READYGO=10,
    PLACECHESS,
    UPDATE_GAMERESULT,
    SEND_MSG,
    GROUP_CHAT,
    NICKNAME_CHECK=15,
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
    SITDOWN_SUCCESS=15,
    SITDOWN_FAILED,
    BROADCAST_LEAVE,
    LEAVE_SUCCESS,
    LEAVE_FAILED,
    SINGLECAST_READYGO=20,
    BROADCAST_READYGO,
    READYGO_SUCCESS,
    READYGO_FAILED,
    PLACECHESS_SUCCESS,
    PLACECHESS_FAILED=25,
    SINGLECAST_PLACECHESS,
    UPDATE_GAMERESULT_SUCCESS,
    UPDATE_GAMERESULT_FAILED,
    SEND_MSG_SUCCESS,
    SEND_MSG_FAILED=30,
    BROADCAST_SOMEONE_UP,
    BROADCAST_SOMEONE_DOWN,
    GROUP_CHAT_MSG,
    GROUP_CHAT_SUCCESS,
    GROUP_CHAT_FAILED=35,
    SINGLECAST_CHAT,
    BROADCAST_GAMERESULT_UPDATE,
    ACCOUNT_CHECK_SUCCESS,
    ACCOUNT_CHECK_FAILED,
    NICKNAME_CHECK_SUCCESS=40,
    NICKNAME_CHECK_FAILED
};

enum class ORDER{
    LEFT,
    RIGHT
};
#endif
