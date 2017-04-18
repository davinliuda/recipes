package learn.java.jdk.io;

import java.io.*;

/**
 * Created by liuda on 2017/4/18.
 */
public class TestTextStream {

    public static void main(String[] args) throws IOException {

        PrintWriter writer = new PrintWriter(System.out);

        FileReader reader = new FileReader("C:\\abc");

        //和上面的等价的，所谓的字符流是因为里面有encoder在作怪。真正的去读数据，还是按字节去读的
        Reader r2 = new InputStreamReader(new FileInputStream("C:\\abc"));


        BufferedReader r = new BufferedReader(reader);


        StringReader r1 = new StringReader("我nihao");


        System.out.println("encoding:" + reader.getEncoding());

        int b = 0;
        int c = -1;
        while ((c = reader.read()) != -1) {
            b = b + 1;
            writer.write(c);
        }

        System.out.println("all out:" + b);

    }

}
