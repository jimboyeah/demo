package hi_javafx

import org.junit.jupiter.api.Test
import org.junit.jupiter.api.Assertions.*
// import kotlin.test.Test
// import kotlin.test.assertNotNull
// import javafx.stage.Stage

class AppTestKt 
{
    @Test fun appHasATest() 
    {
        // MainApp().start( Stage() );
        MainApp.main(emptyArray())
        assertNotNull("void", "app show a GUI window.");
    }
}
