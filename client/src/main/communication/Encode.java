package src.main.communication;

import com.google.gson.Gson;

import src.main.UserInfo;

/**
 * Created by 刘俊延 on 2017/4/9.
 */

public class Encode {
    public String accountToJson(UserInfo a){
        Gson gson = new Gson();
        return gson.toJson(a);
    }
}
