package src.main.lobby;

/**
 * Created by touhoudoge on 2017/4/9.
 */
public class Table {
    private String roomName;
    private String player01;
    private String player02;
    private String passWord;

    public Table(String roomName,String player01){
        this.roomName = roomName;
        this.player01 = player01;
    }

    public Table(String roomName,String player01,String passWord){
        this.roomName = roomName;
        this.player01 = player01;
        this.passWord = passWord;
    }

    public String getRoomName() {return roomName;}
    public String getPlayer01() {return player01;}
    public String getPlayer02() {return player02;}

    public void setRoomName(String roomName) {this.roomName = roomName;}
    public void setPlayer01(String player01) {this.player01 = player01;}
    public void setPlayer02(String player02) {this.player02 = player02;}
}
