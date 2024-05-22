module hi_javafx {
  requires kotlin.stdlib;
  requires javafx.controls;
  requires javafx.fxml;
  requires javafx.web;
  requires transitive javafx.graphics;

  // requires org.controlsfx.controls;
  // requires com.dlsc.formsfx;
  // requires net.synedra.validatorfx;
  // requires org.kordamp.ikonli.javafx;
  // requires org.kordamp.bootstrapfx.core;
  // requires eu.hansolo.tilesfx;
  // requires com.almasb.fxgl.all;

  opens hi_javafx to javafx.fxml;
  exports hi_javafx;
}
