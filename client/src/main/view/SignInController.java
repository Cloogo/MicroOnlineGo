package src.main.view;

import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import src.main.UserInfo;
import src.main.Client;
import src.main.communication.Encode;
import src.main.communication.Connect;

import java.net.URL;
import java.util.ResourceBundle;


/**
 * Created by touhoudoge on 2017/3/23.
 */
public class SignInController implements Initializable{

    private Client client;
    UserInfo account = new UserInfo();

    @FXML private TextField nameFiled;
    @FXML private TextField passwordFiled;
    @FXML private TextField repeatPasswordFiled;
    @FXML private TextField yearFiled;
    @FXML private TextField monthFiled;
    @FXML private TextField dayFiled;
    @FXML private RadioButton maleSelectBar;
    @FXML private RadioButton femaleSelectBar;
    @FXML private Label errorLabel;

    @FXML
    private void signIn() throws Exception{
        /************* test ********************/
        //client.gotoLobby();
        /************* test ********************/

        /************* release *****************/

        String name = nameFiled.getText();
        String password = passwordFiled.getText();
        String repeatPassword = repeatPasswordFiled.getText();
        //gameServe = client.getGameServe();
        if(!password.equals(repeatPassword)){
            errorLabel.setText("密码不一致");
        }/*else if(gameServe.find(name)){
            errorLabel.setText("用户名已被注册");
        }*/else{
            account.setNickname(name);
            account.setPassword(password);
            int year = Integer.parseInt(yearFiled.getText());
            int month = Integer.parseInt(monthFiled.getText());
            int day = Integer.parseInt(dayFiled.getText());
            account.setBirthday(year,month,day);
            //gameServe.signIn(account);
            client.setAccount(account);
            Encode e = new Encode();
            String json = e.accountToJson(account);
            System.out.println(json);
            Connect c = new Connect();
            c.send(json);
        }

        /************* release *****************/
    }

    @FXML
    private void selectMale(){
        /************* test ********************/
        //System.out.println("male");
        /************* test ********************/

        /************* release *****************/
        account.setSex("male");
        /************* release *****************/
    }

    @FXML
    private void selectFemale(){
        /************* test ********************/
        //System.out.println("female");
        /************* test ********************/

        /************* release *****************/
        account.setSex("female");
        /************* release *****************/
    }

    @FXML
    private void backToLogin() throws Exception{
        client.gotoLogin();
    }

    public void setClient(Client client){
        this.client = client;
    }

    @Override
    public void initialize(URL location, ResourceBundle resources){
        ToggleGroup tg = new ToggleGroup();
        maleSelectBar.setToggleGroup(tg);
        femaleSelectBar.setToggleGroup(tg);
        maleSelectBar.setSelected(true);
        account.setSex("male");
    }
}
