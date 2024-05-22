
import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class BMApp extends Application 
{
    @Override
    public void start(Stage stage) throws Exception {
        // Parent root = FXMLLoader.load(getClass().getResource("/fxml/Scene.fxml"));
        String javer = System.getProperty("java.version");
        String fxver = System.getProperty("javafx.version");
        Label label = new Label("JavaFx "+fxver+" at Java "+javer);
        StackPane root = new StackPane(label);
        Scene scene = new Scene(root, 640, 240);
        // scene.getStylesheets().add("/styles/Styles.css");
        stage.setTitle(STYLESHEET_CASPIAN);
        
        stage.setTitle("JavaFX with Java");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
