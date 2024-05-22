package hi_javafx;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.Button;

public class FXMLController implements Initializable {
    
    @FXML
    private Label label2;

    @FXML
    private Button button;

    @FXML
    private void handleButtonAction(ActionEvent event) {
        System.out.println("You clicked me! + " + button.getText());
        label2.setText("Hello World!");
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        System.out.println(
            "relative to root: " + url + 
            " localize: " + rb);
    }    
}
