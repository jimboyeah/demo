package hi_javafx

import java.net.URL
import java.util.ResourceBundle
import javafx.event.ActionEvent
import javafx.fxml.FXML
import javafx.fxml.Initializable
import javafx.scene.control.Label
import javafx.scene.control.Button

class FXMLControllerKt () : Initializable
{

    @FXML 
    lateinit private var label: Label

    @FXML
    lateinit private var button: Button

    @FXML
    @Suppress("UNUSED_PARAMETER")
    private fun handleButtonAction (event: ActionEvent)
    {
        System.out.println("Button was clicked!")
        label.setText("Hello JavaFX with Kotlin")
    }

    override 
    fun initialize(url: URL?, bundle: ResourceBundle?) 
    { 
        System.out.println("url: $url, bundle: $bundle")
    }
}