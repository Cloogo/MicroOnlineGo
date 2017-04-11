package src.main.lobby;

import javafx.scene.control.ListCell;

/**
 * Created by touhoudoge on 2017/4/9.
 */
public class TableCell extends ListCell<Table> {

    @Override
    public void updateItem(Table item, boolean empty) {
        super.updateItem(item, empty);
        if (item != null) {
            if(item.getPlayer02()==null){
                setText(item.getRoomName() + "\n" +
                        item.getPlayer01()+"      等待挑战");
            }else{
                setText(item.getRoomName() + "\n" +
                        item.getPlayer01()+"      对战      "+item.getPlayer02());
            }
        }
    }
}
