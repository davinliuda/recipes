package learn.java.jdk.io;

import java.io.File;

/**
 * Created by liuda on 2017/4/18.
 */
public class TestFile {

    public static void main(String[] args) {

        File f = new File("c://abcdef");
        f.mkdirs();
    }

}
