package org.example.hi_app;

import android.test.ActivityInstrumentationTestCase2;

/**
 * This is a simple framework for a test of an Application.  See
 * {@link android.test.ApplicationTestCase ApplicationTestCase} for more information on
 * how to write and extend Application tests.
 * <p/>
 * To run this test, you can type:
 * adb shell am instrument -w \
 * -e class org.example.hi_app.hi_appTest \
 * org.example.hi_app.tests/android.test.InstrumentationTestRunner
 */
public class hi_appTest extends ActivityInstrumentationTestCase2<hi_app> {

    public hi_appTest() {
        super("org.example.hi_app", hi_app.class);
    }

}
