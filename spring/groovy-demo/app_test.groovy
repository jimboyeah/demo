// spring test app.groovy TestApp.groovy
@Grab('junit')
class TestApp {
   @Test
   void welcomeTest() {
      assertEquals("Hello ABC", new ThisWillActuallyRun().home())
   }
}
