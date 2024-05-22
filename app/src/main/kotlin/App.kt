package hi_javafx;

import javafx.application.Application
import javafx.application.Application.launch
import javafx.fxml.FXMLLoader
import javafx.scene.Parent
import javafx.scene.Scene
import javafx.stage.Stage
import javafx.scene.control.Label
import javafx.scene.layout.StackPane
import java.net.URL


class VerPane : Application ()
{
    override
    fun start(stage: Stage)
    {
       val javaVer: String = System.getProperty("java.version")
       val fxVer: String = System.getProperty("javafx.version")
       val lab: Label = Label("JavaFX " + fxVer + " runs on Java " + javaVer)
       val scene: Scene = Scene(StackPane(lab), 640.0, 480.0)
       stage.setScene(scene)
       stage.show()
    }
}


class App : Application ()
{
    override 
    fun start(stage: Stage) 
    {
        var fxml: URL = App::class.java.getResource("/fxml/Scene.fxml")
        var root : Parent = FXMLLoader.load(fxml)

        var scene: Scene = Scene(root)
        scene.getStylesheets().add("/styles/Styles.css")

        stage.setTitle("JavaFX with Gradle and Kotlin")
        stage.setScene(scene)
        stage.show()
    }

    companion object
    {
        @JvmStatic
        @Suppress("UNUSED_PARAMETER")
        fun main(args: Array<String>) 
        {
            println("Hello JavaFX Application"  )
            // launch( VerPane::class.java )
            Application.launch( App::class.java, *args )
        }
    }
}

