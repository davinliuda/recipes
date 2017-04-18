package learn.java.jdk.io;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;

/**
 * Created by liuda on 2017/4/18.
 */
public class TestRandomFile {

    public static void main(String[] args) throws IOException {

        //这个类是单独的一个类，提供seek功能.
        RandomAccessFile f = new RandomAccessFile(new File("c://abc"), "rw");
        FileChannel f1 = f.getChannel();

        ByteBuffer b = ByteBuffer.allocateDirect(20);


        while (true) {
            b.clear();
            int rc = f1.read(b);
            if (rc == -1) {
                return;
            }

            b.flip();
            int c = b.limit();
            System.out.println(c);
        }


        //f.close();
    }
}
