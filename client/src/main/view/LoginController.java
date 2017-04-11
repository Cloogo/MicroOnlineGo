package src.main.view;

import javafx.scene.control.TextField;
import src.main.Client;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;


import java.net.URL;
import java.util.ResourceBundle;

public class LoginController implements Initializable
{
    private Client client;

    @FXML private TextField nameField;
    @FXML private TextField passwordField;

    @FXML private void login() throws Exception{

        /************* test ********************/
        client.gotoLobby();
        /************* test ********************/

        /************* release *****************/
        /*
        String name = nameField.getText();
        String password = passwordField.getText();

        if(gameServe.check(name,password)){
            client.setAccount(gameServe.getAccount());
            client.gotoLobby();
        }else{
            errorLabel.setText("用户名或密码错误");
        }
        */
        /************* release *****************/
    }

    @FXML
    private void signIn() throws Exception{
        client.gotoSignIn();
    }

    public void setClient(Client client){
        this.client = client;
    }


    @Override
    public void initialize(URL location, ResourceBundle resources){}
}
